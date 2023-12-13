#ifndef ARQUIVO_H
#define ARQUIVO_H


struct pgm{
  int tipo;
  int c; //coluna
  int r; //linha
  int mv;
  unsigned char *pData;
};
void readPGMImage(struct pgm *, char *);
void viewPGMImage(struct pgm *);
void writePGMImage(struct pgm *, char *);

#endif