#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "filtro.h"
#include "suave.h"
#include "Scm.h"
#define VALMAX 8
#define TAM 8
#define LER 5

int main(){
  //declaração
  int *imagem = (int *)calloc(TAM*TAM, sizeof(int));
  if(!(imagem)){
    puts("A alocação falhou!");
    exit(1);
  }
  for(int i=0; i<TAM; i++){
    for(int j=0; j<TAM; j++){
      imagem[i*TAM + j] = rand()%VALMAX;
    }
  }

  int *filtro = (int *)calloc((TAM+LER/2*2)*(TAM+LER/2*2), sizeof(int));
  if(!(filtro)){
    puts("A alocação falhou!");
    exit(2);
  }
  int *suave = (int *)calloc(TAM*TAM, sizeof(int));
  if(!(suave)){
    puts("A alocação falhou!");
    exit(3);
  }
  int *scm = (int *)calloc(VALMAX*VALMAX, sizeof(int));
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
  puts("===================================");
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
    
  }

  
  return 0;
}