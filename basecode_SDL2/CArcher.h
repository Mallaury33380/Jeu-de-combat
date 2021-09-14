#pragma once
#include "CCharacter.h"

class CArcher :public CCharacter
{
protected:
	//Membres
	int m_cdViser;
	int m_cdGuérir;

public:
	//Méthodes
	CArcher();
	~CArcher();

	//Getters
	int getSpecial(string cd);

	//Setters
	void setSpecial(string cd, int valeur);



	//Attaque avec une arme
	void attaqueArme(CCharacter& ennemi);

	//Attaque spéciale viser
	void attaqueSpeciale();

	//Attaque spéciale guérir du poion
	void attaqueSpeciale(CCharacter *player);

	//Diminution du cooldown
	void nouveauTour();

};