#include "TextureManager.h"
#include "Texture.h"

TextureManager* TextureManager::ptrInstance = nullptr;

TextureManager::TextureManager()
{
	defaultPath = "Textures/";
}

TextureManager::~TextureManager()
{
	std::map<std::string, Texture*>::iterator it;

	for (it = mapOfTextures.begin(); it != mapOfTextures.end(); it++)
	{
		delete it->second;
	}
}

Texture* TextureManager::privGet(const std::string& key)
{
	return mapOfTextures.at(key);
}

void TextureManager::privLoad(const std::string& key, const std::string& path)
{
	std::string completePath = defaultPath + path;
	const char* const finalPath = completePath.c_str();

	Texture* pNewTexture = new Texture(finalPath);

	mapOfTextures.insert(std::pair<std::string, Texture*>(key, pNewTexture));
}

void TextureManager::privLoad(const std::string& key, const unsigned char& red, const unsigned char& green, const unsigned char& blue)
{
	Texture* pNewTexture = new Texture(red, green, blue);

	mapOfTextures.insert(std::pair<std::string, Texture*>(key, pNewTexture));
}

void TextureManager::privUpdateDefaultPath(const std::string& newPath)
{
	defaultPath = newPath;
}

void TextureManager::privDelete()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
