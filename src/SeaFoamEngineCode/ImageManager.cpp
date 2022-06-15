#include "ImageManager.h"

ImageManager* ImageManager::ptrInstance = nullptr;

ImageManager::ImageManager()
{
	defaultPath = "Sprites/";
}
ImageManager::~ImageManager()
{
	std::map<std::string, Image*>::iterator it;

	for (it = mapOfImages.begin(); it != mapOfImages.end(); it++)
	{
		delete it->second;
	}
}

Image* ImageManager::privGet(const std::string& key)
{
	return mapOfImages.at(key);;
}

void ImageManager::privLoad(const std::string& key, Texture* tex)
{
	Rect* r = new Rect(0.0f, 0.0f, (float)tex->getWidth(), (float)tex->getHeight());
	Image* pNewImage = new Image(tex, r);

	mapOfImages.insert(std::pair<std::string, Image*>(key, pNewImage));
}

void ImageManager::privLoad(const std::string& key, Texture* tex, Rect* r)
{
	Image* pNewImage = new Image(tex, r);

	mapOfImages.insert(std::pair<std::string, Image*>(key, pNewImage));
}

void ImageManager::privUpdateDefaultPath(const std::string& newPath)
{
	defaultPath = newPath;
}

void ImageManager::privDelete()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
