#include "ShaderManager.h"
#include "ShaderObject.h"

ShaderManager* ShaderManager::ptrInstance = nullptr;

ShaderManager::ShaderManager()
{
	defaultPath = "Shaders/";
}

ShaderManager::~ShaderManager()
{
	std::map<std::string, ShaderObject*>::iterator it;

	for(it = mapOfShaders.begin(); it != mapOfShaders.end(); it++)
	{
		delete it->second;
	}
}

ShaderObject* ShaderManager::privGet(const std::string& key)
{
	return mapOfShaders.at(key);
}

void ShaderManager::privLoad(const std::string& key, const std::string& path)
{
	std::string completePath = defaultPath + path;
	const char* const finalPath = completePath.c_str();

	ShaderObject* pNewShader = new ShaderObject(finalPath);

	mapOfShaders.insert(std::pair<std::string, ShaderObject*>(key, pNewShader));
}

void ShaderManager::privLoadDefaults()
{
	std::string completePath = defaultPath + "spriteRender";
	const char* const finalPath = completePath.c_str();

	ShaderObject* pNewShader = new ShaderObject(finalPath);

	mapOfShaders.insert(std::pair<std::string, ShaderObject*>("spriteRender", pNewShader));
}

void ShaderManager::privUpdateDefaultPath(const std::string& newPath)
{
	defaultPath = newPath;
}

void ShaderManager::privDelete()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}

