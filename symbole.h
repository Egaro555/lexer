#pragma once


#ifndef SYMBOLE_H_
#define SYMBOLE_H_


#include <string>
#include "Automate.h"

using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, IDE_E };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "E" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      virtual int getValue();
   protected:
      int valeur;
};

class SYM_E: public Symbole {
	public:
		SYM_E():Symbole(IDE_E){}
		virtual ~SYM_E(){}
	    virtual int getValue() = 0;
	protected:
};

class SYM_E_PLUS: public SYM_E{
	protected:
		SYM_E* E1, *E2;
	public:
		SYM_E_PLUS(SYM_E* E1_,SYM_E* E2_):SYM_E(),E1(E1_),E2(E2_){}
		virtual ~SYM_E_PLUS(){}
		void Affiche();
	    virtual int getValue();
};

class SYM_E_MULT: public SYM_E{
	protected:
		SYM_E* E1, *E2;
	public:
		SYM_E_MULT(SYM_E* E1_,SYM_E* E2_):E1(E1_),E2(E2_){}
		virtual ~SYM_E_MULT(){}
		void Affiche();
	    virtual int getValue();
};

class SYM_E_PAR: public SYM_E{
	protected:
		SYM_E* E1;
	public:
		SYM_E_PAR(SYM_E* E1_):E1(E1_){}
		virtual ~SYM_E_PAR(){}
		void Affiche();
	    virtual int getValue();
};
class SYM_E_VAL: public SYM_E{
protected:
	Entier* E;
	public:
		SYM_E_VAL(Entier* E_):E(E_){}
		virtual ~SYM_E_VAL(){}
		void Affiche();
	    virtual int getValue();
};

#endif




