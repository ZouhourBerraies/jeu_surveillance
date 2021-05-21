#pragma once
#include"Obstacle.h"
#include"Robot.h"
#include"Sac_argent.h"

class Zone_geo
{
	int ligne, colonne;
public:
	vector<vector<Case> > grille;
	vector<Sac_argent> argent;
	vector<Robot> rob;
	vector<Intrus> intr;
	vector <Case> case_sortie;
	vector <Obstacle> obs;

	Zone_geo(int n, int m) :ligne(n), colonne(m)
	{
		//remplissage grille
		for (int i = 0; i < ligne; i++)
		{
			vector<Case> temp;
			for (int j = 0; j < colonne; j++)
			{
				temp.push_back(Case(i, j));
			}
			grille.push_back(temp);
		}


		//remplissage cases de sorties
		//int e = 2 * (ligne + colonne - 2);
		for (int i = 0; i < colonne; i++)

			case_sortie.push_back(grille[0][i]);


		for (int i = 1; i < ligne; i++)


			case_sortie.push_back(grille[i][0]);


		for (int i = 1; i < colonne; i++)
			case_sortie.push_back(grille[ligne - 1][i]);


		for (int i = 1; i < ligne - 1; i++)
			case_sortie.push_back(grille[i][colonne - 1]);
		//remplissage des obstacles
		srand(time(0));
		int max_obstacle = rand() % ((ligne * colonne) / 4) + 1;

		for (int k = 0; k < max_obstacle; k++)
		{
			//srand(time(0));
			int i, j;
			do {
				i = rand() % (ligne);
				j = rand() % (colonne);
			} while (est_vide(grille[i][j]));
			obs.push_back(Obstacle(grille[i][j]));

		}
		//repmlissage des sac argent
		srand(time(0));
		int maxargent = rand() % ((ligne * colonne) / 3) + 1;
		for (int k = 0; k < maxargent; k++)
		{
			int i, j;
			do {
				i = rand() % (ligne);
				j = rand() % (colonne);
			} while (est_vide(grille[i][j]));
			argent.push_back(Sac_argent(grille[i][j]));
		}

		//repmlissage tableau de robot
		int max_robot = 0;
		do {
			cout << "entrer nombre de robot" << endl;
			cin >> max_robot;
		} while (max_robot > 4);
		for (int k = 0; k < max_robot; k++)
		{
			int i, j;
			do {
				i = rand() % (ligne);
				j = rand() % (colonne);
			} while (est_vide(grille[i][j]));
			rob.push_back(Robot(grille[i][j]));
		}
		//repmlissage tableau de intrus

		int max_intr = 0;
		do {
			cout << "entrer nombre de intrus" << endl;
			cin >> max_intr;
		} while (max_intr > 4);
		for (int k = 0; k < max_intr; k++)
		{
			int i, j;
			do {
				i = rand() % (ligne);
				j = rand() % (colonne);
			} while (est_vide(grille[i][j]));
			intr.push_back(Intrus(grille[i][j]));
		}

	}

	~Zone_geo() {}
	int retype(Case c)
	{
		bool trouve = false;
		int k = 0;
		int i = 0;
		while (!trouve && i < rob.size())
		{
			trouve = (rob[i].getcr() == c);
			i++;
		}
		if (trouve)
			k = 1;
		else {
			i = 0;
			while (!trouve && i < intr.size())
			{
				trouve = (intr[i].getcint() == c);
				i++;
			}
			if (trouve)
				k = 2;
			else {
				i = 0;
				while (!trouve && i < obs.size())
				{
					trouve = (obs[i].getcobs() == c);
					i++;
				}
				if (trouve) {
					k = 3;
				}
				else {
					i = 0;
					while (!trouve && i < argent.size())
					{
						trouve = (argent[i].getcarg() == c);
						i++;
					}
					if (trouve)
						k = 4;
				}
			}

		}
		return k;


	}
	int positionR(Case c, vector<Robot> robt)
	{
		for (int i = 0; i < robt.size(); i++)
		{
			if (robt[i].getcr() == c) {
				return i;
			}
		}
	}
	int positionI(Case c, vector<Intrus> robt)
	{
		for (int i = 0; i < robt.size(); i++)
		{
			if (robt[i].getcint() == c)
				return i;
		}
	}
	void affiche()
	{

		for (int i = 0; i < ligne; i++)
		{
			cout << "|";
			for (int j = 0; j < colonne; j++)
			{
				int k = retype(grille[i][j]);
				if (k == 1)
				{
					int t = positionR(grille[i][j], rob);
					cout << " R" << t << "|";
				}
				else if (k == 2)
				{
					int t = positionI(grille[i][j], intr);
					cout << " I" << t << "|";
				}
				else if (k == 4) {
					cout << " $ |";
				}
				else if (k == 3) {
					cout << " X |";
				}
				else if (k == 0) {
					cout << "___|";
				}
			}
			cout << endl;
		}
	}

	bool est_vide(Case c)
	{
		bool trouve = false;
		int i = 0;
		while (!trouve && i < obs.size())
		{
			trouve = (obs[i].getcobs() == c);
			i++;
		}
		if (i >= obs.size())
		{
			trouve = false;
			i = 0;
			while (!trouve && i < argent.size())
			{
				trouve = (argent[i].getcarg() == c);
				i++;
			}
			if (i >= argent.size())
			{
				trouve = false;
				i = 0;
				while (!trouve && i < rob.size())
				{
					trouve = (rob[i].getcr() == c);
					i++;
				}
				if (i > rob.size())
				{
					trouve = false;
					i = 0;
					while (!trouve && i < intr.size())
					{
						trouve = (intr[i].getcint() == c);
						i++;
					}
				}
			}
		}
		return trouve;
	}
	void supprimerI(int i)
	{
		vector<Intrus> nv;
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
	void supprimerSac(int& i)
	{
		vector<Sac_argent> sc;
		for (int q = 0; q < argent.size(); q++)
		{
			if (q != i) {
				sc.push_back(argent[q]);
			}
		}
		for (int q = 0; q < argent.size(); q++)
		{
			argent.pop_back();
		}

		for (int q = 0; q < sc.size(); q++)
		{
			argent.push_back(sc[q]);
		}
	}
};

