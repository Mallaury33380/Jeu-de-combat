#include "CCharacter.h"

CCharacter::CCharacter()
{

}
CCharacter::~CCharacter()
{

}

//Getters
string CCharacter::getNom()
{
	return m_nom;
}
int CCharacter::getHp()
{
	return m_hp;
}
CWeapon *CCharacter::getArme()
{
	return m_arme;
}
float CCharacter::getEsquive()
{
	return m_esquive;
}
int CCharacter::getVitesse()
{
	return m_vitesse;
}
int CCharacter::getAttaque()
{
	return m_attaque;
}
int CCharacter::getDefense()
{
	return m_defense;
}
int CCharacter::getAgilite()
{
	return m_agilite;
}
int CCharacter::getIntelligence()
{
	return m_intelligence;
}
int CCharacter::getSpecial()
{
	return 0;
}
bool CCharacter::getEmpoisonne()
{
	return m_empoisonne;
}


//Setters
void CCharacter::setNom(string nom)
{
	m_nom = nom;
	return;
}
void CCharacter::setHp(int hp)
{
	m_hp = hp;
	return;
}
void CCharacter::setArme(CWeapon *arme)
{
	//En focntion du type d'arme
	if (dynamic_cast<CSword*> (arme))
	{
		CSword* Arme=new CSword;
		Arme->setCritique(arme->getCritique());
		Arme->setDegat(arme->getDegat());
		Arme->setNom(arme->getNom());
		Arme->setNomBonus(arme->getNomBonus());
		Arme->setSpecial(arme->getSpecial());
		Arme->setValeurBonus(arme->getValeurBonus());
		m_arme = Arme;
	}
	else if (dynamic_cast<CDagger*> (arme))
	{
		CDagger* Arme = new CDagger;
		Arme->setCritique(arme->getCritique());
		Arme->setDegat(arme->getDegat());
		Arme->setNom(arme->getNom());
		Arme->setNomBonus(arme->getNomBonus());
		Arme->setSpecial(arme->getSpecial());
		Arme->setValeurBonus(arme->getValeurBonus());
		m_arme = Arme;
	}
	else if (dynamic_cast<CBow*> (arme))
	{
		CBow* Arme = new CBow;
		Arme->setCritique(arme->getCritique());
		Arme->setDegat(arme->getDegat());
		Arme->setNom(arme->getNom());
		Arme->setNomBonus(arme->getNomBonus());
		Arme->setSpecial(arme->getSpecial());
		Arme->setValeurBonus(arme->getValeurBonus());
		m_arme = Arme;
	}
	else if (dynamic_cast<CStaff*> (arme))
	{
		CStaff* Arme = new CStaff;
		Arme->setCritique(arme->getCritique());
		Arme->setDegat(arme->getDegat());
		Arme->setNom(arme->getNom());
		Arme->setNomBonus(arme->getNomBonus());
		Arme->setSpecial(arme->getSpecial());
		Arme->setValeurBonus(arme->getValeurBonus());
		m_arme = Arme;
	}
	else
	{
		cout << "Type d'armes inconnus CCharacter" << endl;
	}

	return;
}
void CCharacter::setEsquive(float esquive)
{
	m_esquive = esquive;
	return;
}
void CCharacter::setVitesse(int vitesse)
{
	m_vitesse = vitesse;
	return;
}
void CCharacter::setAttaque(int attaque)
{
	m_attaque = attaque;
	return;
}
void CCharacter::setDefense(int defense)
{
	m_defense = defense;
	return;
}
void CCharacter::setAgilite(int agilite)
{
	m_agilite = agilite;
	return;
}
void CCharacter::setIntelligence(int intelligence)
{
	m_intelligence = intelligence;
	return;
}
void CCharacter::setSpecial()
{
	return;
}
void CCharacter::setEmpoisonne(bool val)
{
	m_empoisonne = val;
	return;
}



//Attaque mains nues
void CCharacter::attaqueMainsNues(CCharacter &ennemi)
{
	//Calcul coeff
	srand(time(NULL));
	float coeff = (float) (rand() % 11);
	coeff = (float) (coeff / 100 + 0.95);
	//Calcul attaque mains nues
	coeff =(int) (16 * m_attaque * coeff / ennemi.m_defense);
	
	//Esquive
	float esquive =(float) (rand() % 101);
	if ((esquive / 100) < ennemi.getEsquive())
	{
		coeff = 0;
	}
	   
	//Application des dégats
	ennemi.setHp(ennemi.getHp() - coeff);

	return;
}

//Attaque avec armes
void CCharacter::attaqueArme()
{
	return;
}

//Attaque spéciale
void CCharacter::attaqueSpeciale()
{
	return;
}

//Diminution du cooldown
void CCharacter::nouveauTour()
{
	return;
}