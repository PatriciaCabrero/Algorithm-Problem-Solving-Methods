// VJ04 Patricia Cabrero Villar
/*
 Se construye una clase componentes conexas que realizará un recorrido a través de la matriz de manera que
 cuando encuentre un blanco sin marcar será una posible mancha blanca realizando una búsqueda en profundidad
 para marcar la mancha blanca al completo. Debido a que cada oveja blanca solo puede tener una mancha se asume
 que el número de manchas encontrado -1 (el fondo) será el número de ovejas blancas.
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>

using Mapa = std::vector<std::string>;
const std::pair <int,int> dirs[4] = {{-1,0},{0,1},{1,0},{0,-1}};

//El coste es constante F*C por recorrerlas todas, como mucho hay 4*C*F aristas
//el recorrido en profundidad es V+E con lo que el coste es F*C
class ComponentesConexas{
public:
    ComponentesConexas(Mapa const& g): F(g.size()),C(g[0].size()), marcado(F, std::vector<bool>(C,false)), ovejasBlancas(-1){

        for(int i = 0; i < F ; ++i){
            for (int j = 0; j < C ; ++j){
                if(g[i][j] == '.' && !marcado[i][j]){
                    dfs(g,i,j);
                    ovejasBlancas++;
                }
            }
        }
    }
    int ovejasBlan() const{
        return ovejasBlancas;
    }
private:
    int F, C;
    int ovejasBlancas;
    std::vector<std::vector<bool>> marcado;
    void dfs(Mapa const& g, int i, int j){
        marcado[i][j] = true;
        for (auto d : dirs){
            int ni = i + d.first;
            int nj = j + d.second;
            if(0 <= ni && ni < F && nj >= 0 && nj < C && g[ni][nj] == '.' && !marcado[ni][nj]){
                dfs(g,ni,nj);
            }
        }
    }
    
};
bool resuelveCaso(){
    int F,C;
    std::cin >> C >> F;
    if(!std::cin)
        return false;
    std::cin.ignore(1);//quita salto de linea
    Mapa mapa(F);
    for (int i=0; i<F; ++i){
        getline(std::cin, mapa[i]);
    }
    ComponentesConexas obejas(mapa);
    std::cout << obejas.ovejasBlan()<<"\n";
    return true;
}
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/Pac/Documents/Universidad/UCM 3º/MARP/EJ00/EJ13/datos13.txt");
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
