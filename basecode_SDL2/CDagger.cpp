#include "CDagger.h"

CDagger::CDagger()
{

}
CDagger:: ~CDagger()
{

}

void CDagger::utilisation()
{
	setSpecial(getSpecial() - 1);
	return;
}