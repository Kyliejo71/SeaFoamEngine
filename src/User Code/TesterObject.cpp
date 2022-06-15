#include "TesterObject.h"
#include "KeyStateTest.h"

TesterObject::TesterObject()
{
	myKeyTest = new KeyStateTest(AZUL_KEY::KEY_T);

	SubmitUpdateRegistration();
}

void TesterObject::Update()
{
	myKeyTest->TestKey();
}

