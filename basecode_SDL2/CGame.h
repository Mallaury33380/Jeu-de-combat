#pragma once
#include "utils.h"
#include "CParsing.h"
#include "CGraphique.h"

class CGame
{
public:
	//Membres
	CParsing m_parsing;

	vector<CCharacter*> m_equipeJ1;
	vector<CCharacter*> m_equipeJ2;

	CGraphique m_graphisme;


	//Methodes
	CGame();
	~CGame();

	//Une partie
	void Game();

	void partie();
	void debut();
	void tour();
	bool finDePartie();

	//
	void choixEquipe();
	void applicationBonus();

	void choixPersonnage(vector<CCharacter*>& joueur,int equipe);
	void choixArme(vector<CCharacter*>& joueur);

	CCharacter* tourDeJouer(int& equipe);
	void action(CCharacter* personnage, int equipe);
	CCharacter* cible(vector<CCharacter*> equipe, bool attaque,int camp);

	void majMort();
	void rejouer();


};