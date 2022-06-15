#ifndef _ModelManager
#define _ModelManager

#include <string>
#include <map>
#include "Model.h"

using PMM = Model::PreMadeModels;


class ModelManager
{
	friend class ModelManagerAttorney;
private:
	static ModelManager* ptrInstance;

	ModelManager();
	ModelManager(const ModelManager&) = delete;
	ModelManager& operator=(const ModelManager&) = delete;
	~ModelManager();

	static ModelManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ModelManager();
		return *ptrInstance;
	};

	Model* privGet(const std::string& key);
	void privLoad(const std::string& key, const std::string& path); //load from file
	void privLoad(const std::string& key, const PMM pmm); //load from pre made model
	void privUpdateDefaultPath(const std::string& newPath);

	void privDelete();

	static void Delete() { Instance().privDelete(); }

	std::string defaultPath;
	std::map<std::string, Model*> mapOfModels;

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets a model* using the given key. </summary>
	///
	/// <remarks>	Kylie, 3/11/2021. </remarks>
	///
	/// <param name="key">	The mapped key to the model. </param>
	///
	/// <returns>	Null if it fails, else a pointer to a Model. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static Model* Get(const std::string& key) { return Instance().privGet(key); }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Loads a model from a key and file pathname. </summary>
	///
	/// <remarks>	Kylie, 3/11/2021. </remarks>
	///
	/// <param name="key"> 	The key. </param>
	/// <param name="path">	Full pathname of the file. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Load(const std::string& key, const std::string& path) { Instance().privLoad(key, path); }\

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Loads a a premade model. </summary>
	///
	/// <remarks>	Kylie, 3/11/2021. </remarks>
	///
	/// <param name="key">	The key. </param>
	/// <param name="pmm">	The premade model name. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Load(const std::string& key, const PMM pmm) { Instance().privLoad(key, pmm); }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Updates the default path described by newPath. </summary>
	///
	/// <remarks>	Kylie, 3/11/2021. </remarks>
	///
	/// <param name="newPath">	Full new pathname. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void UpdateDefaultPath(const std::string& newPath) { Instance().privUpdateDefaultPath(newPath); }
};

#endif _ModelManager
