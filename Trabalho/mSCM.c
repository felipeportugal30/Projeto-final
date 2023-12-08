#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 8
#define LER 5
#define VALMAX 10

int main(){
  srand(time(NULL));
  int *mSMC = (int *)calloc(VALMAX * VALMAX, sizeof(int)); 
  if(!(mSMC)){
    puts("Erro na alocação de memória");
    exit(1);
  }

  //supostamente ja deveria ser matrizes definidas anteriormente
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
  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
      printf("%d\t", imagem[i*TAM + j]);
    }
    puts("");
  }
  puts("=============================================")

    
  for (int i = 0; i < VALMAX; i++) {
      for (int l = 0; l < VALMAX; l++) {
          for (int j = 0; j < TAM; j++) {
              for (int k = 0; k < TAM; k++) {
                  if (imagem[j*TAM +k] == i && suave[j*TAM +k] == l) {
                      mSMC[i * VALMAX + l]++;
                  }
              }
          }
      }
  }

  for(int i=0; i<VALMAX; i++){)

  free(mSMC);

  return 0;
}