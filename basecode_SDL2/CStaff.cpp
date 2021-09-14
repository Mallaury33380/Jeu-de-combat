#include "CStaff.h"

CStaff::CStaff()
{}
CStaff::~CStaff()
{}

int CStaff::getSpecial()
{
	return m_cout;
}
void CStaff::setSpecial(int cout)
{
	m_cout = cout;
	return;
}