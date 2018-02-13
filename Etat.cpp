/*
 * Etat.cpp
 *
 *  Created on: 13 févr. 2018
 *      Author: hmartin2
 */

#include "Etat.h"

void Etat::print() const {
	cout << name;
}

/*
	automate.decalage(s, new E2);
 */

/*
	automate.putSymbol(s); // LR(1), on ne consomme pas ce symbole
	Expr * s1 = (Expr*) automate.popSymbol();
	automate.popAndDestroySymbol();
	Expr * s2 = (Expr*) automate.popSymbol();
	automate.reduction(3,new ExprPlus(s2,s1));
 */

/*
	switch (*s){
		case INT:
			break;
		case PLUS:
			break;
		case MULT:
			break;
		case OPENPAR:
			break;
		case CLOSEPAR:
			break;
		case FIN:
			break;
		case IDE_E:
			break;
		default:
			return false;
	}
	return true;
*/


bool E0::transition(Automate& automate, Symbole* next) {
	switch (*next){
		case INT:
			automate.decalage(next, new E3);
			break;
		case OPENPAR:
			automate.decalage(next, new E2);
			break;
		case IDE_E:
			automate.decalage(next, new E1);
			break;
		default:
			return false;
	}
	return true;
}

bool E1::transition(Automate& automate, Symbole* next) {
	switch (*next){
		case PLUS:
			automate.decalage(next, new E4);
			break;
		case MULT:
			automate.decalage(next, new E5);
			break;
		case FIN:
			automate.accepter();
			break;
		default:
			return false;
	}
	return true;
}

bool E2::transition(Automate& automate, Symbole* next) {
	switch (*next){
		case INT:
			automate.decalage(next, new E3);
			break;
		case OPENPAR:
			automate.decalage(next, new E2);
			break;
		case IDE_E:
			automate.decalage(next, new E6);
			break;
		default:
			return false;
	}
	return true;
}

bool E3::transition(Automate& automate, Symbole* next) {
	Entier * sEn;
	switch (*next){
		case PLUS:
		case MULT:
		case CLOSEPAR:
		case FIN:
			// R5 E -> Val
			sEn = (Entier*) automate.popSymbol();
			automate.reduction(1,new SYM_E_VAL(sEn),next);
			break;
		default:
			return false;
	}
	return true;
}

bool E4::transition(Automate& automate, Symbole* next) {
	switch (*next){
		case INT:
			automate.decalage(next, new E3);
		break;
		case OPENPAR:
			automate.decalage(next, new E2);
			break;
		case IDE_E:
			automate.decalage(next, new E7);
			break;
		default:
			return false;
	}
	return true;
}

bool E5::transition(Automate& automate, Symbole* next) {
	switch (*next){
		case INT:
			automate.decalage(next, new E3);
			break;
		case OPENPAR:
			automate.decalage(next, new E2);
			break;
		case IDE_E:
			automate.decalage(next, new E8);
			break;
		default:
			return false;
	}
	return true;
}

bool E6::transition(Automate& automate, Symbole* next) {
	switch (*next){
		case PLUS:
			automate.decalage(next, new E4);
			break;
		case MULT:
			automate.decalage(next, new E5);
			break;
		case CLOSEPAR:
			automate.decalage(next, new E9);
			break;
		default:
			return false;
	}
	return true;
}

bool E7::transition(Automate& automate, Symbole* next) {
	SYM_E* s1, * s2;
	switch (*next){
		case MULT:
			automate.decalage(next, new E5);
			break;
		case PLUS:
		case CLOSEPAR:
		case FIN:
			//R2 E -> E + E
			s2 = (SYM_E*) automate.popSymbol();
			delete (automate.popSymbol()); // remove symbole +
			s1 = (SYM_E*) automate.popSymbol();
			automate.reduction(3,new SYM_E_PLUS(s1,s2),next);
			break;
		default:
			return false;
	}
	return true;
}

bool E8::transition(Automate& automate, Symbole* next) {
	SYM_E* s1, * s2;
	switch (*next){
		case PLUS:
		case MULT:
		case CLOSEPAR:
		case FIN:
			//R3 E -> E * E
			s2 = (SYM_E*) automate.popSymbol();
			delete (automate.popSymbol()); // remove symbole +
			s1 = (SYM_E*) automate.popSymbol();
			automate.reduction(3,new SYM_E_MULT(s1,s2),next);
			break;
		default:
			return false;
	}
	return true;
}

bool E9::transition(Automate& automate, Symbole* next) {
	SYM_E* se;
	switch (*next){
		case PLUS:
		case MULT:
		case CLOSEPAR:
		case FIN:
			//R4 E -> ( E )
			delete (automate.popSymbol()); // remove symbole )
			se = (SYM_E*) automate.popSymbol();
			delete (automate.popSymbol()); // remove symbole (
			automate.reduction(3,new SYM_E_PAR(se),next);
			break;
		default:
			return false;
	}
	return true;
}
