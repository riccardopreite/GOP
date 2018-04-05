#include<ctime>
#include<cstdlib>
using namespace std;


class Lista{
        private: Nodo *Start;
    			 Coda c;
				deck card;
        public:
			Lista();
            ~Lista();
            void AddFront(Nodo *nuovo);
            void Append(int n);
            void Visualizza();
        	void SetGiocatore(Persona *g, int n, int n_caselle);
        	int GetType();
          void duello(Persona *giocatore, Persona *giocatore2);
          void get_effect(Persona *giocatore,Nodo *tmp);

};
