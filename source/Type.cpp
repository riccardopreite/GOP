#include "header.h"

Type::Type(){
  d1=Dado();
  d2=Dado();
  CaricaMostri();
  CaricaOgettiMagici();
  CaricaMezzi();
  CaricaLuoghi();
}

Type::~Type(){
}

void Type::cavalca_mezzo(int x, Persona *g){
  if(x == 0){
    cout<<g->getNome()<<" Hai rubato un cavallo."<<endl;
    cout<<"Oh no ti hanno scoperto! Lancia due dadi. Se mantieni la calma e fai meno di 9, riesci a raddoppiare il risultato fuggendo.\nAltrimenti cadi dalla fretta, il contadino ti picchia e avanzi di una casella strisciando\n";
    if(getc(stdin) != 13){
      lancio=d1.Tira()+d2.Tira();
      cout<<"Hai fatto: "<<lancio<<endl;
    }
    if(lancio<9){
      g->setCasella(g->getCasella()+(lancio*2));
      cout<<"\nVai avanti di: "<<lancio*2<<" caselle\n";
    }
    else{
      cout<<"\nOh no! Sei caduto prosegui di una sola casella.\n";
      g->setCasella(g->getCasella()+1);
    }
  }
  else if(x == 1){
    cout<<g->getNome()<<" Hai trovato un drago. Per domarlo tira tre volte il dado e totalizza almeno 15 e avanzi volando di 25 caselle.\nAltrimenti scappi a gambe levate e vai avanti di una casella"<<endl;
    if(getc(stdin) != 13){
      lancio=d1.Tira()+d2.Tira();
      lancio=lancio+d1.Tira();
      cout<<"Hai fatto: "<<lancio<<endl;
    }
    if(lancio>=15){
      cout<<"\nHai domato il Drago! Adesso puoi cavalcarlo!\n";
      g->setCasella(g->getCasella()+25);
    }
    else{
      cout<<"\nOh no! Il drago ti sta attaccando.\n Scappi via dalla grotta avanzando di 1.\n";
      g->setCasella(g->getCasella()+1);
    }
  }
  else if(x==2){
    cout<<"Uno straniero ti offre un passaggio sulla sua carovana ad una condizione, tira due dadi,se totalizzi un punteggio uguale a 2,5 o 10 ti accompogna per 15 caselle. Altrimenti continui a piedi.\n";
    if(getc(stdin) != 13){
      lancio=d1.Tira()+d2.Tira();
      lancio=lancio+d1.Tira();
      cout<<"Hai fatto: "<<lancio<<endl;
    }
    if((lancio==2) || (lancio==5) || (lancio==10)){
      cout<<"\nLo straniero ti accompagna per 15 caselle.\n";
      g->setCasella(g->getCasella()+15);
    }
    else{
      cout<<"\nLo straniero ti ha lasciato a piedi. Rimani dove ti trovi.\n";
    }
  }
}


void Type::combatti_mostro(int x,Persona *g){
  char sconfiggi;
  cout<<g->getNome()<<" Devi combattere contro: "<<mostri[x].nome<<"Per vincere fai più di: "<<mostri[x].nbattere;
  if(g->getSconfiggi()==true){
    cout<<"\nHai a disposizione una magia. La vuoi usare? Y/N\n";
    while(true){
      sconfiggi=getc(stdin);
      if(sconfiggi=='y' || sconfiggi=='Y'){
        d1.err_input();
        cout<<"Hai usato la magia! Il mostro è morto.\n";
        g->setstop(false);
        return;
      }
      else if(sconfiggi=='n' || sconfiggi=='N'){
        d1.err_input();
        cout<<"Allora lancia i dadi e sconfiggi il mostro. Buona fortuna!\n";
        break;
      }
    }
  }
  if(getc(stdin) != 13){
    lancio=d1.Tira()+d2.Tira();
    cout<<"Hai fatto: "<<lancio<<endl;
    if (lancio>mostri[x].nbattere){
      cout<<"Complimenti hai sconfitto quel mostro! Non ti tocca tornare all'inizio.\n";
    }
    else{
      cout<<"Oh no! "<<g->getNome()<< " non sei riuscito a sconfiggere il mostro, devi tornare all'inizio!\n";
      g->setCasella(0);
    }
  }
}


void Type::CaricaMostri(){
  int x = 0;
  FILE* fin;
  size_t n=0;
  char* line;
  fin=fopen("FileCaselle/mostri.txt","r");
  while (x<9){
    getline(&line, &n, fin);
    mostri[x].nome = line;
    getline(&line, &n, fin);
    mostri[x].nbattere = atoi(line);
    mostri[x].cont=0;
    x++;
  }
  fclose(fin);
}


void Type::CaricaOgettiMagici(){
  int x = 0;
  FILE* fin;
  size_t n=0;
  char* line;
  fin=fopen("FileCaselle/oggettimagici.txt","r");
  while (x<5)
  {
    getline(&line, &n, fin);
    oggettiMagici[x].nome = line;
    getline(&line, &n, fin);
    oggettiMagici[x].operatore = line;
    getline(&line, &n, fin);
    oggettiMagici[x].navanti= atoi(line);
    oggettiMagici[x].cont = 0;
    x++;
  }
  fclose(fin);
}


void Type::CaricaMezzi(){
  int x = 0;
  FILE* fin;
  size_t n=0;
  char* line;
  fin=fopen("FileCaselle/mezzi.txt","r");
  while (x<3){
    getline(&line, &n, fin);
    mezzi[x].nome = line;
    mezzi[x].cont = 0;
    x++;
  }
  fclose(fin);
}


void Type::CaricaLuoghi(){
  int x = 0;
  FILE* fin;
  size_t n=0;
  char* line;
  fin=fopen("FileCaselle/luoghi.txt","r");
  while (x<6){
    getline(&line, &n, fin);
    luoghi[x].nome = line;
    getline(&line, &n, fin);
    luoghi[x].info = line;
    x++;
  }
  fclose(fin);
}
