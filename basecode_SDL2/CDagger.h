#pragma once
#include "CMelee.h"

class CDagger :public CMelee
{
protected:
	//Membres
public:
	//Methodes
	CDagger();
	virtual ~CDagger();

	void utilisation();
};