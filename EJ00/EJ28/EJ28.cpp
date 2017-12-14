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

struct tesoro{
	int profundidad;
	int oro;
	int tiempo;
	void actTiempo(){
		tiempo = profundidad * 3;
	}
};

// El coste será

int resolver() {
	return 0;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int T, cofres;
	std::cin >> T;
	if (!std::cin) return false;
	std::cin >> cofres;
	std::vector<tesoro> bTesoro(cofres);
	for (int i = 0; i < cofres; i++)
	{
		std::cin >> bTesoro[i].profundidad >> bTesoro[i].oro;
		bTesoro[i].actTiempo();
	}

	//Resuelve el problema
	int sol = resolver();

	// escribir sol
	std::cout << sol << "\n";

	return true;
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in(/*"/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ25/*/"datos28.txt");
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