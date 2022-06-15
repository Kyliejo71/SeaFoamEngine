#ifndef _TextureManager
#define _TextureManager

#include <string>
#include <map>

class Texture;

class TextureManager
{
	friend class TextureManagerAttorney;
private:
	static TextureManager* ptrInstance;

	TextureManager();
	TextureManager(const TextureManager&) = delete;
	TextureManager& operator=(const TextureManager&) = delete;
	~TextureManager();

	static TextureManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new TextureManager();
		return *ptrInstance;
	};

	Texture* privGet(const std::string& key);
	void privLoad(const std::string& key, const std::string& path); //load from a file
	void privLoad(const std::string& key, const unsigned char& red, const unsigned char& green, const unsigned char& blue); //create from one color
	void privUpdateDefaultPath(const std::string& newPath);

	void privDelete();

	static void Delete() { Instance().privDelete(); }

	std::string defaultPath;
	std::map<std::string, Texture*> mapOfTextures;

public:

	static Texture* Get(const std::string& key) { return Instance().privGet(key); }
	static void Load(const std::string& key, const std::string& path) { Instance().privLoad(key, path); }
	static void Load(const std::string& key, const unsigned char& red, const unsigned char& green, const unsigned char& blue) { Instance().privLoad(key, red, green, blue); }
	static void UpdateDefaultPath(const std::string& newPath) { Instance().privUpdateDefaultPath(newPath); }
};

#endif _TextureManager
