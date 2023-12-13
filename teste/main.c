#include "imagem.h"
#include "arquivo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

#define LER 3
#define QUANTIZAR 16
#define FOLDER "folder_pgm"

int main(int argc, char *argv[]){
  int k;
  clock_t begin, end;
  double time_per_img, time_total=0;
  long long int a = 999999999;
  begin = clock();

  int vez=0;

  DIR *d;
  struct dirent *dir;
  d = opendir("./images");
  if (d){
    while ((dir = readdir(d)) != NULL){
      vez++;
          if(vez==4)  break;
          //printf("\n-> %s \n ", dir->d_name);
          puts("0");
          if((vez==1) || (vez==2))  continue;
          puts("01");
          printf("%s",dir->d_name);

          char filename[256];
          snprintf(filename, sizeof(filename), "%s/%s", FOLDER, dir->d_name); 

          struct pgm *imagem;

          readPGMImage(&imagem,filename);

          unsigned char *filtro = (unsigned char*) calloc((imagem->r+LER/2*2)*(imagem->c+LER/2*2), sizeof(unsigned char));
          if(!filtro) {
            puts("Alocação de memória falhou");
            exit(1);
          }
          filtro = matrizFltr(imagem, LER);

          unsigned char *suave = (unsigned char*) calloc(imagem->r*imagem->c, sizeof(unsigned char));
          if(!suave) {
            puts("Alocação de memória falhou");
            exit(2);
          }
          suave = matrizSv(filtro, imagem, LER);

          struct pgm *scm = (unsigned char *)calloc(QUANTIZAR * QUANTIZAR, sizeof(unsigned char));
          if(!scm){
            puts("Alocação de memória falhou");
            exit(3);
          }
          MSCM(scm, suave, imagem, QUANTIZAR);

          viewPGMImage(&scm);

              preencher_csv(scm->pData,QUANTIZAR,"csv_img",0);

                  FILE *rev;
                   rev = fopen("ordem_imagens.txt", "a+");
                   if (!rev) {
                   puts("Erro ao abrir o arquivo");
                   exit(1);
                    }

                      fprintf(rev, "%s\n", dir->d_name);

                                   fclose(rev);

      }

      closedir(d);
  }

  end = clock();

  time_total = (double)(end - begin) / CLOCKS_PER_SEC;

  printf("Tempo Total: %lf\n",time_total);

  return 0;
}