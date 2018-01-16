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

struct Pelicula{
    Horas h;
    int T= 0;
    Horas fin;
    void actualiza(){
        int aux = T+10;
        fin = h + aux;
    }
};
bool operator<(Pelicula const& a, Pelicula const& b) {
    Horas c = a.fin, d = b.fin;
    return c < d;
}
bool operator>(Pelicula const& a, Pelicula const& b) {
    Horas c= a.fin, d = b.fin;
    
    return c > d;
}
// El coste será la ordenación del vector es N log N, más N bucle que lo recorre. Siendo N el número de películas.
// Coste total O(N log N + N)
int resolver(std::vector<Pelicula> const & cine) {
    int resultado = 1;
    Horas finPeli = cine[0].fin;
    for (int i=0; i < cine.size() ; i++) {
        Horas aux = cine[i].h;
        if(aux >= finPeli){
            resultado++;
            finPeli = cine[i].fin;
        }
    }
    return resultado;
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
    
    //Resuelve el problema
    int sol = resolver(Cine);
    
    // escribir sol
    std::cout << sol << "\n";
    
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos24.txt");
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
