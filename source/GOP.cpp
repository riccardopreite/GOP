
//main di prova

#include "header.h"

int main(){
  int x=0,res,n_caselle,giocatori;
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
  //l.stampa_caselle();
  cout<<"Il tabellone è di: "<<n_caselle<<" caselle.\n";
  cout<<"\nQuanti giocatori ci sono? (minimo 2)\n";

  cin>>giocatori;

  while((!cin.good())||giocatori<2){
    cout<<"Quanti giocatori ci sono? (minimo 2)\n";
    d1.err_input();
    cin>>giocatori;
  }
  x=giocatori;
  while(giocatori>0){
    cout<<"inserisci il nome del giocatore:\n";
    cin>>nome;
    g.aggiungi_giocatore(nome);
    giocatori--;
  }
  l.Visualizza(n_caselle);
  d1.err_input();
  cout<<"\nPremi invio per iniziare!\n";
  if(getc(stdin) != 13){
    system("clear");
  }
  cout<<"Iniziamo!\n";
  c=g.scegli_primo();
  while(win==false){
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
      cout<<"\npremi invio per tirare i dadi\n";
        res = d1.Tira();
        cout<<res<<endl;
        l.SetGiocatore(c, res, n_caselle);
        g.stampa_posizione();
        l.Visualizza(n_caselle);
        cout<<"\nPremi invio per passare il turno.\n";
        if(getc(stdin) != 13){
        system("clear");
      }
    }
    if(c->getCasella()==n_caselle){
      win=true;
      break;
    }
    c=g.player_turn(c);
  }
  winner=c->getNome();
  cout<<"Il vincitore è:"<<winner<<endl;
  return 0;
}
