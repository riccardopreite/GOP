
class deck{
private:
  int n_card;
  int queue[4];
  int cont;
  int lancio;
  Dado d1;
  Coda coda;
public:
    deck();
    void catch_card(Persona *g);
    void call_effect(int n_card, Persona *g);
    void effect_0(Persona *g);
    void effect_1(Persona *g);
    void effect_2(Persona *g);
    void effect_3(Persona *g);
    void effect_4(Persona *g);
    void effect_5();
    void effect_6(Persona *g);
    void effect_7(Persona *g);
    void effect_8(Persona *g);
    void effect_9(Persona *g);
    void effect_10(Persona *g);


};
