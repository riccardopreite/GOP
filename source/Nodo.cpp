#include "header.h"

Nodo::Nodo(){
	SetNome(NULL);
	SetNum(0);
	SetSucc(NULL);
	nome_effetto = "";
}

Nodo::~Nodo(){
}

void Nodo::SetNome(Persona *x) {
     nome_g=x;
}

Persona *Nodo::GetNome(){
    return nome_g;
}

void Nodo::SetSucc(Nodo *x){
     succ=x;
}

Nodo* Nodo::GetSucc(){
     return succ;
}

void Nodo::SetNum(int n){
	num = n;
}

int Nodo::GetNum(){
	return num;
}

void Nodo::SetType(int t){
	tip_cas = t;
}

int Nodo::GetType(){
	return tip_cas;
}
