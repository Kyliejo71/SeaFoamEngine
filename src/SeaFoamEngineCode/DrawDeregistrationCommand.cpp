#include "DrawDeregistrationCommand.h"
#include "DrawableAttorney.h"

DrawDeregistrationCommand::DrawDeregistrationCommand(Drawable* dr)
	:ptrDr(dr)
{
}

void DrawDeregistrationCommand::execute()
{
	DrawableAttorney::Deregistration::SceneDeregistration(ptrDr);
}
