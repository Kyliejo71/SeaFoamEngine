#ifndef _DrawableManager
#define _DrawableManager

#include <list>

class Drawable;

class DrawableManager
{
private:

	using StorageList = std::list<Drawable*>;
	StorageList storageList;

public:

	using StorageListIt = StorageList::iterator;

	DrawableManager() = default;
	DrawableManager(const DrawableManager&) = delete;
	DrawableManager& operator=(const DrawableManager&) = delete;
	~DrawableManager();

	void ProcessElements();

	void Register(Drawable* up, StorageListIt& ref);
	void Deregister(StorageListIt& ref);

};

#endif _DrawableManager
