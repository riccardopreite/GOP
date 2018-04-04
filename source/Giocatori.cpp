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

void Giocatori::stampa_posizione(){
  Persona *tmp=head;
  while(tmp!=NULL){
    cout<<endl<<tmp->getNome()<<" è nella poszione: "<<tmp->getCasella()<<endl;
    tmp=tmp->getNext();
  }
}

Persona *Giocatori::Set_first(int n_giocatori){
  int first;
  Persona *tmp=head;
  n_giocatori=n_giocatori*100;
  first=(rand() % n_giocatori) +1;
  first=first/100;
  cout<<"\nInizia il "<<first<<"giocatore\n";
  while(first>0){
    if(tmp==NULL){
      tmp=head;
    }
    tmp=tmp->getNext();
    first--;
  }
  cout<<tmp->getNome()<<" è il tuo turno!\n";
  return tmp;
}
Persona *Giocatori::player_turn(Persona *c){
  Persona *tmp= c;
  if(tmp->getNext()==NULL){
    return this->head;
  }
  else tmp=tmp->getNext();
  return tmp;

}
