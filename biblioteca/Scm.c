#include <stdio.h>
#include <stdlib.h>
#include "Scm.h"

int *matrizSCM(int *suave1, int *imagem1, int VALMAX, int TAM){
  int *mSMC = (int *)calloc(VALMAX * VALMAX, sizeof(int)); 
  if(!(mSMC)){
    puts("Erro na alocação de memória");
    exit(1);
  }

  for (int i = 0; i < VALMAX; i++) {
      for (int l = 0; l < VALMAX; l++) {
          for (int j = 0; j < TAM; j++) {
              for (int k = 0; k < TAM; k++) {
                    if (imagem1[j * TAM + k] == i && suave1[j * TAM + k] == l) {
                      mSMC[i * VALMAX + l]++;
                  }
              }
          }
      }
  }
  return mSMC;
}