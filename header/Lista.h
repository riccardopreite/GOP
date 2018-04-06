#include<ctime>
#include<cstdlib>
using namespace std;


class Lista{
        private: Nodo *Start;
    			 Coda c;
				 deck card;
        		 Giocatori player;
        public:
			Lista();
            ~Lista();
            void get_caselle();
            void AddFront(Nodo *nuovo);
            void Append(int n);
            void Visualizza(int n_caselle);
        	void SetGiocatore(Persona *g, int n, int n_caselle);
        	int GetType();
          void duello(Persona *giocatore, Persona *giocatore2,int n_caselle);
          void get_effect(Persona *giocatore,Nodo *tmp);

};
