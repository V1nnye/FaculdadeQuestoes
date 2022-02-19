// Exercicio003.cpp
// Autor: Vinicius Rocha Miranda Souza
// Finalidade: Utilizar os conceitos de heranca para interagir a classe equipe com a clube, alem de contabilizar e realizar operacoes sobre a pontuacao dos times
// Data de criacao: 04/11/2021
#include <iostream>
#include <iomanip>

using namespace std;

// --- SOLUÇÃO (início) ---
class Clube{
  private:
    string abreviatura;
    string nome;
    string nomeCompleto;
    string cidade;
    string estado;
  public:
   Clube(string abrev = "", string nom = "", string nomComp = "", string cid = "", string est = "");
   ~Clube();

   string obtemAbreviatura();
   string obtemNome();
   string obtemNomeCompleto();
   string obtemCidade();
   string obtemEstado();

   void defineAbreviatura(string abrev);
   void defineNome(string nom);
   void defineNomeCompleto(string nomComp);
   void defineCidade(string cid);
   void defineEstado(string est);
};

Clube::Clube(string abrev, string nom, string nomComp, string cid, string est){
  this->abreviatura = abrev;
  this->nome = nom;
  this->nomeCompleto = nomComp;
  this->cidade = cid;
  this->estado = est;
}
Clube::~Clube(){
}

string Clube::obtemAbreviatura(){
 return abreviatura;
}
string Clube::obtemNome(){
 return nome;
}
string Clube::obtemNomeCompleto(){
 return nomeCompleto;
}
string Clube::obtemCidade(){
 return cidade;
}
string Clube::obtemEstado(){
 return estado;
}

void Clube::defineAbreviatura(string abrev){
 this->abreviatura = abrev;
}
void Clube::defineNome(string nom){
 this->nome = nom;
}
void Clube::defineNomeCompleto(string nomComp){
 this->nomeCompleto = nomComp;
}
void Clube::defineCidade(string cid){
 this->cidade = cid;
}
void Clube::defineEstado(string est){
 this->estado = est;
}

class Equipe : public Clube{
  private:
    int pontos, jogos, vitorias;
    int empates, derrotas, golsFeitos, golsTomandos;
  public:
    Equipe(string abrev = "", string nom = "", string nomComp = "", string cid = "", string est = "", int pont = 0, int jog = 0, int vit = 0, int emp = 0, int der = 0, int glsF = 0, int glsT = 0);
    ~Equipe();

    int obtemPontos();
    int obtemJogos();
    int obtemVitorias();
    int obtemEmpates();
    int obtemDerrotas();
    int obtemGolsFeitos();
    int obtemGolsTomados();

    void registraJogo(int glsF, int glsT);
};

Equipe::Equipe(string abrev, string nom, string nomComp, string cid, string est, int pont, int jog, int vit, int emp, int der, int glsF, int glsT) : Clube(abrev, nom, nomComp, cid, est){
  this->pontos = pont;
  this->jogos = jog;
  this->vitorias = vit;
  this->empates = emp;
  this->derrotas = der;
  this->golsFeitos = glsF;
  this->golsTomandos = glsT;
}
Equipe::~Equipe(){
}

int Equipe::obtemPontos(){
  return pontos;
}
int Equipe::obtemJogos(){
  return jogos;
}
int Equipe::obtemVitorias(){
  return vitorias;
}
int Equipe::obtemEmpates(){
  return empates;
}
int Equipe::obtemDerrotas(){
  return derrotas;
}
int Equipe::obtemGolsFeitos(){
  return golsFeitos;
}
int Equipe::obtemGolsTomados(){
  return golsTomandos;
}

void Equipe::registraJogo(int glsF, int glsT){
  jogos++;
  if(glsF > glsT){
    vitorias++;
    pontos += 3;
    golsFeitos += glsF;
    golsTomandos += glsT;
  }
  else if(glsF < glsT){
    derrotas++;
    golsFeitos += glsF;
    golsTomandos += glsT;
  }
  else{
    empates++;
    pontos += 1;
    golsFeitos += glsF;
    golsTomandos += glsT;
  }
}
// --- SOLUÇÃO (fim) ---

void imprimeClube(Clube *c) {
    cout << "Abreviatura: " << c->obtemAbreviatura() << endl;
    cout << "Nome: " << c->obtemNome() << endl;
    cout << "Nome completo: " << c->obtemNomeCompleto() << endl;
    cout << "Cidade: " << c->obtemCidade() << endl;
    cout << "Estado: " << c->obtemEstado() << endl;
    cout << "----------" << endl;
}

void imprimeEquipe(Equipe *e) {
    cout << "Abreviatura: " << e->obtemAbreviatura() << endl;
    cout << "Nome: " << e->obtemNome() << endl;
    cout << "Nome completo: " << e->obtemNomeCompleto() << endl;
    cout << "Cidade: " << e->obtemCidade() << endl;
    cout << "Estado: " << e->obtemEstado() << endl;
    cout << "Pontos: " << e->obtemPontos() << endl;
    cout << "Jogos: " << e->obtemJogos() << endl;
    cout << "Vitorias: " << e->obtemVitorias() << endl;
    cout << "Empates: " << e->obtemEmpates() << endl;
    cout << "Derrotas: " << e->obtemDerrotas() << endl;
    cout << "Gols Feitos: " << e->obtemGolsFeitos() << endl;
    cout << "Gols Tomados: " << e->obtemGolsTomados() << endl;
    cout << "----------" << endl;
}

int main() {
    Clube bah("BAH","Bahia","Esporte Clube Bahia","Salvador","BA");
    imprimeClube(&bah);
    Clube fla;
    imprimeClube(&fla);
    fla.defineAbreviatura("FLA");
    fla.defineNome("Flamengo");
    fla.defineNomeCompleto("Clube de Regatas do Flamengo");
    fla.defineCidade("Rio de Janeiro");
    fla.defineEstado("RJ");
    imprimeClube(&fla);
    
    Equipe flu("FLU","Fluminense","Fluminense Football Club","Rio de Janeiro","RJ");
    flu.registraJogo(0,0);
    flu.registraJogo(1,0);
    flu.registraJogo(2,2);
    flu.registraJogo(1,0);
    flu.registraJogo(1,1);
    flu.registraJogo(0,1);
    flu.registraJogo(1,1);
    flu.registraJogo(1,4);
    flu.registraJogo(1,0);
    flu.registraJogo(0,0);
    flu.registraJogo(2,1);
    flu.registraJogo(0,1);
    flu.registraJogo(0,1);
    flu.registraJogo(0,1);
    flu.registraJogo(2,4);
    flu.registraJogo(1,1);
    flu.registraJogo(2,0);
    flu.registraJogo(1,1);
    flu.registraJogo(2,1);
    flu.registraJogo(2,1);
    flu.registraJogo(2,2);
    flu.registraJogo(2,1);
    flu.registraJogo(0,2);
    flu.registraJogo(0,0);
    imprimeEquipe(&flu);
    Equipe cap;
    imprimeEquipe(&cap);
    cap.defineAbreviatura("CAP");
    cap.defineNome("Athletico-PR");
    cap.defineNomeCompleto("Club Athletico Paranaense");
    cap.defineCidade("Curitiba");
    cap.defineEstado("PR");
    cap.registraJogo(1,0);
    cap.registraJogo(3,0);
    cap.registraJogo(1,0);
    cap.registraJogo(2,1);
    cap.registraJogo(1,2);
    cap.registraJogo(2,2);
    cap.registraJogo(4,1);
    cap.registraJogo(2,1);
    cap.registraJogo(1,2);
    cap.registraJogo(2,2);
    cap.registraJogo(0,1);
    cap.registraJogo(2,1);
    cap.registraJogo(0,2);
    cap.registraJogo(1,2);
    cap.registraJogo(0,1);
    cap.registraJogo(0,1);
    cap.registraJogo(1,2);
    cap.registraJogo(0,0);
    cap.registraJogo(0,2);
    cap.registraJogo(2,1);
    cap.registraJogo(4,2);
    cap.registraJogo(0,3);
    cap.registraJogo(2,0);
    cap.registraJogo(0,2);
    imprimeEquipe(&cap);

    return 0;
}