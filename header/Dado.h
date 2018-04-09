#include<iostream>
using namespace std;
#include<ctime>
#include<cstdlib>


class Dado{
private:
  int res_1;
  int res_2;
public:
  Dado();
  ~Dado();
  int Tira();
  int Tira_2();
  void err_input();

};
