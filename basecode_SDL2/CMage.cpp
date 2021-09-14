#include "CMage.h"
#include "CWarrior.h"



CMage::CMage()
{

}
CMage::CMage(int intelligence)
{
	m_mana = 10 * intelligence;
	m_cdSoin = 0;
	m_cdEnchantement = 0;
}
CMage::~CMage()
{

}

//BON
//Getters
int CMage::getSpecial(string cd)
{
	if (cd == "m_mana")
	{
		return m_mana;
	}
	else if (cd == "m_cdSoin")
	{
		return m_cdSoin;
	}
	else if (cd == "m_cdEnchantement")
	{
		return m_cdEnchantement;
	}
	else
	{
		cout << "erreur entree getspecial mage" << endl;
		return -1;
	}

}

//BON
//Setters
void CMage::setSpecial(string cd, int valeur)
{
	if (cd == "m_mana")
	{
		m_mana = valeur;
	}
	else if (cd == "m_cdSoin")
	{
		m_cdSoin=valeur;
	}
	else if (cd == "m_cdEnchantement")
	{
		m_cdEnchantement=valeur;
	}
	else
	{
		cout << "erreur entree getspecial mage" << endl;
	}
}

//BON
//Attaque avec une arme
void CMage::attaqueArme(CCharacter& ennemi)
{
	//Calcul coeff
	srand(time(NULL));
	float coeff = (float)(rand() % 16);
	coeff = (float)(coeff / 100 + 0.85);

	//Calcul attaque avec l'arme
	coeff = (int) (5 * coeff * (m_intelligence + m_arme->getDegat()) / ennemi.getDefense());
	
	//SI epee cassée
	if (dynamic_cast<CSword*> (m_arme) && m_arme->getSpecial() <= 0)
	{
		coeff = (int)coeff / 10;
	}

	//Si attaque avec baguette
		//SI plus de mana
	if (dynamic_cast<CStaff*> (m_arme) && m_mana<m_arme->getSpecial())
	{
		coeff = 0;
	}



	//Effet du critique
	float critique = (float)(rand() % 101);
	if ((critique / 100) < m_arme->getCritique())
	{
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
	m_arme->utilisation();
	return;

}

//BON
//Attaque spéciale regenerer
void CMage::attaqueSpeciale()
{
	srand(time(NULL));
	setSpecial("m_mana", m_mana+(rand() % 6 + 2));
	return;
}

//BON
//Attaque spéciale soigner
//Attaque spéciale enchanter
void CMage::attaqueSpeciale(CCharacter& player,string cd)
{
	//Si enchantement
	if (cd == "enchantement")
	{
		//Si il a assez de mana et cooldown
		if (m_mana >= 7 && m_cdEnchantement<=0)
		{
			//O enchante
			player.getArme()->setEnchante(true);
			return;
			//On soustrait le mana
			m_mana -= 7;
			//Cooldown
			m_cdEnchantement = 3;
		}
		else
		{
			cout << "pas assez de mana pour enchanter ou trop tot pour utiliser cette capacité" << endl;
		}
	}
	//Si soin
	else if (cd == "soin" )
	{
		//Si il a un baton,cooldown et mana
		if (dynamic_cast<CStaff*> (m_arme) && m_mana >=5 && m_cdSoin <= 0)
		{
			if (m_mana >= 5)
			{
				//Soin
				srand(time(NULL));
				int soin = (rand() % 2) * 10 + 10;
				player.setHp(player.getHp() + soin);
				//On soustrait le mana
				m_mana -= 5;
				//Cooldown
				m_cdSoin = 4;
			}
		}
		else
		{
			cout << "Capacité inefficace, pas de baton, pas de mana ou top tot";
		}
	}
	else
	{
		cout << "erreur capacité attaque spéciale mage";
	}
	return;
}

//BON
//Nouveau tour
void CMage::nouveauTour()
{
	//Cooldowns
	if (m_cdEnchantement != 0)
	{
		m_cdEnchantement--;
	}
	if (m_cdSoin != 0)
	{
		m_cdSoin--;
	}

	//Effets empoisonnements
	if (m_empoisonne)
	{
		m_hp = (int) (m_hp *11/ 12);
	}
	return;
}