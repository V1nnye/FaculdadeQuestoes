// Exercicio003.cpp
// Autor: Vinicius Rocha Miranda Souza
// Finalidade: Operacoes realizadas sobre os profutos de um deposito
// Data de criacao: 22/09/2021
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

#define MAX_PRODUTOS 10

// --- SOLUÇÃO (início) ---
class Produto {
  private:
    int codigo;
    string descricao;
    int quantidade;
    float valor;
  public:
    Produto(int c = 0, string d = "", int q = 0, float v = 0.00){
      this->codigo = c;
      this->descricao = d;
      this->quantidade = q;
      this->valor = v;
    }
    int obtemCodigo(){
      return codigo;
    }
    string obtemDescricao(){
      return descricao;
    }
    int obtemQuantidade(){
      return quantidade;
    }
    float obtemValorUnitario(){
      return valor;
    }
    void defineCodigo(int c){
      this->codigo = c;
    }
    void defineDescricao(string d){
      this->descricao = d;
    }
    void defineQuantidade(int q){
      this->quantidade = q;
    }
    void defineValorUnitario(float v){
      this->valor = v;
    }
    string str(){
      stringstream ss;
      ss << "[" << obtemCodigo() << "] " << obtemDescricao() << ": " << obtemQuantidade() << "x" << fixed << setprecision(2) << obtemValorUnitario();
      return ss.str();
    }
};

class Estoque {
  private:
    string deposito;
    Produto *produto[MAX_PRODUTOS] = {0};
    int numProdutos;
  public:
    Estoque(string d = "", int np = 0){
      this->deposito = d;
      this->numProdutos = np;
    }
    string obtemDeposito(){
      return deposito;
    }
    int obtemNumProdutos(){
      return numProdutos;
    }
    Produto *obtemProduto(int i){
      if(i<0 || i>=numProdutos)
        return nullptr;
      return produto[i];
    }
    void defineDeposito(string d){
      this->deposito = d;
    }
    bool adicionaProduto(Produto *p){
      if(numProdutos < MAX_PRODUTOS){
        produto[numProdutos] = p;
        numProdutos++;
        return true;
      }
      return false;
    }
    float calculaTotalEstoque(){
      float total_estoque = 0, temp = 0;
      for(int i = 0; i < numProdutos; i++){
        temp = produto[i]->obtemQuantidade() * produto[i]->obtemValorUnitario();
        total_estoque += temp;
      }
      return total_estoque;
    }
    string str(){
      stringstream buffer;
      buffer << "Deposito: " << obtemDeposito() << endl;
      for(int i = 0; i < numProdutos; i++)
        buffer << produto[i]->str() << endl;
      if(calculaTotalEstoque() != 0)
        buffer << "TOTAL DO ESTOQUE = " << fixed << setprecision(2) << calculaTotalEstoque() << endl;
      
      return buffer.str();
      
    }
};
// --- SOLUÇÃO (fim) ---

int main() {
    Produto *produto[] = {
        new Produto(1,"Cimento CP IV 32 25kg Votoran", 500, 17.29),
        new Produto(2,"Cimento CPB-40 Branco Estrutural 15kg Axton", 100, 72.90),
        new Produto(3,"Rejunte Ceramica Ceramfix Marfim 1kg", 50, 7.00),
        new Produto(4,"Luva PVC Branco Rosca 1/2\" 20mm Plastilit", 60, 1.47),
        new Produto(5,"Luva PVC Marrom Solda 1\" 32mm Tigre", 30, 2.79),
        new Produto(6,"Meio Bloco Ceramico 6 Furos 9x14x12cm Olaria Estancia", 10000, 0.76),
        new Produto(7,"Bloco de Concreto Celular Autoclavado 60x30x10cm Sical", 1000, 13.99),
        new Produto(8,"Telha Ceramica 40x22,5cm Francesa Esmaltada Chumbo Vogel", 300, 2.79),
        new Produto(9,"Telha Cerâmica 41x24cm Portuguesa Natural Cláudio Vogel", 1000, 0.94),
        new Produto(10,"Janela de Correr Alumínio Pintado Preto Fosco 1,00x1,50m Linha Confort Brimak", 10, 574.90),
        new Produto(11,"Folha de Porta de Giro Branco 2,10x0,70m Artens", 5, 219.90)
    };
    int numProdutos = sizeof(produto)/sizeof(Produto *);
    
    Estoque *estoque = new Estoque("Provisorio");
    cout << estoque->str() << endl;

    estoque->defineDeposito("Deposito Geral");
  
    int p;
    // Insere 5 produtos
    for (p=0; p<5; ++p)
        if (!estoque->adicionaProduto(produto[p])) { cerr << "ERRO"; exit(1); }
    // Testa se os 5 produtos foram inseridos
    for (p=0; p<5; ++p)
        if (estoque->obtemProduto(p) != produto[p]) { cerr << "ERRO"; exit(1); }
    // Testa se há outros itens no estoque
    for (; p<numProdutos; ++p)
        if (estoque->obtemProduto(p) != nullptr) { cerr << "ERRO"; exit(1); }
    cout << estoque->str() << endl;
    // Adiciona mais 5 produtos
    for (p=5; p<MAX_PRODUTOS; ++p)
        if (!estoque->adicionaProduto(produto[p])) { cerr << "ERRO"; exit(1); }
    // Tenta adicionar produtos além do limite
    for (; p<numProdutos; ++p)
        if (estoque->adicionaProduto(produto[p])) { cerr << "ERRO"; exit(1); }
    // Testa se os 10 produtos estao inseridos
    for (p=0; p<MAX_PRODUTOS; ++p)
        if (estoque->obtemProduto(p) != produto[p]) { cerr << "ERRO"; exit(1); }
    cout << estoque->str() << endl;

    delete estoque;
    for (int p=0; p<numProdutos; ++p)
        delete produto[p];
    
    return 0;
}