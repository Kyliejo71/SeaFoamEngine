#ifndef _ModelManagerAttorney
#define _ModelManagerAttorney

#include "ModelManager.h"

class ModelManagerAttorney
{
	friend class SeaFoamEngine;
public:

	ModelManagerAttorney() = default;
	ModelManagerAttorney(const ModelManagerAttorney&) = delete;
	ModelManagerAttorney& operator=(const ModelManagerAttorney&) = delete;
	~ModelManagerAttorney() = default;

private:
	static void Delete() { ModelManager::Delete(); }

};

#endif _ModelManagerAttorney