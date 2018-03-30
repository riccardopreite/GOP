#include "header.h"
Coda::Coda(){
}


Coda::Coda(int n){
	l = n;
	for(int i = 0; i < l; i ++){
		this->coda[i] = -1;
	}
}

Coda::~Coda(){
}


void Coda::Shift(int val){
	int j=l-1;
	for(int i = l-2; i >= 0; i-- ){
		this->coda[j] = this->coda[i];
		j--;
	}
	this->coda[0]=val;
}

void Coda::Visualizza(){
	for(int i = 0; i < l; i ++){
		cout<<this->coda[i];
	}
}


bool Coda::Find(int val){
	for(int i = 0; i< l; i++){
		if(coda[i]==val){
			return true;
		}
	}
	return false;
}
