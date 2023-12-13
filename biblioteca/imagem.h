#include <stdio.h>
#include <stdlib.h>

#ifndef IMAGEM_H
#define IMAGEM_H

unsigned char *matrizFltr(struct pgm *, int );

unsigned char *matrizSv(unsigned char *, struct pgm *, int );

void MSCM(struct pgm *,int *, struct pgm *, int );

#endif
