#include "CWeapon.h"

CWeapon::CWeapon()
{

}
CWeapon:: ~CWeapon()
{

}

//Sets
void CWeapon::setNom(string nom)
{
	m_nom = nom;
	return;
}
void CWeapon::setDegat(int degat)
{
	m_degat = degat;
	return;
}
void CWeapon::setCritique(float critique)
{
	m_critique = critique;
	return;
}
void CWeapon::setNomBonus(vector<string> nomBonus)
{
	m_nomBonus = nomBonus;
	return;
}
void CWeapon::setValeurBonus(vector<float> valeurBonus)
{
	m_valeurBonus = valeurBonus;
	return;
}
void CWeapon::setEnchante(bool val)
{
	m_enchante = val;
	return;
}





//Gets
string CWeapon::getNom()
{
	return m_nom;
}
int CWeapon::getDegat()
{
	return m_degat;
}
float CWeapon::getCritique()
{
	return m_critique;
}
vector<string> CWeapon::getNomBonus()
{
	return m_nomBonus;
}
vector<float> CWeapon::getValeurBonus()
{
	return m_valeurBonus;
}
bool CWeapon::getEnchante()
{
	return m_enchante;
}

//Virtual
void CWeapon::utilisation()
{

}
int CWeapon::getSpecial()
{
	return 0;
}
void CWeapon::setSpecial()
{

}