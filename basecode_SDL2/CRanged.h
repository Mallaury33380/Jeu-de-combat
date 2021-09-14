#pragma once
#include "CWeapon.h"

class CRanged :public CWeapon
{
protected:
	//Membres

public:
	//Methodes
	CRanged();
	~CRanged();

	virtual int getSpecial();
	virtual void setSpecial();

	virtual void utilisation();
};