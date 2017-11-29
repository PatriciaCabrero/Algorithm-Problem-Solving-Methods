// VJ04, Patricia Cabrero Villar
/*
 Maratón de cine de terror
 
 Se ordenan las defensas en dos vectores de mayor a menor. Se intenta emparejar al mayor equipo de
 UCM contra el mayor de los invasores, sino puede superarle se le empareja con el menor de la UCM
 que no haya sido enviado a otra ciudad previamente. De esta manera seguimos teniendo el mayor
 equipo disponible de la UCM y enviamos el peor ya que es una batalla perdida siempre.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "horas.h"

struct Conferencia{
    int ini;
    int duracion;
    int fin;
    void actualiza(){
        fin = duracion + ini;
    }
};
bool operator<(Conferencia const& a, Conferencia const& b) {
    
    return a.fin < b.fin;
}
bool operator>(Conferencia const& a, Conferencia const& b) {
    
    return a.fin > b.fin;
}
// El coste será la ordenación del vector es N log N, más N bucle que lo recorre. Siendo N el número de películas.
// Coste total O(N log N + N)
int resolver(std::vector<Conferencia> const & salas) {
    int resultado = 1;
    int finPeli = salas[0].fin;
    for (int i=1; i < salas.size() ; i++) {
        if(salas[i].ini >= finPeli){
            resultado++;
            finPeli = salas[i].fin;
        }
    }
    return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int conferencias;
    std::cin >> conferencias;
    if (conferencias ==0)return false;
    
    std::vector<Conferencia> salas(conferencias);
    
    for (int i = 0; i < conferencias; i++)
    {
        std::cin >> salas[i].ini >> salas[i].duracion;
        salas[i].actualiza();
    }

    //COSTE N log N
    std::sort(salas.begin(), salas.end(), std::less<Conferencia>());
    
    //Resuelve el problema
    int sol = resolver(salas);
    
    // escribir sol
    std::cout << sol << "\n";
    
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ25/datos25.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    
    while (resuelveCaso())
        ;
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
