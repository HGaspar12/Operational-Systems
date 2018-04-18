#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "../Modo_Nucleo/rotina.cpp"

using namespace std;
//chamada da funcao de leitura
    void read(){
    lerArquivo();
    }
// camada da funcao de gravacao
    void write(string dados){
    gravarRotina(dados);
    }

    int checkUser(string user, string password){
        if(user == "henrique" && password == "admin"){
            return 0;
        }
        else{
            return -1;
        }
    }


