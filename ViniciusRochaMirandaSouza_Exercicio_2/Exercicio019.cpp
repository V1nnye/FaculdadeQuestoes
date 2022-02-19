// Exercicio019.cpp
// Autor: Vinicius Rocha Miranda Souza
// Finalidade: Construcao do modelo de "inseto-robo" unidimensional
// Data de criacao: 03/09/2021

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum{DIREITA,ESQUERDA};

class Inseto {
  private:
    int pos = 0;
    int sent = DIREITA;
    int dist = 0;
  public:
    Inseto(int p = 0, int s = DIREITA, int d = 0){
      this-> pos = p;
      this-> sent = s;
      this-> dist = d;
    }

    void anda(){
      if(sent == DIREITA){
        pos++;
        dist++;
      }
      if(sent == ESQUERDA){
        pos--;
        dist++;
      }
    }
    void vira(){
      if(sent == DIREITA){
        sent = ESQUERDA;
      }
      else if(sent == ESQUERDA){
        sent = DIREITA;
      }
    }
    int obtemPosicao(){
      return pos;
    }
    int obtemDistancia(){
      return dist;
    }
};

int main() {
  string s;
  int pos;
  
  cin >> pos;
  cin >> s;
  Inseto inseto(pos);
  for (int i=0; i<s.size(); ++i) {
    char c = s.at(i);
    if (c=='.')
      inseto.anda();
    else if (c=='@')
      inseto.vira();
  }
  cout << inseto.obtemPosicao() << " " << inseto.obtemDistancia() << endl;
  return 0;
}
