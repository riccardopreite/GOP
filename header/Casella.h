#include<iostream>
using namespace std;

class Casella{

      private:
            Persona *nome_g;
      		   int num;
               Casella *succ;
               int tip_cas;
      public: Casella();
              ~Casella();
              void SetType(int t);
              void SetNum(int n);
              void SetNome(Persona *x);
              void SetSucc(Casella *x);
              Persona *GetNome();
              int GetNum();
              int GetType();
			        Casella* GetSucc();
};
