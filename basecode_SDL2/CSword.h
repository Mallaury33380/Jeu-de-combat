#pragma once
#include "CMelee.h"


class CSword :public CMelee
{
protected:
	//Membres
public:
	//Methodes
	CSword();
	virtual ~CSword();

	void utilisation();
};