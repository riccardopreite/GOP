
class Persona{
private:
	string _nome;
	int _casella;
	bool _sconfiggi_mostro;
	int _colore;
	int stop;
	Persona *next;
	int val_dado_init;
public:
	Persona();
    void setValDadoInit(int n);
    int getValDadoInit();
	void setNome(string n);
	string getNome();
	void setCasella(int casella);
	int getCasella();
	void setSconfiggi(bool sconfiggi_mostro);
	bool getSconfiggi();
	void setColore(int colore);
	int getColore();
	void setNext(Persona *succ);
	Persona *getNext();
	void setstop(int n);
	int getstop();
	~Persona();
};
