#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filtro.h"
#include "suave.h"
#include "scm.h"
#define VALMAX 256
#define TAM 8
#define LER 5

int main(){
  //declaração
  srand(time(NULL));
  unsigned char *imagem = (unsigned char *)calloc(TAM*TAM, sizeof(unsigned char));
  if(!(imagem)){
    puts("A alocação falhou!");
    exit(1);
  }
  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
      imagem[i*TAM + j] = rand()%VALMAX;
    }
  }

  unsigned char *filtro = (unsigned char *)calloc((TAM+LER/2*2)*(TAM+LER/2*2), sizeof(unsigned char));
  if(!(filtro)){
    puts("A alocação falhou!");
    exit(2);
  }
  unsigned char *suave = (unsigned char *)calloc(TAM*TAM, sizeof(unsigned char));
  if(!(suave)){
    puts("A alocação falhou!");
    exit(3);
  }
  unsigned char *scm = (unsigned char *)calloc(VALMAX*VALMAX, sizeof(unsigned char));
  if(!(scm)){
    puts("A alocação falhou!");
    exit(4);
  }

  //processamento
  filtro = matrizFiltro(imagem, TAM, LER);
  suave = matrizSuave(filtro, TAM, LER);
  scm = matrizSCM(suave, imagem, VALMAX, TAM);
  //saída
  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
      printf("%d ", imagem[i*TAM + j]);
    }
    puts("");
  }    
  puts("===================================");
  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
      printf("%d ", suave[i*TAM + j]);
    }
    puts("");
  }   
  /*puts("===================================");
  for(int i=0; i<VALMAX; i++){
    for(int j=0; j<VALMAX; j++){
      printf("%d ", scm[i*VALMAX + j]);
    }
    puts("");
  }
  puts("===================================");
  //matriz scm vetorizada
  for(int i=0; i<VALMAX; i++){
    for(int j=0; j<VALMAX; j++){
      printf("%d, ", scm[i*VALMAX + j]);
    }

  }*/


  return 0;
}