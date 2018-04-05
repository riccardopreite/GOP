
//main di prova

#include "header.h"
int main(){
  int x=0,res,n_caselle,giocatori;
  bool win=false;
  string winner;
  Persona *c;
  string nome;
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
	  try
		{
		cout<<"Quanti giocatori ci sono? (minimo 2)\n";
		cin>>giocatori;
		throw 1;
	}
  catch (int e)
  {
    cout << "Ma allora sei scemo\n";
  }
  giocatori = 0;
  }
  while(giocatori<2);
  x=giocatori;
  while(giocatori>0){
    cout<<"inserisci il nome del giocatore:\n";
    cin>>nome;
    g.aggiungi_giocatore(nome);
    giocatori--;
  }
  cout<<"Premi invio per iniziare!\n";
  if(getc(stdin) != 13){
  system("clear");
}
  cout<<"Iniziamo!\n";
  c=g.Set_first(x);
  while(win==false){
    if(c->getstop()!=0){
      g.stampa_giocatore(c);
      c->setstop(c->getstop()-1);
      cout<<"Devi rimanere fermo ancora: "<<c->getstop()<<" turni\n";
    }
    else{
      cout<<"\npremi invio per tirare i dadi\n";
      if(getc(stdin) != 13){
        cout<<"è il turno di: ";
        g.stampa_giocatore(c);
        res = d1.Tira() + d2.Tira();
        cout<<res<<endl;
        l.SetGiocatore(c, res, n_caselle);
        //cout<<c->getCasella();
        g.stampa_posizione();
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
