#pragma once
#include "utils.h"
#include "CWeapon.h"

class CMelee :public CWeapon
{
protected:
	//Membres
	int m_durabilite;
public:
	//Methodes
	CMelee();
	virtual ~CMelee();
	
	int getSpecial();
	void setSpecial(int durabilite);

	virtual void utilisation();

};