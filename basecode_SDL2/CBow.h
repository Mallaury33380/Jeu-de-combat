#pragma once
#include "CRanged.h"

class CBow :public CRanged
{
protected:
	//Membres
	int m_fleches;
public:
	//Methodes
	CBow();
	~CBow();

	int getSpecial();
	void setSpecial(int fleches);

	void utilisation();
};