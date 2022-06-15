#ifndef _TextureManagerAttorney
#define _TextureManagerAttorney

#include "TextureManager.h"

class TextureManagerAttorney
{
	friend class SeaFoamEngine;
public:

	TextureManagerAttorney() = default;
	TextureManagerAttorney(const TextureManagerAttorney&) = delete;
	TextureManagerAttorney& operator=(const TextureManagerAttorney&) = delete;
	~TextureManagerAttorney() = default;

private:
	static void Delete() { TextureManager::Delete(); }
};

#endif _TextureManagerAttorney

