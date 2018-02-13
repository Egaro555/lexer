#include <iostream>
#include "lexer.h"


int main(void) {
	string chaine("(1+34)*123+65*123");

	Automate automate;

	Lexer l(chaine);

	Symbole * s;
	do{
		s=l.Consulter();
		automate.transition(s);
		cout << "Ajout de  : ";
		s->Affiche();
		cout<<endl;
		automate.afficher();
		cout<<endl;

		l.Avancer();
	}while(*s!=FIN);
	return 0;
}

