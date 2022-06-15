#ifndef _ImageManager
#define _ImageManager

#include <string>
#include <map>
#include "AzulCore.h"


class ImageManager
{
	friend class ImageManagerAttorney;
private:
	static ImageManager* ptrInstance;

	ImageManager();
	ImageManager(const ImageManager&) = delete;
	ImageManager& operator=(const ImageManager&) = delete;
	~ImageManager();

	static ImageManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ImageManager();
		return *ptrInstance;
	};

	Image* privGet(const std::string& key);
	void privLoad(const std::string& key, Texture* tex);
	void privLoad(const std::string& key, Texture* tex, Rect* r);
	void privUpdateDefaultPath(const std::string& newPath);

	void privDelete();

	static void Delete() { Instance().privDelete(); }

	std::string defaultPath;
	std::map<std::string, Image*> mapOfImages;

public:

	static void Load(const std::string& key, Texture* tex) { Instance().privLoad(key, tex); }
	static void Load(const std::string& key, Texture* tex, Rect* r) { Instance().privLoad(key, tex, r); }
	static void UpdateDefaultPath(const std::string& newPath) { Instance().privUpdateDefaultPath(newPath); }
	static Image* Get(const std::string& key) { return Instance().privGet(key); }

};

#endif _ImageManager
