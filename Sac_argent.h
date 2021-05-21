#pragma once
#include"Case.h"
//class Case;

class Sac_argent
{
	Case carg;
public:
	Sac_argent(Case c)
	{
		
		carg = c;
		
	}
	~Sac_argent() {  }

	void disparaitre(vector<Sac_argent>& argent)
	{
		vector<Sac_argent> nv;
		bool trouve = false;
		int i = 0;
		while (trouve == false && i < argent.size())
		{
			if (argent[i].carg == carg)
				trouve = true;
			i++;
		}
		if (trouve)
		{
			/*for (int j = i; j < argent.size()-1; j++)
			argent[j] = argent[j + 1];*/
			for (int q = 0; q < argent.size(); q++)
			{
				if (q != i) {
					nv.push_back(argent[q]);
				}
			}
			for (int q = 0; q < argent.size(); q++)
			{
				argent.pop_back();
			}

			for (int q = 0; q < nv.size(); q++)
			{
				argent.push_back(nv[q]);
			}

		}
	}
	void revenir(vector<Sac_argent>& argent) {
		argent.push_back(*this);
	}
	Case getcarg() const {
		return carg;
	}


};
