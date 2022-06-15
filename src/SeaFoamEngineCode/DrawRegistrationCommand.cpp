#include "DrawRegistrationCommand.h"
#include "DrawableAttorney.h"

DrawRegistrationCommand::DrawRegistrationCommand(Drawable* dr)
	:ptrDr(dr)
{
}

void DrawRegistrationCommand::execute()
{
	DrawableAttorney::Registration::SceneRegistration(ptrDr);
}
