/*
 * Automate.h
 *
 *  Created on: 13 févr. 2018
 *      Author: hmartin2
 */


#ifndef AUTOMATE_H_
#define AUTOMATE_H_

#include <list>
#include "symbole.h"
class Symbole;
#include "Etat.h"
class Etat;

using namespace std;

class Automate {
protected:
	list<Symbole *> symbolstack;
	list<Etat *> statestack;


public:
	Automate();
	virtual ~Automate(){}

	void decalage(Symbole* s, Etat* e);
	void reduction(int n,Symbole * symRedui,Symbole * next);
	void accepter();
	void transition(Symbole* next);
	void afficher();
	Symbole* popSymbol();
};

#endif /* AUTOMATE_H_ */
