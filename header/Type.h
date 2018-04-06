#include <string.h>
using namespace std;
struct Mostri{
	string nome;
	int nbattere;
	int cont;
};

struct Mezzi{
	string nome;
	int cont;
};

struct Oggetti{
	string nome;
	string operatore;
	int navanti;
	int cont;
};

struct Luoghi{
	string nome;
	string info;
};

class Type{

	private:
		size_t n;
		Luoghi luoghi[6]; 			//TipoCasella 1  1)nome, 2) info
		Mezzi mezzi[3];  			//TipoCasella 2  1)nome mezzo
		Mostri mostri[9];			//TipoCasella 3  1)Nome mostro,  2)Numero Perbattere , 3) numero di volte che puo comparire
		Oggetti oggettiMagici[5];	//TipoCasella4  1)Nome, 2)Operatore, 3)navanti, 4)contatore

	public:
		Type();
		~Type();
		void CaricaLuoghi();
		void CaricaMezzi();
		void CaricaMoastri();
		void CaricaOgettiMagici();
		void CaricaMostri();
};
