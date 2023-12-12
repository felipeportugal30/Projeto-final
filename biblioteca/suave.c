#include <stdio.h>
#include <stdlib.h>
#include "suave.h"

int *matrizSuave(int *paraFiltrar, int TAM, int LER){
  //declaração
  int *suave = (int *)calloc(TAM*TAM, sizeof(int));
  if(!(suave)){
    puts("A alocação falhou!");
    exit(2);
  }

  int pFiltro[TAM+LER/2*2][TAM+LER/2*2];
  int ElementoMatriz = 0, SomaLinha = 0, SomaMatriz = 0;

  //transformando ponteiro em matriz (paraFiltrar)
  for(int i=0; i<(TAM+(LER/2*2)); i++){
    for(int k=0; k<(TAM+(LER/2*2)); k++){
      pFiltro[i][k] = paraFiltrar[i*(TAM+(LER/2*2)) + k];
    }
  }

  //processamento da matriz suave
  for(int l=0; l<(TAM); l++){ 
    for(int i=0; i<(TAM); i++){ 
      for(int k=0; k<(LER); k++){ 
        for(int m=0; m<(LER); m++){
          ElementoMatriz = pFiltro[k+l][m+i]; 
          SomaLinha = SomaLinha+ElementoMatriz;
          ElementoMatriz = 0;
        }
        SomaMatriz += SomaLinha;
        SomaLinha=0;
      } 
      suave[l*TAM + i] = (SomaMatriz)/(LER*LER); 
      SomaMatriz = 0;
    }
  }

  return suave;
}