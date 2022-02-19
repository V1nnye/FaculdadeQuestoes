// Exercicio004.cpp
// Autor: Vinicius Rocha Miranda Souza
// Finalidade: Operacoes realizadas sobre valores de tempo
// Data de criacao: 27/09/2021
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;    

class Hora {
private:
    int hora, minuto, segundo;
public:
    Hora();
    Hora(int h, int m, int s);
    ~Hora();
    int obtemHora() const;
    int obtemMinuto() const;
    int obtemSegundo() const;
    void defineHora(int h);
    void defineMinuto(int m);
    void defineSegundo(int s);
    string str() const;
    Hora operator+(const Hora &hr);
    friend ostream &operator<<(ostream &out, const Hora &h);
    friend istream &operator>>(istream &in, Hora &h);
};

ostream &operator<< (ostream &out, const Hora &h){
  out << setw(2) << setfill('0')  << h.hora << ":" << setw(2) << setfill('0') << h.minuto  << ":" << setw(2) << setfill('0') << h.segundo;
  return out;
}
istream &operator>> (istream &in, Hora &h){
  in >> h.hora;
  in >> h.minuto;
  in >> h.segundo;
  return in;
}

Hora::Hora(){
}
Hora::Hora(int h, int m, int s){
  this->hora = h;
  this->minuto = m;
  this->segundo = s;
}
Hora::~Hora(){
}
int Hora::obtemHora() const{
  return hora;
}
int Hora::obtemMinuto() const{
  return minuto;
}
int Hora::obtemSegundo() const{
  return segundo;
}
void Hora::defineHora(int h){
  this->hora = h;
}
void Hora::defineMinuto(int m){
  this->minuto = m;
}
void Hora::defineSegundo(int s){
  this->segundo = s;
}
string Hora::str() const{
  stringstream buffer;
  buffer << obtemHora() << ":" << obtemMinuto() << ":" << obtemSegundo() << endl;
  return buffer.str();
}
Hora Hora::operator+(const Hora &hr){
  int x,y,z;
  x = segundo+hr.obtemSegundo();
  y = minuto+hr.obtemMinuto();
  z = hora+hr.obtemHora();
  if(x >= 60){
    x = (segundo+hr.obtemSegundo()) - 60;
    y += 1;
  }
  if(y >= 60){
    y -= 60;
    z += 1;
  }
  if(z >= 24){
    z -= 24;
  }
  return Hora(z, y, x);
}

int main() {
    Hora h1, h2;
    cin >> h1;
    cin >> h2;
    Hora h3 = h1 + h2;
    cout << h3 << endl;
    return 0;
}
