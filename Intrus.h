#pragma once
#include"Sac_argent.h"



class Intrus
{
	int nbrargent;
	Case cint;


public:
	vector <Sac_argent> volee;

	Intrus(Case c)
	{
		
			cint = c;
		nbrargent = 0;


	}
	~Intrus()
	{}
	void deplacer()
	{
		enum direction { gauche, droite, haut, bas };
		int a = cint.getx();
		int b = cint.gety();

		int dir;
		cout << "choisir une direction (gauche(0), droite(1), haut(2), bas(3)" << endl;
		cin >> dir;

		if (dir < 4) {
			switch (direction(dir)) {
			case gauche:
				if (b > 0)
					cint.sety(--b);


				else
					cout << "erreur" << endl;
				break;
			case droite:
					cint.sety(++b);
				break;
			case haut: if ( a > 0)
				cint.setx(--a);
					 else
				cout << "erreur" << endl;
				break;
			case bas: 
				cint.setx(++a);
				break;
			}
		}

	}
	void voler(Sac_argent& sac, vector<Sac_argent>& argent)
	{

		if (nbrargent < 2)
		{


			volee.push_back(sac);

			sac.disparaitre(argent);
			nbrargent++;
		}


	}

	/*void sortir(vector<Case> &case_sortie, vector<Intrus> &intr)
	{
	vector<Intrus> nv;
	if (nbrargent == 2)
	{
	bool test=false;
	int i = 0;

	while (test == false && i < case_sortie.size())
	{
	if (cint == case_sortie[i])
	{
	test = true;
	}
	i++;
	}
	if (test == true)
	{

	for (int q = 0; q < intr.size(); q++)
	{
	if (q != i) {
	nv.push_back(intr[q]);
	}
	}
	for (int q = 0; q < intr.size(); q++)
	{
	intr.pop_back();
	}

	for (int q = 0; q < nv.size(); q++)
	{
	intr.push_back(nv[q]);
	}

	}
	}*/
	bool sortir(vector<Case>& case_sortie)
	{
		bool test = false;
		if (nbrargent == 2)
		{
			int i = 0;

			while (test == false && i < case_sortie.size())
			{

				test = cint == case_sortie[i];

				i++;
			}

		}
		return test;
	}
	int getnbrargent() const
	{
		return nbrargent;
	}
	Case getcint() const {
		return cint;
	}
};
