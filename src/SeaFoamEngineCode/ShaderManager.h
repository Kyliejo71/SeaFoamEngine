#ifndef _ShaderManager
#define _ShaderManager

#include <string>
#include <map>

class ShaderObject;

class ShaderManager
{
	friend class ShaderManagerAttorney;
private:
	static ShaderManager* ptrInstance;

	ShaderManager();
	ShaderManager(const ShaderManager&) = delete;
	ShaderManager& operator=(const ShaderManager&) = delete;
	~ShaderManager();

	static ShaderManager& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new ShaderManager();
		return *ptrInstance;
	};

	ShaderObject* privGet(const std::string& key);
	void privLoad(const std::string& key, const std::string& path);
	void privLoadDefaults();
	void privUpdateDefaultPath(const std::string& newPath);

	void privDelete();

	static void Delete() { Instance().privDelete(); }

	std::string defaultPath;
	std::map<std::string, ShaderObject*> mapOfShaders;

public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets a shader object* using the given key. </summary>
	///
	/// <remarks>	Kylie, 3/11/2021. </remarks>
	///
	/// <param name="key">	The key mapped to the Shader. </param>
	///
	/// <returns>	Null if it fails, else a pointer to a ShaderObject. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static ShaderObject* Get(const std::string& key) { return Instance().privGet(key); }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Loads the shader from a key and file pathname. </summary>
	///
	/// <remarks>	Kylie, 3/11/2021. </remarks>
	///
	/// <param name="key"> 	The mapped key. </param>
	/// <param name="path">	Full pathname of the file. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void Load(const std::string& key, const std::string& path) { Instance().privLoad(key, path); }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Loads the default shaders. </summary>
	///
	/// <remarks>	Kylie, 3/11/2021. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void LoadDefaults() { Instance().privLoadDefaults(); }

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Updates the default path described by newPath. </summary>
	///
	/// <remarks>	Kylie, 3/11/2021. </remarks>
	///
	/// <param name="newPath">	Full pathname for the new path. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	static void UpdateDefaultPath(const std::string& newPath) { Instance().privUpdateDefaultPath(newPath); }
};

#endif _ShaderManager