#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "imagem.h"
#include "arquivo.h"

void gerarFiltro(struct pgm *imagem, int LER, unsigned char *filtro){
    // Aloca memória para a matriz iMagem
    int **iMagem = (int **)malloc(imagem->r * sizeof(int *));
    for (int i = 0; i < imagem->r; i++) {
        iMagem[i] = (int *)malloc(imagem->c * sizeof(int));
    }

    // Preenche a matriz iMagem
    for (int i = 0; i < imagem->r; i++) {
        for (int j = 0; j < imagem->c; j++) {
            iMagem[i][j] = *(imagem->pData + i * imagem->c + j) ;
        }
    }

    // Preenche o filtro
    for (int i = 0; i < (imagem->r + (LER / 2 * 2)); i++) {
        for (int k = 0; k < (imagem->c + (LER / 2 * 2)); k++) {
            if (i < LER / 2 || i >= imagem->r + LER / 2 || k < LER / 2 || k >= imagem->c + LER / 2) {
              *(filtro + i *imagem->c + (LER / 2 * 2) + k) = 0; 
            } else {
              *(filtro + i *imagem->c + (LER / 2 * 2) + k) = iMagem[i - (LER / 2)][k - (LER / 2)];
            }
        }
    }

    // Libera a memória da matriz iMagem
    for (int i = 0; i < imagem->r; i++) {
        free(iMagem[i]);
    }
    free(iMagem);
}

void gerarSuave(unsigned char *filtro, unsigned char *suave, int LER, struct pgm *img){
    int paraFiltro[img->r + LER / 2 * 2][img->c + LER / 2 * 2];
    int ElementoMatriz = 0, SomaLinha = 0, SomaMatriz = 0;

    // Transformando ponteiro em matriz (paraFiltrar) 
    for (int i = 0; i < (img->r + (LER / 2 * 2)); i++) {
        for (int k = 0; k < (img->c + (LER / 2 * 2)); k++) {
            paraFiltro[i][k] = *(filtro + i *img->c + (LER / 2 * 2) + k);
        }
    }
  
    // Processamento da matriz suave
    for (int l = 0; l < (img->r); l++) {
        for (int i = 0; i < (img->c); i++) {
            for (int k = 0; k < (LER); k++) {
                for (int m = 0; m < (LER); m++) {
                    ElementoMatriz = paraFiltro[k + l][m + i];
                    SomaLinha = SomaLinha + ElementoMatriz;
                    ElementoMatriz = 0;
                }
                SomaMatriz += SomaLinha;
                SomaLinha = 0;
            }
            *(suave + l *img->c + i) = SomaMatriz / (LER * LER);
            SomaMatriz = 0;
        }
    }
}

void quantizar(struct pgm *img, int quantizacao){
    int tamIntervalo = (img->mv + 1) / quantizacao; // Tamanho de cada intervalo

    puts("Quantizando Imagem PGM");
    // Percorre os pixels da imagem
    for (int k = 0; k < (img->r * img->c); k++) {
        // Calcula o índice do intervalo ao qual o pixel pertence
        int intervaloIndex = *(img->pData + k) / tamIntervalo;

        // Atribui o valor quantizado, limitado entre 0 e quantizacao - 1
        *(img->pData + k) = (unsigned char)fmin(fmax(0, intervaloIndex), quantizacao - 1);
    }
}

void matrizSCM(unsigned char *scm, unsigned char *suave, struct pgm *imagem, int quantizacao){
    //percorre a imagem original e a matriz suave
    for (int i = 0; i < quantizacao; i++) {
        for (int l = 0; l < quantizacao; l++) {
            for (int j = 0; j < imagem->r; j++) {
                for (int k = 0; k < imagem->c; k++) {
                    if (*(imagem->pData + j * imagem->c + k) == i && *(suave+j*quantizacao+k) == l){
                      *(scm + i *quantizacao + l)+=1;
                    } 
                }
            }
        }
    }
}

void criarArqv(char *filename, unsigned char *scm, int tam){
  printf("Gerando Arquivo...\n");

  FILE *file = fopen(filename, "a");
  if (!file) {
    perror("Erro ao abrir o arquivo");
    exit(1);
  }

  fputs("\n", file);

  int cont = 0;  
  while(cont<(tam*tam)){
 //transforma de int pra char
    fprintf(file, "%hhu", *(scm + cont));
    fputs(",", file);
    cont++;
  }
  fclose(file);
}