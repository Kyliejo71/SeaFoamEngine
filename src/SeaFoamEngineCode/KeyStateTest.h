#ifndef _KeyStateTest
#define _KeyStateTest

#include "AzulCore.h"

class KeyStateTest
{
public:

	KeyStateTest() = default;
	KeyStateTest(AZUL_KEY k);
	KeyStateTest(const KeyStateTest&) = default;
	KeyStateTest& operator=(const KeyStateTest&) = default;
	~KeyStateTest() = default;

	void TestKey();

	enum PressState
	{
		CURRENTLY_PRESSED,
		CURRENTLY_RELEASED	
	};


private:

	AZUL_KEY key;
	PressState curState;

};

#endif _KeyStateTest
