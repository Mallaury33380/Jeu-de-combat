#pragma once
#include "utils.h"
#include "CParsing.h"

class CGraphique
{
public:
	//Membres
	SDL_Window* window;
	SDL_Renderer* renderer;


	//Methodes
	CGraphique();
	~CGraphique();

	//Initialisation SDL et SDL image etconstruction de la fenetre
	void init();
	void clear();


	void affichageMenu(int choix);
	void affichageChoixPersonnages(int choix,int equipe);
	void affichageChoixArmes(int choix);

	void affichageTourDeJouer(vector<CCharacter*> personnages,int equipe, int place);
	void afficherChoixAction(CCharacter* personnage,int choix);
	void affichageCible(vector<CCharacter*> personnages, int place);

	void finDepartie(int camp);
	void affichierRegles();
};