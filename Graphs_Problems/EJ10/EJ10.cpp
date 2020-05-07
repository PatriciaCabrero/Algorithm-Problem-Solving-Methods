// VJ04 Patricia Cabrero Villar
/*
 Se construye una clase bipartito que nos permitirá saber dado un grafo si sus vértices pueden colorearse utilizando dos
 colores de tal forma que no exista ninguna arista que conecte dos vértices del mismo color.
 Se realiza una búsqueda en profundidad comprobando si el color de los adyacentes marcados es diferente del actual,
 sino es así se cambia a false la variable bipartito_. Si no están marcados se les asignará el color opuesto del vértice de consulta.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

#include "Grafo.h"

/*Nos permite saber dado un grafo si sus vértices pueden colorearse utilizando dos
  colores de tal forma que no exista ninguna arista que conecte dos vértices del mismo color*/
class Bipartito
{
private:
    std::vector<bool> marked;
    std::vector<unsigned int> colores; // 0 si no se ha asignado y 1 y 2 los dos colores diferentes
    bool bipartito_;
public:
    Bipartito(Grafo const& G) : marked(G.V(),false), bipartito_(true), colores(G.V(),0)
    {
        for (int v = 0; v < G.V(); v++){
            if (!marked[v]){
                dfs(G, v, 1);
            }
        }
    }
    bool bipartito(){
        return bipartito_;
    }
private:
    void dfs(Grafo const& G, int v, int color)
    {
        int colAux;
        if (color ==1){
            colAux = 2;
        }else colAux = 1;
        colores[v] = color;
        marked[v] = true;
   
        for (int w : G.adj(v)){
            if (!marked[w]){
                dfs(G, w, colAux);
            }else if(colores[w]==color){
                bipartito_ = false;
            }
        }
    }
};
// El coste será la suma del coste de crear el grafo  E+V, V al crear un grafo de V vértices y E al generar las aristas,
// sumado al coste de realizar una búsqueda en profundidad, con coste E+V.
// El coste será O(2*(E+V))
bool resolver(Grafo const grafo) {
    Bipartito conexo(grafo);
    return conexo.bipartito();
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int nV, nA,aux,aux1;
    std::cin >> nV >> nA;
    if(!std::cin)return false;

    Grafo bipart(nV);                    // Coste O(nV)
    for (int i = 0; i < nA; i++)
    {
        std::cin >> aux >> aux1;
        bipart.ponArista(aux, aux1);
    }                                   // Coste O(nA)
    bool sol = resolver(bipart);
    
    // escribir sol
    if(sol)
        std::cout << "SI\n";
    else
        std::cout << "NO\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ10/datos10.txt");
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


