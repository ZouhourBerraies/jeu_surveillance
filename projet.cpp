#include "Zone_geo.h"

int main()
{
	int l, c;
	cout << "entrer nombre de ligne : ";
	cin >> l;
	cout << "entrer nombre de colonne : ";
	cin >> c;
	Zone_geo zone(l, c);
	zone.affiche();
	cout << "les robots" << endl;
	for (int i = 0; i < zone.rob.size(); i++)
		cout << "robot" << i << ": " << zone.rob[i].getcr().getx() << "    " << zone.rob[i].getcr().gety() << endl;
	cout << "les intrus" << endl;
	for (int i = 0; i < zone.intr.size(); i++)
		cout << "Inrus" << i << ": " << zone.intr[i].getcint().getx() << "    " << zone.intr[i].getcint().gety() << endl;
	int s = zone.argent.size();
	cout << "nombre de sac argent = " << s << endl;
	cout << "<< le jeu commence >>" << endl;
	int t = 1;
	while (zone.intr.size() != 0)
	{
		int i;
		cout << "choisir un robot a deplace" << endl;
		cin >> i;
		zone.rob[i].deplacer();
		// chercher un intrus
		int m = 0;
		int n = 0;
		int f = 0;
		for (int k = 0, s = 0; s < zone.intr.size() && k < 1; s++) {
			if (adjacente(zone.rob[i].getcr(), zone.intr[s].getcint())) {
				zone.rob[i].attraper(zone.intr[s], zone.argent);
				zone.supprimerI(s);
				k++;
				n++;
				m = i;
				f = s;
			}
		}
		zone.affiche();
		if (n != 0) {
			cout << "le robot  " << m << " a  attrapper l intrus " << f << endl;
		}


		int j;
		cout << "choisir un intrus a deplace" << endl;
		cin >> j;
		zone.intr[j].deplacer();
		// chercher un sac d argent
		int p = 0;
		int z = 0;
		for (int t = 0, v = 0; t < zone.argent.size() && v < 1; t++) {
			if (adjacente(zone.intr[j].getcint(), zone.argent[t].getcarg())) {
				zone.intr[j].voler(zone.argent[t], zone.argent);
				zone.supprimerSac(t);
				v++;
				p++;
				z = j;
			}
		}
		if (p != 0) {
			cout << "un sac etait voler par l intrus " << z << endl;

		}

		zone.affiche();
		// l intrus cherche a sortir
		if (zone.intr[j].sortir(zone.case_sortie))
		{
			zone.supprimerI(j);
			cout << "Intrus " << j << "sort " << endl;
		}

		cout << "tour " << t << " terminer " << endl;
		t++;
		zone.affiche();
		cout << "<< commencer un autre tour  >>" << endl;
	}
	if (s == zone.argent.size())
		cout << "ROBOT WINNER" << endl;
	else
		cout << "INTRUS WINNER" << endl;
	return 0;
}
