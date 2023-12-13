#include <stdlib.h>
#include <stdio.h>
#include "imagem.h"
#include "arquivo.h"

unsigned char *matrizFiltro(struct pgm *imagem, int LER){

  unsigned char *filtro = (unsigned char*) calloc((imagem->r+LER/2*2) * (imagem->c+LER/2*2), sizeof(unsigned char));

  int iMagem[imagem->r][imagem->c];
  for(int i=0; i<imagem->r; i++){
    for(int j=0; j<imagem->c; j++){
      iMagem[i][j] = imagem->pData[i*imagem->c + j];
    }
  }

  if(!(filtro)){
    puts("Alocação de memória falhou");
    exit(1);
  }

  for(int i=0; i<(imagem->r+(LER/2*2)); i++){
    for(int k=0; k<(imagem->c+(LER/2*2)); k++){
      if((k<(LER/2)) || (k>=(imagem->r+(LER/2)))){
         filtro[i*(imagem->c+(LER/2*2)) + k] = 0;
      }else{
        filtro[i*(imagem->r+(LER/2*2)) + k] = iMagem[i-(LER/2)][k-(LER/2)];
      }
    }
  }

  return filtro;
}

unsigned char *matrizSuave(unsigned char *paraFiltrar, struct pgm *imagem, int LER) {
  unsigned char *suave = (unsigned char *)calloc(imagem->r*imagem->c, sizeof(unsigned char));
  if(!(suave)){
    puts("A alocação falhou!");
    exit(2);
  }
  int pFiltro[imagem->r+LER/2*2][imagem->c+LER/2*2];
  int ElementoMatriz = 0, SomaLinha = 0, SomaMatriz = 0;

  //transformando ponteiro em matriz (paraFiltrar)
  for(int i=0; i<(imagem->r+(LER/2*2)); i++){
    for(int k=0; k<(imagem->c+(LER/2*2)); k++){
      pFiltro[i][k] = paraFiltrar[i*(imagem->r+(LER/2*2)) + k];
    }
  }

  //processamento da matriz suave
  for(int l=0; l<(imagem->r); l++){ 
    for(int i=0; i<(imagem->c); i++){ 
      for(int k=0; k<(LER); k++){ 
        for(int m=0; m<(LER); m++){
          ElementoMatriz = pFiltro[k+l][m+i]; 
          SomaLinha = SomaLinha+ElementoMatriz;
          ElementoMatriz = 0;
        }
        SomaMatriz += SomaLinha;
        SomaLinha=0;
      } 
      suave[l*imagem->r + i] = (SomaMatriz)/(LER*LER); 
      SomaMatriz = 0;
    }
  }

  return suave;
}

void MatrizSCM(struct pgm *scm, int *suave, struct pgm *imagem, int quantizacao) {
  scm = (struct pgm *)malloc(sizeof(struct pgm));
  scm->r = quantizacao;
  scm->c = quantizacao;
  scm->pData = (unsigned char *)calloc(scm->r * scm->c, sizeof(unsigned char));

  if (!scm->pData) {
    puts("Erro na alocação de memória");
    exit(1);
  }

  // Implementação do restante da função matrizSCM
}
