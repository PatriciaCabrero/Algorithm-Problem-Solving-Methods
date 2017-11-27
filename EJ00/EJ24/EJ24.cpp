// VJ04, Patricia Cabrero Villar
/*
 ¡Nos invaden!

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

struct Pelicula{
    Horas h;
    int T= 0;
};
// El coste será la ordenación de los vectores de partidos 2N log N, más N el caso que tengan todos
// los pares mejor puntuación los broncos. Siendo N el número de partidos.
// Coste total O(N log N + N)
int resolver(std::vector<int> const  b, std::vector<int> const  c) {
    int resultado = 0;
    int ini = 0;
    for (int i=0; i < b.size() ; i++) {
        if(b[ini] >= c[i]){
            ini++;
            resultado++;
        }
    }
    return resultado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int ciudades;
    std::cin >> ciudades;
    if (ciudades ==0)return false;
    
    std::vector<Pelicula> Cine(ciudades);
    
    for (int i = 0; i < ciudades; i++)
    {
        std::cin >> Cine[i].h >> Cine[i].T;
    }


    //COSTE 2N log N
    
    //Resuelve el problema
    
    //int sol = resolver(UCM, invasores);
    
    // escribir sol
    std::cout << 0 << "\n";
    
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ24/datos24.txt");
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
