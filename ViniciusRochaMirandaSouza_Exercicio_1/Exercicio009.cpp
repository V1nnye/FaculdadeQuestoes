//Exercicio 009
//Autor: Vinicius Rocha Miranda Souza
//Finalidade: Realizar operações sobre um array bidimensional
//Data de criação: 23/08/2021

#include <iostream>

using namespace std;

int main(){
  int matriz[6][4] = {0};
  int i = 0,j = 0;
  int maior[6] = {0};

  for(i = 0; i < 6; i++){
    for(j = 0; j < 4; j++){
      cin >> matriz[i][j];
    }
    cout << "\n";
  }

  for(i = 0; i < 6; i++){
    for(j = 0; j < 4; j++){
      if(maior[i] < matriz[i][j]){
        maior[i] = matriz[i][j];
      }
    }
  }

  for(i = 0; i < 6; i++){
    for(j = 0; j < 4; j++){
      matriz[i][j] *= maior[i];
      cout << matriz[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}