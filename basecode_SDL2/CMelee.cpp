#include "CMelee.h"

CMelee::CMelee()
{}
CMelee::~CMelee()
{}

int CMelee::getSpecial()
{
	return m_durabilite;
}
void CMelee::setSpecial(int durabilite)
{
	m_durabilite = durabilite;
	return;
}

void CMelee::utilisation()
{}