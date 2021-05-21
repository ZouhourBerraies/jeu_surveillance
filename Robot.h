#pragma once

#include"Intrus.h"
#include"Sac_argent.h"
//#include "Zone.h"
class Zone_geo;


class Robot
{
	Case cr;
public:
	Robot(Case c):cr (c)
	{
	}
	~Robot() { }
	void deplacer()
	{
		enum direction { gauche, droite, haut, bas };
		int a = cr.getx();
		int b = cr.gety();

		int dir;
		cout << "choisir une direction (gauche(0), droite(1), haut(2), bas(3)" << endl;
		cin >> dir;

		if (dir < 4) {
			switch (direction(dir)) {
			case gauche:
				if ( b > 0)
					cr.sety(--b);
				else
					cout << "erreur" << endl;
				break;
			case droite:
				
				cr.sety(++b);
				break;
			case haut: if ( a > 0)
				cr.setx(--a);
					 else
				cout << "erreur" << endl;
				break;
			case bas: 
				cr.setx(++a);
		
				break;
			}
		}
		else
			cout << "direction invalide" << endl;

	}
	void attraper(Intrus& it, vector<Sac_argent>& argent) {

		

		int p = it.getnbrargent();

		while (p != 0)
		{
			it.volee[--p].revenir(argent);
			it.volee.pop_back();
		}

	}

	Case getcr()
	{
		return cr;
	}
};

