#include<ctime>
#include<cstdlib>
using namespace std;


class Tabellone{
  private: Nodo *Start;
  Coda c;
  deck card;
  Giocatori player;
  Type t;
  int cont;
public:
  Tabellone();
  ~Tabellone();
  void AddFront(Nodo *nuovo);
  void stampa_caselle();
  void Append(int n);
  void Visualizza(int n_caselle);
  void SetGiocatore(Persona *g, int n, int n_caselle);
  int GetType();
  void set_cont(int n_caselle);
  void duello(Persona *giocatore, Persona *giocatore2,int n_caselle);
  void get_effect(Persona *giocatore,Nodo *tmp,int n);
};
