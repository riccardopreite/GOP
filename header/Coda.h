#include<iostream>
using namespace std;



class Coda{

	private:
		int coda[10];
		int l;
	public:
			Coda();
			Coda(int n);
			~Coda();
			void Shift(int val);
			void Visualizza();
			bool Find(int val);
};
