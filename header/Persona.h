/*
 * Persona.h
 *
 *  Created on: 09 mar 2018
 *      Author: xxxx
 */

#ifndef PERSONA_H_
#define PERSONA_H_
#include <string>
using namespace std;

class Persona{
private:
	string _nome;
	int _casella;
	bool _sconfiggi_mostro;
	string _colore;
	int stop;
	Persona *next;
public:
	Persona();
	void setNome(string n);
	string getNome();
	void setCasella(int casella);
	int getCasella();
	void setSconfiggi(bool sconfiggi_mostro);
	bool getSconfiggi();
	void setColore(string colore);
	string getColore();
	void setNext(Persona *succ);
	Persona *getNext();
	void setstop(int n);
	int getstop();
	~Persona();
};


#endif /* PERSONA_H_ */