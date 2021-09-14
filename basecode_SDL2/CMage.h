#pragma once
#include "CCharacter.h"


class CMage :public CCharacter
{
protected:
	//Membres
	int m_mana;

	int m_cdSoin;
	int m_cdEnchantement;

public:
	//Methodes
	CMage();
	CMage(int intelligence);
	~CMage();

	//Getters
	int getSpecial(string cd);

	//Setters
	void setSpecial(string cd, int valeur);


	//Attaque avec une arme
	void attaqueArme(CCharacter& ennemi);


	//Attaque spéciale regenerer
	void attaqueSpeciale();

	//Attaque spéciale soigner
	//Attaque spéciale enchanter
	void attaqueSpeciale(CCharacter& player, string cd);

	//Nouveau tour
	void nouveauTour();
};