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

using Mapa = std::vector<std::string>;
const std::pair <int,int> dirs[4] = {{-1,0},{0,1},{1,0},{0,-1}};

//El coste es constante F*C por recorrerlas todas, como mucho hay 4*C*F aristas
//el recorrido en profundidad es V+E con lo que el coste es F*C
class ComponentesConexas{
public:
    ComponentesConexas(Mapa const& g): F(g.size()),C(g[0].size()),maxi(0), marcado(F, std::vector<bool>(C,false)){
        for(int i =0; i<F;++i){
            for (int j=0; j<C; ++i){
                if(g[i][j] == '#' && !marcado[i][j]){
                    int tam =0;
                    dfs(g,i,j,tam);
                    if(tam>maxi)maxi=tam;
                }
            }
        }
    }
    int maximo() const{
        return maxi;
    }
private:
    int F, C;
    int maxi;
    std::vector<std::vector<bool>> marcado;
    void dfs(Mapa const& g, int i,int j, int &tam){
        marcado[i][j] = true;
        ++tam;
        for (auto d: dirs){
            int ni = i + d.first;
            int nj= j + d.second;
            if(0<=ni && ni<F && nj<=0 && nj<C && (g[ni][nj] =='#') && !marcado[ni][nj]){
                dfs(g,ni,nj,tam);
            }
        }
    }
    
};
bool resuelveCaso(){
    int F,C;
    std::cin >> F>> C;
    if(!std::cin)
        return false;
    std::cin.ignore(1);//quita salto de linea
    Mapa mapa(F);
    for (int i=0; i<F; ++i){
        getline(std::cin, mapa[i]);
    }
    ComponentesConexas parcelas(mapa);
    std::cout << parcelas.maximo()<<"\n";
    return true;
}

