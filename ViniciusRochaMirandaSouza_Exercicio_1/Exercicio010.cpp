//Exercicio 010
//Autor: Vinicius Rocha Miranda Souza
//Finalidade: Realizar calculos sobre datas
//Data de criação: 29/08/2021

#include <iostream>

using namespace std;

int main(){
  int i;
  int data_dia = 0, data_mes = 0, data_ano = 0;
  bool data_valida = false;
  bool imprime_data = false;
  struct registro{
    int dia;
    int mes;
    int ano;
  };
  registro data[5];
  for(i = 0; i < 5; i++){
    cin >> data[i].dia;
    cin >> data[i].mes;
    cin >> data[i].ano;
  }

  for(i = 0; i < 5; i++){
     if (data[i].ano > 0){
      if (data[i].mes >= 1 && data[i].mes <= 12){
        if ((data[i].dia >= 1 && data[i].dia <= 31) && (data[i].mes == 1 || data[i].mes == 3 || data[i].mes == 5 || data[i].mes == 7 || data[i].mes == 8 || data[i].mes == 10 || data[i].mes == 12))
                data_valida = true;
            else if ((data[i].dia >= 1 && data[i].dia <= 30) && (data[i].mes == 4 || data[i].mes == 6 || data[i].mes == 9 || data[i].mes == 11))
                data_valida = true;
            else if ((data[i].dia >= 1 && data[i].dia <= 28) && (data[i].mes == 2))
                data_valida = true;
            else if (data[i].dia == 29 && data[i].mes == 2 && (data[i].ano % 400 == 0 || (data[i].ano % 4 == 0 && data[i].ano % 100 != 0)))
                data_valida = true;
            else
                data_valida = false;
        } else {
            data_valida = false;
        }
    } else {
        data_valida = false;
    }

    if(data_valida == true){
      if(data_ano < data[i].ano) data_ano = data[i].ano;
      if(data_mes < data[i].mes) data_mes = data[i].mes;
      if(data_dia < data[i].dia) data_dia = data[i].dia;
      cout << "+" << endl;
      imprime_data = true;
    } else {
      cout << "-" << endl;
    }
 
  }

  if(imprime_data == true){
   cout << data_dia << "/" << data_mes << "/" << data_ano << endl;
  } else cout << "*" << endl;

return 0;
}