#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LER 3
#define TAM 8
#define VALMAX 10

int main(){
  int *mSMC = (int *)calloc(VALMAX * VALMAX, sizeof(int)); 
  if(!(mSMC)){
    puts("Erro na alocação de memória");
    exit(1);
  }

  int imagem[TAM][TAM];
  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
      imagem[i][j] = rand()%VALMAX;
      }
    }
  }
  int suave[TAM][TAM];
  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
      suave[i][j] = rand()%VALMAX;
    }
  }

  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
     printf("%d\t", suave[i][j]); 
    }
  }
  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
      printf("%d\t", imagem[i][j]); 
    }
  }


for(int i=0; i<VALMAX; i++){ // i<(quantidade de tons disponiveis)
  for(int l=0; i<VALMAX; i++){
    for(int j=0; j<TAM; j++){
      for(int k=0; k<TAM; k++){
        if(imagem[j][k] != i){
          continue;
        }else if(imagem[j][k] == i){
          if(suave[j][k] != l){
            continue;
          }else if(suave[j][k] == l){
             mSMC[i*VALMAX + j] ++ ;
          }
        } 
      }
    } 
  }
}
  for (int i = 0; i < VALMAX; i++) {
      for (int l = 0; l < VALMAX; l++) {
        printf("%d\t", mSMC[i * VALMAX + l]);
      }
  }

  free(mSMC);
  return 0;
}