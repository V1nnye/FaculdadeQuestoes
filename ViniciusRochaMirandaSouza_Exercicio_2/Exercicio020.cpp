// Exercicio020.cpp
// Autor: Vinicius Rocha Miranda Souza
// Finalidade: Simulacoes as operacoes feitas em uma conta
// Data de criacao: 05/09/2021
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class ContaCorrente {
  private:
    string numero;
    string titular;
    double limite;
    double saldo;
    int dia_negado = 0;
  public:
    ContaCorrente(string n="", string t="", double l=0.0){
      this -> numero = n;
      this -> titular = t;
      this -> limite = l;
      saldo = 0;
    }
    void deposita(double v){
      saldo += v;
    }
    bool debita(double v) {
      if ( saldo - v >= limite * -1 ){
        saldo -= v;
        return true;
      }else{
        dia_negado++;
        return false;
      }
    }
    string obtemNumero(){
      return numero;
    }
    string obtemTitular(){
      return titular;
    }
    double obtemLimite(){
      return limite;
    }
    double obtemSaldo(){
      return saldo;
    }
    void aplicaJuros(){
      if ( saldo < 0 ) saldo = saldo + (0.001 * saldo);
    }
    int dia_Negado(){
      return dia_negado;
    }
};

int main(){
  string numero, titular;
  double limite, valor = 0;
  bool esta_rodando = true;
  int dia = 0;
 
  getline(cin, numero);
  getline(cin, titular);
  cin >> limite;

  ContaCorrente conta(numero, titular, limite);

  while(esta_rodando){
    char sinal;

    cin >> sinal;
    if(sinal == '+'){
      cin >> valor;
      conta.deposita(valor);
    }
    else if(sinal == '-'){
      cin >> valor;
      conta.debita(valor);
    }
    else if(sinal == ','){
      if(conta.obtemSaldo() < 0){
        dia++;
        conta.aplicaJuros();
      }
    }
    else if(sinal == '.'){
      if(conta.obtemSaldo() < 0){
        conta.aplicaJuros();
        dia++;
      }
        esta_rodando = false;
    }
  }

  cout << conta.obtemNumero() << endl;
  cout << conta.obtemTitular() << endl;
  cout << fixed << setprecision(4) << conta.obtemLimite() << endl;
  cout << fixed << setprecision(4) << conta.obtemSaldo() << endl;
  cout << dia << endl;
  cout << conta.dia_Negado() << endl;

  return 0;
}
