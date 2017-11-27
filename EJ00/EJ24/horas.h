class Horas {
public:
    
    Horas() : h(0), m(0), s(0) {};
    Horas(int horas, int minutos, int segundos) {
        if (horas > 23 || minutos > 60 || segundos > 60) throw std::invalid_argument("ERROR");
        else if (horas < 0 || minutos < 0 || segundos < 0) throw std::invalid_argument("ERROR");
        else {
            h = horas;
            m = minutos;
            s = segundos;
        }
    };
    
    friend std::istream & operator >> (std::istream & in, Horas & h) {
        try {
            char ignor;
            int hEntrada, mEntrada, sEntrada;
            in >> hEntrada >> ignor>> mEntrada;
            h = Horas(hEntrada, mEntrada, 0);
            return in;
        }
        catch (std::invalid_argument & e) { throw e; }
    }
    
    friend std::ostream & operator << (std::ostream & os, Horas & h) {
        os << std::setw(2) << std::setfill('0')<< h.h << ':'<<std::setw(2) << std::setfill('0')<< h.m << ':' <<std::setw(2) << std::setfill('0')<< h.s;
        return os;
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
