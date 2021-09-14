#pragma once
#include "CCharacter.h"

class CArcher :public CCharacter
{
protected:
	//Membres
	int m_cdViser;
	int m_cdGu�rir;

public:
	//M�thodes
	CArcher();
	~CArcher();

	//Getters
	int getSpecial(string cd);

	//Setters
	void setSpecial(string cd, int valeur);



	//Attaque avec une arme
	void attaqueArme(CCharacter& ennemi);

	//Attaque sp�ciale viser
	void attaqueSpeciale();

	//Attaque sp�ciale gu�rir du poion
	void attaqueSpeciale(CCharacter *player);

	//Diminution du cooldown
	void nouveauTour();

};