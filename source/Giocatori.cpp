/*
 * Giocatori.cpp
 *
 *  Created on: 09 mar 2018
 *      Author: xxxx
 */

 #include "header.h"

Giocatori::Giocatori(){
	head = NULL;
	next = NULL;
}
Giocatori::~Giocatori(){}

void Giocatori::aggiungi_giocatore(string nome){
		Persona *tmp = head;
		Persona *tmp2;
		if(head == NULL){
			head = new Persona;
			head->Persona::setNome(nome);
			head->Persona::setCasella(0);
      head->setNext(NULL);
			next = head;
		}
		else{
			while(tmp->getNext() != NULL){
				tmp = tmp->getNext();
			}
			tmp2 = new Persona;
			tmp2->setNext(NULL);
			tmp2->setNome(nome);
			tmp2->setCasella(0);
			tmp->setNext(tmp2);
		}
	}

Persona *Giocatori::search_player(string nome){
  Persona *tmp=head;
  while(tmp!=NULL){
    if(tmp->getNome()==nome){
      cout<<"Giocatore trovato!";
      return tmp;
    }
tmp=tmp->getNext();
  }

}

void Giocatori::stampa_giocatore(Persona *c){
  Persona *tmp= c;
		cout << tmp->getNome()<<"\n";
}
Persona *Giocatori::Set_first(){
  return head;
}
Persona *Giocatori::player_turn(Persona *c){
Persona *tmp= c;
	if(tmp->getNext()==NULL){
	return this->head;
	}
   else tmp=tmp->getNext();
   return tmp;

}
