
 #include "header.h"

	Persona::Persona(){
		setNome("");
		setCasella(0);
		setSconfiggi(false);
		setstop(0);
		setValDadoInit(0);
		setColore(0);
	}

	Persona::~Persona(){}
	void Persona::setNome(string nome){
		_nome = nome;
	}
	string Persona::getNome(){
		return _nome;
	}
	void Persona::setCasella(int casella){
		_casella = casella;
    if(this->_casella<0) {
        setCasella(0);
    }
	}
	int Persona::getCasella(){
		return _casella;
	}
	void Persona::setSconfiggi(bool sconfiggi_mostro){
		_sconfiggi_mostro = sconfiggi_mostro;
	}
	bool Persona::getSconfiggi(){
		return _sconfiggi_mostro;
	}
	void Persona::setColore(int colore){
		_colore = colore;
	}
	int Persona::getColore(){
		return _colore;
	}
	void Persona::setNext(Persona *succ){
		next = succ;
	}
	Persona *Persona::getNext(){
		return next;
	}

	void Persona::setstop(int n){
		stop=n;
		return;
	}
	int Persona::getstop(){
		return this->stop;
	}

	void Persona::setValDadoInit(int n){
		val_dado_init=n;
		return;
	}
	int Persona::getValDadoInit(){
		return val_dado_init;
	}
