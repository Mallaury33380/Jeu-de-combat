#include "CRogue.h"
#include "CWarrior.h"

CRogue::CRogue()
{

}
CRogue::~CRogue()
{

}

//BON
//Getters
float CRogue::getSpecial(string cd)
{
	if (cd == "m_invisible")
	{
		return m_invisible;
	}
	else if (cd == "m_cdFurtif")
	{
		return m_cdFurtif;
	}
	else if (cd == "m_probEpoisonnement")
	{
		return m_probEpoisonnement;
	}
	else
	{
		cout << "erreur variable get special Crogue" << endl;
		return -1;
	}
}

//BON
//Setters
void CRogue::setSpecial(string cd, float valeur)
{
	if (cd == "m_invisible")
	{
		m_invisible = valeur;
	}
	else if (cd == "m_cdFurtif")
	{
		m_cdFurtif = valeur;
	}
	else if (cd == "m_probEpoisonnement")
	{
		m_probEpoisonnement = valeur;
	}
	else
	{
		cout << "erreur variable set special Crogue" << endl;
		return ;
	}
}

//BON
//Attaque avec une arme
void CRogue::attaqueArme(CCharacter& ennemi)
{
	//Initialisation rand
	srand(time(NULL));
	//Si attaque avec un arc
	if (dynamic_cast<CBow*> (m_arme))
	{
		//Si il a des fleches
		if (m_arme->getSpecial() == 0)
		{
			return;
		}
	}
	//Si attaque avec une dague
	else
	{
		if (((rand() % 101) / 100) < m_probEpoisonnement)
		{
			ennemi.setEmpoisonne(true);
		}
	}

	//Calcul coeff
	float coeff = (float)(rand() % 16);
	coeff = (float)(coeff / 100 + 0.85);

	//Calcul attaque avec l'arme
	coeff = (int)(7 * coeff * (m_agilite + m_arme->getDegat()) / ennemi.getDefense());


	//SI dague cassée
	if (dynamic_cast<CDagger*> (m_arme) && m_arme->getSpecial() <= 0)
	{
		coeff = coeff / 10;
	}
	
	//Si c'est un arc
	if (dynamic_cast<CBow*> (m_arme))
	{
		//Si il a des fleches
		if (dynamic_cast<CBow*> (m_arme)->getSpecial() != 0)
		{
			//retir une fleche
			dynamic_cast<CBow*> (m_arme)->setSpecial(dynamic_cast<CBow*> (m_arme)->getSpecial() - 1);
		}
		else
		{
			coeff = 0;
		}
	}

	//Effet du critique
	float critique = (float)(rand() % 101);
	if ((critique / 100) < m_arme->getCritique())
	{
		cout << 1;
		coeff *= 2;
	}

	//Effet enchantement
	if (m_arme->getEnchante())
	{
		coeff = coeff * 4 / 3;
		m_arme->setEnchante(false);
	}

	//Esquive
	float esquive = (float)(rand() % 101);
	//attaque un guerrier avec une épe
	if (dynamic_cast<CWarrior*> (&ennemi) && dynamic_cast<CSword*> (ennemi.getArme()))
	{
		if ((esquive / 100) < ennemi.getEsquive() + dynamic_cast<CWarrior*> (&ennemi)->getSpecial("m_parade"))
		{
			cout << (ennemi.getEsquive() + dynamic_cast<CWarrior*> (&ennemi)->getSpecial("m_parade"));
			coeff = 0;
		}
	}
	else
	{
		if ((esquive / 100) < ennemi.getEsquive())
		{
			coeff = 0;
		}
	}

	//Application des dégats
	ennemi.setHp(ennemi.getHp() - coeff);

	//Fonction utilisation
	if (dynamic_cast<CBow*> (m_arme) == NULL)
	{
		m_arme->utilisation();
	}
	return;
}

//BON
//Attaque spéciale furtif
void CRogue::attaqueSpeciale()
{
	//Si le cooldown est à 0
	if (m_cdFurtif <= 0)
	{
		m_invisible = true;

		srand(time(NULL));
		m_cdFurtif = rand() % 2 + 1;
	}
	else
	{
		cout << "Capacité inefficace utilisé trop tot";
	}
	return;
}

//BON
//Nouveau tour
void CRogue::nouveauTour()
{
	if (!m_cdFurtif)
	{
		m_invisible = false;
	}
	else
	{
		m_cdFurtif--;
	}
	
	//Effets empoisonnements
	if (m_empoisonne)
	{
		m_hp = (int)(m_hp * 11 / 12);
	}
	return;
}