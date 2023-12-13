#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//essa biblioteca serve para implementar a struct scm
#include "arquivo.h" 

#ifndef IMAGEM_H
#define IMAGEM_H

void gerarFiltro(struct pgm *imagem, int LER, unsigned char *filtro);

void gerarSuave(unsigned char *filtro, unsigned char *suave, int LER, struct pgm *img);

void quantizar(struct pgm *img, int quantizacao);

void matrizSCM(unsigned char *scm, unsigned char *suave, struct pgm *imagem, int quantizacao);

void criarArqv(char *filename, unsigned char *scm, int tam);

#endif
