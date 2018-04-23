#include "header.h"

Casella::Casella(){
	SetNome(NULL);
	SetNum(0);
	SetSucc(NULL);
}

Casella::~Casella(){
}


void Casella::SetNome(Persona *x) {
	nome_g=x;
}

Persona *Casella::GetNome(){
	return nome_g;
}

void Casella::SetSucc(Casella *x){
	succ=x;
}

Casella* Casella::GetSucc(){
	return succ;
}

void Casella::SetNum(int n){
	num = n;
}

int Casella::GetNum(){
	return num;
}

void Casella::SetType(int t){
	tip_cas = t;
}

int Casella::GetType(){
	return tip_cas;
}
