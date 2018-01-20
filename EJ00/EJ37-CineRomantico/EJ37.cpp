// VJ04, Patricia Cabrero Villar
/*
 CINE ROMÁNTICO
 
                duracionpelicula          si pi = 0
 minutos(i) = 
                max(0<k<i*)(minutos(k)) + duracionpelicula(i)  si
                    *siempre que i inicio >= k fin
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "Matriz.h"
#include "horas.h"

using namespace std;
struct Pelicula{
    Horas h;
    int T = 0;
    Horas fin;
    int sol = 0;
    void actualiza(){
        int aux = T+10;
        fin = h + aux;
        sol = T;
    }
};
bool operator<(Pelicula const& a, Pelicula const& b) {
    Horas c = a.fin, d = b.fin;
    return c < d;
}

class comparadorSol{
public:
    bool operator () (const Pelicula a, const Pelicula b){
        return a.sol > b.sol;
    }
};

// COSTE O(n^2) en tiempo y O(n) en espacio 
void resolver(std::vector<Pelicula> & cine, int & valor) {
    size_t n = cine.size();
    for (int i = 1; i < n; i++) {
        for(int j = 0; j < i ; j++){
            if ((cine[j].fin <= cine[i].h) && cine[i].sol < (cine[i].T+cine[j].sol)) {
                cine[i].sol = cine[i].T+cine[j].sol;
            }
        }
    }
    //Se recorre buscando el valor más alto
    for (int i=0; i<cine.size(); i++) {
        if(valor < cine[i].sol){
            valor = cine[i].sol;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nPelis;
    std::cin >> nPelis;
    if (nPelis == 0)return false;
    
    std::vector<Pelicula> Cine(nPelis);
    
    for (int i = 0; i < nPelis; i++)
    {
        std::cin >> Cine[i].h >> Cine[i].T;
        Cine[i].actualiza();
    }
    
    //COSTE N log N
    std::sort(Cine.begin(), Cine.end(), std::less<Pelicula>());
    
    int sol = 0;
    resolver(Cine, sol);
    
    // escribir sol
    std::cout << sol << endl;
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ37-CineRomantico/datos37.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    while (resuelveCaso())
        ;
    
    // Para restablacer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
