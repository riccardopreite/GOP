#include "header.h"

Lista::Lista(){
  Start=NULL;
  c = Coda(3);
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

void Lista::SetGiocatore(Persona *g, int n, int n_caselle){
  int scarto;
  int res_duello, res_duello_2;
  bool duello=true;
  Dado d1 = Dado();
  Dado d2 = Dado();
  Giocatori player=Giocatori();
  if(Start == NULL){
    return;
  }
  Nodo *tmp = Start;
  Nodo *tmp2 = Start;
  Persona *giocatore;
  giocatore=g;
  while(tmp2 != NULL){
    if(tmp2->GetNome() == giocatore){
      tmp2->SetNome(NULL);
      break;
    }
    tmp2 = tmp2->GetSucc();
  }
  g->setCasella(g->getCasella()+n);
  if(g->getCasella()>n_caselle){
    scarto=g->getCasella()-n_caselle;
    cout<<"oh no! Sei andato oltre al limite del tabellone, devi tornare indietro di: "<<scarto<<" caselle!\n";
    g->setCasella(n_caselle-scarto);
  }
  while(tmp->GetSucc() != NULL){
    if(tmp->GetNum() == g->getCasella()){
      break;
    }
    tmp = tmp->GetSucc();
  }
//  giocatore=tmp->GetNome();
  //Trovare prima giocatore ed eliminare la posizione nel tabellone
  if(tmp->GetNome() == NULL){
    tmp->SetNome(g);
    //Controllare il tipo casella
    //return SetGiocatore(g,g->GetCasella)
  }else{
    giocatore=tmp->GetNome();
    while(duello==true){
    cout<<"E' ora del duello!\n"<<g->getNome()<<"Lancia i dadi!\n";
    if(getc(stdin) != 13){
      res_duello= d1.Tira() + d2.Tira();
      cout<<"Hai fatto: "<<res_duello<<endl;
    }
    cout<<"\nLancia i dadi!\n"<<giocatore->getNome()<<endl;
    if(getc(stdin) != 13){
      res_duello_2= d1.Tira() + d2.Tira();
      cout<<"Hai fatto: "<<res_duello_2<<endl;
    }
    if(res_duello>res_duello_2){
      cout<<"Ha vinto "<<g->getNome()<<endl;
    //  giocatore=player.search_player(g->getNome());
      res_duello_2=giocatore->getCasella()-res_duello_2;
      duello=false;
      giocatore->setCasella(res_duello_2);
    }
    else if(res_duello<res_duello_2){
      cout<<"Ha vinto "<<giocatore->getNome()<<endl;
      duello=false;
    //  giocatore=player.search_player(g->getNome());
      res_duello=g->getCasella()-res_duello;
      g->setCasella(res_duello);
    }
    else cout<<"Oh no! Avete fatto lo stesso risultato dovete combattere ancora!\n";
}
  }
}
