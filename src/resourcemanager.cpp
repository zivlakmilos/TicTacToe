#include "resourcemanager.h"

ResourceManager::ResourceManager(void)
{
}

ResourceManager &ResourceManager::getResourceManager(void)
{
    static ResourceManager resourceManager;
    return resourceManager;
}

void ResourceManager::loadTexture(const std::string &id, const std::string &filePath)
{
    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
    if(!texture->loadFromFile(filePath))
        throw std::string("Can't load texture");

    m_textures[id] = texture;
}

std::shared_ptr<sf::Texture> ResourceManager::getTexture(const std::string &id) const
{
    auto it = m_textures.find(id);
    if(it == m_textures.end())
        throw std::string("Texture don't exists");

    return it->second;
}

void ResourceManager::loadFont(const std::string &id, const std::string &filePath)
{
    std::shared_ptr<sf::Font> font = std::make_shared<sf::Font>();
    if(!font->loadFromFile(filePath))
        throw std::string("Can't load texture");

    m_fonts[id] = font;
}

std::shared_ptr<sf::Font> ResourceManager::getFont(const std::string &id) const
{
    auto it = m_fonts.find(id);
    if(it == m_fonts.end())
        throw std::string("Font don't exists");

    return it->second;
}
