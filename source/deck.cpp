//deck.cpp
#include "header.h"

deck::deck(){
  coda=Coda();
  coda=Coda(4);
  cont=0;
  d1=Dado();
  d2=Dado();
}


void deck::catch_card(Persona *g){
  bool check;
  do{
    srand(static_cast<unsigned int>(time(NULL)));
    n_card=(rand() % 109)+1;
    n_card=n_card/10;
    check=coda.Find(n_card);
  }
  while(check==true);
  if(this->cont>=4){
    coda.Shift2();
  }
  cont=coda.insert(n_card);
  call_effect(n_card, g);
  return;
}

void deck::call_effect(int n_card, Persona *g){

  if((n_card>=0)&&(n_card<=10)){

    switch(n_card){
      case 0:
      effect_0(g);
      break;
      case 1 :
      effect_1(g);
      break;
      case 2 :
      effect_2(g);
      break;
      case 3 :
      effect_3(g);
      break;
      case 4 :
      effect_4(g);
      break;
      case 5 :
      effect_5();
      break;
      case 6 :
      effect_6(g);
      break;
      case 7 :
      effect_7(g);
      break;
      case 8 :
      effect_8(g);
      break;
      case 9 :
      effect_9(g);
      break;
      case 10 :
      effect_10(g);
      break;
    }
  }

  return;
}

#if 0
bool deck::found(int n_card){
  bool check=false;
  for(int iq=3; iq>=0;iq--){
    if(queue[iq]==n_card){
      check=true;
      return check;
    }
  }
  return check;
}
void deck::edit_queue(){
  int jq=3;
  for(int iq=2; iq>=0;iq--){
    queue[jq]=queue[iq];
    jq--;
  }
  queue[0]=-1;
  return;
}
void deck::insert_queue(int n_card){
  if (this->cont<4){
    this->cont++;
  }
  for(int iq=3; iq>=0; iq--){
    if(queue[iq]==-1){
      queue[iq]=n_card;
      return;
    }
  }
  return;
}
void deck::stampa_queue(){
  for(int iq=3; iq>=0; iq-- ){
    cout<<" "<<queue[iq]<<" ";
  }
  cout<<endl;
}
#endif

void deck::effect_0(Persona *g){
  printf("Oh no! Hai incontrato uno stregone.\n Se fai più di 6 puoi ritirare i dadi, altrimenti rimani fermo due turni\n" );    //parametro: puntatore al giocatore passato per indirizzo, modifico i campi in base all'effetto

  lancio=d1.Tira() + d2.Tira();
  if(lancio>6){
  lancio=d1.Tira() + d2.Tira();
  cout<<"Hai fatto: "<<lancio<<endl;

  g->setCasella(g->getCasella()+lancio);
}
else {
g->setstop(g->getstop() + 2);
}
return;
}
void deck::effect_1(Persona *g){
  printf("Una ninfa esce dall'acqua e ti regala la possibilità di rilanciare i dadi.\n" );
  lancio=d1.Tira() + d2.Tira();
  cout<<"Hai fatto: "<<lancio<<endl;
  g->setCasella(g->getCasella()+lancio);
  return;
}
void deck::effect_2(Persona *g){
  printf("Rilancia i dadi e vai avanti\n" );
  lancio=d1.Tira() + d2.Tira();
  cout<<"Hai fatto: "<<lancio<<endl;

  g->setCasella(g->getCasella()+lancio);
  return;
}
void deck::effect_3(Persona *g){
  printf("Rilancia i dadi e vai indietro\n" );
  lancio=d1.Tira() + d2.Tira();
  cout<<"Hai fatto: "<<lancio<<endl;

  g->setCasella(g->getCasella()-lancio);
  return;
}
void deck::effect_4(Persona *g){
  printf("AH! Sfigato! Devi rimanere fermo 3 turni!\n" );
  g->setstop(g->getstop() + 3);

  return;
}
void deck::effect_5(){
  printf("Ti è andata bene! Questa volta non farai nulla.\n" );
  return;
}
void deck::effect_6(Persona *g){
  printf("Sei caduto nel pozzo e ti sei rotto una gamba!\n Fai 5 per guarire altrimenti rimani lì per due turni.\n" );
  lancio=d1.Tira() + d2.Tira();
  cout<<"Hai fatto: "<<lancio<<endl;

  if(lancio!=5){
  g->setstop(g->getstop() + 2);
}
return;
}
void deck::effect_7(Persona *g){
  printf("Con questa magia potrai sconfiggere un mostro qualsiasi\n" );
  g->setSconfiggi(true);
  return;
}
void deck::effect_8(Persona *g){
  printf("Ti perdi nella foresta nera. Impieghi due turni per uscire\n" );
  g->setstop(g->getstop() + 2);
  return;
}
void deck::effect_9(Persona *g){
  printf("Sfigato! Ritorna al Via.\n" );
  g->setCasella(0);
  return;
}
void deck::effect_10(Persona *g){
  printf("Vai avanti di 10 caselle!\n" );
  g->setCasella(g->getCasella()+10);
  return;
}
