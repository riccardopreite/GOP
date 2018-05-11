
//main di prova

#include "header.h"

void visualizzaGOP(){
  system("clear");
  cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t   _____  ____  _____\n";
  cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t / _____|/ __ \\|  __ \\ "<<endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t | |  __| |  | | |__) |"<<endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t | | |_ | |  | |  ___/"<<endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t | |__| | |__| | |"<<endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t \\______|\\____/|_|"<<endl;
}


int main(){
  visualizzaGOP();
  int n = 31;
  string inizio="\033[1;";
  string fine="m:)\033[0m";
  //string colore=(string)n;
  //colore=colore+"@;1m";
  //printf("%s %s %s", inizio,n,fine);
  int x=0,res,n_caselle,giocatori;
  bool win;
  char game;
  string winner;
  Persona *c;
  string nome;
  Giocatori g;
  Tabellone l;
  Dado d1;
  do{
    c=NULL;
    nome="\0";
    winner="\0";
    win=false;
    game='\0';
    g = Giocatori();
    l = Tabellone();
    d1 = Dado();
    srand((time(0)));
    n_caselle = (rand() % 50)+41;
    l.set_cont(n_caselle);
    for(int i = 0; i <= n_caselle; i++ ){
      l.Append(i);
    }
    cout<<"Il tabellone è di: "<<n_caselle<<" caselle.\n";
    cout<<"\nQuanti giocatori ci sono? (minimo 2)\n";
    cin>>giocatori;
    while((!cin.good())||giocatori<2){
      cout<<"Quanti giocatori ci sono? (minimo 2)\n";
      d1.err_input();
      cin>>giocatori;
    }
    x=1;
    while(giocatori>0){
      visualizzaGOP();
      cout<<"Inserisci il nome del "<<x<<"° del giocatore :\n";
      cin>>nome;
      g.aggiungi_giocatore(nome);
      x++;
      giocatori--;
    }
    visualizzaGOP();
    l.Visualizza(n_caselle,g);
    d1.err_input();
    cout<<"\n\nPremi invio per lottare per il primo posto!\n";
    if(getc(stdin) != 13){
      system("clear");
    }

    visualizzaGOP();
    c=g.scegli_primo();
    cout<<"\nPremi invio per iniziare!";
    if(getc(stdin) != 13){
      system("clear");
    }

    visualizzaGOP();
    cout<<"Iniziamo!\n";
    while(win==false){
      visualizzaGOP();
      if(c->getstop()!=0){
        g.stampa_giocatore(c);
        c->setstop(c->getstop()-1);
        if(c->getstop()==1){
          cout<<" Devi rimanere fermo ancora: "<<c->getstop()<<" turno\n";

        }
        else if(c->getstop()>1){
          cout<<" Devi rimanere fermo ancora: "<<c->getstop()<<" turni\n";
        }
        else cout<<" Al prossimo turno potrai giocare di nuovo.\n";
      }
      else{
        cout<<"\nè il turno di: ";
        g.stampa_giocatore(c);
        res = d1.Tira();
        l.SetGiocatore(c, res, n_caselle);
        g.stampa_posizione();
      }
      if(c->getCasella()==n_caselle){
        win=true;
        break;
      }
      l.Visualizza(n_caselle,g);
      cout<<"\nPremi invio per passare il turno.\n";
      if(getc(stdin) != 13){
        system("clear");
        c=g.player_turn(c);
      }
    }
    winner=c->getNome();
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t%s_____ _         __      ___                     _      _ \n%s",COL(31),COL_CLEAR);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t%s|_   _| |_  ___  \\ \\    / (_)_ _  _ _  ___ _ _  (_)___ (_)\n%s",COL(31),COL_CLEAR);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t%s  | | | ' \\/ -_)  \\ \\/\\/ /| | ' \\| ' \\/ -_) '_| | (_-<  _ \n%s",COL(31),COL_CLEAR);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t%s  |_| |_||_\\___|   \\_/\\_/ |_|_||_|_||_\\___|_|   |_/__/ (_)%s          ",COL(31),COL_CLEAR);
    cout<<winner<<"\n\n\n\n";
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t%s_________          _______    _______  _        ______%s \n",COL(33),COL_CLEAR);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t%s\\__   __/|\\     /|(  ____ \\  (  ____ \\( (    /|(  __  \\%s \n",COL(33),COL_CLEAR);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t%s   ) (   | )   ( || (    \\/  | (    \\/|  \\  ( || (  \\  )%s\n",COL(33),COL_CLEAR);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t%s   | |   | (___) || (__      | (__    |   \\ | || |   ) |%s\n",COL(33),COL_CLEAR);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t%s   | |   |  ___  ||  __)     |  __)   | (\\ \\) || |   | |%s\n",COL(33),COL_CLEAR);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t%s   | |   | (   ) || (        | (      | | \\   || |   ) |%s\n",COL(33),COL_CLEAR);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t%s   | |   | )   ( || (____/\\  | (____/\\| )  \\  || (__/  )%s\n",COL(33),COL_CLEAR);
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t%s   )_(   |/     \\|(_______/  (_______/|/    )_)(______/%s \n",COL(33),COL_CLEAR);



    if(getc(stdin) != 13){
      system("clear");
    }


    cout<<"\nVuoi giocare di nuovo? (Y o y)\n";
    cin>>game;
  }while((game=='y' || game=='Y'));

  return 0;
}
