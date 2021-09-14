#include"CParsing.h"



CParsing::CParsing()
{
	m_fileArmes = "config/weapons.jdc";
	m_filePersonnages = "config/characters.jdc";
}
CParsing::~CParsing()
{

}

//Gets
vector<CWeapon*> CParsing::getListeArmes()
{
	return m_listeArmes;
}
vector<CCharacter*>  CParsing::getListePersonnages()
{
	return m_listePersonnages;
}

//Sets
void CParsing::setListeArmes(vector<CWeapon*> listeArmes)
{
	m_listeArmes = listeArmes;
	return;
}
void CParsing::setListePersonnages(vector<CCharacter*> listePersonnages)
{
	m_listePersonnages = listePersonnages;
	return;
}


//BON
void CParsing::constructionListeArmes()
{
	ifstream fichierArmes(m_fileArmes);
	string ligneCourante;

	//Boucle lecture fichier s'arrete a la fin ou en cas d'erreurs
	while (fichierArmes>>ligneCourante)
	{
		//Début d'une arme
		if (ligneCourante == "Weapon")
		{
			//Acquisition type
			fichierArmes >> ligneCourante; fichierArmes >> ligneCourante;

			//BON
			//Epee
			if (ligneCourante == "Epee")
			{
				CSword *New=new CSword;
				fichierArmes >> ligneCourante;
				while (ligneCourante != "EndWeapon")
				{
					if (ligneCourante == "Nom")
					{
						fichierArmes >> ligneCourante;
						New->setNom(ligneCourante);
					}
					else if (ligneCourante == "Degat")
					{
						int a;
						fichierArmes >> a;
						New->setDegat(a);
					}
					else if (ligneCourante == "Critique")
					{
						float a;
						fichierArmes >> a;
						New->setCritique(a);
					}
					else if (ligneCourante == "Durabilite")
					{
						int a;
						fichierArmes >> a;
						New->setSpecial(a);
					}
					else
					{
						vector<string> tmp = New->getNomBonus();
						tmp.push_back(ligneCourante);
						New->setNomBonus(tmp);

						float a;
						fichierArmes >> a;
						vector<float> tmp2 = New->getValeurBonus();
						tmp2.push_back(a);
						New->setValeurBonus(tmp2);
					}
					//Ligne suivante
					fichierArmes >> ligneCourante;
				}
				//Inclut l'epee dans la liste
				m_listeArmes.push_back(New);
			}

			//Bon
			//Dague
			if (ligneCourante == "Dague")
			{
				CDagger* New2 = new CDagger;
				fichierArmes >> ligneCourante;
				while (ligneCourante != "EndWeapon")
				{
					if (ligneCourante == "Nom")
					{
						fichierArmes >> ligneCourante;
						New2->setNom(ligneCourante);
					}
					else if (ligneCourante == "Degat")
					{
						int a;
						fichierArmes >> a;
						New2->setDegat(a);
					}
					else if (ligneCourante == "Critique")
					{
						float a;
						fichierArmes >> a;
						New2->setCritique(a);
					}
					else if (ligneCourante == "Durabilite")
					{
						int a;
						fichierArmes >> a;
						New2->setSpecial(a);
					}
					else
					{
						vector<string> tmp = New2->getNomBonus();
						tmp.push_back(ligneCourante);
						New2->setNomBonus(tmp);

						float a;
						fichierArmes >> a;
						vector<float> tmp2 = New2->getValeurBonus();
						tmp2.push_back(a);
						New2->setValeurBonus(tmp2);
					}
					//Ligne suivante
					fichierArmes >> ligneCourante;
				}
				//Inclut la dague dans la liste
				m_listeArmes.push_back(New2);
			}

			//Bon
			//Arc
			if (ligneCourante == "Arc")
			{
				CBow* New2 = new CBow;
				fichierArmes >> ligneCourante;
				while (ligneCourante != "EndWeapon")
				{
					if (ligneCourante == "Nom")
					{
						fichierArmes >> ligneCourante;
						New2->setNom(ligneCourante);
					}
					else if (ligneCourante == "Degat")
					{
						int a;
						fichierArmes >> a;
						New2->setDegat(a);
					}
					else if (ligneCourante == "Critique")
					{
						float a;
						fichierArmes >> a;
						New2->setCritique(a);
					}
					else if (ligneCourante == "Fleche")
					{
						int a;
						fichierArmes >> a;
						New2->setSpecial(a);
					}
					else
					{
						vector<string> tmp = New2->getNomBonus();
						tmp.push_back(ligneCourante);
						New2->setNomBonus(tmp);

						float a;
						fichierArmes >> a;
						vector<float> tmp2 = New2->getValeurBonus();
						tmp2.push_back(a);
						New2->setValeurBonus(tmp2);
					}
					//Ligne suivante
					fichierArmes >> ligneCourante;
				}
				//Inclut l'arc dans la liste
				m_listeArmes.push_back(New2);
			}

			//BON
			//Baton
			if (ligneCourante == "Baton")
			{
				CStaff* New2 = new CStaff;
				fichierArmes >> ligneCourante;
				while (ligneCourante != "EndWeapon")
				{
					if (ligneCourante == "Nom")
					{
						char a;
						fichierArmes.get(a);
						fichierArmes.get(a);
						fichierArmes.get(a);
						fichierArmes.get(a);
						getline(fichierArmes, ligneCourante);
						New2->setNom(ligneCourante);
					}
					else if (ligneCourante == "Degat")
					{
						int a;
						fichierArmes >> a;
						New2->setDegat(a);
					}
					else if (ligneCourante == "Critique")
					{
						float a;
						fichierArmes >> a;
						New2->setCritique(a);
					}
					else if (ligneCourante == "Cout")
					{
						int a;
						fichierArmes >> a;
						New2->setSpecial(a);
					}
					else
					{
						vector<string> tmp = New2->getNomBonus();
						tmp.push_back(ligneCourante);
						New2->setNomBonus(tmp);

						float a;
						fichierArmes >> a;
						vector<float> tmp2 = New2->getValeurBonus();
						tmp2.push_back(a);
						New2->setValeurBonus(tmp2);
					}
					//Ligne suivante
					fichierArmes >> ligneCourante;
				}
				//Inclut le baton dans la liste
				m_listeArmes.push_back(New2);
			}
			
		}
	}
	//Fin
	return;
}

//BON
void CParsing::constructionListePersonnages()
{
	ifstream fichierPersonnages(m_filePersonnages);
	string ligneCourante;

	//Boucle lecture fichier s'arrete a la fin ou en cas d'erreurs
	while (fichierPersonnages >> ligneCourante)
	{
		if (ligneCourante == "Character")
		{
			//Acquisition type
			fichierPersonnages >> ligneCourante; fichierPersonnages >> ligneCourante;

			//Guerrier
			if (ligneCourante == "Guerrier")
			{
				CWarrior* New2 = new CWarrior;
				fichierPersonnages >> ligneCourante;
				while (ligneCourante != "EndCharacter")
				{
					if (ligneCourante == "Nom")
					{
						char a;
						fichierPersonnages.get(a);
						fichierPersonnages.get(a);
						fichierPersonnages.get(a);
						fichierPersonnages.get(a);
						getline(fichierPersonnages, ligneCourante);
						New2->setNom(ligneCourante);
					}
					else if (ligneCourante == "HP")
					{
						int a;
						fichierPersonnages >> a;
						New2->setHp(a);
					}
					else if (ligneCourante == "Dodge")
					{
						float a;
						fichierPersonnages >> a;
						New2->setEsquive(a);
					}
					else if (ligneCourante == "Attaque")
					{
						int a;
						fichierPersonnages >> a;
						New2->setAttaque(a);
					}
					else if (ligneCourante == "Defense")
					{
						int a;
						fichierPersonnages >> a;
						New2->setDefense(a);
					}
					else if (ligneCourante == "Agilite")
					{
						int a;
						fichierPersonnages >> a;
						New2->setAgilite(a);
					}
					else if (ligneCourante == "Vitesse")
					{
						int a;
						fichierPersonnages >> a;
						New2->setVitesse(a);
					}
					else if (ligneCourante == "Intelligence")
					{
						int a;
						fichierPersonnages >> a;
						New2->setIntelligence(a);
					}
					else if (ligneCourante == "Special")
					{
						float a;
						fichierPersonnages >> a;
						New2->setSpecial("m_parade",a);
					}

					//Ligne suivante
					fichierPersonnages >> ligneCourante;
				}
				//Inclut le baton dans la liste
				m_listePersonnages.push_back(New2);

			}

			//Archer
			else if (ligneCourante == "Archer")
			{
				CArcher* New2 = new CArcher;
				New2->setSpecial("m_cdGuérir", 3);
				fichierPersonnages >> ligneCourante;
				while (ligneCourante != "EndCharacter")
				{
					if (ligneCourante == "Nom")
					{
						char a;
						fichierPersonnages.get(a);
						fichierPersonnages.get(a);
						fichierPersonnages.get(a);
						fichierPersonnages.get(a);
						getline(fichierPersonnages, ligneCourante);
						New2->setNom(ligneCourante);
					}
					else if (ligneCourante == "HP")
					{
						int a;
						fichierPersonnages >> a;
						New2->setHp(a);
					}
					else if (ligneCourante == "Dodge")
					{
						float a;
						fichierPersonnages >> a;
						New2->setEsquive(a);
					}
					else if (ligneCourante == "Attaque")
					{
						int a;
						fichierPersonnages >> a;
						New2->setAttaque(a);
					}
					else if (ligneCourante == "Defense")
					{
						int a;
						fichierPersonnages >> a;
						New2->setDefense(a);
					}
					else if (ligneCourante == "Agilite")
					{
						int a;
						fichierPersonnages >> a;
						New2->setAgilite(a);
					}
					else if (ligneCourante == "Vitesse")
					{
						int a;
						fichierPersonnages >> a;
						New2->setVitesse(a);
					}
					else if (ligneCourante == "Intelligence")
					{
						int a;
						fichierPersonnages >> a;
						New2->setIntelligence(a);
					}
					//Ligne suivante
					fichierPersonnages >> ligneCourante;
				}
				//Inclut le baton dans la liste
				m_listePersonnages.push_back(New2);
			}

			//Mage
			else if (ligneCourante == "Mage")
			{
			CMage* New2 = new CMage;
			fichierPersonnages >> ligneCourante;
			while (ligneCourante != "EndCharacter")
			{
				if (ligneCourante == "Nom")
				{
					char a;
					fichierPersonnages.get(a);
					fichierPersonnages.get(a);
					fichierPersonnages.get(a);
					fichierPersonnages.get(a);
					getline(fichierPersonnages, ligneCourante);
					New2->setNom(ligneCourante);
				}
				else if (ligneCourante == "HP")
				{
					int a;
					fichierPersonnages >> a;
					New2->setHp(a);
				}
				else if (ligneCourante == "Dodge")
				{
					float a;
					fichierPersonnages >> a;
					New2->setEsquive(a);
				}
				else if (ligneCourante == "Attaque")
				{
					int a;
					fichierPersonnages >> a;
					New2->setAttaque(a);
				}
				else if (ligneCourante == "Defense")
				{
					int a;
					fichierPersonnages >> a;
					New2->setDefense(a);
				}
				else if (ligneCourante == "Agilite")
				{
					int a;
					fichierPersonnages >> a;
					New2->setAgilite(a);
				}
				else if (ligneCourante == "Vitesse")
				{
					int a;
					fichierPersonnages >> a;
					New2->setVitesse(a);
				}
				else if (ligneCourante == "Intelligence")
				{
					int a;
					fichierPersonnages >> a;
					New2->setIntelligence(a);
				}
				//Ligne suivante
				fichierPersonnages >> ligneCourante;
			}
			//Inclut le baton dans la liste
			m_listePersonnages.push_back(New2);
			}

			//Voleur
			else if (ligneCourante == "Voleur")
			{
			CRogue* New2 = new CRogue;
			fichierPersonnages >> ligneCourante;
			while (ligneCourante != "EndCharacter")
			{
				if (ligneCourante == "Nom")
				{
					char a;
					fichierPersonnages.get(a);
					fichierPersonnages.get(a);
					fichierPersonnages.get(a);
					fichierPersonnages.get(a);
					getline(fichierPersonnages, ligneCourante);
					New2->setNom(ligneCourante);
				}
				else if (ligneCourante == "HP")
				{
					int a;
					fichierPersonnages >> a;
					New2->setHp(a);
				}
				else if (ligneCourante == "Dodge")
				{
					float a;
					fichierPersonnages >> a;
					New2->setEsquive(a);
				}
				else if (ligneCourante == "Attaque")
				{
					int a;
					fichierPersonnages >> a;
					New2->setAttaque(a);
				}
				else if (ligneCourante == "Defense")
				{
					int a;
					fichierPersonnages >> a;
					New2->setDefense(a);
				}
				else if (ligneCourante == "Agilite")
				{
					int a;
					fichierPersonnages >> a;
					New2->setAgilite(a);
				}
				else if (ligneCourante == "Vitesse")
				{
					int a;
					fichierPersonnages >> a;
					New2->setVitesse(a);
				}
				else if (ligneCourante == "Intelligence")
				{
					int a;
					fichierPersonnages >> a;
					New2->setIntelligence(a);
				}
				else if (ligneCourante == "Special")
				{
					float a;
					fichierPersonnages >> a;
					New2->setSpecial("m_probEpoisonnement", a);
				}
				//Ligne suivante
				fichierPersonnages >> ligneCourante;
			}
			//Inclut le baton dans la liste
			m_listePersonnages.push_back(New2);
			}
		}
	}
	//Fin
	return;
}