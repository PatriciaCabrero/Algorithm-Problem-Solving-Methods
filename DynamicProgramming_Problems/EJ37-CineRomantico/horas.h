#include <iostream>
class Horas {
public:
    
    Horas() : h(0), m(0), s(0) {};
    Horas(int horas, int minutos, int segundos) {
            h = horas;
            m = minutos;
            s = segundos;
    };
    
    friend std::istream & operator >> (std::istream & in, Horas & h) {
        char ignor;
        int hEntrada, mEntrada;
        in >> hEntrada >> ignor>> mEntrada;
        h = Horas(hEntrada, mEntrada, 0);
        return in;
    }
    
    bool operator <= (Horas & hora) {
        return (tiempototal() <= hora.tiempototal());
    }
    bool operator >= (Horas & hora) {
        return (tiempototal() >= hora.tiempototal());
    }
    bool operator < (Horas & hora) {
        return (tiempototal() < hora.tiempototal());
    }
    bool operator < (int mins) {
        return (tiempototal() < mins*60);
    }
    bool operator > (Horas & hora) {
        return (tiempototal() > hora.tiempototal());
    }
    bool operator > (int mins) {
        return (tiempototal() > mins*60);
    }
    bool operator == (Horas & h) {
        return tiempototal() == h.tiempototal();
    }
    int tiempototal(){
        return h * 3600 + m * 60 + s;
    }
    Horas operator + (int & h) {
        
        return tiempotoHoras(tiempototal() + h*60);
    }
    Horas tiempotoHoras(int T){
        Horas aux;
        aux.h = T/3600;
        aux.m = (T%3600)/60;
        aux.s = (T%3600)%60;
        return aux;
    }
private:
    
    int h, m, s;
    
};
