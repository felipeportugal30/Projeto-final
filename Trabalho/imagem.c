#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 8
#define LER 5

int main(){
  srand(time(NULL));
  
  //declaração matriz
  int imagem[TAM][TAM];
  int paraFiltrar[TAM+(LER/2*2)][TAM+(LER/2*2)];
  
  //gerado imagem
  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
      imagem[i][j] = rand()%10+1;
    }
  }
  //imprimindo imagem
  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
      printf("%d\t", imagem[i][j]);
    }
    puts("");
  }
  puts("===============================");
  
  //processamento da nova matriz
  for(int i=0; i<(TAM+(LER/2*2)); i++){
    for(int k=0; k<(TAM+(LER/2*2)); k++){
      if((i<(LER/2)) || (i>=(TAM+(LER/2)))){
        paraFiltrar[i][k] = 0;
      }else if((k<(LER/2)) || (k>=(TAM+(LER/2)))){
        paraFiltrar[i][k] = 0;
      }else{
        paraFiltrar[i][k] = imagem[i-(LER/2)][k-(LER/2)];
      }
    }
  }

  //teste
  for(int i=0; i<(TAM+(LER/2*2)); i++){
    for(int j=0; j<(TAM+(LER/2*2)); j++){
      printf("%d\t", paraFiltrar[i][j]);
    }
    puts("");
  }
  //fim do teste
  
  
  return 0;  
}