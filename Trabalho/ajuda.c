#include <stdio.h>
#include <stdlib.h>
#include "bSCM.h"
#define TAM 8
#define VALMAX 10

int main(){
  srand(time(NULL));
  int *imagem = (int *)calloc(TAM * TAM, sizeof(int)); 
  if(!(imagem)){
    puts("Erro na alocação de memória");
    exit(2);
  }  
  int *suave = (int *)calloc(TAM * TAM, sizeof(int)); 
  if(!(suave)){
    puts("Erro na alocação de memória");
    exit(3);
  }

  for (int i = 0; i < VALMAX; i++) {
    for (int l = 0; l < VALMAX; l++) {
      imagem[i * VALMAX + l] = rand() % VALMAX;
      suave[i * VALMAX + l] = rand() % VALMAX;
    }
  }

  int *mSMC = *matrizSMC(int *imagem, int *suave, int TAM, int VALMAX)
  
  for(int i=0; i<VALMAX; i++){
    for(int j=0; j<VALMAX; j++){
      printf("%d\t", mSMC[i*VALMAX + j]);
    }
    puts("");
  }
  
  free(mSMC);
  free(imagem);
  free(suave);
 
  return 0;
}