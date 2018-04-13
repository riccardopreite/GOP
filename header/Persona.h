/*
 * Persona.h
 *
 *  Created on: 09 mar 2018
 *      Author: xxxx
 */

#ifndef PERSONA_H_
#define PERSONA_H_
using namespace std;

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


#endif /* PERSONA_H_ */
