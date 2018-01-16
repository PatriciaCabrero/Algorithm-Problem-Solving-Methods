// VJ04, Patricia Cabrero Villar
/*
	Conferencias
	Se ordena en un vector las conferencias de menor a mayor hora de inicio.
	Se crea una cola de prioridad que representará las salas ordenada por las horas de finalización.
	Se recorre el vector de conferencias y si su hora de inicio es menor que la hora de finalización del top
	de la cola se actualiza la sala con la nueva conferencia, si su hora es mayor se necesitará una nueva sala.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "PriorityQueue.h"

struct Conferencia{
    int ini;
    int fin;
};
bool operator<(Conferencia const& a, Conferencia const& b) {
    
    return a.ini < b.ini;
}
bool operator>(Conferencia const& a, Conferencia const& b) {
    
    return a.ini > b.ini;
}
class antes{
public:
	bool operator () (const Conferencia a, const Conferencia b){
		return a.fin < b.fin;
	}
};
// El coste será la ordenación del vector es N log N, más N log N del coste de la cola (pop,push). Siendo N el número de películas.
// Coste total O(2N log N)
int resolver(std::vector<Conferencia> const & salas) {
	PriorityQueue<Conferencia, antes> colaPrioridad;
 	colaPrioridad.push(salas[0]);

    for (int i=1; i < salas.size() ; i++) {
        if(salas[i].ini >= colaPrioridad.top().fin){
			colaPrioridad.pop();
			colaPrioridad.push(salas[i]);
		}
		else
			colaPrioridad.push(salas[i]);
    }
    return colaPrioridad.size();
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
        std::cin >> salas[i].ini >> salas[i].fin;
    }

    //COSTE N log N
    std::sort(salas.begin(), salas.end(),  std::less<Conferencia>());
    
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
    std::ifstream in(/*"/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ25/*/"datos25.txt");
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
