// VJ04 Patricia Cabrero Villar
/*
 Se busca el número de caminos de igual coste de un punto a otro. Se utiliza el algoritmo de Dijkstra
 utilizando además un vector de numero de caminos, que se actualizará cada vez que encontremos un nuevo camino
 con igual coste.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include "GrafoDirigidoValorado.h"
#include "IndexPQ.h"

#define INFINITO 2147483647

/*
 El coste de descubrir el número de caminos mínimos de un grafo valorado dirigido, será O(2E log V).
 Donde E es el número de aristas y V es el número de vértices. Como se puede ir de un sitio a otro
 independientemente de la calle las aristas se introducen en ida y vuelta con lo que será 2E.
 */
class Dijkstra{
public:
    Dijkstra(GrafoDirigidoValorado<int> const& G, int s): V(G.V()), distTo(G.V(), INFINITO), pq(G.V()), numCam(G.V(), 0)
    {
        distTo[s] = 0;
        pq.push(s, 0);
        numCam[s] = 1;
        while (!pq.empty())
        {
            auto v = pq.top();
            pq.pop();
            for (AristaDirigida<int> e : G.adj(v.elem))
                relax(e);
        }
    }
    int numeroCaminos(){
        return numCam[V-1];
    }
private:
    std::vector<int> distTo; // distTo[w] = edgeTo[w].weight()
    IndexPQ<int> pq; // eligible crossing edges
    std::vector<int> numCam;
    int V;
    
    void relax(AristaDirigida<int> const& e)
    {
        int v = e.from();
        int w = e.to();
        if (distTo[w] > distTo[v] + e.valor())
        {
            numCam[w] = numCam[v];
            distTo[w] = distTo[v] + e.valor();
            pq.update(w, distTo[w]);
        }else if(distTo[w] == distTo[v] + e.valor()){
            numCam[w] += numCam[v];
        }
    }
    
};

bool resuelveCaso(){
    int V,E;
    std::cin >> V >> E;
    if (!std::cin) {
        return false;
    }
    
    GrafoDirigidoValorado<int> grafo(V);                            // Coste O(nV)
    int A, B, valor;
    for (int i=0; i < E; ++i){
        std::cin >> A >> B >> valor;
        AristaDirigida<int>aux(A-1, B-1, valor);
        grafo.ponArista(aux);
    }                                                       // Coste O(nE)
    //Resolver el problema
    Dijkstra Solucion(grafo, 0);
    std::cout << Solucion.numeroCaminos() << "\n";
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ16/datos16.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    while(resuelveCaso());
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}

