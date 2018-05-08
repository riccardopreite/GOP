
class Giocatori{
protected:
	Persona *head;
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
};
