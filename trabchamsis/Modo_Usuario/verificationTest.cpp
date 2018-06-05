
int main(){
int resposta;
string dados;
string usuario;
string senha;
cout << "Nome de usuario: ";
cin >> usuario;
cout << "Digite a senha: ";
cin >> senha;
do{
    aqui:
cout << "\n==================================" << endl;
cout << "O que voce quer fazer?" << endl;
cout << "Digite [1] para: Ler" << endl;
cout << "Digite [2] para: Escrever" << endl;
cout << "Digite [3] para: Trocar de Usuario" << endl;
cout << "Digite [4] para: Sair" << endl;
cout << "==================================" << endl;
    cin >> resposta;
    system("cls");

    if(resposta == 1){
        if(verificar(usuario, senha) == 0){
        ler();
        }
        else{
            cout << "Voce nao tem permissao para isso." << endl;
            goto aqui;
        }
    }else if(resposta == 2){
        system("cls");
        if(verificar(usuario, senha)== 0){
        cout << "O que deseja escrever?" << endl;
        cin >> dados;
        escrever(dados);
        }
        else {
            cout << "Voce nao tem permissao para isso." << endl;
            goto aqui;
        }
    }else if(resposta == 3){
        cout << "Nome de usuario: ";
        cin >> usuario;
        cout << "Digite a senha: ";
        cin >> senha;
    }
}while(resposta != 4);
return 0;
}
