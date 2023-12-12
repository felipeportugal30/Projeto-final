#include <stdio.h>
#include <stdlib.h>
#include "filtro.h"

int *matrizFiltro(int *imagem, int TAM, int LER){
  int iMagem[TAM][TAM];
  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
      iMagem[i][j] = imagem[i*TAM + j];
    }
  }
  int *paraFiltrar = (int *)calloc((TAM+LER/2*2)*(TAM+LER/2*2), sizeof(int));
  if(!(paraFiltrar)){
    puts("Alocação de memória falhou");
    exit(1);
  }
  for(int i=0; i<(TAM+(LER/2*2)); i++){
    for(int k=0; k<(TAM+(LER/2*2)); k++){
      if((i<(LER/2)) || (i>=(TAM+(LER/2)))){
        paraFiltrar[i*(TAM+(LER/2*2)) + k] = 0;
      }else if((k<(LER/2)) || (k>=(TAM+(LER/2)))){
        paraFiltrar[i*(TAM+(LER/2*2)) + k] = 0;
      }else{
        paraFiltrar[i*(TAM+(LER/2*2)) + k] = iMagem[i-(LER/2)][k-(LER/2)];
      }
    }
  }
  return paraFiltrar;
}