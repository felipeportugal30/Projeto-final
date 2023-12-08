#include <stdio.h>
#include <stdlib.h>
#define TAM 8
#define LER 5

int main(){
  //declaração matrizes
  int imagem[TAM][TAM];
  int *paraFiltrar = (int *)calloc((TAM+LER/2*2)*(TAM+LER/2*2), sizeof(int *));
  int *suave = (int *)calloc(TAM*TAM, sizeof(int*));
  int pFiltro[TAM+LER/2*2][TAM+LER/2*2];
  
  //declaração vetores
  int ElementoMatriz = 0, SomaLinha = 0, SomaMatriz = 0;

  //imagem e filtro
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
        paraFiltrar[i*(TAM+(LER/2*2)) + k] = 0;
      }else if((k<(LER/2)) || (k>=(TAM+(LER/2)))){
        paraFiltrar[i*(TAM+(LER/2*2)) + k] = 0;
      }else{
        paraFiltrar[i*(TAM+(LER/2*2)) + k] = imagem[i-(LER/2)][k-(LER/2)];
      }
    }
  }
  for(int i=0; i<(TAM+(LER/2*2)); i++){
    for(int k=0; k<(TAM+(LER/2*2)); k++){
      printf("%d\t", paraFiltrar[i*(TAM+(LER/2*2)) + k]);
    }
    puts("");
  }
  puts("===============================");

  //transformando ponteiro em matriz (paraFiltrar)
  for(int i=0; i<(TAM+(LER/2*2)); i++){
    for(int k=0; k<(TAM+(LER/2*2)); k++){
      pFiltro[i][k] = paraFiltrar[i*(TAM+(LER/2*2)) + k];
    }
  }

  //processamento da nova matriz(leitura da matriz gerada)
  for(int l=0; l<(TAM); l++){ 
    for(int i=0; i<(TAM); i++){ 
      for(int k=0; k<(LER); k++){ 
        for(int m=0; m<(LER); m++){
          ElementoMatriz = pFiltro[k+l][m+i]; //f[k+l][m+i]
          SomaLinha = SomaLinha+ElementoMatriz;
          ElementoMatriz = 0;
        }
        SomaMatriz += SomaLinha;
        SomaLinha=0;
      } 
      printf("%d\n", SomaMatriz);
      suave[l*TAM + i] = (SomaMatriz)/(LER*LER); //suave[l][i]
      SomaMatriz = 0;
    }
  }
  puts("===============================");
  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
      printf("%d\t", suave[i*TAM + j]);
    }
    puts("");  
  }

  return 0;
}