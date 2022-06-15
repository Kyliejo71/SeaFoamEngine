#ifndef _ShaderManagerAttorney
#define _ShaderManagerAttorney

#include "ShaderManager.h"

class ShaderManagerAttorney
{
	friend class SeaFoamEngine;
public:

	ShaderManagerAttorney() = default;
	ShaderManagerAttorney(const ShaderManagerAttorney&) = delete;
	ShaderManagerAttorney& operator=(const ShaderManagerAttorney&) = delete;
	~ShaderManagerAttorney() = default;

private:
	static void Delete() { ShaderManager::Delete(); }
};

#endif _ShaderManagerAttorney
