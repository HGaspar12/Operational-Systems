#include <iostream>
#include<fstream>
#include<cstdlib>
#include <string>
#include <stdlib.h>
#include "../Modo_Lib/lib.h"

int main(){
    int option; //opcao a ser escolhida pelo usuario
    string dados;//o que sera gravado
    string user;//usuario para verificacao de permissao
    string password;//senha de verificacao de permissao

    printf("Informe o Usuario: \n");
    cin >> user;
    printf("Informe a Senha: \n");
    cin >> password;

    //menu de interacao com o usuario
    aqui:
    printf("**********************\n");
    printf("**CHAMADA DE SISTEMA**\n");
    printf("**********************\n");
    printf("[1]-Ler \n");
    printf("[2]-Escrever \n");
    printf("[3]-Alterar Usuario \n");
    printf("[0]-Sair \n");
    printf("Digite a Operacao Desejada: \n");

    do{
        //opcao de leitura do arquivo
        cin>>option;
        if(option == 1){
            if(checkUser(user, password) == 0){
                read();
            }
            else{
                printf("Voce nao tem permissao! \n");
                goto aqui;
            }
        }
        //opcao de escrita do arquivo
        else if(option == 2){
            system("cls");

            if(checkUser(user, password) == 0){
                printf("O que deseja gravar?");
                cin >> dados;
                write(dados);
            }
            else{
                printf("Voce nao tem permissao! \n");
            }
            goto aqui;
        }
        else if (option == 3){
            printf("Informe o Usuario: ");
            cin >> user;
            printf("Informe a Senha: ");
            cin >> password;
        }
    }while(option != 0);
 return 0;
}
