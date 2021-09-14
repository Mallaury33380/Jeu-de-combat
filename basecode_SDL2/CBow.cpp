#include "CBow.h"

CBow::CBow()
{}
CBow::~CBow()
{}

int CBow::getSpecial()
{
	return m_fleches;
}
void CBow::setSpecial(int fleches)
{
	m_fleches = fleches;
	return;
}

void CBow::utilisation()
{
	m_fleches--;
	return;
}