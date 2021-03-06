
#include "header.h"

Giocatori::Giocatori(){
  head = NULL;
}
Giocatori::~Giocatori(){}


Persona *Giocatori::scegli_primo(){
  Persona *tmp = head;
  Persona *max;
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
  max = head;
  tmp = max->getNext();
  bool check = false;
  while(tmp != NULL){
    if(tmp->getValDadoInit() != -1){
      if(tmp->getValDadoInit() > max->getValDadoInit()){
        max->setValDadoInit(-1);
        max = tmp;
      }
      else if(tmp->getValDadoInit() == max->getValDadoInit()){
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
    cout<<"\n\nInizia il giocatore: "<<max->getNome();
    return max;
  }else{
    return scegli_primo();
  }
}

void Giocatori::aggiungi_giocatore(string nome){
  bool found=true;
  string colore;
  Dado d1=Dado();
  Persona *tmp = head;
  Persona *tmp2;
  if(head == NULL){
    cout<<"\ninserisci un numero da 31 a 37 per scegliere un colore.\n";
    printf("%sRED:31%s\n%sGREEN:32%s\n%sYELLOW:33%s\n%sBLUE:34%s\n%sPINK:35%s\n%sSKY:36%s\n%sWHITE:37%s\n",COL(31),COL_CLEAR,COL(32),COL_CLEAR,COL(33),COL_CLEAR,COL(34),COL_CLEAR,COL(35),COL_CLEAR,COL(36),COL_CLEAR,COL(37),COL_CLEAR );
    cin>>colore;
    while((colore<"31")||(colore>"37")){
      cout<<"\ninserisci un numero da 31 a 37 per scegliere un colore.\n";
      printf("%sRED:31%s\n%sGREEN:32%s\n%sYELLOW:33%s\n%sBLUE:34%s\n%sPINK:35%s\n%sSKY:36%s\n%sWHITE:37%s\n",COL(31),COL_CLEAR,COL(32),COL_CLEAR,COL(33),COL_CLEAR,COL(34),COL_CLEAR,COL(35),COL_CLEAR,COL(36),COL_CLEAR,COL(37),COL_CLEAR );
      cin>>colore;
      }

    head = new Persona;
    head->Persona::setNome(nome);
    head->Persona::setCasella(0);
    head->Persona::setColore(colore);
    head->setNext(NULL);
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
    while((colore<"31")||(colore>"37")){
      cout<<"\ninserisci un numero da 31 a 37 per scegliere un colore.\n";
      printf("%sRED:31%s\n%sGREEN:32%s\n%sYELLOW:33%s\n%sBLUE:34%s\n%sPINK:35%s\n%sSKY:36%s\n%sWHITE:37%s\n",COL(31),COL_CLEAR,COL(32),COL_CLEAR,COL(33),COL_CLEAR,COL(34),COL_CLEAR,COL(35),COL_CLEAR,COL(36),COL_CLEAR,COL(37),COL_CLEAR );
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
  string nome;
  while(tmp!=NULL){
    nome=tmp->getNome();
    if(tmp->getCasella()==0){
      printf("%s",COL(31));
      cout<<nome;
      printf(" è nella posizione %d%s\n", tmp->getCasella(), COL_CLEAR );
    }
    else{
      printf("%s",COL(36));
      cout<<nome;
      printf(" è nella posizione %d%s\n", tmp->getCasella(), COL_CLEAR );
    }
    tmp=tmp->getNext();
  }
}

Persona *Giocatori::return_head(){
  return this->head;
}

Persona *Giocatori::player_turn(Persona *c){
  Persona *tmp= c;
  if(tmp->getNext()==NULL){
    return this->head;
  }
  else tmp=tmp->getNext();
  return tmp;

}
