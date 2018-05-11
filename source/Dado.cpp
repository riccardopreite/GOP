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
  printf("\n%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s|          |%s   %s|          |%s\n%s|     *    |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
  printf("%s|          |%s   %s|          |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
  cout<<"\nPREMI INVIO PER TIRARE I DADI\n";
  if(getc(stdin) != 13){
    res_1=((rand() % 599)+1);
    res_1=(res_1/100)+1;
    res_2=((rand() % 599)+1);
    res_2=(res_2/100)+1;
    switch(res_1){
      case 1:
      switch(res_2){
        case 1:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s|          |%s   %s|          |%s\n%s|     *    |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|          |%s   %s|          |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 2:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s|          |%s   %s| *        |%s\n%s|     *    |%s   %s|          |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|          |%s   %s|        * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 3:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s|          |%s   %s| *        |%s\n%s|     *    |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|          |%s   %s|        * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 4:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s|          |%s   %s| *      * |%s\n%s|     *    |%s   %s|          |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|          |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 5:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s|          |%s   %s| *      * |%s\n%s|     *    |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|          |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 6:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s|          |%s   %s| *      * |%s\n%s|     *    |%s   %s| *      * |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|          |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
      }
      break;
      case 2:
      switch(res_2){
        case 1:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *        |%s   %s|          |%s\n%s|          |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);

        printf("%s|        * |%s   %s|          |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 2:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *        |%s   %s| *        |%s\n%s|          |%s   %s|          |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|        * |%s   %s|        * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 3:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *        |%s   %s| *        |%s\n%s|          |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|        * |%s   %s|        * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 4:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *        |%s   %s| *      * |%s\n%s|          |%s   %s|          |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|        * |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 5:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *        |%s   %s| *      * |%s\n%s|          |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|        * |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 6:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *        |%s   %s| *      * |%s\n%s|          |%s   %s| *      * |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|        * |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
      }
      break;
      case 3:
      switch(res_2){
        case 1:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *        |%s   %s|          |%s\n%s|     *    |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);

        printf("%s|        * |%s   %s|          |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 2:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *        |%s   %s| *        |%s\n%s|     *    |%s   %s|          |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|        * |%s   %s|        * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 3:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *        |%s   %s| *        |%s\n%s|     *    |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|        * |%s   %s|        * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 4:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *        |%s   %s| *      * |%s\n%s|     *    |%s   %s|          |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|        * |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 5:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *        |%s   %s| *      * |%s\n%s|     *    |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|        * |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 6:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *        |%s   %s| *      * |%s\n%s|     *    |%s   %s| *      * |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s|        * |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
      }
      break;
      case 4:
      switch(res_2){
        case 1:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s|          |%s\n%s|          |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s|          |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 2:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s| *        |%s\n%s|          |%s   %s|          |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s|        * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 3:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s| *        |%s\n%s|          |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s|        * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 4:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s| *      * |%s\n%s|          |%s   %s|          |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 5:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s| *      * |%s\n%s|          |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 6:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s| *      * |%s\n%s|          |%s   %s| *      * |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
      }
      break;
      case 5:
      switch(res_2){
        case 1:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s|          |%s\n%s|     *    |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);

        printf("%s| *      * |%s   %s|          |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 2:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s| *        |%s\n%s|     *    |%s   %s|          |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s|        * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 3:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s| *        |%s\n%s|     *    |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s|        * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 4:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s| *      * |%s\n%s|     *    |%s   %s|          |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 5:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s| *      * |%s\n%s|     *    |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 6:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s| *      * |%s\n%s|     *    |%s   %s| *      * |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
      }
      break;
      case 6:
      switch(res_2){
        case 1:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s|          |%s\n%s| *      * |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s|          |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 2:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s| *        |%s\n%s| *      * |%s   %s|          |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s|        * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 3:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s| *        |%s\n%s| *      * |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s|        * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 4:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s| *      * |%s\n%s| *      * |%s   %s|          |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 5:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s| *      * |%s\n%s| *      * |%s   %s|     *    |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
        case 6:
        printf("%s____________%s  %s ____________%s\n%s|          |%s   %s|          |%s\n%s| *      * |%s   %s| *      * |%s\n%s| *      * |%s   %s| *      * |%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR);
        printf("%s| *      * |%s   %s| *      * |%s\n%s|__________|%s   %s|__________|%s\n",COL(33),COL_CLEAR,COL(31),COL_CLEAR,COL(33),COL_CLEAR,COL(31),COL_CLEAR );
        break;
      }
      break;
    }
    res_1=res_1+res_2;
    return res_1;
  }
}
int Dado::Tira_2(){
  printf("\n%s____________%s\n%s|          |%s\n%s|          |%s\n%s|     *    |%s\n%s|          |%s\n%s|__________|%s\n",COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR);
  cout<<"PREMI INVIO PER TIRARE IL DADO\n";
  if(getc(stdin) != 13){
    res_1=((rand() % 599)+1);
    res_1=(res_1/100)+1;
    switch (res_1) {
      case 1:
      printf("%s____________%s\n%s|          |%s\n%s|          |%s\n%s|     *    |%s\n%s|          |%s\n%s|__________|%s",COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR);
      break;
      case 2:
      printf("%s____________%s\n%s|          |%s\n%s| *        |%s\n%s|          |%s\n%s|        * |%s\n%s|__________|%s",COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR);
      break;
      case 3:
      printf("%s____________%s\n%s|          |%s\n%s| *        |%s\n%s|     *    |%s\n%s|        * |%s\n%s|__________|%s",COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR);
      break;
      case 4:
      printf("%s____________%s\n%s|          |%s\n%s| *      * |%s\n%s|          |%s\n%s| *      * |%s\n%s|__________|%s",COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR);
      break;
      case 5:
      printf("%s____________%s\n%s|          |%s\n%s| *      * |%s\n%s|     *    |%s\n%s| *      * |%s\n%s|__________|%s",COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR);
      break;
      case 6:
      printf("%s____________%s\n%s|          |%s\n%s| *      * |%s\n%s| *      * |%s\n%s| *      * |%s\n%s|__________|%s",COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR,COL(33),COL_CLEAR);
      break;
    }

  }

  return res_1;
}
