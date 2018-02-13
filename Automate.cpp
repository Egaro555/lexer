/*
 * Automate.cpp
 *
 *  Created on: 13 févr. 2018
 *      Author: hmartin2
 */

#include "Automate.h"

Automate::Automate(){
	statestack.push_back(new E0);
}


void Automate::decalage(Symbole * s, Etat * e) {
	symbolstack.push_back(s);
	statestack.push_back(e);
}

void Automate::reduction(int n,Symbole * symRedui,Symbole * next) {
	for (int i=0;i<n;i++){
		delete(statestack.back());
		statestack.pop_back();
	}

	transition(symRedui);
	transition(next);
}
void Automate::accepter(){
	cout << "ACCEPTED";
}
void Automate::transition(Symbole* next){
	statestack.back()->transition(*this, next);
}
void Automate::afficher(){
	bool f = true;

	cout << "Automate : {" << endl;
	cout << "\tstateStack : [" << endl;
	for(Etat* e : statestack){
		if(f)
			f = false;
		else
			cout << ", ";
		cout<<"\"";
		e->print();
		cout<<"\"";
	}
	cout << "]," << endl << "\tsymbolstack ["<<endl;
	f=true;
	for(Symbole* s : symbolstack){
		if(f)
			f = false;
		else
			cout << ","<<endl;
		cout<<"\t\t\"";
		s->Affiche();
		cout<<"\"";
		if(*s == IDE_E){
			cout << ", "<<((SYM_E*) s)->getValue();
		}else if(*s == INT){
			cout << ", "<<((Entier*) s)->getValue();
		}
	}
	cout << endl << "\t]"<<endl<<"}"<<endl;
}

Symbole* Automate::popSymbol() {
	Symbole* res = symbolstack.back();
	symbolstack.pop_back();
	return res;
}
