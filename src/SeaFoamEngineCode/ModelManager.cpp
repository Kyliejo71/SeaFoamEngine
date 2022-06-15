#include "ModelManager.h"
#include "Model.h"

ModelManager* ModelManager::ptrInstance = nullptr;

ModelManager::ModelManager()
{
	defaultPath = "Models/";
}

ModelManager::~ModelManager()
{
	std::map<std::string, Model*>::iterator it;

	for (it = mapOfModels.begin(); it != mapOfModels.end(); it++)
	{
		delete it->second;
	}
}

Model* ModelManager::privGet(const std::string& key)
{
	return mapOfModels.at(key);
}

void ModelManager::privLoad(const std::string& key, const std::string& path)
{
	std::string completePath = defaultPath + path;
	const char* const finalPath = completePath.c_str();

	Model* pNewModel = new Model(finalPath);

	mapOfModels.insert(std::pair<std::string, Model*>(key, pNewModel));
}

void ModelManager::privLoad(const std::string& key, const PMM pmm)
{
	Model* pNewModel = new Model(pmm);

	mapOfModels.insert(std::pair<std::string, Model*>(key, pNewModel));
}

void ModelManager::privUpdateDefaultPath(const std::string& newPath)
{
	defaultPath = newPath;
}

void ModelManager::privDelete()
{
	delete ptrInstance;
	ptrInstance = nullptr;
}
