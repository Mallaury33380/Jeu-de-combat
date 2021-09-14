#pragma once
#include "CRanged.h"

class CStaff :public CRanged
{
protected:
	//membres
	int m_cout;
public:
	CStaff();
	~CStaff();

	int getSpecial();
	void setSpecial(int cout);
};