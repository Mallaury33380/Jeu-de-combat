#pragma once
#include "utils.h"
#include "CCharacter.h"

class CWarrior :public CCharacter
{
protected:
	//Membres
	int m_cdCris;
	int m_cdReparation;

	int m_nombreDeTours;
	float m_parade;

public:
	//Méthodes
	CWarrior();
	~CWarrior();


	//Getters
	float getSpecial(string cd);

	//Setters
	void setSpecial(string cd, float valeur);

	//Attaque avec armes
	void attaqueArme(CCharacter &ennemi);

	//Attaque spéciale
	void attaqueSpeciale();
	void attaqueSpeciale(CCharacter* amiReparage, vector<CWeapon*> listeArmes);

	//Diminution du cooldown
	void nouveauTour();

};