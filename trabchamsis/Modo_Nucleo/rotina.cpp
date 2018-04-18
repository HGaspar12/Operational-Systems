#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void lerArquivo(){
  FILE *arq;
  char Linha[100];
  char *resultado;
  int i;

  arq = fopen("../Modo_Nucleo/chamada_sist.txt", "r");

  if(arq == NULL){
    printf("Erro ao abrir arquivo\n");
  }
  i = 1;
  while (!feof(arq)){
      resultado = fgets(Linha, 100, arq);

      if (resultado){
	  printf("Linha %d : %s",i,Linha);
      i++;
      }
  }
  fclose(arq);
}
void gravarRotina(string dados){
    fstream arq;
    arq.open("../Modo_Nucleo/chamada_sist.txt", ios::in | ios:: out | ios::app);
    arq << dados;
    arq.close();
    cout << "Dados gravados com sucesso!" << endl;

}


