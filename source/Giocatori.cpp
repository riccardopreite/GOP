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


Persona *Giocatori::scegli_primo(){
  Persona *tmp = head;
  Dado d1 = Dado();
  int lancio,x;
  if(tmp == NULL){
    return NULL;
  }
  while(tmp != NULL){
    if(tmp->getValDadoInit() != -1){
      cout<<"\n\nTocca al giocatore "<<tmp->getNome()<<"\nPremi invio per tirare il dado\n";
      lancio = d1.Tira();
      cout<<"Hai totalizzato: "<<lancio;
      tmp->setValDadoInit(lancio);
    }
    tmp = tmp->getNext();
  }
  tmp = head;
  Persona *tmp2 = tmp;
  tmp = tmp->getNext();
  bool check = false;
  while(tmp != NULL){
    if(tmp->getValDadoInit() != -1){
      if(tmp->getValDadoInit() > tmp2->getValDadoInit()){
        tmp2->setValDadoInit(-1);
        tmp2 = tmp;
      }
      else if(tmp->getValDadoInit() == tmp2->getValDadoInit()){
      }
      else{
        tmp->setValDadoInit(-1);
      }
    }
    tmp = tmp->getNext();
  }

  x =0;
  tmp = head;

  while(tmp!= NULL){
    if(tmp->getValDadoInit() != -1){
      x = x +1;
    }
    tmp = tmp->getNext();
  }
  if( x == 1){
    cout<<"\n\nInizia il giocatore: "<<tmp2->getNome();
    next = tmp2;
    return next;
  }else{
    return scegli_primo();
  }
}

void Giocatori::aggiungi_giocatore(string nome){
  bool found=true;
  int colore;
  Dado d1=Dado();
  Persona *tmp = head;
  Persona *tmp2;
  if(head == NULL){
    cout<<"\ninserisci un numero da 31 a 37 per scegliere un colore.\n";
    printf("%sRED:31%s\n%sGREEN:32%s\n%sYELLOW:33%s\n%sBLUE:34%s\n%sPINK:35%s\n%sSKY:36%s\n%sWHITE:37%s\n",COL(31),COL_CLEAR,COL(32),COL_CLEAR,COL(33),COL_CLEAR,COL(34),COL_CLEAR,COL(35),COL_CLEAR,COL(36),COL_CLEAR,COL(37),COL_CLEAR );
    cin>>colore;
    while((!cin.good())||((colore<=31)||(colore>=37))){
      if(cin.good()){
        if((colore>=31)&&(colore<=37)){
          break;
        }
      }
      cout<<"\ninserisci un numero da 31 a 37 per scegliere un colore.\n";
      printf("%sRED:31%s\n%sGREEN:32%s\n%sYELLOW:33%s\n%sBLUE:34%s\n%sPINK:35%s\n%sSKY:36%s\n%sWHITE:37%s\n",COL(31),COL_CLEAR,COL(32),COL_CLEAR,COL(33),COL_CLEAR,COL(34),COL_CLEAR,COL(35),COL_CLEAR,COL(36),COL_CLEAR,COL(37),COL_CLEAR );
      d1.err_input();
      cin>>colore;
    }
    head = new Persona;
    head->Persona::setNome(nome);
    head->Persona::setCasella(0);
    head->Persona::setColore(colore);
    head->setNext(NULL);
    next = head;
  }
  else{
    while(found==true){
      tmp=head;
      while(tmp!=NULL){
        if(tmp->getNome()==nome){
          cout<<"Questo nome è stato già scelto da un altro giocatore, per favore scegline un altro!\n";
          cin>>nome;
          cout<<endl;
          found=true;
          break;
        }
        else if(tmp->getNome()!=nome){
          tmp=tmp->getNext();
          found=false;
        }
      }
    }
    cout<<"\ninserisci un numero da 31 a 37 per scegliere un colore.\n";
    printf("%sRED:31%s\n%sGREEN:32%s\n%sYELLOW:33%s\n%sBLUE:34%s\n%sPINK:35%s\n%sSKY:36%s\n%sWHITE:37%s\n",COL(31),COL_CLEAR,COL(32),COL_CLEAR,COL(33),COL_CLEAR,COL(34),COL_CLEAR,COL(35),COL_CLEAR,COL(36),COL_CLEAR,COL(37),COL_CLEAR );
    cin>>colore;
    while((!cin.good())||((colore<=31)||(colore>=37))){
      if(cin.good()){
        if((colore>=31)&&(colore<=37)){
          break;
        }
      }
      cout<<"\ninserisci un numero da 31 a 37 per scegliere un colore.\n";
      printf("%sRED:31%s\n%sGREEN:32%s\n%sYELLOW:33%s\n%sBLUE:34%s\n%sPINK:35%s\n%sSKY:36%s\n%sWHITE:37%s\n",COL(31),COL_CLEAR,COL(32),COL_CLEAR,COL(33),COL_CLEAR,COL(34),COL_CLEAR,COL(35),COL_CLEAR,COL(36),COL_CLEAR,COL(37),COL_CLEAR );
      d1.err_input();
      cin>>colore;
    }
    tmp=head;
    while(tmp->getNext() != NULL){
      tmp = tmp->getNext();

    }
    tmp2 = new Persona;
    tmp2->setNext(NULL);
    tmp2->setNome(nome);
    tmp2->setCasella(0);
    tmp2->setColore(colore);
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
  cout << tmp->getNome();
}

void Giocatori::stampa_posizione(){
  Persona *tmp=head;
  while(tmp!=NULL){
    cout<<endl<<tmp->getNome()<<" è nella posizione: "<<tmp->getCasella()<<endl;
    tmp=tmp->getNext();
  }
}

Persona *Giocatori::return_head(){
  return this->head;
}

#if 0
Persona *Giocatori::Set_first(int n_giocatori){
int first;
Persona *tmp=head;
n_giocatori=n_giocatori*100;
first=(rand() % n_giocatori) +1;
first=first/100;
while(first>0){
if(tmp==NULL){
tmp=head;
}
tmp=tmp->getNext();
first--;
}
cout<<"\nInizia "<<tmp->getNome()<<endl;
return tmp;
}
#endif
Persona *Giocatori::player_turn(Persona *c){
  Persona *tmp= c;
  if(tmp->getNext()==NULL){
    return this->head;
  }
  else tmp=tmp->getNext();
  return tmp;

}
