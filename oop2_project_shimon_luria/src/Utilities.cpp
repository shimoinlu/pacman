#include "Utilities.h"

Utilities& Utilities::getInstance()
{
	static Utilities utl;
	return utl;
	// TODO: insert return statement here
}
