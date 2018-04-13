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
  cout<<"               _____________________________________________"<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |                  IMPREVISTI                 | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |_____________________________________________| "<<endl;
cout<<g->getNome()<<" Premi invio per pescare una carta\n";
    if(getc(stdin) != 13){

}
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

void deck::effect_0(Persona *g){
//  printf(" Oh no! Hai incontrato uno stregone.\n Se fai più di 6 puoi ritirare i dadi, altrimenti rimani fermo due turni\n" );    //parametro: puntatore al giocatore passato per indirizzo, modifico i campi in base all'effetto

  cout<<"               _____________________________________________"<<endl;
  cout<<"              |      Oh no! Hai incontrato uno stregone.    | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |     Se fai più di 6 puoi ritirare i dadi    | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |      altrimenti rimani fermo due turni      | "<<endl;
  cout<<"              |_____________________________________________| "<<endl;
  lancio=d1.Tira();
  cout<<"Hai fatto: "<<lancio<<endl;
  if(lancio>6){
    lancio=d1.Tira();
    cout<<g->getNome()<<" Vai avanti di: "<<lancio<<" caselle.\n";
    g->setCasella(g->getCasella()+lancio);
  }
  else {
    cout<<g->getNome()<<" Devi rimanere fermo 2 turni!\n";
    g->setstop(g->getstop() + 2);
  }
  return;
}
void deck::effect_1(Persona *g){

//  printf(" Una ninfa esce dall'acqua e ti regala la possibilità di rilanciare i dadi.\n" );
  cout<<"               _____________________________________________"<<endl;
  cout<<"              |         Una ninfa esce dall'acqua           | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |         e ti regala la possibilità          | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |            di rilanciare i dadi.            | "<<endl;
  cout<<"              |_____________________________________________| "<<endl;
  lancio=d1.Tira();
  cout<<"Prosegui di altre: "<<lancio<<" caselle"<<endl;
  g->setCasella(g->getCasella()+lancio);
  return;
}
void deck::effect_2(Persona *g){

//  printf(" Rilancia i dadi e vai avanti\n" );
  cout<<"               _____________________________________________"<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |        Rilancia i dadi e vai avanti.        | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |_____________________________________________| "<<endl;

  lancio=d1.Tira();
  cout<<"Vai avanti di: "<<lancio<<" caselle"<<endl;

  g->setCasella(g->getCasella()+lancio);
  return;
}
void deck::effect_3(Persona *g){

//  printf(" Rilancia i dadi e vai indietro\n" );
  cout<<"               _____________________________________________"<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |       Rilancia i dadi e vai indietro.       | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |_____________________________________________| "<<endl;
  lancio=d1.Tira();
  cout<<"Vai indietro di: "<<lancio<<" caselle"<<endl;

  g->setCasella(g->getCasella()-lancio);
  return;
}
void deck::effect_4(Persona *g){

//  printf(" AH! Sfigato! Devi rimanere fermo 3 turni!\n" );
  cout<<"               _____________________________________________"<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |                  AH! Sfigato!                | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |         Devi rimanere fermo 3 turni!        | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |_____________________________________________| "<<endl;
  g->setstop(g->getstop() + 3);

  return;
}
void deck::effect_5(){

//  printf(" Ti è andata bene! Questa volta non farai nulla.\n" );
  cout<<"               _____________________________________________"<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |               Ti è andata bene!             | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |       Questa volta non farai nulla.         | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |_____________________________________________| "<<endl;
  return;
}
void deck::effect_6(Persona *g){

//  printf(" Sei caduto nel pozzo e ti sei rotto una gamba!\n Fai almeno 5 per guarire altrimenti rimani lì per due turni.\n" );
  cout<<"               _____________________________________________"<<endl;
  cout<<"              |         Sei caduto nel pozzo e  ti sei      | "<<endl;
  cout<<"              |                rotto una gamba!             | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |      Fai almeno 5 per guarire altrimenti    | "<<endl;
  cout<<"              |           rimani lì per due turni.          | "<<endl;
  cout<<"              |_____________________________________________| "<<endl;
  lancio=d1.Tira();
  cout<<"Hai fatto: "<<lancio<<endl;

  if(lancio<5){
    cout<<"Devi rimanere fermo 2 turni!\n";
    g->setstop(g->getstop() + 2);
  }
  return;
}
void deck::effect_7(Persona *g){

//  printf(" Con questa magia potrai sconfiggere un mostro qualsiasi\n" );
  cout<<"               _____________________________________________"<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |     Con questa magia potrai sconfiggere     | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |            un mostro qualsiasi!             | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |_____________________________________________| "<<endl;
  g->setSconfiggi(true);
  return;
}
void deck::effect_8(Persona *g){

//  printf(" Ti perdi nella foresta nera. Impieghi due turni per uscire\n" );
  cout<<"               _____________________________________________"<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |         Ti perdi nella foresta nera.        | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |         Impieghi due turni per uscire       | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |_____________________________________________| "<<endl;
  g->setstop(g->getstop() + 2);
  return;
}
void deck::effect_9(Persona *g){

//  printf(" Sfigato! Ritorna al Via.\n" );
  cout<<"               _____________________________________________"<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |           Sfigato! Ritorna al Via.          | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |_____________________________________________| "<<endl;
  g->setCasella(0);
  return;
}
void deck::effect_10(Persona *g){

//  printf(" Vai avanti di 10 caselle!\n" );
  cout<<"               _____________________________________________"<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |          Vai avanti di 10 caselle!          | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |                                             | "<<endl;
  cout<<"              |_____________________________________________| "<<endl;
  g->setCasella(g->getCasella()+10);
  return;
}
