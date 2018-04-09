#include "header.h"


Dado::Dado(){
  res_1=0;
  res_2=0;
}
Dado::~Dado(){

}
void Dado::err_input(){
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Dado::Tira(){
   res_1,res_2;
  if(getc(stdin) != 13){
    res_1=((rand() % 500)+1);
    res_1=(res_1/100)+1;
    res_2=((rand() % 500)+1);
    res_2=(res_2/100)+1;
    res_1=res_1+res_2;
  }
  return res_1;
}

int Dado::Tira_2(){
  if(getc(stdin) != 13){
    res_1=((rand() % 500)+1);
    res_1=(res_1/100)+1;
  }
  return res_1;
}
