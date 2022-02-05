//Exercicio 007
//Autor: Vinicius Rocha Miranda Souza
//Finalidade: Catalogar 3 atributos e realizar operações sobre esses valores
//Data de modificação: 26/08/2021

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int idade[10];
  float peso[10], altura[10];

  int i = 0;
  while(i < 10){
  cin >> idade[i];
  cin >> peso[i];
  cin >> altura[i];
  i++;
  }

  float auxiliar = 0;
  for(i = 0; i < 10; i++){
    auxiliar += idade[i];
  }
  auxiliar = auxiliar/10;

  int contador = 0;
  for(i = 0; i < 10; i++){
    if(peso[i] > 90){
      if(altura[i] < 1.5){
      contador++;
      }
    }
  }

  float porcentagem = 0;
  int total = 0;
  for(i = 0; i < 10; i++){
    if(altura[i] > 1.9){
      total++;
      if(idade[i] > 10){
        if(idade[i] < 30){
          porcentagem++;
        }
      }
    }
  }
  porcentagem = (porcentagem/total)*100;

  cout << fixed << setprecision(4);
  cout << auxiliar << " ";
  cout << contador << " ";
  cout << porcentagem << "\n";

  return 0;
}