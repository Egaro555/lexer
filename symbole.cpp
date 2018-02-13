#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

void SYM_E_PLUS::Affiche() {
	SYM_E::Affiche();
	cout<<"(";
	E1->Affiche();
	cout<<"+";
	E2->Affiche();
	cout<<")";
}

void SYM_E_MULT::Affiche() {
	SYM_E::Affiche();
	cout<<"(";
	E1->Affiche();
	cout<<"+";
	E2->Affiche();
	cout<<")";
}

void SYM_E_PAR::Affiche() {
	SYM_E::Affiche();
	cout<<"([";
	E1->Affiche();
	cout<<"])";
}

void SYM_E_VAL::Affiche() {
	SYM_E::Affiche();
	cout<<"(";
	E->Affiche();
	cout<<")";
}

int Entier::getValue() {
	return valeur;
}

int SYM_E_PLUS::getValue() {
	return E1->getValue() + E2->getValue();
}

int SYM_E_MULT::getValue() {
	return E1->getValue() * E2->getValue();
}

int SYM_E_PAR::getValue() {
	return E1->getValue();
}

int SYM_E_VAL::getValue() {
	return E->getValue();
}
