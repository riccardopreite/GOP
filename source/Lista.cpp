#include "header.h"

Lista::Lista(){
  Start=NULL;
  c = Coda(4);
  card=deck();
}

Lista::~Lista(){
}

void Lista::AddFront(Nodo *nuovo){
  Start=nuovo;
}

//prendi random casella, vedi se in quelle adiacenti sono di diverso tipo,altrimenti ti blocchi




int Lista::GetType(){
  int val = (rand() % 10 )+1;
  if(c.Find(val)==1){
    return GetType();
  }
  c.Shift(val);
  return val;
}

void Lista::Append(int n)
{
  int tipo = GetType();
  Nodo *nuovo = new Nodo;
  nuovo->SetSucc(NULL);
  nuovo->SetNome(NULL);
  nuovo->SetNum(n);
  nuovo->SetType(tipo);

  if(Start == NULL){
    AddFront(nuovo);
    return;
  }
  Nodo *scor=Start;

  while(scor->GetSucc()!= NULL){
    scor = scor->GetSucc();
  }
  scor->SetSucc(nuovo);
}

void Lista::Visualizza()
{
  Nodo *scor=Start;

  if(Start==NULL){
    cout<<"Non ci sono valori nella lista\n";
    return;
  }

  cout<<"I Valori sono: \n";

  while(scor!=NULL){
    cout<<scor->GetNum()<<" "<<scor->GetNome()<<" "<<scor->GetType()<<endl;
    scor=scor->GetSucc();
  }
}

void Lista::SetGiocatore(Persona *giocatore, int n, int n_caselle){
  int scarto;
  if(Start == NULL){
    return;
  }
  Nodo *tmp = Start;
  Nodo *tmp2 = Start;
  Persona *giocatore2;
  giocatore2=giocatore;
  while(tmp2 != NULL){
    if(tmp2->GetNome() == giocatore2){
      tmp2->SetNome(NULL);
      break;
    }
    tmp2 = tmp2->GetSucc();
  }
  giocatore->setCasella(giocatore->getCasella()+n);
  if(giocatore->getCasella()>n_caselle){
    scarto=giocatore->getCasella()-n_caselle;
    cout<<"oh no! Sei andato oltre al limite del tabellone, devi tornare indietro di: "<<scarto<<" caselle!\n";
    giocatore->setCasella(n_caselle-scarto);
  }
  while(tmp->GetSucc() != NULL){
    if(tmp->GetNum() == giocatore->getCasella()){
      break;
    }
    tmp = tmp->GetSucc();
  }
//  giocatore=tmp->GetNome();
  //Trovare prima giocatore ed eliminare la posizione nel tabellone
  if(tmp->GetNome() == NULL){
    tmp->SetNome(giocatore);
    switch(tmp->GetType()){
      case 1:
      card.catch_card(giocatore);
      break;
      case 2:
      card.catch_card(giocatore);
      break;
      case 3:
      card.catch_card(giocatore);
      break;
      case 4:
      card.catch_card(giocatore);
      break;
      case 5:
      card.catch_card(giocatore);
      break;
    }
    //Controllare il tipo casella
    //return SetGiocatore(g,g->GetCasella)
  }else{
    giocatore=tmp->GetNome();
    duello(giocatore,giocatore2);
  }
}

void Lista::duello(Persona *giocatore, Persona* giocatore2){
  bool duello=true;
  int res_duello, res_duello_2;
  Dado d1 = Dado();
  Dado d2 = Dado();
  while(duello==true){
  cout<<"E' ora del duello!\n"<<giocatore->getNome()<<"Lancia i dadi!\n";
  if(getc(stdin) != 13){
    res_duello= d1.Tira() + d2.Tira();
    cout<<"Hai fatto: "<<res_duello<<endl;
  }
  cout<<"\nLancia i dadi!\n"<<giocatore2->getNome()<<endl;
  if(getc(stdin) != 13){
    res_duello_2= d1.Tira() + d2.Tira();
    cout<<"Hai fatto: "<<res_duello_2<<endl;
  }
  if(res_duello>res_duello_2){
    cout<<"Ha vinto "<<giocatore->getNome()<<endl;
    res_duello_2=giocatore2->getCasella()-res_duello_2;
    duello=false;
    giocatore2->setCasella(res_duello_2);
  }
  else if(res_duello<res_duello_2){
    cout<<"Ha vinto "<<giocatore2->getNome()<<endl;
    duello=false;
    res_duello=giocatore->getCasella()-res_duello;
    giocatore->setCasella(res_duello);
  }
  else cout<<"Oh no! Avete fatto lo stesso risultato dovete combattere ancora!\n";
}
cout<<"\nOra "<<giocatore2->getNome()<<" è nella casella "<<giocatore2->getCasella()<<endl;
cout<<"Ora "<<giocatore->getNome()<<" è nella casella "<<giocatore->getCasella()<<endl;

}
