#include <stdio.h>
#define TAM 8
#define LER 5

int main(){
  //declaração matrizes
  int paraFiltrar[TAM+(LER/2*2)][TAM+(LER/2*2)] = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 4, 7, 8, 6, 4, 6, 7, 3, 0, 0},
      {0, 0, 10, 2, 3, 8, 1, 10, 4, 7, 0, 0},
      {0, 0, 1, 7, 3, 7, 2, 9, 8, 10, 0, 0},
      {0, 0, 3, 1, 3, 4, 8, 6, 10, 3, 0, 0},
      {0, 0, 3, 9, 10, 8, 4, 7, 2, 3, 0, 0},
      {0, 0, 10, 4, 2, 10, 5, 8, 9, 5, 0, 0},
      {0, 0, 6, 1, 4, 7, 2, 1, 7, 4, 0, 0},
      {0, 0, 3, 1, 7, 2, 6, 6, 5, 8, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
  };
;
  int suave[TAM][TAM];

  //declaração vetores
  int ElementoMatriz=0;
  int SomaLinha=0, SomaMatriz=0;

  
  //processamento da nova matriz(leitura da matriz gerada)
  for(int l=0; l<(TAM); l++){ 
    for(int i=0; i<(TAM); i++){ 
      for(int k=0; k<(LER); k++){ 
        for(int m=0; m<(LER); m++){
          ElementoMatriz = paraFiltrar[k+l][m+i];
          SomaLinha = SomaLinha + ElementoMatriz;
        } 
        SomaMatriz = SomaMatriz + SomaLinha;
      
        SomaLinha = 0;
      } 
      suave[l][i] = (SomaMatriz)/(LER*LER); 
      SomaMatriz = 0;
    }
  }
  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
      printf("%d\t", suave[i][j]);
    }
    puts("");                                                 }

  return 0;
}