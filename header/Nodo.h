#include<iostream>
using namespace std;

class Nodo{

      private:
            Persona *nome_g;
      		   int num;
               Nodo *succ;
               int tip_cas;
			   string nome_effetto;
      public: Nodo();
              ~Nodo();
              void SetType(int t);
              void SetNum(int n);
              void SetNome(Persona *x);
              void SetSucc(Nodo *x);
              Persona *GetNome();
              int GetNum();
              int GetType();
			  Nodo* GetSucc();
};
