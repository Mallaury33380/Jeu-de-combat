#include "CGraphique.h"

CGraphique::CGraphique ()
{

}
CGraphique::~CGraphique()
{

}

//Initialisation SDL et SDL image etconstruction de la fenetre
void CGraphique::init()
{
	if (!SDL_WasInit(SDL_INIT_VIDEO))
	{
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			std::cerr << "[-] ERROR - Failed to initialise SDL (" << SDL_GetError() << ")\n";
			return;
		}
	}

	if (!IMG_Init(IMG_INIT_PNG))
	{
		std::cerr << "[-] ERROR - Failed to initialise SDL_Image (" << SDL_GetError() << ")\n";
		return;
	}


	window = SDL_CreateWindow("Ma fenetre SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1024, 768, SDL_WINDOW_SHOWN);
	if (!window)
	{
		std::cerr << "[-] ERROR - Failed to create SDL window (" << SDL_GetError() << ")\n";
		return;
	}
	


	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	return;
}

void CGraphique::clear()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return;
}

//BON
void CGraphique::affichageMenu(int choix)
{
	SDL_RenderClear(renderer);
	
	//Fond du menu
	SDL_Texture* textureFond;
	SDL_Surface* imageFond;

	imageFond = IMG_Load("data/Menu.png");
	textureFond = SDL_CreateTextureFromSurface(renderer, imageFond);
	SDL_FreeSurface(imageFond);

	SDL_Rect rectFond;

	rectFond.w = 1024;
	rectFond.h = 768;
	rectFond.x = 0;
	rectFond.y = 0;

	SDL_RenderCopy(renderer, textureFond, &rectFond, &rectFond);

	//Affichage
	SDL_Texture* textureIndicateur;
	SDL_Surface* imageIndicateur;

	imageIndicateur = IMG_Load("data/indicateur.png");
	textureIndicateur = SDL_CreateTextureFromSurface(renderer, imageIndicateur);
	SDL_FreeSurface(imageIndicateur);

	SDL_Rect rectIndicateur;
	SDL_Rect rectPositionIndicateur;

	rectIndicateur.w = 50;
	rectIndicateur.h = 50;
	rectIndicateur.x = 0;
	rectIndicateur.y = 0;

	rectPositionIndicateur.w = 50;
	rectPositionIndicateur.h = 50;
	rectPositionIndicateur.x = 200;
	rectPositionIndicateur.y = 150*choix+25;

	SDL_RenderCopy(renderer, textureIndicateur, &rectIndicateur, &rectPositionIndicateur);

	//Affichage console
	system("cls");
	cout << "\t\t\t==Simulateur de combat epique interlicense==\n\n\n" << "-0 : Commencer une nouvelle partie\n-1 : Lire les regles\n-2 : Quitter\n\nVotre preselection: " <<choix<<"\n\t\t\tAppuyer sur ESPACE pour valider"<<endl;


	//affichage fenetre
	SDL_RenderPresent(renderer);

	return;
}

void CGraphique::affichageChoixPersonnages(int choix,int equipe)
{
	SDL_RenderClear(renderer);
	//Fond du menu
	SDL_Texture* textureFond;
	SDL_Surface* imageFond;

	imageFond = IMG_Load("data/imageArene.png");
	textureFond = SDL_CreateTextureFromSurface(renderer, imageFond);
	SDL_FreeSurface(imageFond);

	SDL_Rect rectFond;

	rectFond.w = 1024;
	rectFond.h = 768;
	rectFond.x = 0;
	rectFond.y = 0;

	SDL_RenderCopy(renderer, textureFond, &rectFond, &rectFond);

	//Affichage
	SDL_Texture* texturePersonnage;
	SDL_Surface* imagePersonnage;

	imagePersonnage = IMG_Load("data/imagePersonnages.png");
	texturePersonnage = SDL_CreateTextureFromSurface(renderer, imagePersonnage);
	SDL_FreeSurface(imagePersonnage);

	SDL_Rect rectPersonnage;
	SDL_Rect rectPositionPersonnage;

	rectPersonnage.w = 775;
	rectPersonnage.h = 500;
	rectPersonnage.x = 0;
	rectPersonnage.y = 500*choix;

	rectPositionPersonnage.w = 400;
	rectPositionPersonnage.h = 258;
	rectPositionPersonnage.x = 100;
	rectPositionPersonnage.y = 234;

	SDL_RenderCopy(renderer, texturePersonnage, &rectPersonnage, &rectPositionPersonnage);


	//Affichage joueur qui choisi
		//Affichage plaque
	if (equipe == 1)
	{
		SDL_Texture* texturePlaque;
		SDL_Surface* imagePlaque;



		imagePlaque = IMG_Load("data/plaque1.png");
		texturePlaque = SDL_CreateTextureFromSurface(renderer, imagePlaque);
		SDL_FreeSurface(imagePlaque);

		SDL_Rect rectPlaque;
		SDL_Rect rectPositionPlaque;

		rectPlaque.w = 210;
		rectPlaque.h = 100;
		rectPlaque.x = 0;
		rectPlaque.y = 0;

		rectPositionPlaque.w = 200;
		rectPositionPlaque.h = 100;
		rectPositionPlaque.x = 412;
		rectPositionPlaque.y = 600;

		SDL_RenderCopy(renderer, texturePlaque, &rectPlaque, &rectPositionPlaque);
	}
	else if (equipe == 2)
	{
		SDL_Texture* texturePlaque;
		SDL_Surface* imagePlaque;



		imagePlaque = IMG_Load("data/plaque2.png");
		texturePlaque = SDL_CreateTextureFromSurface(renderer, imagePlaque);
		SDL_FreeSurface(imagePlaque);

		SDL_Rect rectPlaque;
		SDL_Rect rectPositionPlaque;

		rectPlaque.w = 210;
		rectPlaque.h = 100;
		rectPlaque.x = 0;
		rectPlaque.y = 0;

		rectPositionPlaque.w = 200;
		rectPositionPlaque.h = 100;
		rectPositionPlaque.x = 412;
		rectPositionPlaque.y = 600;

		SDL_RenderCopy(renderer, texturePlaque, &rectPlaque, &rectPositionPlaque);
	}

	//Affichage console
	system("cls");
	cout << "\t\t\t==Simulateur de combat epique interlicense==\n\n\n" << "C'est au joueur " << equipe << " de choisir son personnage:\n\n" << endl;
	switch (choix)
	{
	case 0:
		cout << "-0\tGandalf Mage\n\nHP: 150\nEsquive:0.12\nVitesse:23\nAttaque:13\nDefense:12\nAgilite:15\nIntelligence:20"<<endl;
		break;
	case 1:
		cout << "-1\tLeoric Guerrier\n\nHP: 230\nEsquive:0.12\nVitesse:27\nAttaque:20\nDefense:34\nAgilite:11\nIntelligence:12\tParade:0.06" << endl;
		break;
	case 2:
		cout << "-2\tSylvanas Coursevent Archer\n\nHP: 175\nEsquive:0.12\nVitesse:21\nAttaque:14\nDefense:23\nAgilite:17\nIntelligence:12" << endl;
		break;
	case 3:
		cout << "-3\tJaina Portvaillant Mage\n\nHP: 125\nEsquive:0.12\nVitesse:22\nAttaque:14\nDefense:14\nAgilite:17\nIntelligence:19" << endl;
		break;
	case 4:
		cout << "-4\tGarona Voleur\n\nHP: 170\nEsquive:0.25\nVitesse:19\nAttaque:12\nDefense:20\nAgilite:17\nIntelligence:9\nprobabilite emoisonnement:0.2" << endl;
		break;
	case 5:
		cout << "-5\tXena Guerrier\n\nHP: 240\nEsquive:0.12\nVitesse:19\nAttaque:26\nDefense:37\nAgilite:12\nIntelligence:12\tParade:0.08" << endl;
		break;
	case 6:
		cout << "-6\tJorach Ravenholdt Voleur\n\nHP: 170\nEsquive:0.2\nVitesse:18\nAttaque:11\nDefense:21\nAgilite:18\nIntelligence:9\nprobabilite emoisonnement:0.22" << endl;
		break;
	case 7:
		cout << "-7\tOliver Queen Archer\n\nHP: 175\nEsquive:0.12\nVitesse:22\nAttaque:15\nDefense:25\nAgilite:16\nIntelligence:11" << endl;
		break;
	}
	cout<<"\n\t\t\tAppuyer sur ESPACE pour selectionner"<<endl;

	
	

	//affichage fenetre
	SDL_RenderPresent(renderer);

	return;
}

void CGraphique::affichageChoixArmes(int choix)
{

	//Affichage
	SDL_Texture* textureArme;
	SDL_Surface* imageArme;

	imageArme = IMG_Load("data/imageArmes.png");
	textureArme = SDL_CreateTextureFromSurface(renderer, imageArme);
	SDL_FreeSurface(imageArme);

	SDL_Rect rectArme;
	SDL_Rect rectPositionArme;

	rectArme.w = 775;
	rectArme.h = 500;
	rectArme.x = 0;
	rectArme.y = 500 * choix;

	rectPositionArme.w = 400;
	rectPositionArme.h = 258;
	rectPositionArme.x = 524;
	rectPositionArme.y = 234;

	//copie renderer et texture
	SDL_RenderCopy(renderer, textureArme, &rectArme, &rectPositionArme);

	//Affichage console
	system("cls");
	cout << "\t\t\t==Simulateur de combat epique interlicense==\n\n\n" << "et son arme:\n\n" << endl;
	switch (choix)
	{
	case 0:
		cout << "-0\tBaguette de Sureau Baton\n\nDegat:7\nCritique:0.12\nCout:6\nBonus:\nHp:-30\nIntelligence:+8" << endl;
		break;
	case 1:
		cout << "-1\tExcalibur Epee\n\nDegat:15\nCritique:0.09\nDurabilite:30\nBonus:\nAttack:+3" << endl;
		break;
	case 2:
		cout << "-2t\tGandiva Arc\n\nDegat:12\nCritique:0.17\nFleche:20\nBonus:\nAttack:+5" << endl;
		break;
	case 3:
		cout << "-3\tPerce-bourse Dague\n\nDegat:12\nCritique:0.25\nDurabilite:220\nBonus:\nHP:-10\nDefense:+4" << endl;
		break;
	case 4:
		cout << "-4\tPorte-cendre Epee\n\nDegat:17\nCritique:0.1\nDurabilite:200\nBonus:\nHP:-90\nAttack:+7" << endl;
		break;
	case 5:
		cout << "-5\tThori'dal Arc\n\nDegat:10\nCritique:0.12\nFleche:22\nBonus:\nHP:+30" << endl;
		break;
	case 6:
		cout << "-6\tAtiesh Baton\n\nDegat:10\nCritique:0.12\nCout:7\nBonus:\nIntelligence:+5" << endl;
		break;
	case 7:
		cout << "-7\tSorcelame Dague\n\nDegat:12\nCritique:0.24\nDurabilite:180\nBonus:\nAgilite:+5\nAttaque:-2" << endl;
		break;
	}
	cout << "\n\t\t\tAppuyer sur ESPACE pour selectionner" << endl;


	//affichage fenetre
	SDL_RenderPresent(renderer);
}






void CGraphique::affichageTourDeJouer(vector<CCharacter*> personnages, int equipe, int place)
{
	//TODO:trouver meilleur sol
	clear();
	init();

	//Fond
	SDL_Texture* textureFond;
	SDL_Surface* imageFond;

	imageFond = IMG_Load("data/champDeBataille.png");
	textureFond = SDL_CreateTextureFromSurface(renderer, imageFond);
	SDL_FreeSurface(imageFond);

	SDL_Rect rectFond;

	rectFond.w = 1024;
	rectFond.h = 768;
	rectFond.x = 0;
	rectFond.y = 0;

	SDL_RenderCopy(renderer, textureFond, &rectFond, &rectFond);

	//Affichage du joueur
	SDL_Texture* texturePersonnage;
	SDL_Surface* imagePersonnage;

	imagePersonnage = IMG_Load("data/imagePersonnages.png");
	texturePersonnage = SDL_CreateTextureFromSurface(renderer, imagePersonnage);
	SDL_FreeSurface(imagePersonnage);

	SDL_Rect rectPersonnage;
	SDL_Rect rectPositionPersonnage;

	rectPersonnage.w = 500;
	rectPersonnage.h = 500;
	rectPersonnage.x = 0;
	rectPersonnage.y = 0;

	rectPositionPersonnage.w = 258;
	rectPositionPersonnage.h = 258;
	rectPositionPersonnage.x = 50;
	rectPositionPersonnage.y = 255;

	if (personnages[place]->getNom()=="Gandalf")
	{
		cout << "gandalf";
		rectPersonnage.y = 0;
	}
	else if (personnages[place]->getNom() == "Leoric")
	{
		rectPersonnage.y = 500;
	}
	else if (personnages[place]->getNom() == "Sylvanas Coursevent")
	{
		rectPersonnage.y = 1000;
	}
	else if (personnages[place]->getNom() == "Jaina Portvaillant")
	{
		rectPersonnage.y = 1500;
	}
	else if (personnages[place]->getNom() == "Garona")
	{
		rectPersonnage.y = 2000;
	}
	else if (personnages[place]->getNom() == "Xena")
	{
		rectPersonnage.y = 2500;
	}
	else if (personnages[place]->getNom() == "Jorach Ravenholdt")
	{
		rectPersonnage.y = 3000;
	}
	else if (personnages[place]->getNom() == "Oliver Queen")
	{
		rectPersonnage.y = 3500;
	}
	SDL_RenderCopy(renderer, texturePersonnage, &rectPersonnage, &rectPositionPersonnage);
	


	//Affichage camp
		//Affichage plaque
	if (equipe == 0)
	{
		SDL_Texture* texturePlaque;
		SDL_Surface* imagePlaque;



		imagePlaque = IMG_Load("data/plaque1.png");
		texturePlaque = SDL_CreateTextureFromSurface(renderer, imagePlaque);
		SDL_FreeSurface(imagePlaque);

		SDL_Rect rectPlaque;
		SDL_Rect rectPositionPlaque;

		rectPlaque.w = 210;
		rectPlaque.h = 100;
		rectPlaque.x = 0;
		rectPlaque.y = 0;

		rectPositionPlaque.w = 200;
		rectPositionPlaque.h = 100;
		rectPositionPlaque.x = 412;
		rectPositionPlaque.y = 600;

		SDL_RenderCopy(renderer, texturePlaque, &rectPlaque, &rectPositionPlaque);
	}
	else if (equipe == 1)
	{
		SDL_Texture* texturePlaque;
		SDL_Surface* imagePlaque;



		imagePlaque = IMG_Load("data/plaque2.png");
		texturePlaque = SDL_CreateTextureFromSurface(renderer, imagePlaque);
		SDL_FreeSurface(imagePlaque);

		SDL_Rect rectPlaque;
		SDL_Rect rectPositionPlaque;

		rectPlaque.w = 210;
		rectPlaque.h = 100;
		rectPlaque.x = 0;
		rectPlaque.y = 0;

		rectPositionPlaque.w = 200;
		rectPositionPlaque.h = 100;
		rectPositionPlaque.x = 412;
		rectPositionPlaque.y = 600;

		SDL_RenderCopy(renderer, texturePlaque, &rectPlaque, &rectPositionPlaque);
	}


	//Affichage console
	system("cls");
	cout << "\t\t\t==Simulateur de combat epique interlicense==\n\n" << "Le joueur "<<equipe+1<<" joue\n" << endl;
	cout << "\tLe personnage " << personnages[place]->getNom() << " joue\nIl a "<< personnages[place]->getHp()<<"HP et " ;
	//Empoisonne
	if (personnages[place]->getEmpoisonne())cout << "'est empoisonne."; else { cout << "n'est pas empoisonne."; }
	//Enchanter
	if (personnages[place]->getArme()->getEnchante())cout << " Son arme est enchante et "; else { cout << " Son arme n'est pas enchante et "; }

	//Classe
	if (dynamic_cast<CWarrior*>(personnages[place]))
	{
		if (personnages[place]->getArme()->getSpecial() == 0)cout << " est casse."; else { cout << "n'est pas casse."; }
		if (dynamic_cast<CWarrior*>(personnages[place])->getSpecial("m_nombreDeTours") == 0)cout << " Il n'a pas hurle"; else {
			cout << "Il a hurlé pour" << dynamic_cast<CWarrior*>(personnages[place])->getSpecial("m_nombreDeTours") << " tours";
		}
	}
	else if (dynamic_cast<CArcher*>(personnages[place]))
	{
		if (dynamic_cast<CArcher*>(personnages[place])->getSpecial("m_cdGuerir") == 0)cout << "Il n'a plus de soin."; else {
			cout << "Il a " << dynamic_cast<CArcher*>(personnages[place])->getSpecial("m_cdGuerir") << " de soin(s).";
		}
		if (dynamic_cast<CArcher*>(personnages[place])->getSpecial("m_cdViser") == 0)cout << "N'est pas en train de viser"; else {
			cout << "Est en train de viser";
		}
	}
	else if (dynamic_cast<CMage*>(personnages[place]))
	{
		if (dynamic_cast<CMage*>(personnages[place])->getSpecial("m_mana") == 0)cout << "il n'aplus de mana."; else {
			cout << "il a " << dynamic_cast<CMage*>(personnages[place])->getSpecial("m_mana") << " de mana";
		}
	}
	else if (dynamic_cast<CRogue*>(personnages[place]))
	{
		if (personnages[place]->getArme()->getSpecial() == 0)cout << "casse."; else { cout << "pas casse."; }
		if (dynamic_cast<CRogue*>(personnages[place])->getSpecial("m_invisible") == 0)cout << "Il n'est pas invisible"; else {
			cout << "il est invisible";
		}
	}

	cout << "\n\t\t\tAppuyer sur ESPACE pour valider" << endl;



	//affichage fenetre
	SDL_RenderPresent(renderer);

	return;
}

void CGraphique::afficherChoixAction(CCharacter* personnage,int choix)
{
	//Affichage Action possible
	SDL_Texture* textureAction;
	SDL_Surface* imageAction;

	imageAction = IMG_Load("data/imageActions.png");
	textureAction = SDL_CreateTextureFromSurface(renderer, imageAction);
	SDL_FreeSurface(imageAction);

	SDL_Rect rectAction;
	SDL_Rect rectPositionAction;

	rectAction.w = 300;
	rectAction.h = 600;
	rectAction.x = 0;
	rectAction.y = 0;

	rectPositionAction.w = 200;
	rectPositionAction.h = 400;
	rectPositionAction.x = 412;
	rectPositionAction.y = 50;

	if (dynamic_cast<CArcher*> (personnage))
	{
		rectAction.y = 600;
	}
	else if (dynamic_cast<CMage*> (personnage))
	{
		rectAction.y = 1200;
		rectAction.h = 750;
		rectPositionAction.h = 500;
	}
	else if (dynamic_cast<CRogue*> (personnage))
	{
		rectAction.y = 1950;
		rectAction.h = 450;
		rectPositionAction.h = 300;
	}
	SDL_RenderCopy(renderer, textureAction, &rectAction, &rectPositionAction);

	//Choix
	SDL_Texture* textureChoix;
	SDL_Surface* imageChoix;

	imageChoix = IMG_Load("data/selection.png");
	textureChoix = SDL_CreateTextureFromSurface(renderer, imageChoix);
	SDL_FreeSurface(imageChoix);

	SDL_Rect rectChoix;
	SDL_Rect rectPositionChoix;

	rectChoix.w = 300;
	rectChoix.h = 150;
	rectChoix.x = 0;
	rectChoix.y = 0;

	rectPositionChoix.w = 200;
	rectPositionChoix.h = 100;
	rectPositionChoix.x = 412;
	rectPositionChoix.y = 50+100*choix;
	SDL_RenderCopy(renderer, textureChoix, &rectChoix, &rectPositionChoix);


	//Affichage console
	system("cls");
	cout << "\t\t\t==Simulateur de combat epique interlicense==\n\n" << "Le joueur choisi comme action pour son personnage:\n" << endl;
	
	if (dynamic_cast<CWarrior*> (personnage))
	{
		switch (choix)
		{
		case 0:
			cout << "\t-0: Attaquer a mains nues." << endl;
			break;
		case 1:
			cout << "\t-1: Attaquer avec son arme." << endl;
			break;
		case 2:
			cout << "\t-2: Hurler." << endl;
			break;
		case 3:
			cout << "\t-3: De réparer une arme." << endl;
			break;
		default:
			break;
		}
	}
	else if (dynamic_cast<CArcher*> (personnage))
	{
		switch (choix)
		{
		case 0:
			cout << "\t-0: Attaquer a mains nues." << endl;
			break;
		case 1:
			cout << "\t-1: Attaquer avec son arme." << endl;
			break;
		case 2:
			cout << "\t-2: De viser." << endl;
			break;
		case 3:
			cout << "\t-3: De soigner un allie du poison." << endl;
			break;
		default:
			break;
		}


	}
	else if (dynamic_cast<CMage*> (personnage))
	{
		switch (choix)
		{
		case 0:
			cout << "\t-0: Attaquer a mains nues." << endl;
			break;
		case 1:
			cout << "\t-1: Attaquer avec son arme." << endl;
			break;
		case 2:
			cout << "\t-2: Regenerer son mana." << endl;
			break;
		case 3:
			cout << "\t-3: Soigner un allie." << endl;
			break;
		case 4:
			cout << "\t-4: Enchanter une arme." << endl;
			break;
		default:
			break;
		}

	}
	else if (dynamic_cast<CRogue*> (personnage))
	{
		switch (choix)
		{
		case 0:
			cout << "\t-0: Attaquer a mains nues." << endl;
			break;
		case 1:
			cout << "\t-1: Attaquer avec son arme." << endl;
			break;
		case 2:
			cout << "\t-2: De devenir invisble." << endl;
			break;
		default:
			break;
		}

	}

	cout << "\n\t\t\tAppuyer sur ESPACE pour valider" << endl;


	//affichage fenetre
	SDL_RenderPresent(renderer);

	return;
}

void CGraphique::affichageCible(vector<CCharacter*> personnages, int place)
{
	//Affichage du joueur
	SDL_Texture* texturePersonnage;
	SDL_Surface* imagePersonnage;

	imagePersonnage = IMG_Load("data/imagePersonnages.png");
	texturePersonnage = SDL_CreateTextureFromSurface(renderer, imagePersonnage);
	SDL_FreeSurface(imagePersonnage);

	SDL_Rect rectPersonnage;
	SDL_Rect rectPositionPersonnage;

	rectPersonnage.w = 500;
	rectPersonnage.h = 500;
	rectPersonnage.x = 0;
	rectPersonnage.y = 0;

	rectPositionPersonnage.w = 258;
	rectPositionPersonnage.h = 258;
	rectPositionPersonnage.x = 716;
	rectPositionPersonnage.y = 255;

	if (personnages[place]->getNom() == "Gandalf")
	{
		cout << "gandalf";
		rectPersonnage.y = 0;
	}
	else if (personnages[place]->getNom() == "Leoric")
	{
		rectPersonnage.y = 500;
	}
	else if (personnages[place]->getNom() == "Sylvanas Coursevent")
	{
		rectPersonnage.y = 1000;
	}
	else if (personnages[place]->getNom() == "Jaina Portvaillant")
	{
		rectPersonnage.y = 1500;
	}
	else if (personnages[place]->getNom() == "Garona")
	{
		rectPersonnage.y = 2000;
	}
	else if (personnages[place]->getNom() == "Xena")
	{
		rectPersonnage.y = 2500;
	}
	else if (personnages[place]->getNom() == "Jorach Ravenholdt")
	{
		rectPersonnage.y = 3000;
	}
	else if (personnages[place]->getNom() == "Oliver Queen")
	{
		rectPersonnage.y = 3500;
	}
	SDL_RenderCopy(renderer, texturePersonnage, &rectPersonnage, &rectPositionPersonnage);



	//Affichage console
	system("cls");
	cout << "\t\t\t==Simulateur de combat epique interlicense==\n\n" << "Le joueur selectionne comme cible de son action:\n" << endl;
	cout << "\tLe personnage " << personnages[place]->getNom() << "\nIl a " << personnages[place]->getHp() << "HP et ";
	//Empoisonne
	if (personnages[place]->getEmpoisonne())cout << "'est empoisonne."; else { cout << "n'est pas empoisonne."; }
	//Enchanter
	if (personnages[place]->getArme()->getEnchante())cout << " Son arme est enchante et "; else { cout << " Son arme n'est pas enchante et "; }

	//Classe
	if (dynamic_cast<CWarrior*>(personnages[place]))
	{
		if (personnages[place]->getArme()->getSpecial() == 0)cout << " est casse."; else { cout << "n'est pas casse."; }
		if (dynamic_cast<CWarrior*>(personnages[place])->getSpecial("m_nombreDeTours") == 0)cout << " Il n'a pas hurle"; else {
			cout << "Il a hurlé pour" << dynamic_cast<CWarrior*>(personnages[place])->getSpecial("m_nombreDeTours") << " tours";
		}
	}
	else if (dynamic_cast<CArcher*>(personnages[place]))
	{
		if (dynamic_cast<CArcher*>(personnages[place])->getSpecial("m_cdGuerir") == 0)cout << "Il n'a plus de soin."; else {
			cout << "Il a " << dynamic_cast<CArcher*>(personnages[place])->getSpecial("m_cdGuerir") << " de soin(s).";
		}
		if (dynamic_cast<CArcher*>(personnages[place])->getSpecial("m_cdViser") == 0)cout << "N'est pas en train de viser"; else {
			cout << "Est en train de viser";
		}
	}
	else if (dynamic_cast<CMage*>(personnages[place]))
	{
		if (dynamic_cast<CMage*>(personnages[place])->getSpecial("m_mana") == 0)cout << "il n'aplus de mana."; else {
			cout << "il a " << dynamic_cast<CMage*>(personnages[place])->getSpecial("m_mana") << " de mana";
		}
	}
	else if (dynamic_cast<CRogue*>(personnages[place]))
	{
		if (personnages[place]->getArme()->getSpecial() == 0)cout << "casse."; else { cout << "pas casse."; }
		if (dynamic_cast<CRogue*>(personnages[place])->getSpecial("m_invisible") == 0)cout << "Il n'est pas invisible"; else {
			cout << "il est invisible";
		}
	}

	cout << "\n\t\t\tAppuyer sur ESPACE pour valider" << endl;





	//affichage fenetre
	SDL_RenderPresent(renderer);

}

void CGraphique::finDepartie(int camp)
{
	//Choix
	SDL_Texture* textureChoix;
	SDL_Surface* imageChoix;



	SDL_Rect rectChoix;
	SDL_Rect rectPositionChoix;

	rectChoix.w = 700;
	rectChoix.h = 367;
	rectChoix.x = 0;
	rectChoix.y = 0;

	rectPositionChoix.w = 700;
	rectPositionChoix.h = 367;
	rectPositionChoix.x = 162;
	rectPositionChoix.y = 200;
	
	if (!camp)
	{
		imageChoix = IMG_Load("data/vaincu2.png");
		textureChoix = SDL_CreateTextureFromSurface(renderer, imageChoix);
		SDL_FreeSurface(imageChoix);
		
		SDL_RenderCopy(renderer, textureChoix, &rectChoix, &rectPositionChoix);
		//affichage fenetre
		SDL_RenderPresent(renderer);


	}
	else
	{
		imageChoix = IMG_Load("data/vaincu1.png");
		textureChoix = SDL_CreateTextureFromSurface(renderer, imageChoix);
		SDL_FreeSurface(imageChoix);
		
		SDL_RenderCopy(renderer, textureChoix, &rectChoix, &rectPositionChoix);
		//affichage fenetre
		SDL_RenderPresent(renderer);
	}

	//Affichage console
	system("cls");
	cout << "\t\t\t==Simulateur de combat epique interlicense==\n\n" << "Bravo au joueur " << camp + 1 << " qui a extermie son adversaire" << endl;
	cout << "\n\t\t\tAppuyer sur ESPACE pour valider" << endl;

	SDL_Delay(3000);
	SDL_RenderClear(renderer);

}

void CGraphique::affichierRegles()
{
	SDL_RenderClear(renderer);

	//Fond du menu
	SDL_Texture* textureFond;
	SDL_Surface* imageFond;

	imageFond = IMG_Load("data/regles.png");
	textureFond = SDL_CreateTextureFromSurface(renderer, imageFond);
	SDL_FreeSurface(imageFond);

	SDL_Rect rectFond;

	rectFond.w = 1024;
	rectFond.h = 768;
	rectFond.x = 0;
	rectFond.y = 0;

	SDL_RenderCopy(renderer, textureFond, &rectFond, &rectFond);
	SDL_RenderPresent(renderer);

	SDL_Event e;
	int quit = 0;

	//Affichage console
	system("cls");
	cout << "\t\t\t==Simulateur de combat epique interlicense==\n\n" << "Regles du jeu:\n" << endl;
	cout << "Debut de partie:\n\t-Chaque joueur choisit tour par\n\ttour un de ses 3 personnages et\n\tson arme.\n" << endl;
	cout << "Deroulement de la partie:\n\t-Le personnage ayant la vitesse\n\tla plus faible commence.Sa\n\tvitesse est ensuite soustraite a\n\ta celle des autres et la sienne\n\tremise a sa valeur nominale.\n\n" << endl;
	cout << "\t-Il peut choisir entre une \n\tattaque a mains nues ou avec une\n\tarme ou une attaque speciale\n\tpropre a sa classe." << endl;
	cout << "\n\t-La partie se termine lorsque\n\t tous les personnages d'un joueur\n\t sont morts." << endl;
	cout << "\n\t\t\tAppuyer sur ESCAPE pour revenir au menu" << endl;



	while (!quit)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					quit = 1;
					break;
				}
				break;

			default:
				break;
			}
		}
	}
	return;
}