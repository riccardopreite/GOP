#include "header.h"


Dado::Dado(){

}
Dado::~Dado(){

}
int Dado::Tira(){
	int res;
	//srand(static_cast<unsigned int>(time(NULL)));
	res=((rand() % 500)+1);
	res=(res/100)+1;
	return res;
}
