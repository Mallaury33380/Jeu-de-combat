#pragma once
#include"utils.h"

#include "CWeapon.h"
#include "CSword.h"
#include "CDagger.h"
#include "CBow.h"
#include "CStaff.h"

class CCharacter
{
protected:
	//Membres
	string m_nom;
	int m_hp;
	CWeapon *m_arme=NULL;
	float m_esquive;
	int m_vitesse;
	int m_attaque;
	int m_defense;
	int m_agilite;
	int m_intelligence;

	bool m_empoisonne;

public:
	//Méthodes
	CCharacter();
	virtual ~CCharacter();

	//Getters
	string getNom();
	int getHp();
	CWeapon *getArme();
	float getEsquive();
	int getVitesse();
	int getAttaque();
	int getDefense();
	int getAgilite();
	int getIntelligence();
	int getSpecial();
	bool getEmpoisonne();

	//Setters
	void setNom(string nom);
	void setHp(int hp);
	void setArme(CWeapon *arme);
	void setEsquive(float esquive);
	void setVitesse(int vitesse);
	void setAttaque(int attaque);
	void setDefense(int defense);
	void setAgilite(int agilite);
	void setIntelligence(int intelligence);
	void setSpecial();
	void setEmpoisonne(bool val);

	//Attaque mains nues
	void attaqueMainsNues(CCharacter &ennemi);

	//Attaque avec armes
	virtual void attaqueArme();

	//Attaque spéciale
	virtual void attaqueSpeciale();

	//Diminution du cooldown
	virtual void nouveauTour();

};