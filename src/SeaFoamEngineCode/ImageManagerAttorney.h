#ifndef _ImageManagerAttorney
#define _ImageManagerAttorney

#include "ImageManager.h"

class ImageManagerAttorney
{
	friend class SeaFoamEngine;
public:

	ImageManagerAttorney() = default;
	ImageManagerAttorney(const ImageManagerAttorney&) = delete;
	ImageManagerAttorney& operator=(const ImageManagerAttorney&) = delete;
	~ImageManagerAttorney() = default;

private:
	static void Delete() { ImageManager::Delete(); }

};

#endif _ImageManagerAttorney
