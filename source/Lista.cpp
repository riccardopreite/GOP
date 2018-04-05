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

// da 1 a 25 vuote, il resto mostri
//0 è vuota
//1 è mezzo
//2 è mostro
//3 è oggetto
//4 è luoghi
//5 è pesca carta
int Lista::GetType(){
	int val = (rand()%100)+1;
	if(val>=1 && val<=25){ //caselle vuote
		if(c.Find(0)==1){
			return GetType();
		}
		c.Shift(0);
		return 0;
	}
	if(val>=26 && val<=34){ //caselle luoghi
		if(c.Find(4)==1){
			return GetType();
		}
		c.Shift(4);
		return 4;
	}
	if(val>=35 && val<=42){ //caselle mezzi
		if(c.Find(1)==1){
			return GetType();
		}
		c.Shift(1);
		return 1;
	}
	if(val>=43 && val<=78){ //caselle mostri
		if(c.Find(2)==1){
			return GetType();
		}
		c.Shift(2);
		return 2;
	}
	if(val>=79 && val<=92){ //caselle oggetti
		if(c.Find(3)==1){
			return GetType();
		}
		c.Shift(3);
		return 3;
	}
	if(val>=93 && val<=100){ //caselle pesca
		if(c.Find(5)==1){
			return GetType();
		}
		c.Shift(5);
		return 5;
	}
}




void Lista::Append(int n)
{
  Nodo *nuovo = new Nodo;
  nuovo->SetSucc(NULL);
  nuovo->SetNome(NULL);
  nuovo->SetNum(n);
  if(n==0){
    nuovo->SetType(0);
  }
   else nuovo->SetType(GetType());

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
  if(tmp->GetNome() == NULL){
    tmp->SetNome(giocatore);
    get_effect(giocatore, tmp);
  }
  else{
    giocatore2=tmp->GetNome();
    if(giocatore2->getNome()!=giocatore->getNome()){
      duello(giocatore,giocatore2);
    }
  }
}

void Lista::get_effect(Persona *giocatore, Nodo *tmp){
  Persona *giocatore2;
  switch(tmp->GetType()){
    case 0:
    break;
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
    #if 0
    #endif

  }
  while(tmp->GetSucc() != NULL){
    if(tmp->GetNum() == giocatore->getCasella()){
      break;
    }
    tmp = tmp->GetSucc();
  }
  if(tmp->GetNome() == NULL){
    tmp->SetNome(giocatore);
    get_effect(giocatore,tmp);
  }
  else{
    giocatore2=tmp->GetNome();
    if(giocatore2->getNome()!=giocatore->getNome()){
      duello(giocatore,giocatore2);
      //  cout<<"\nOra "<<giocatore2->getNome()<<" è nella casella "<<giocatore2->getCasella()<<endl;
      //  cout<<"Ora "<<giocatore->getNome()<<" è nella casella "<<giocatore->getCasella()<<endl;

    }
  }

  return;
}


void Lista::duello(Persona *giocatore, Persona* giocatore2){
  bool duello=true;
  if(giocatore->getCasella()==0){
    return;
  }
  int res_duello, res_duello_2;
  Dado d1 = Dado();
  Dado d2 = Dado();
  Nodo *tmp = Start;
  Nodo *tmp2 = Start;
  while(duello==true){
    cout<<"E' ora del duello!\n"<<giocatore->getNome()<<" Lancia i dadi!\n";
    if(getc(stdin) != 13){
      res_duello= d1.Tira() + d2.Tira();
      cout<<"Hai fatto: "<<res_duello<<endl;
    }
    cout<<giocatore2->getNome()<<" Lancia i dadi!\n"<<endl;
    if(getc(stdin) != 13){
      res_duello_2= d1.Tira() + d2.Tira();
      cout<<"Hai fatto: "<<res_duello_2<<endl;
    }
    if(res_duello>res_duello_2){
      cout<<"Ha vinto "<<giocatore->getNome()<<endl;
      res_duello_2=giocatore2->getCasella()-res_duello_2;
      duello=false;
      giocatore2->setCasella(res_duello_2);
      tmp=Start;
      tmp2=Start;
      while(tmp2->GetSucc() != NULL){
        if(tmp2->GetNum() == giocatore->getCasella()){
          break;
        }
        tmp2 = tmp2->GetSucc();
      }
      if(tmp2->GetNome() == NULL){
        tmp2->SetNome(giocatore);
        get_effect(giocatore,tmp2);
      }
      while(tmp->GetSucc() != NULL){
        if(tmp->GetNum() == giocatore2->getCasella()){
          break;
        }
        tmp = tmp->GetSucc();
      }
      if(tmp->GetNome() == NULL){
        tmp->SetNome(giocatore2);
        get_effect(giocatore2,tmp);
      }
      else{
        giocatore=tmp->GetNome();
        if(giocatore2->getNome()!=giocatore->getNome()){
          Lista::duello(giocatore,giocatore2);
        }
      }
    }
    else if(res_duello<res_duello_2){
      cout<<"Ha vinto "<<giocatore2->getNome()<<endl;
      duello=false;
      res_duello=giocatore->getCasella()-res_duello;
      giocatore->setCasella(res_duello);
      tmp=Start;
      tmp2=Start;

      while(tmp2->GetSucc() != NULL){
        if(tmp2->GetNum() == giocatore2->getCasella()){
          break;
        }
        tmp2 = tmp2->GetSucc();
      }
      if(tmp2->GetNome() == NULL){
        tmp2->SetNome(giocatore2);
        get_effect(giocatore2,tmp2);
      }

      while(tmp->GetSucc() != NULL){
        if(tmp->GetNum() == giocatore->getCasella()){
          break;
        }
        tmp = tmp->GetSucc();
      }
      if(tmp->GetNome() == NULL){
        tmp->SetNome(giocatore);
        get_effect(giocatore,tmp);
      }
      else{
        giocatore2=tmp->GetNome();
        if(giocatore2->getNome()!=giocatore->getNome()){
          Lista::duello(giocatore,giocatore2);
        }
      }

    }
    else cout<<"Oh no! Avete fatto lo stesso risultato dovete combattere ancora!\n";
  }

}
