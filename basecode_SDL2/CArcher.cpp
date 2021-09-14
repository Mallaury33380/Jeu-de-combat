#include "CArcher.h"
#include "CWarrior.h"

CArcher::CArcher()
{
	m_cdViser = 0;
	m_cdGuérir = 3;
}
CArcher::~CArcher()
{

}

//BON
//Getters
int CArcher::getSpecial(string cd)
{
	if (cd == "m_cdViser")
	{
		return m_cdViser;
	}
	else if(cd == "m_cdGuerir")
	{
		return m_cdGuérir;
	}
	else
	{
		cout << "capacité inexistente getSpecial archer" << endl;
	}
	return 0;
}

//BON
//Setters
void CArcher::setSpecial(string cd, int valeur)
{
	if (cd == "m_cdViser")
	{
		m_cdViser = valeur;
	}
	else if (cd == "m_cdGuérir")
	{
		m_cdGuérir=valeur;
	}
	else
	{
		cout << "capacité inexistente getSpecial archer" << endl;
	}
	return;
}

//BON
//Attaque avec une arme
void CArcher::attaqueArme(CCharacter& ennemi)
{
	//Calcul coeff
	srand(time(NULL));
	float coeff = (float)(rand() % 16);
	coeff = (float)(coeff / 100 + 0.85);
	//Calcul attaque avec l'arme
	coeff = (int)((7 * coeff * (m_agilite + m_arme->getDegat())) / ennemi.getDefense());
	
	//SI dague cassée
	if (dynamic_cast<CDagger*> (m_arme) && m_arme->getSpecial() <= 0)
	{
		coeff = (int)coeff / 10;
	}

	//Si c'est un arc
	if (dynamic_cast<CBow*> (m_arme))
	{
		//Si il a des fleches
		if (dynamic_cast<CBow*> (m_arme)->getSpecial() != 0)
		{
			//Si il a la capacité de viser 
			if (m_cdViser)
			{
				coeff = (int)coeff * 1.33;
				//On remet le cooldown a 0
				m_cdViser = 0;
			}
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
		coeff =coeff* 4 / 3;
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
//Attaque spéciale viser
void CArcher::attaqueSpeciale()
{
	if (!m_cdViser)
	{
		m_cdViser = 1;
	}
	return;
}

//BON
//Attaque spéciale guérir du poion
void CArcher::attaqueSpeciale(CCharacter* player)
{
	//Si ce n'est pas un archer
	if (dynamic_cast<CArcher*> (player) == NULL)
	{
		player->setEmpoisonne(false);
		m_cdGuérir--;

	}
	else
	{
		cout << "Capacité inefficace. Le personnage est immunisé au poison";
	}
	return;
}

//BON
//Diminution du cooldown
void CArcher::nouveauTour()
{
	if (m_cdViser != 0)
	{
		m_cdViser--;
	}
	if (m_cdGuérir != 0)
	{
		m_cdGuérir--;
	}
	return;
}