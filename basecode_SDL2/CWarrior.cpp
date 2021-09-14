#include "CWarrior.h"

//Méthodes
CWarrior::CWarrior()
{
	m_cdCris = 0;
	m_cdReparation = 0;
}
CWarrior::~CWarrior()
{

}

//Getters
float CWarrior::getSpecial(string cd)
{
	if (cd == "cdCris")
	{
		return m_cdCris;
	}
	else if (cd == "cdReparation")
	{
		return m_cdReparation;
	}
	else if (cd == "m_nombreDeTours")
	{
		return m_nombreDeTours;
	}
	else if (cd == "m_parade")
	{
		return m_parade;
	}
	else
	{
		cout << "mauvais getters warrior" << endl;
		return -1;
	}
}

//Setters
void CWarrior::setSpecial(string cd, float valeur)
{
	if (cd == "cdCris")
	{
		m_cdCris = valeur;
	}
	else if (cd == "cdReparation")
	{
		m_cdReparation = valeur;
	}
	else if (cd == "m_nombreDeTours")
	{
		m_nombreDeTours = valeur;
	}
	else if (cd == "m_parade")
	{
		m_parade = valeur;
	}
	else
	{
		cout << "mauvais getters warrior" << endl;
		
	}
	return;
}




//Bon
//Attaque avec armes
void CWarrior::attaqueArme(CCharacter& ennemi)
{
	//Calcul coeff
	srand(time(NULL));
	float coeff = (float)(rand() % 16);
	coeff = (float)(coeff / 100 + 0.85);

	//Calcul attaque avec l'arme
	coeff = (int) ((7 * coeff * (m_attaque + m_arme->getDegat())) / ennemi.getDefense());
	//Si arme est cassée
	if (m_arme->getSpecial() <= 0)
	{
		coeff = (int) coeff/10;
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
		if ((esquive / 100) < ennemi.getEsquive()+ dynamic_cast<CWarrior*> (&ennemi)->getSpecial("m_parade"))
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

//Bon
//Attaque spéciale
//Hurler
void CWarrior::attaqueSpeciale()
{
	//Si la capacité peut être utilisée
	if (m_cdCris <= 0)
	{
		m_cdCris = 4;

		srand(time(NULL));
		m_nombreDeTours = (rand() % 2) + 1;
	}
	return;
}

//Bon
//Attaque spéciale
//Reparer
void CWarrior::attaqueSpeciale(CCharacter* amiReparage, vector<CWeapon*> listeArmes)
{
	if (m_cdReparation <= 0)
	{
		//Teste la valeur max de la durabilité
		CWeapon *tmp = amiReparage->getArme();
		//Si c'est une arem de mêlée
		if (dynamic_cast<CMelee*> (tmp))
		{
			//On cherhce l'arme dans la liste pour la comparer
			vector<CWeapon*>::iterator it;
			for (it = listeArmes.begin(); it < listeArmes.end(); it++)
			{
				if ((*it)->getNom() == tmp->getNom());
				{
					//Si l'arme n'est pas neuve
					if ((*it)->getSpecial() != tmp->getSpecial())
					{
						//Si l'arme est cassée
						if (tmp->getSpecial() <= 0)
						{
							dynamic_cast<CMelee*> (tmp)->setSpecial(1);
						}
						else
						{
							srand(time(NULL));
							int valeur = (rand() % 4) + 2+ dynamic_cast<CMelee*> (tmp)->getSpecial();
							//Si la valeur est supérieur
							if (valeur > (*it)->getSpecial())
							{
								cout << 1<<endl;
								dynamic_cast<CMelee*> (tmp)->setSpecial((*it)->getSpecial());
							}
							else
							{
								cout << 2<<endl;
								dynamic_cast<CMelee*> (tmp)->setSpecial(valeur);
							}
						}
						return;
					}
					return;
				}
			}
			return;
		}
		else
		{
			cout << "La réparation a été inefficace l'arme n'était pas une arme de mêlée!" << endl;
		}


	}
	cout << "mauvais parametres reparaion cwarrior";
	return;
}

//BON
void CWarrior::nouveauTour()
{
	if (m_cdCris != 0)
	{
		m_cdCris--;
	}
	if (m_cdReparation != 0)
	{
		m_cdReparation--;
	}
	if (m_nombreDeTours != 0)
	{
		m_nombreDeTours--;
	}

	//Effets empoisonnements
	if (m_empoisonne)
	{
		m_hp = (int)(m_hp * 11 / 12);
	}	
	
	return;

}