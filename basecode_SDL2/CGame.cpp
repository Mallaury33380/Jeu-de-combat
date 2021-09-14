#include "CGame.h"

CGame::CGame()
{
	return;
}
CGame::~CGame()
{
	return;
}


//Une partie
void CGame::Game()
{
	//Initialiastion composantes SDL et création de la fenetre
	m_graphisme.init();

	//Nombre d'options
	int nbOptions = 2;
	int cur = 0;

	SDL_Event e;
	int quit = 0;

	m_graphisme.affichageMenu(cur);
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_SPACE:
					quit = 1;
					break;

				case SDLK_UP:
					if (!cur)
					{
						cur = nbOptions;
					}
					else
					{
						cur--;
					}
					break;

				case SDLK_DOWN:
					if (cur == nbOptions)
					{
						cur = 0;
					}
					else
					{
						cur++;
					}
					break;
				}
				break;

			default:
				break;
			}
			cout << "Option " << cur << endl;
			m_graphisme.affichageMenu(cur);
		}
	}
	switch (cur)
	{
	case 0:
		partie();
		break;
	case 1:
		m_graphisme.affichierRegles();
		m_graphisme.clear();
		Game();
		return;
		break;
	case 2:
		return;
		break;
	default:
		break;
	}
	

	return;
}

void CGame::partie()
{
	cout << "debut" << endl;
	debut();
	while (!finDePartie())
	{
		cout << "tour" << endl;
		tour();
	}
	rejouer();
	m_graphisme.clear();
	cout << "fin" << endl;
	return;   
}

void CGame::debut()
{
	//Initialisation des listes
	m_parsing.constructionListeArmes();
	m_parsing.constructionListePersonnages();
	
	cout << "choix equipe" << endl;

	//Choix de l'équipe
	choixEquipe();
	cout << "bonus" << endl;

	return;
}


void CGame::tour()
{
	//On détermine qui joue et son équipe
	int equipe = 0;
	CCharacter* personnage = tourDeJouer(equipe);
	//Init nouveau tour
	personnage->nouveauTour();
	//réalise son action
	action(personnage, equipe);
	//On refresh la liste des morts
	majMort();   
}

//BON
bool CGame::finDePartie()
{
	//Si une équipe est vide
	if (m_equipeJ1.size() == 0  )
	{
		m_graphisme.finDepartie(0);
		return true;
	}
	else if (m_equipeJ2.size() == 0)
	{
		m_graphisme.finDepartie(1);
		return true;
	}

	return false;
}



//BON
void CGame::choixEquipe()
{
	//Choix de l'équipe de 3 personnages
	for (int i = 0; i < 3; i++)
	{
		cout << endl << i << endl;
		//Joueur 1
		choixPersonnage(m_equipeJ1,1);
		choixArme(m_equipeJ1);

		//Joueur 2
		choixPersonnage(m_equipeJ2,2);
		choixArme(m_equipeJ2);
	}
	applicationBonus();
	return;
}
//BON
void CGame::applicationBonus()
{
	//Equipe 1
	//Pour chaque personnage
	for (int i=0; i < m_equipeJ1.size(); i++)
	{
		//On applique les bonus
		for (int j = 0; j < m_equipeJ1[i]->getArme()->getNomBonus().size(); j++)
		{
			if (m_equipeJ1[i]->getArme()->getNomBonus()[j] == "HP")
			{
				m_equipeJ1[i]->setHp(m_equipeJ1[i]->getHp() + m_equipeJ1[i]->getArme()->getValeurBonus()[j]);
			}
			else if (m_equipeJ1[i]->getArme()->getNomBonus()[j] == "Dodge")
			{
				m_equipeJ1[i]->setEsquive(m_equipeJ1[i]->getEsquive() + m_equipeJ1[i]->getArme()->getValeurBonus()[j]);
			}
			else if (m_equipeJ1[i]->getArme()->getNomBonus()[j] == "Attack")
			{
				m_equipeJ1[i]->setAttaque(m_equipeJ1[i]->getAttaque() + m_equipeJ1[i]->getArme()->getValeurBonus()[j]);
			}
			else if (m_equipeJ1[i]->getArme()->getNomBonus()[j] == "Defense")
			{
				m_equipeJ1[i]->setDefense(m_equipeJ1[i]->getDefense() + m_equipeJ1[i]->getArme()->getValeurBonus()[j]);
			}
			else if (m_equipeJ1[i]->getArme()->getNomBonus()[j] == "Agilite")
			{
				m_equipeJ1[i]->setAgilite(m_equipeJ1[i]->getAgilite() + m_equipeJ1[i]->getArme()->getValeurBonus()[j]);
			}
			else if (m_equipeJ1[i]->getArme()->getNomBonus()[j] == "Vitesse")
			{
				m_equipeJ1[i]->setVitesse(m_equipeJ1[i]->getVitesse() + m_equipeJ1[i]->getArme()->getValeurBonus()[j]);
			}
			else if (m_equipeJ1[i]->getArme()->getNomBonus()[j] == "Intelligence")
			{
				m_equipeJ1[i]->setIntelligence(m_equipeJ1[i]->getIntelligence() + m_equipeJ1[i]->getArme()->getValeurBonus()[j]);
			}
			else if (m_equipeJ1[i]->getArme()->getNomBonus()[j] == "Special")
			{
				dynamic_cast<CWarrior*> (m_equipeJ1[i])->setSpecial("m_parade",m_equipeJ1[i]->getHp() + m_equipeJ1[i]->getArme()->getValeurBonus()[j]);
			}
			else
			{
				cout << "caractéristique inconnu application bonus "<< m_equipeJ1[i]->getArme()->getNomBonus()[j] << endl;
			}
		}
	}

	//Equipe 2
//Pour chaque personnage
	for (int i = 0; i < m_equipeJ2.size(); i++)
	{
		//On applique les bonus
		for (int j = 0; j < m_equipeJ2[i]->getArme()->getNomBonus().size(); j++)
		{
			if (m_equipeJ2[i]->getArme()->getNomBonus()[j] == "HP")
			{
				m_equipeJ2[i]->setHp(m_equipeJ2[i]->getHp() + m_equipeJ2[i]->getArme()->getValeurBonus()[j]);
			}
			else if (m_equipeJ2[i]->getArme()->getNomBonus()[j] == "Dodge")
			{
				m_equipeJ2[i]->setEsquive(m_equipeJ2[i]->getEsquive() + m_equipeJ2[i]->getArme()->getValeurBonus()[j]);
			}
			else if (m_equipeJ2[i]->getArme()->getNomBonus()[j] == "Attack")
			{
				m_equipeJ2[i]->setAttaque(m_equipeJ2[i]->getAttaque() + m_equipeJ2[i]->getArme()->getValeurBonus()[j]);
			}
			else if (m_equipeJ2[i]->getArme()->getNomBonus()[j] == "Defense")
			{
				m_equipeJ2[i]->setDefense(m_equipeJ2[i]->getDefense() + m_equipeJ2[i]->getArme()->getValeurBonus()[j]);
			}
			else if (m_equipeJ2[i]->getArme()->getNomBonus()[j] == "Agilite")
			{
				m_equipeJ2[i]->setAgilite(m_equipeJ2[i]->getAgilite() + m_equipeJ2[i]->getArme()->getValeurBonus()[j]);
			}
			else if (m_equipeJ2[i]->getArme()->getNomBonus()[j] == "Vitesse")
			{
				m_equipeJ2[i]->setVitesse(m_equipeJ2[i]->getVitesse() + m_equipeJ2[i]->getArme()->getValeurBonus()[j]);
			}
			else if (m_equipeJ2[i]->getArme()->getNomBonus()[j] == "Intelligence")
			{
				m_equipeJ2[i]->setIntelligence(m_equipeJ2[i]->getIntelligence() + m_equipeJ2[i]->getArme()->getValeurBonus()[j]);
			}
			else if (m_equipeJ2[i]->getArme()->getNomBonus()[j] == "Special")
			{
				dynamic_cast<CWarrior*> (m_equipeJ2[i])->setSpecial("m_parade", m_equipeJ2[i]->getHp() + m_equipeJ2[i]->getArme()->getValeurBonus()[j]);
			}
			else
			{
				cout << "caractéristique inconnu application bonus" << m_equipeJ2[i]->getArme()->getNomBonus()[j] << endl;
			}
		}
	}
	return;
}

//BON
void CGame::choixPersonnage(vector<CCharacter*>& joueur,int equipe)
{
	//Nombre de personnages
	int nbPersonnages = m_parsing.getListePersonnages().size()-1;
	int cur = 0;

	SDL_Event e;
	int quit = 0;

	m_graphisme.affichageChoixPersonnages(cur,equipe);
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_SPACE:
					quit = 1;
					break;

				case SDLK_UP:
					if (!cur)
					{
						cur = nbPersonnages;
					}
					else
					{
						cur--;
					}
					break;

				case SDLK_DOWN:
					if (cur == nbPersonnages)
					{
						cur = 0;
					}
					else
					{
						cur++;
					}
					break;
				}
				break;

			default:
				break;
			}
			cout << "Choix personnage " << cur << endl;
			m_graphisme.affichageChoixPersonnages(cur,equipe);
			SDL_Delay(150);

		}
	}

	//On récupère le personnage et on l,ajoute
	if (dynamic_cast<CWarrior*> (m_parsing.getListePersonnages()[cur]))
	{
		CWarrior *tmp= (dynamic_cast<CWarrior*>(m_parsing.getListePersonnages()[cur]));
		CWarrior* ajout=new CWarrior;
		ajout->setNom(tmp->getNom());
		ajout->setHp(tmp->getHp());
		ajout->setEsquive(tmp->getEsquive());
		ajout->setAttaque(tmp->getAttaque());
		ajout->setDefense(tmp->getDefense());
		ajout->setAgilite(tmp->getAgilite());
		ajout->setVitesse(tmp->getVitesse());
		ajout->setIntelligence(tmp->getIntelligence());
		ajout->setSpecial("m_parade", tmp->getSpecial("m_parade"));
		joueur.push_back(ajout);
	}
	else if (dynamic_cast<CArcher*> (m_parsing.getListePersonnages()[cur]))
	{
		CArcher* tmp = (dynamic_cast<CArcher*>(m_parsing.getListePersonnages()[cur]));

		CArcher* ajout=new CArcher;
		ajout->setNom(tmp->getNom());
		ajout->setHp(tmp->getHp());
		ajout->setEsquive(tmp->getEsquive());
		ajout->setAttaque(tmp->getAttaque());
		ajout->setDefense(tmp->getDefense());
		ajout->setAgilite(tmp->getAgilite());
		ajout->setVitesse(tmp->getVitesse());
		ajout->setIntelligence(tmp->getIntelligence());
		joueur.push_back(ajout);
	}
	else if (dynamic_cast<CMage*> (m_parsing.getListePersonnages()[cur]))
	{
		CMage* tmp = (dynamic_cast<CMage*>(m_parsing.getListePersonnages()[cur]));

		CMage* ajout=new CMage(tmp->getIntelligence());
		ajout->setNom(tmp->getNom());
		ajout->setHp(tmp->getHp());
		ajout->setEsquive(tmp->getEsquive());
		ajout->setAttaque(tmp->getAttaque());
		ajout->setDefense(tmp->getDefense());
		ajout->setAgilite(tmp->getAgilite());
		ajout->setVitesse(tmp->getVitesse());
		ajout->setIntelligence(tmp->getIntelligence());
		joueur.push_back(ajout);
	}
	else if (dynamic_cast<CRogue*> (m_parsing.getListePersonnages()[cur]))
	{
		CRogue* tmp = (dynamic_cast<CRogue*>(m_parsing.getListePersonnages()[cur]));

		CRogue* ajout=new CRogue;
		ajout->setNom(tmp->getNom());
		ajout->setHp(tmp->getHp());
		ajout->setEsquive(tmp->getEsquive());
		ajout->setAttaque(tmp->getAttaque());
		ajout->setDefense(tmp->getDefense());
		ajout->setAgilite(tmp->getAgilite());
		ajout->setVitesse(tmp->getVitesse());
		ajout->setIntelligence(tmp->getIntelligence());
		ajout->setSpecial("m_probEpoisonnement", tmp->getSpecial("m_probEpoisonnement"));
		joueur.push_back(ajout);
	}
	else
	{
		cout << "Type inconnu erreur choixPersonnage" << endl;
	}
	return;	
}
//BON
void CGame::choixArme(vector<CCharacter*>& joueur)
{
	//Nombre de personnages
	int nbArmes = m_parsing.getListeArmes().size()-1;
	int cur = 0;

	SDL_Event e;
	int quit = 0;

	m_graphisme.affichageChoixArmes(cur);
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_SPACE:
					//Si epee uniquement guerrier et mage
  					if (dynamic_cast<CSword*> (m_parsing.getListeArmes()[cur]))
					{
						if (dynamic_cast<CWarrior*> (joueur[joueur.size() - 1]) || dynamic_cast<CMage*> (joueur[joueur.size() - 1]))
						{
							quit = 1;
						}
					}
					//Si dague uniquement voleur et archer
					else if (dynamic_cast<CDagger*> (m_parsing.getListeArmes()[cur]))
					{
						if (dynamic_cast<CArcher*> (joueur[joueur.size() - 1]) || dynamic_cast<CRogue*> (joueur[joueur.size() - 1]) || dynamic_cast<CWarrior*> (joueur[joueur.size() - 1]))
						{
							quit = 1;
						}
					}
					//Si arc uniquement archer et voleur
					else if (dynamic_cast<CBow*> (m_parsing.getListeArmes()[cur]))
					{
						if (dynamic_cast<CArcher*> (joueur[joueur.size() - 1]) || dynamic_cast<CRogue*> (joueur[joueur.size() - 1]))
						{
							quit = 1;
						}
					}
					//Si baton uniquement mage
					else if (dynamic_cast<CStaff*> (m_parsing.getListeArmes()[cur]))
					{
						if (dynamic_cast<CMage*> (joueur[joueur.size() - 1]))
						{
							quit = 1;
						}
					}
					else
					{
						cout << "type d'arme inconnu" << endl;
					}
					
					break;

				case SDLK_UP:
					if (!cur)
					{
						cur = nbArmes;
					}
					else
					{
						cur--;
					}
					break;

				case SDLK_DOWN:
					if (cur == nbArmes)
					{
						cur = 0;
					}
					else
					{
						cur++;
					}
					break;
				}
				break;

			default:
				break;
			}
			cout <<"Choix armes "<< cur << endl;
			m_graphisme.affichageChoixArmes(cur);
		}
	}

	//On récupère l'arme et on l'ajoute au personnage
	if (dynamic_cast<CSword*> (m_parsing.getListeArmes()[cur]))
	{
		CSword* tmp = (dynamic_cast<CSword*>(m_parsing.getListeArmes()[cur]));

		CSword* ajout = new CSword;
		ajout->setNom(tmp->getNom());
		ajout->setDegat(tmp->getDegat());
		ajout->setCritique(tmp->getCritique());
		ajout->setNomBonus(tmp->getNomBonus());
		ajout->setValeurBonus(tmp->getValeurBonus());
		ajout->setSpecial(tmp->getSpecial());
		
		joueur[joueur.size() - 1]->setArme(ajout);
	}
	else if (dynamic_cast<CDagger*> (m_parsing.getListeArmes()[cur]))
	{
		CDagger* tmp = (dynamic_cast<CDagger*>(m_parsing.getListeArmes()[cur]));

		CDagger* ajout = new CDagger;
		ajout->setNom(tmp->getNom());
		ajout->setDegat(tmp->getDegat());
		ajout->setCritique(tmp->getCritique());
		ajout->setNomBonus(tmp->getNomBonus());
		ajout->setValeurBonus(tmp->getValeurBonus());
		ajout->setSpecial(tmp->getSpecial());

		joueur[joueur.size() - 1]->setArme(ajout);
	}
	else if (dynamic_cast<CBow*> (m_parsing.getListeArmes()[cur]))
	{
		CBow* tmp = (dynamic_cast<CBow*>(m_parsing.getListeArmes()[cur]));

		CBow* ajout = new CBow;
		ajout->setNom(tmp->getNom());
		ajout->setDegat(tmp->getDegat());
		ajout->setCritique(tmp->getCritique());
		ajout->setNomBonus(tmp->getNomBonus());
		ajout->setValeurBonus(tmp->getValeurBonus());
		ajout->setSpecial(tmp->getSpecial());

		joueur[joueur.size() - 1]->setArme(ajout);
	}
	else if (dynamic_cast<CStaff*> (m_parsing.getListeArmes()[cur]))
	{
		CStaff* tmp = (dynamic_cast<CStaff*>(m_parsing.getListeArmes()[cur]));

		CStaff* ajout = new CStaff;
		ajout->setNom(tmp->getNom());
		ajout->setDegat(tmp->getDegat());
		ajout->setCritique(tmp->getCritique());
		ajout->setNomBonus(tmp->getNomBonus());
		ajout->setValeurBonus(tmp->getValeurBonus());
		ajout->setSpecial(tmp->getSpecial());

		joueur[joueur.size() - 1]->setArme(ajout);
	}
	else
	{
		cout << "Type inconnu erreur choixPersonnage" << endl;
	}
	return;
}
//BON
CCharacter* CGame::tourDeJouer(int& equipe)
{
	//liste avec la plus faible vitesse
	vector<CCharacter*> liste;
	vector<int> appartenance;
	int minVitesse = 99999;

	//On cherche dans l'équipe 1
	vector<CCharacter*>::iterator it;
	for (it = m_equipeJ1.begin(); it < m_equipeJ1.end(); it++)
	{
		//Si vitesse plus faible
		if ((*it)->getVitesse() < minVitesse)
		{
			liste.clear();
			liste.push_back(*it);
			appartenance.push_back(0);
			minVitesse = (*it)->getVitesse();
		}
		else if ((*it)->getVitesse() == minVitesse)
		{
			liste.push_back(*it);
			appartenance.push_back(0);

		}
	}

	//On cherche dans l'équipe 2
	for (it = m_equipeJ2.begin(); it < m_equipeJ2.end(); it++)
	{
		//Si vitesse plus faible
		if ((*it)->getVitesse() < minVitesse)
		{
			liste.clear();
			liste.push_back(*it);
			appartenance.push_back(1);
			minVitesse = (*it)->getVitesse();
		}
		else if ((*it)->getVitesse() == minVitesse)
		{
			liste.push_back(*it);
			appartenance.push_back(1);

		}
	}
	//Choix dans la liste
	int numero = rand() % liste.size();
	CCharacter* tmp = liste[numero];
	equipe = appartenance[numero];

	//Afficher le prochain personnage qui jouera
	int place = 0;
		//Calcule de la position du personnage
	if (equipe == 0)
	{
		place = numero;
	}
	else
	{
		int i=0;
		while (appartenance[i] == 0)
		{
			i++;
		}
		place = numero - i;
	}

	//TODO:afficher prochain perso
	m_graphisme.affichageTourDeJouer(m_equipeJ1, equipe, place); 
	 
	//Reevaluation des vitesses
	//Equipe 1
	for (it = m_equipeJ1.begin(); it < m_equipeJ1.end(); it++)
	{
		(*it)->setVitesse((*it)->getVitesse() - tmp->getVitesse());
	}
	//Equipe 2
	for (it = m_equipeJ2.begin(); it < m_equipeJ2.end(); it++)
	{
		(*it)->setVitesse((*it)->getVitesse() - tmp->getVitesse());
	}

	//Remet la vitesse du personnage à sa norme
	for (int i=0;i<m_parsing.getListePersonnages().size();i++)
	{
		if (tmp->getNom() == m_parsing.getListePersonnages()[i]->getNom())
		{
  			tmp->setVitesse(m_parsing.getListePersonnages()[i]->getVitesse());
		}
	}

	return tmp;
}



//Mage chevaleir archer  voleurbon
void CGame::action(CCharacter* personnage,int equipe)
{
	//On détermine le nombre d'action spéciale
	SDL_Event e;
	int quit = 0;
	int limite;
	int cur = 0;

	if (dynamic_cast<CWarrior*> (personnage) || dynamic_cast<CArcher*> (personnage))
	{
		limite = 3;
	}
	else if (dynamic_cast<CMage*> (personnage))
	{
		limite = 4;
	}
	else if (dynamic_cast<CRogue*> (personnage))
	{
		limite = 2;
	}
	else
	{
		cout << "type de personnage inconnu action" << endl;
	}

	m_graphisme.afficherChoixAction(personnage, cur);
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_SPACE:
					quit = 1;
					break;

				case SDLK_UP:
					if (!cur)
					{
						cur = limite;
					}
					else
					{
						cur--;
					}
					break;

				case SDLK_DOWN:
					if (cur == limite)
					{
						cur = 0;
					}
					else
					{
						cur++;
					}
					break;
				}
				break;

			default:
				break;
			}
			cout << "Choix action " << cur << endl;
			m_graphisme.afficherChoixAction(personnage, cur);
			SDL_Delay(150);


		}
	}

	
	//Action
	switch (cur)
	{
	case 0:
		//Attaque à mains nues
		//equipe 1
		if (!equipe)
		{
			personnage->attaqueMainsNues(*(cible(m_equipeJ2,true,1)));
		}
		else
		{
			personnage->attaqueMainsNues(*(cible(m_equipeJ1,true,0)));
		}

		break;
	case 1:
		//Attaque avec arme
		//equipe 1
		if (!equipe)
		{

			if (dynamic_cast<CWarrior*>(personnage))
			{
				dynamic_cast<CWarrior*> (personnage)->attaqueArme(*(cible(m_equipeJ2, true,1)));
			}
			else if (dynamic_cast<CArcher*>(personnage))
			{
				dynamic_cast<CArcher*> (personnage)->attaqueArme(*(cible(m_equipeJ2, true,1)));
			}
			else if (dynamic_cast<CMage*>(personnage))
			{
				dynamic_cast<CMage*> (personnage)->attaqueArme(*(cible(m_equipeJ2, true,1)));
			}
			else if (dynamic_cast<CRogue*>(personnage))
			{
				dynamic_cast<CRogue*> (personnage)->attaqueArme(*(cible(m_equipeJ2, true,1)));
			}
		}
		else
		{
			if (dynamic_cast<CWarrior*>(personnage))
			{
				dynamic_cast<CWarrior*> (personnage)->attaqueArme(*(cible(m_equipeJ1, true,0)));
			}
			else if (dynamic_cast<CArcher*>(personnage))
			{
				dynamic_cast<CArcher*> (personnage)->attaqueArme(*(cible(m_equipeJ1, true,0)));
			}
			else if (dynamic_cast<CMage*>(personnage))
			{
				dynamic_cast<CMage*> (personnage)->attaqueArme(*(cible(m_equipeJ1, true,0)));
			}
			else if (dynamic_cast<CRogue*>(personnage))
			{
				dynamic_cast<CRogue*> (personnage)->attaqueArme(*(cible(m_equipeJ1, true,0)));
			}
		}
		break;


	case 2:
		//Attaque spéciale
		//equipe 1
		if (dynamic_cast<CWarrior*>(personnage))
		{
			dynamic_cast<CWarrior*> (personnage)->attaqueSpeciale();
		}
		else if (dynamic_cast<CArcher*>(personnage))
		{
			dynamic_cast<CArcher*> (personnage)->attaqueSpeciale();
		}
		else if (dynamic_cast<CMage*>(personnage))
		{
			dynamic_cast<CMage*> (personnage)->attaqueSpeciale();
		}
		else if (dynamic_cast<CRogue*>(personnage))
		{
			dynamic_cast<CRogue*> (personnage)->attaqueSpeciale();
		}
		break;
	case 3:
		if (!equipe)
		{
			if (dynamic_cast<CWarrior*>(personnage))
			{
				dynamic_cast<CWarrior*> (personnage)->attaqueSpeciale(cible(m_equipeJ1,false,0),m_parsing.getListeArmes());
			}
			else if (dynamic_cast<CArcher*>(personnage))
			{
				dynamic_cast<CArcher*> (personnage)->attaqueSpeciale(cible(m_equipeJ1,false,0));
			}
			else if (dynamic_cast<CMage*>(personnage))
			{
				dynamic_cast<CMage*> (personnage)->attaqueSpeciale(*cible(m_equipeJ1,false,0), "soin");
			}
		}
		else
		{
			if (dynamic_cast<CWarrior*>(personnage))
			{
				dynamic_cast<CWarrior*> (personnage)->attaqueSpeciale(cible(m_equipeJ2, false,1), m_parsing.getListeArmes());
			}
			else if (dynamic_cast<CArcher*>(personnage))
			{
				dynamic_cast<CArcher*> (personnage)->attaqueSpeciale(cible(m_equipeJ2, false,1));
			}
			else if (dynamic_cast<CMage*>(personnage))
			{
				dynamic_cast<CMage*> (personnage)->attaqueSpeciale(*cible(m_equipeJ2, false,1), "soin");
			}
		}
		break;
	case 4:
		if (!equipe)
		{
			if (dynamic_cast<CMage*>(personnage))
			{
				dynamic_cast<CMage*> (personnage)->attaqueSpeciale(*cible(m_equipeJ1, false,0), "enchantement");
			}
		}
		else
		{
			if (dynamic_cast<CMage*>(personnage))
			{
				dynamic_cast<CMage*> (personnage)->attaqueSpeciale(*cible(m_equipeJ2, false,1), "enchantement");
			}
		}
		break;
	default:
		break;
	}
	return;
}
//BON hurler et invisible
CCharacter* CGame::cible(vector<CCharacter*> equipe,bool attaque,int camp)
{
	SDL_Event e;
	int quit = 0;

	vector<CCharacter*> disponible;
	vector<int*> cible;
	int suivi = 0;

	vector<CCharacter*>::iterator it;

	if (attaque)
	{
		//Si chevalier a hurlé
		for (it = equipe.begin(); it < equipe.end(); it++)
		{
			
			if (dynamic_cast<CWarrior*> (*it) && dynamic_cast<CWarrior*> (*it)->getSpecial("m_nombreDeTours")!=0)
			{
				//TODO: Affichage cible
				
				return *it;
			}
			suivi++;
		}
		suivi = 0;
		//Si invisible
		for (it = equipe.begin(); it < equipe.end(); it++)
		{
			if (dynamic_cast<CRogue*>(*it) && dynamic_cast<CRogue*>(*it)->getSpecial("m_invisible"))
			{
				//On ne l'ajoute pas
			}
			else
			{
				//On le rajoute
				cible.push_back(&suivi);
				disponible.push_back(*it);
			}
			suivi++;
		}
		//Si tous invisible
		if (equipe.size() != 0 && disponible.size() == 0)
		{
			suivi = 0;
			for (it = equipe.begin(); it < equipe.end(); it++)
			{
				//On les rajoute tous
				disponible.push_back(*it);
				cible.push_back(&suivi);
				suivi++;
			}
		}
	}
	else
	{
		for (it = equipe.begin(); it < equipe.end(); it++)
		{
			disponible.push_back(*it);
			cible.push_back(&suivi);
			suivi++;
		}
	}


	int limite=disponible.size() -1 ;
 	int cur = 0;

	//TODO:affichage
	m_graphisme.affichageCible(equipe, cur);
	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_SPACE:
					quit = 1;
					break;

				case SDLK_UP:
					if (!cur)
					{
						cur = limite;
					}
					else
					{
						cur--;
					}
					break;

				case SDLK_DOWN:
					if (cur == limite)
					{
						cur = 0;
					}
					else
					{
						cur++;
					}
					break;
				}
				break;

			default:
				break;
			}
			cout << "Choix personnage " << cur << endl;
			//TODO:affichage
			m_graphisme.affichageCible(equipe, cur);
		}
	}
	return disponible[cur];
}
//BON
void CGame::majMort()
{
	//On cherche dans l'équipe 1
	if (m_equipeJ1.size() != 0)
	{
		for (int i = 0; i < m_equipeJ1.size(); i++)
		{
			//Si il est mort
			if (m_equipeJ1[i]->getHp() <= 0)
			{
				m_equipeJ1.erase(m_equipeJ1.begin()+i);
			}
		}
	}

	//On cherche dans l'équipe 2
	if (m_equipeJ2.size() != 0)
	{
		for (int i = 0; i < m_equipeJ2.size(); i++)
		{
			for (int i = 0; i < m_equipeJ2.size(); i++)
			{
				//Si il est mort
				if (m_equipeJ2[i]->getHp() <= 0)
				{
					m_equipeJ2.erase(m_equipeJ2.begin() + i);
				}
			}
		}
	}
	return;
}



void CGame::rejouer()
{
	Game();
	return;
}



