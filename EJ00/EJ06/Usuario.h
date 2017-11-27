//
//  Usuario.h
//  MARP
//
//  Created by Patri Cabrero on 12/10/17.
//  Copyright © 2017 Patricia Cabrero Villar. All rights reserved.
//

#ifndef Usuario_h
#define Usuario_h
class Usuario{
public:
    Usuario():usuario(0), periodo(0), periodoInicial(0){};
    ~Usuario() = default;
    long int usuario;
    int periodo;
protected:
    int periodoInicial;
public:
    void setUsuarioPeriodo(long int u, int p){
        usuario= u;
        periodoInicial = p;
        periodo = p;
    };
    void sumaPeriodo(){
        periodo+=periodoInicial;
    }
};

#endif /* Usuario_h */
