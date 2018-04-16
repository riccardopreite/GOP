
//main di prova

#include "header.h"

void visualizzaGOP(){
  system("clear");
  cout<<"\t\t\t\t\t\t\t\t\t\t   _____  ____  _____\n";
  cout<<"\t\t\t\t\t\t\t\t\t\t / _____|/ __ \\|  __ \\ "<<endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t | |  __| |  | | |__) |"<<endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t | | |_ | |  | |  ___/"<<endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t | |__| | |__| | |"<<endl;
  cout<<"\t\t\t\t\t\t\t\t\t\t \\______|\\____/|_|"<<endl;
}


int main(){
  visualizzaGOP();
  int x=0,res,n_caselle,giocatori,colore=32;
  bool win=false;
  string winner;
  Persona *c;
  string nome;
  Giocatori g = Giocatori();
  Tabellone l=Tabellone();
  Dado d1 = Dado();
  srand(static_cast<unsigned int>(time(NULL)));
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
  x=giocatori;
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
  l.Visualizza(n_caselle);
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
    l.Visualizza(n_caselle);
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
      printf("\n%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s|          |%s   %s|          |%s\n%s|     *    |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
      printf("%s|          |%s   %s|          |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
      cout<<"\nPREMI INVIO PER TIRARE I DADI\n";
      res = d1.Tira();
      l.SetGiocatore(c, res, n_caselle);
      g.stampa_posizione();
    }
    if(c->getCasella()==n_caselle){
      win=true;
      break;
    }
    cout<<"\nPremi invio per passare il turno.\n";
    if(getc(stdin) != 13){
      system("clear");
      c=g.player_turn(c);
    }
  }
  winner=c->getNome();
  cout<<"\nIl vincitore è:"<<winner<<endl;
  return 0;
}
