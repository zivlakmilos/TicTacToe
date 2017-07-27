#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

#include <string>
#include <memory>
#include <unordered_map>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>

class ResourceManager
{
public:
    ResourceManager(const ResourceManager &) = delete;
    const ResourceManager &operator=(const ResourceManager &) = delete;

    static ResourceManager &getResourceManager(void);

    void loadTexture(const std::string &id, const std::string &filePath);
    std::shared_ptr<sf::Texture> getTexture(const std::string &id) const;

    void loadFont(const std::string &id, const std::string &filePath);
    std::shared_ptr<sf::Font> getFont(const std::string &id) const;

private:
    ResourceManager(void);

    std::unordered_map<std::string, std::shared_ptr<sf::Texture>> m_textures;
    std::unordered_map<std::string, std::shared_ptr<sf::Font>> m_fonts;
};

#endif // _RESOURCE_MANAGER_H_
