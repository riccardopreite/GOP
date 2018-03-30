
//main di prova

#include "header.h"
int main(){
  int x=0,res,n_caselle;
  bool win=false;
  string winner;
  Persona *c;
  string nome;
  deck a=deck();
  Giocatori g = Giocatori();
  Lista l=Lista();
  Dado d1 = Dado();
  Dado d2 = Dado();
  srand(static_cast<unsigned int>(time(NULL)));
  n_caselle = (rand() % 50)+41;
  for(int i = 0; i <= n_caselle; i++ ){
    l.Append(i);
  }
  cout<<"Il tabellone è di: "<<n_caselle<<" caselle.\n";
  l.Visualizza();
  do{
    cout<<"Quanti giocatori ci sono? (minimo 2)\n";
    cin>>x;
  }
  while(x<2);
  while(x>0){
    cout<<"inserisci il nome del giocatore:\n";
    cin>>nome;
    g.aggiungi_giocatore(nome);
    x--;
  }
  cout<<"Iniziamo!\n";
  c=g.Set_first();
  while(win==false){
      cout<<"\npremi invio per tirare i dadi\n";
      if(getc(stdin) != 13){
        cout<<"è il turno di: ";
        g.stampa_giocatore(c);
        res = d1.Tira() + d2.Tira();
        cout<<res<<endl;
        l.SetGiocatore(c, res, n_caselle);
        cout<<c->getCasella();
      }
      if(c->getCasella()==n_caselle){
        win=true;
        break;
      }
      c=g.player_turn(c);
    }
  //if controllo casella per decidere azione
  //  a.catch_card(c);
  //t--;
  winner=c->getNome();
  cout<<"Il vincitore è:"<<winner<<endl;
  return 0;
}
