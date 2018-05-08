#include "header.h"
Type::Type(){
  d1=Dado();
  CaricaMostri();
  CaricaOgettiMagici();
  CaricaMezzi();
  CaricaLuoghi();
  line=NULL;
  n=0;
}



void Type::esplora_luogo(int x, Persona* g){
  int parz=0;
  cout<<g->getNome()<<" Hai trovato: "<<luoghi[x].nome<<endl<<luoghi[x].info<<endl;
  if(x==2){
    parz=d1.Tira_2();
    cout<<"\nCon il primo dado hai fatto: "<<parz<<". Tira di nuovo!\n";
    lancio=d1.Tira_2();
    cout<<"\nCon il Secondo dado hai fatto: "<<lancio<<".\n";
    if(lancio==parz){
      cout<<"Hai fatto doppio! Raddoppi il tuo risultato.\n";
      lancio=lancio+parz;
      g->setCasella(g->getCasella()+lancio);
    }
    else {
      cout<<" Ops. Hai sbagliato strada! Perdi un turno per tornare indietro.\n";
      g->setstop(g->getstop()+1);
    }
    return;
  }
  lancio=d1.Tira();
  switch (x) {
    case 0:
    if(lancio%2==0){
      cout<<"Totalizzando "<<lancio<<" hai saltato il dirupo! Avanzi di una casella.\n";
      g->setCasella(g->getCasella()+1);
    }
    else if(lancio%2!=0){
      cout<<"Hai fatto solo: "<<lancio<<" Oh no! Sei caduto nel dirupo! Per risalire impieghi un turno!!\n";
      g->setstop(g->getstop()+1);
    }
    break;
    case 1:
    cout<<"Hai fatto: "<<lancio;
    if(lancio<4){
      cout<<"Stai attraversando pian piano il ghiaccio. Sei riuscito a non cadere.\n";
      g->setCasella(g->getCasella()+1);
    }
    else{
      cout<<" Ops. Hai il passo troppo pesante e rompi il ghiaccio! Perdi il turno per scaldarti.\n";
      g->setstop(g->getstop()+1);
    }
    break;
    case 3:
    if(lancio<=5){
      cout<<"Con "<<lancio<<" Sei caduto nel vulcano! Ritorna all'inizio!\n";
      g->setCasella(0);
    }
    else {
      cout<<"Con "<<lancio<<" Sei riuscito a superare il vulcano senza caderci. Hai avuto fortuna questa volta!\n";
    }
    break;

    case 4:
    if (lancio%2==0){
      cout<<"Non ti sei perso all'interno della foresta avanzi di: "<<lancio<<endl;
      g->setCasella(g->getCasella()+lancio);
    }
    else {
      cout<<"La foresta ti ha confuso torni indietro di "<<lancio<<endl;
    }
    g->setCasella(g->getCasella()-lancio);
    break;
    case 5:
    if(lancio%3==0){
      cout<<"Facendo "<<lancio<<" il pozzo ha divorato i tuoi ricordi. Non capisci più dove ti trovi e cosa stai facendo. Perdi tre turni per recuperare la memoria.\n";
      g->setstop(g->getstop()+3);
    }
    else {
      cout<<"Facendo "<<lancio<<" sei scampato alla potenza del pozzo dell'oblio, la tua memoria rimane intatta.\n";
    }
    break;
  }
}

void Type::raccogli_oggetto(int x, int lancio, Persona *g){

  cout<<g->getNome()<<" hai trovato: "<<oggettiMagici[x].nome<<oggettiMagici[x].effetto;
  switch (x) {
    case 0:
    g->setCasella(g->getCasella()+5);
    break;
    case 1:
    g->setCasella(g->getCasella()+3);
    break;
    case 2:
    g->setCasella((g->getCasella()+lancio)+1);
    break;
    case 3:
    g->setCasella(g->getCasella()+1);
    break;
    case 4:
    g->setCasella(g->getCasella()+3);
    break;
  }
}


void Type::cavalca_mezzo(int x, Persona *g){
  cout<<g->getNome()<<" "<<mezzi[x].nome<<endl<<mezzi[x].effetto;
  switch(x){
    case 0:
    lancio=d1.Tira();
    cout<<"Hai fatto: "<<lancio<<endl;
    if(lancio<9){
      g->setCasella(g->getCasella()+(lancio*2));
      cout<<"\nVai avanti di: "<<lancio*2<<" caselle\n";
    }
    else{
      cout<<"\nOh no! Sei caduto prosegui di una sola casella.\n";
      g->setCasella(g->getCasella()+1);
    }
    break;
    case 1:
    lancio=d1.Tira();
    cout<<"Primo lancio: "<<lancio<<"\nOra tira per la seconda volta.\n";
    lancio=lancio+d1.Tira();
    cout<<"Secondo lancio: "<<lancio<<"\nOra tira per la terza volta.\n";
    lancio=lancio+d1.Tira();
    cout<<"Hai fatto: "<<lancio<<endl;
    if(lancio>=20){
      cout<<"\nHai domato il Drago! Adesso puoi cavalcarlo!\n";
      g->setCasella(g->getCasella()+25);
    }
    else{
      cout<<"\nOh no! Il drago ti sta attaccando.\n Scappi via dalla grotta avanzando di 1.\n";
      g->setCasella(g->getCasella()+1);
    }
    break;
    case 2:
    lancio=d1.Tira();
    cout<<"Hai fatto: "<<lancio<<endl;
    if((lancio==2) || (lancio==5) || (lancio==10)){
      cout<<"\nLo straniero ti accompagna per 15 caselle.\n";
      g->setCasella(g->getCasella()+15);
    }
    else{
      cout<<"\nLo straniero ti ha lasciato a piedi. Rimani dove ti trovi.\n";
    }
    break;
  }
}


void Type::combatti_mostro(int x,Persona *g){
  char sconfiggi;
  cout<<g->getNome()<<" Devi combattere contro: "<<mostri[x].nome<<"Per vincere fai più di: "<<mostri[x].nbattere<<endl;
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
  lancio=d1.Tira();
  cout<<"Hai fatto: "<<lancio<<endl;
  if (lancio>mostri[x].nbattere){
    cout<<"Complimenti hai sconfitto quel mostro! Non ti tocca tornare all'inizio.\n";
  }
  else{
    cout<<"Oh no! "<<g->getNome()<< " non sei riuscito a sconfiggere il mostro, devi tornare all'inizio!\n";
    g->setCasella(0);
  }
}


void Type::CaricaMostri(){
  int x = 0;
  FILE* fin;
  line=NULL;

  fin=fopen("./FileCaselle/mostri.txt","r");
  while (x<9){
    getline(&line, &n, fin);
    mostri[x].nome = line;
    getline(&line, &n, fin);
    mostri[x].nbattere = atoi(line);
    x++;
  }
  fclose(fin);
}


void Type::CaricaOgettiMagici(){
  int x = 0;
  FILE* fin;
  line=NULL;

  fin=fopen("./FileCaselle/oggettimagici.txt","r");
  while (x<5)
  {
    getline(&line, &n, fin);
    oggettiMagici[x].nome = line;
    getline(&line, &n, fin);
    oggettiMagici[x].effetto = line;
    x++;
  }
  fclose(fin);
}


void Type::CaricaMezzi(){
  int x = 0;
  FILE* fin;
  line=NULL;

  fin=fopen("./FileCaselle/mezzi.txt","r");
  while (x<3){
    getline(&line, &n, fin);
    mezzi[x].nome = line;
    getline(&line, &n, fin);
    mezzi[x].effetto = line;
    x++;
  }
  fclose(fin);
}


void Type::CaricaLuoghi(){
  int x = 0;
  FILE* fin;
  line=NULL;


  fin=fopen("./FileCaselle/luoghi.txt","r");
  while (x<6){
    getline(&line, &n, fin);
    luoghi[x].nome = line;
    getline(&line, &n, fin);
    luoghi[x].info = line;
    x++;
  }

  fclose(fin);
}
