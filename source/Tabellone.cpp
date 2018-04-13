#include "header.h"

Tabellone::Tabellone(){
  Start=NULL;
  c = Coda(4);
  card=deck();
  player=Giocatori();
  t=Type();
  cont=0;
}

Tabellone::~Tabellone(){
}


void Tabellone::set_cont(int n_caselle){
  if(n_caselle>=40 && n_caselle<75){
    this->cont=2;
  }
  else if(n_caselle>=75 && n_caselle<=90){
    this->cont=3;
  }
}
void Tabellone::AddFront(Nodo *nuovo){
  Start=nuovo;
}
#if 0
prendi random casella, vedi se in quelle adiacenti sono di diverso tipo,altrimenti ti blocchi

<<<<<<< HEAD
da 1 a 25 vuote, il resto mostri
0 PICCHIA IL PORTAPIZZE
--------
1 CAVALLO
2 DRAGO              MEZZI
3 CAROVANA
-------
4 GOBLIN
5 LUPO
6 ORCO
7 TROLL
8 SPIRITO            MOSTRI
9 VAMPIRO
10 BASILISCO
11 MANGIANIME
12 CAVALIERE NERO
--------
13 DIRUPO
14 LANDE DI GHIACCIO
15 SCORCIATOIA
16 VULCANO                      LUOGHI
17 FORESTA DELLE ILLUSIONI
18 POZZO DELLOBLIO
---------
19 ALI DELLANGELO
20 SPADA SCACCIADEMONI
21 SPINTA DIVINA                OGGETTI
22 INSTANCABILE
23 LANCIO DELEROE
---------
24 PESCA CARTE



#endif
//prendi random casella, vedi se in quelle adiacenti sono di diverso tipo,altrimenti ti blocchi

// da 1 a 25 vuote, il resto mostri
//0 è vuota
//1 è mezzo
//2 è mostro
//3 è oggetto
//4 è luoghi
//5 è pesca carta
int Tabellone::GetType(){
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
    while(true){
      int val = (rand()%600);
      val=val/10;
      if(val>=0 && val<=9){
        return 13; //dirupo
      }
      else if(val>=10 && val<=19){
        return 14; //lande
      }
      else if(val>=20 && val<=29){
        return 15; //scorciatoi
      }
      else if(val>=30 && val<=39){
        return 16; //vulcano
      }
      else if(val>=40 && val<=49){
        return 17; //foresta
      }
      else if(val>=50 && val<=59){
        return 18; //oblio
      }
    }
    return 4;
  }
  if(val>=35 && val<=42){ //caselle mezzi
    if(c.Find(1)==1){
      return GetType();
    }
    c.Shift(1);
    while(true){
      int val = (rand()%300);
      val=val/10;
      if(val>=0 && val<=9){
        return 1; //cavallo
      }
      else if(val>=10 && val<=19){
        return 2; //drago
      }
      else if(val>=20 && val<=29){
        return 3; //carovana
      }
    }
  }
  if(val>=43 && val<=78){ //caselle mostri
    if(c.Find(2)==1){
      return GetType();
    }
    c.Shift(2);
    while(true){
      int val = (rand()%1400);
      val=val/10;
      if(val>=0 && val<=19){
        return 4; //goblin
      }
      else if(val>=20 && val<=39){
        return 5; //lupo
      }
      else if(val>=40 && val<=52){
        return 6; //orco
      }
      else if(val>=53 && val<=65){
        return 7; //troll
      }
      else if(val>=66 && val<=75){
        return 8; //spirito
      }
      else if(val>=76 && val<=82){
        return 9; //vampiro
      }
      else if(val>=83 && val<=89){
        return 10; //basilisco
      }
      else if(val>=90 && val<=114){
        if(cont>0){
          cont--;     //mangianime
          return 11;
        }
      }

      else if(val>=115 && val<=139){
        if(cont>0){
          cont--;       //cavaliere nero
          return 12;
        }
      }
    }
  }
  if(val>=79 && val<=92){ //caselle oggetti
    if(c.Find(3)==1){
      return GetType();
    }
    c.Shift(3);    while(true){
      int val = (rand()%500);
      val=val/10;
      if(val>=0 && val<=9){
        return 19; //ali
      }
      else if(val>=10 && val<=19){
        return 20; //spada
      }
      else if(val>=20 && val<=29){
        return 21; //spinta
      }
      else if(val>=30 && val<=39){
        return 22; //INSTANCABILE
      }
      else if(val>=40 && val<=49){
        return 23; //lancio
      }
    }
  }
  if(val>=93 && val<=100){ //caselle pesca
    if(c.Find(5)==1){
      return GetType();
    }
    c.Shift(5);
    return 24;
  }
}


/*String setCasellaNameEffect(){

}*/





void Tabellone::Append(int n)
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

void Tabellone::Visualizza(int n_caselle){
  Nodo *scor=Start;
  Nodo *tmp = Start;
  int colore;
  Persona *giocatore=player.return_head();
  int res=0,caselle_2;
  if(Start==NULL){
    cout<<"Non ci sono valori nella Tabellone\n";
    return;
  }

  cout<<"\nIl tabellone è: \n";

  while((scor!=NULL)&&(n_caselle>=0)){
    res=0;
    if(scor->GetNum()<=25){
      cout<<"  ";
      while((tmp->GetSucc() != NULL)&&(res<=25)){
        if (tmp->GetNome()!=NULL) {
          giocatore=tmp->GetNome();

          //  printf("%s#%s", COL(32) ,COL_CLEAR );
          colore=giocatore->getColore();
          switch(colore){
            case 31:
            printf("%s#", COL(31) );
            break;
            case 32:
            printf("%s#", COL(32) );
            break;
            case 33:
            printf("%s#", COL(33) );
            break;
            case 34:
            printf("%s#", COL(34) );
            break;
            case 35:
            printf("%s#", COL(35) );
            break;
            case 36:
            printf("%s#", COL(36) );
            break;
            case 37:
            printf("%s#", COL(37) );
            break;
          }
          printf("%s",COL_CLEAR );
          //  cout<<"#";
          if(res<=9){
            cout<<"   ";
          }
          else{
            cout<<"    ";
          }
        }
        else if(res<=9){
          cout<<"    ";
        }
        else{
          cout<<"     ";
        }
        res++;
        tmp = tmp->GetSucc();
      }
      //cout<<"\n_________________________________________________________________________________________________________________________";
      printf("%s\n_________________________________________________________________________________________________________________________\n%s",COL(32),COL_CLEAR);

      printf("%s|%s",COL(32),COL_CLEAR);
      while(scor->GetNum()<=25){
        printf("%s_%d_|%s",COL(32),scor->GetNum(),COL_CLEAR );
        //cout<<"_"<<scor->GetNum()<<"_|";
        scor=scor->GetSucc();
      }
      n_caselle=n_caselle-26;
    }
    caselle_2=n_caselle;
    n_caselle=n_caselle-24;
    res=0;
    if(n_caselle>=0){
      cout<<"\n\n   ";
      while((tmp->GetSucc() != NULL)&&(res<=23)) {
        if (tmp->GetNome()!=NULL) {
          giocatore=tmp->GetNome();
          colore=giocatore->getColore();
          switch(colore){
            case 31:
            printf("%s#", COL(31) );
            break;
            case 32:
            printf("%s#", COL(32) );
            break;
            case 33:
            printf("%s#", COL(33) );
            break;
            case 34:
            printf("%s#", COL(34) );
            break;
            case 35:
            printf("%s#", COL(35) );
            break;
            case 36:
            printf("%s#", COL(36) );
            break;
            case 37:
            printf("%s#", COL(37) );
            break;
          }
          printf("    %s",COL_CLEAR );
          //  printf("%s#%s     ", COL(32) ,COL_CLEAR );
          //  cout<<"#    ";
        }
        else cout<<"     ";
        res++;
        tmp = tmp->GetSucc();
      }
      //cout<<"\n_________________________________________________________________________________________________________________________";
      printf("%s\n_________________________________________________________________________________________________________________________\n%s",COL(32),COL_CLEAR);

      printf("%s|%s",COL(32),COL_CLEAR);
      res=0;
      while((res<24)&&(scor!=NULL)){
        printf("%s_%d_|%s",COL(32),scor->GetNum(),COL_CLEAR );
        //  cout<<"_"<<scor->GetNum()<<"_|";
        scor=scor->GetSucc();
        res++;
      }
    }
    else{
      res=0;
      cout<<"\n\n   ";
      n_caselle=caselle_2;
      while((tmp->GetSucc() != NULL)&&(res<=n_caselle)) {
        if (tmp->GetNome()!=NULL) {
          giocatore=tmp->GetNome();
          colore=giocatore->getColore();
          colore=giocatore->getColore();
          switch(colore){
            case 31:
            printf("%s#", COL(31) );
            break;
            case 32:
            printf("%s#", COL(32) );
            break;
            case 33:
            printf("%s#", COL(33) );
            break;
            case 34:
            printf("%s#", COL(34) );
            break;
            case 35:
            printf("%s#", COL(35) );
            break;
            case 36:
            printf("%s#", COL(36) );
            break;
            case 37:
            printf("%s#", COL(37) );
            break;
          }
          printf("%s",COL_CLEAR );
          //printf("%s#%s    ", COL(32) ,COL_CLEAR );
          //  cout<<"#    ";
        }
        else cout<<"     ";
        res++;
        tmp = tmp->GetSucc();
      }
      cout<<"\n";
      while(caselle_2>=0){
        printf("%s_____%s",COL(32) ,COL_CLEAR );
        //cout<<"_____";
        caselle_2--;
      }
      //  cout<<"_\n|";
      printf("%s_\n|%s",COL(32),COL_CLEAR );
      while((n_caselle>=0)&&(scor!=NULL)){
        printf("%s_%d_|%s",COL(32),scor->GetNum(),COL_CLEAR );
        //cout<<"_"<<scor->GetNum()<<"_|";
        scor=scor->GetSucc();
        n_caselle--;
      }
    }
  }
}

void Tabellone::SetGiocatore(Persona *giocatore, int n, int n_caselle){
  int scarto;
  if(Start == NULL){
    return;
  }
  Nodo *tmp = Start;
  Nodo *tmp2 = Start;
  Persona *giocatore2;
  giocatore2=giocatore;
  while(tmp2 != NULL){
    if(tmp2->GetNome() == giocatore){
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
    get_effect(giocatore, tmp,n);
    if(tmp->GetNum() != giocatore->getCasella()){
      Tabellone::SetGiocatore(giocatore, 0, n_caselle );
    }
  }
  else{
    giocatore2=tmp->GetNome();
    if(giocatore2->getNome()!=giocatore->getNome()){
      duello(giocatore,giocatore2,n_caselle);
    }
  }
}

void Tabellone::get_effect(Persona *giocatore, Nodo *tmp, int n){
  Persona *giocatore2;
  Nodo *tmp2=Start;
  switch(tmp->GetType()){
    case 0:
    cout<<"\nVisto che non devi fare niente,almeno picchia il porta pizza!\n";
    break;
    case 1:
    t.cavalca_mezzo(0,giocatore);
    break;
    case 2:
    t.cavalca_mezzo(1,giocatore);
    break;
    case 3:
    t.cavalca_mezzo(2,giocatore);
    break;
    case 4:
    t.combatti_mostro(0,giocatore);
    break;
    case 5:
    t.combatti_mostro(1,giocatore);
    break;
    case 6:
    t.combatti_mostro(2,giocatore);
    break;
    case 7:
    t.combatti_mostro(3,giocatore);
    break;
    case 8:
    t.combatti_mostro(4,giocatore);
    break;
    case 9:
    t.combatti_mostro(5,giocatore);
    break;
    case 10:
    t.combatti_mostro(6,giocatore);
    break;
    case 11:
    t.combatti_mostro(7,giocatore);
    break;
    case 12:
    t.combatti_mostro(8,giocatore);
    break;
    case 13:
    t.esplora_luogo(0,giocatore);
    break;
    case 14:
    t.esplora_luogo(1,giocatore);
    break;
    case 15:
    t.esplora_luogo(2,giocatore);
    break;
    case 16:
    t.esplora_luogo(3,giocatore);
    break;
    case 17:
    t.esplora_luogo(4,giocatore);
    break;
    case 18:
    t.esplora_luogo(5,giocatore);
    break;
    case 19:
    t.raccogli_oggetto(0,n, giocatore);
    break;
    case 20:
    t.raccogli_oggetto(1,n, giocatore);
    break;
    case 21:
    t.raccogli_oggetto(2,n, giocatore);
    break;
    case 22:
    t.raccogli_oggetto(3,n, giocatore);
    break;
    case 23:
    t.raccogli_oggetto(4,n, giocatore);
    break;
    case 24:
    card.catch_card(giocatore);
    break;
  }
  return;
}


void Tabellone::duello(Persona *giocatore, Persona* giocatore2,int n_caselle){
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
    res_duello= d1.Tira();
    cout<<"Hai fatto: "<<res_duello<<endl;
    cout<<giocatore2->getNome()<<" Lancia i dadi!\n"<<endl;
    res_duello_2= d1.Tira();
    cout<<"Hai fatto: "<<res_duello_2<<endl;
    if(res_duello>res_duello_2){
      cout<<"Ha vinto "<<giocatore->getNome()<<endl;
      duello=false;
      SetGiocatore(giocatore2,-res_duello_2,n_caselle);
      SetGiocatore(giocatore,0,n_caselle);
    }
    else if(res_duello<res_duello_2){
      cout<<"Ha vinto "<<giocatore2->getNome()<<endl;
      duello=false;
      res_duello=giocatore->getCasella()-res_duello;
      giocatore->setCasella(res_duello);
      SetGiocatore(giocatore,0,n_caselle);
    }
    else cout<<"Oh no! Avete fatto lo stesso risultato dovete combattere ancora!\n";
  }

}
#if 0
void Tabellone::stampa_caselle(){
Nodo*tmp= Start;
while(tmp!=NULL){
cout<<"effect: "<<tmp->GetType()<<endl;
tmp=tmp->GetSucc();
}
}
#endif
