#include "header.h"

Coda::Coda(){

}
Coda::Coda(int n){
	if(n>10){
		n=10;
		cout<<"La coda non può essere più grande di 10, modificarla prima nell'header.\nPer ora il valore viene settato automaticamente a 10\n";
	}
	l = n;
	cont=0;
	for(int i = 0; i < l; i ++){
		this->coda[i] = -1;
	}
	cont=0;
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
