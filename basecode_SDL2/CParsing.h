#pragma once
#include "utils.h"

#include "CWeapon.h"
#include "CSword.h"
#include "CDagger.h"
#include "CBow.h"
#include "CStaff.h"

#include "CCharacter.h"
#include "CWarrior.h"
#include "CArcher.h"
#include "CMage.h"
#include "CRogue.h"


class CParsing
{
protected:
	//Membres
	string m_fileArmes;
	string m_filePersonnages;

	vector<CWeapon*> m_listeArmes;
	vector<CCharacter*> m_listePersonnages;

public:
	//methodes
	CParsing();
	~CParsing();


	//Gets
	vector<CWeapon*> getListeArmes();
	vector<CCharacter*> getListePersonnages();

	//Sets
	void setListeArmes(vector<CWeapon*> listeArmes);
	void setListePersonnages(vector<CCharacter*> listePersonnages);

	void constructionListeArmes();
	void constructionListePersonnages();


};