//Exercicio 008
//Autor: Vinicius Rocha Miranda Souza
//Finalidade: Encontrar numeros primos
//Data de criação: 26/08/2021
//Nao consegui concluir

#include <iostream>

using namespace std;

int main(){
  int vetor[9];
  
  int i = 0;
  while(i < 9){
    cin >> vetor[i];
    i++;
  }

  for(i = 0; i < 9; i++){
    if(vetor[i] == 2) cout << vetor[i] << " " << i << " \n";
    if(vetor[i] == 3) cout << vetor[i] << " " << i << " \n";

    if(vetor[i] >= 2){
      if(vetor[i] % 2 != 0){
        if(vetor[i] % 3 != 0){
          if(vetor[i] % 5 != 0){
            if(vetor[i] % 13 != 0){
        cout << vetor[i] << " " << i << " \n";
          }
        }
      }
    }
  }
}
return 0;
}