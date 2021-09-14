#pragma once
#include "utils.h"

class CWeapon
{
protected:
	//Membres
	string m_nom;
	int m_degat;
	float m_critique;

	bool m_enchante;

	vector<string> m_nomBonus;
	vector<float> m_valeurBonus;
public:
	//Méthodes
	CWeapon();
	virtual ~CWeapon();

	//Sets
	void setNom(string nom);
	void setDegat(int degat);
	void setCritique(float critique);
	void setNomBonus(vector<string> nomBonus);
	void setValeurBonus(vector<float> valeurBonus);
	void setEnchante(bool val);

	//Gets
	string getNom();
	int getDegat();
	float getCritique();
	vector<string> getNomBonus();
	vector<float> getValeurBonus();
	bool getEnchante();

	//Virtual
	virtual void utilisation();
	virtual int getSpecial();
	virtual void setSpecial();
};