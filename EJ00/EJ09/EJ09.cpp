// VJ04 Patricia Cabrero Villar
// Se construye una clase conexo que nos permitirá saber dado un grafo el mayor número de vértices conectados,
// es decir quien es el amigo del amigo. Para ello se hace un recorrido en profundidad, pasando el numero de amigos
// como parámetro por referencia. Actualizándolo en cada vuelta del bucle y guardando el resultado mayor en una variable auxiliar.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

#include "Grafo.h"

/*Busca el mayor número de vértices conexos entre ellos*/
class Conexo
{
private:
    std::vector<bool> marked;
    int maxi;
public:
    Conexo(Grafo const& G) : marked(G.V(),false), maxi(0)
    {
        for (int v = 0; v < G.V(); v++){
            if (!marked[v]) {
                int aux = 0;
                dfs(G, v,aux);
                if(aux > maxi) maxi = aux;
            }
        }
    }
    int max(){
        return maxi;
    }
private:
    void dfs(Grafo const& G, int v,int & tam)
    {
        marked[v] = true;
        ++tam;
        for (int w : G.adj(v))
            if (!marked[w]){
                dfs(G, w, tam);
            }
    }
};

// El coste de crear el grafo será E+V, V al crear un grafo de V vértices(personas) y E de crear las aristas(amistades)
// El coste de realizar una búsqueda en profundidad es decir E + V siendo E el número de amistades y V el número de personas.
// El coste será O(E+V)
int resolver(Grafo const grafo) {
	Conexo conexo(grafo);
	return conexo.max();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int nV, nA,aux,aux1;
	std::cin >> nV >> nA;
	Grafo amigos(nV);
	for (int i = 0; i < nA; i++)
	{
		std::cin >> aux >> aux1;
		amigos.ponArista(aux-1, aux1-1);
	}
	int sol = resolver(amigos);

	// escribir sol
	std::cout << sol << "\n";
}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ09/datos9.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}

