#include "header.h"

Type::Type(){
	CaricaMostri();
	CaricaOgettiMagici();
	CaricaMezzi();
	CaricaLuoghi();
}

Type::~Type(){
}

void Type::CaricaMostri(){
	int x = 0;
	FILE* fin;
	size_t n=0;
	char* line;
	fin=fopen("FileCaselle/mostri.txt","r");
    while (x<9){
			getline(&line, &n, fin);
     	mostri[x].nome = line;
		 getline(&line, &n, fin);
		mostri[x].nbattere = atoi(line);
		mostri[x].cont=0;
			x++;
    }
		fclose(fin);
for (int i=0; i<9; i++){
	cout<<mostri[i].nome<<endl;
	//cout<<mostri[i].nbattere<<endl;
  //cout<<mostri[i].cont<<endl;
}
}


void Type::CaricaOgettiMagici(){
	int x = 0;
	FILE* fin;
	size_t n=0;
	char* line;
	fin=fopen("FileCaselle/oggettimagici.txt","r");
    while (x<5)
    {
			getline(&line, &n, fin);
     	oggettiMagici[x].nome = line;
			getline(&line, &n, fin);
		oggettiMagici[x].operatore = line;
		getline(&line, &n, fin);
		oggettiMagici[x].navanti= atoi(line);
		oggettiMagici[x].cont = 0;
     	x++;
    }
		fclose(fin);
		for (int i=0; i<5; i++){
			cout<<oggettiMagici[i].nome<<endl;
}
}


void Type::CaricaMezzi(){
	int x = 0;
	FILE* fin;
	size_t n=0;
	char* line;
	fin=fopen("FileCaselle/mezzi.txt","r");
    while (x<3){
			getline(&line, &n, fin);
     	mezzi[x].nome = line;
		mezzi[x].cont = 0;
     	x++;
    }
		fclose(fin);
		for (int i=0; i<3 ; i++){
			cout<<mezzi[i].nome<<endl;
		}
}


void Type::CaricaLuoghi(){
	int x = 0;
	FILE* fin;
	size_t n=0;
	char* line;
	fin=fopen("FileCaselle/luoghi.txt","r");
    while (x<6){
			getline(&line, &n, fin);
     	luoghi[x].nome = line;
			getline(&line, &n, fin);
     	luoghi[x].info = line;
     	x++;
    }
		fclose(fin);
 	for(int i= 0; i< 6; i++){
 		cout<<luoghi[i].info<<endl;
	 }
}
