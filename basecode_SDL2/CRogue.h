#pragma once
#include	"CCharacter.h"

class CRogue :public CCharacter
{
protected:
	//Membres
	bool m_invisible;
	int m_cdFurtif;
	float m_probEpoisonnement;
public:
	//Methodes
	CRogue();
	~CRogue();

	//Getters
	float getSpecial(string cd);

	//Setters
	void setSpecial(string cd, float valeur);


	//Attaque avec une arme
	void attaqueArme(CCharacter& ennemi);


	//Attaque spéciale furtif
	void attaqueSpeciale();

	//Nouveau tour
	void nouveauTour();
};
