#include "UpdateDeregistrationCommand.h"
#include "UpdatableAttorney.h"

UpdateDeregistrationCommand::UpdateDeregistrationCommand(Updatable* up)
	:ptrUp(up)
{
}

void UpdateDeregistrationCommand::execute()
{
	UpdatableAttorney::Deregistration::SceneDeregistration(ptrUp);
}
