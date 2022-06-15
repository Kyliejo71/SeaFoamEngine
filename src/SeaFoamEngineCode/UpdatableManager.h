#ifndef _UpdatableManager
#define _UpdatableManager

#include <list>

class Updatable;

class UpdatableManager
{
private:

	using StorageList = std::list<Updatable*>;
	StorageList storageList;

public:

	using StorageListIt = StorageList::iterator;

	UpdatableManager() = default;
	UpdatableManager(const UpdatableManager&) = delete;
	UpdatableManager& operator=(const UpdatableManager&) = delete;
	~UpdatableManager();

	void ProcessElements();

	void Register(Updatable* up, StorageListIt& ref);
	void Deregister(StorageListIt& ref);

};

#endif _UpdatableManager
