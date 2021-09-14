#include "CSword.h"

CSword::CSword()
{}
CSword::~CSword()
{}

void CSword::utilisation()
{
	srand(time(NULL));
	setSpecial(getSpecial() - ((rand() % 4) + 2));
	return;
}