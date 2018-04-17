#include <string.h>
using namespace std;
struct Mostri{
	string nome;
	int nbattere;
};

struct Mezzi{
	string nome;
};

struct Oggetti{
	string nome;
};

struct Luoghi{
	string nome;
	string info;
};

class Type{

	private:
		Dado d1;
		int lancio;
		size_t n;
		Luoghi luoghi[6]; 			//TipoCasella 1  1)nome, 2) info
		Mezzi mezzi[3];  			//TipoCasella 2  1)nome mezzo
		Mostri mostri[9];			//TipoCasella 3  1)Nome mostro,  2)Numero Perbattere , 3) numero di volte che puo comparire
		Oggetti oggettiMagici[5];	//TipoCasella4  1)Nome, 2)Operatore, 3)navanti, 4)contatore
		char* line;
	public:
		Type();
		void raccogli_oggetto(int x, int lancio, Persona *g);
		void esplora_luogo(int x, Persona *g);
		void cavalca_mezzo(int x, Persona *g);
		void combatti_mostro(int x,Persona *g);
		void CaricaLuoghi();
		void CaricaMezzi();
		void CaricaMoastri();
		void CaricaOgettiMagici();
		void CaricaMostri();
};
