#include <iostream>
#include <string>
#include <sstream>
#include <string.h>

using namespace std;

class Equipe{
  private:
    string clube;
    int pontos;

  public:
    Equipe(string c="", int p=0){
      clube = c;
      pontos = p;
    }
    string obtemClube(){
      return clube;
    }
    void defineClube(string c){
      clube = c;
    }
    int obtemPontos(){
      return pontos;
    }
    void definePontos(int p){
      pontos = p;
    }
    string toString() {
      stringstream ss;
      ss << clube << ": " << pontos << " pontos";
      return ss.str();
    }
    string toCSV() {
      stringstream ss;
      ss << clube << ";" << pontos;
      return ss.str();
    }
};

class Campeonato{
  private:
    class Nodo{
      public:
        Equipe *equipe;
        Nodo *prox, *ant;
        Nodo(Equipe *e){
          equipe = e;
          prox = ant = nullptr;
        }
    };
    Nodo *primeiro;
    int numEquipes;
  public:
    Campeonato();
    ~Campeonato();
    int obtemNumEquipes();
    Equipe *obtemEquipe(int indice);
    void insere(Equipe *e);
    void insere(string c, int p);
    void limpa();
};

Campeonato::Campeonato(){
  primeiro = nullptr;
}

Campeonato::~Campeonato(){
  limpa();
}

int Campeonato::obtemNumEquipes(){
  return numEquipes;
}

Equipe* Campeonato::obtemEquipe(int indice){
  Nodo *n;
  int j = 0;
  if( indice < 0 || indice >= numEquipes)
    return nullptr;
    n = primeiro;
    for(j = 0; j < indice; j++)
      n = n->prox;
    return n->equipe;
  }

void Campeonato::insere(string c, int p){
  insere(new Equipe(c,p));
}

void Campeonato::insere(Equipe *e){
  Nodo *n = new Nodo(e);
  //Inserindo ordenado
  if(primeiro == nullptr){
    n->prox = nullptr;
    n->ant = nullptr;
    primeiro = n;
  } else {
    Nodo *ante, *atual = primeiro;
    while(atual->equipe->obtemPontos() > e->obtemPontos()){
      ante = atual;
      atual = atual->prox;
    }
    while(atual->equipe->obtemPontos() == e->obtemPontos() && atual->equipe->obtemClube() < e->obtemClube()){
      ante = atual;
      atual = atual->prox;
    }
    if(atual == primeiro){
      n->ant = nullptr;
      primeiro->ant = n;
      n->prox = primeiro;
      primeiro = n;
    } else {
      n->prox = ante->prox;
      n->ant = ante;
      ante->prox = n;
      if(atual != nullptr)
        atual->ant = n;
      }
    }
  numEquipes++;
}

void Campeonato::limpa(){
  Nodo *n;
  while(primeiro != nullptr){
    n = primeiro;
    primeiro = primeiro->prox;
    delete n;
  }
  delete primeiro;
}

void mostraCampeonato(Campeonato *c) {
  int tam = c->obtemNumEquipes();
  for (int i=0; i<tam; ++i) {
    Equipe *e = c->obtemEquipe(i);
    cout << e->toString() << endl;
  }
  cout << "------------------" << endl;
}

int main(){
  Campeonato *brasileirao2021 = new Campeonato();
  mostraCampeonato(brasileirao2021);
  Equipe *e = new Equipe("Chapecoense",12);
  brasileirao2021->insere(e);
  mostraCampeonato(brasileirao2021);
  brasileirao2021->insere("Santos",28);
  brasileirao2021->insere("Bragantino",41);
  brasileirao2021->insere("Atletico Goianiense",31);
  mostraCampeonato(brasileirao2021);
  brasileirao2021->insere("Flamengo",42);
  brasileirao2021->insere("Atletico-MG",53);
  brasileirao2021->insere("Internacional",36);
  brasileirao2021->insere("Fluminense",33);
  brasileirao2021->insere("Juventude",28);
  brasileirao2021->insere("Sport",26);
  brasileirao2021->insere("Cuiaba",31);
  brasileirao2021->insere("Gremio",23);
  mostraCampeonato(brasileirao2021);
  brasileirao2021->insere("Corinthians",37);
  brasileirao2021->insere("Athletico-PR",33);
  brasileirao2021->insere("Palmeiras",40);
  brasileirao2021->insere("Sao Paulo",30);
  brasileirao2021->insere("Ceara",29);
  brasileirao2021->insere("Fortaleza EC",39);
  brasileirao2021->insere("Bahia",27);
  brasileirao2021->insere("America-MG",31);
  mostraCampeonato(brasileirao2021);
  delete brasileirao2021;
  return 0;
}
