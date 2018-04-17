
class Giocatori{
private:
	Persona *head;
	Persona *next;
public:
	Giocatori();
	~Giocatori();
    Persona *scegli_primo();
	void aggiungi_giocatore(string nome);
	void stampa_giocatore(Persona *c);
	void stampa_posizione();
	Persona *player_turn(Persona *c);
	Persona *return_head();
	Persona *search_player(string nome);
	Persona *Set_first(int n_giocatori);
};
