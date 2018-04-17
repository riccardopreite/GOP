
class Coda{

	private:
		int coda[10];
		int l;
		int cont;
	public:
			 Coda();
			 Coda(int n);
			~Coda();
			void Shift(int val);
			void Shift2();
			void Visualizza();
			bool Find(int val);
			int insert(int val);
};
