#include <dirent.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "arquivo.h"
#include "imagem.h"

//determina o tamanho da janela na hora de filtrar
#define LER 5

int main(int argc, char *argv[]){
  //inicialização do tempo
  clock_t begin, end;
  double time_per_img, time_total=0;
  begin = clock();
  DIR *d;
  struct dirent *dir;
  struct pgm img;
  int cont = 0;

  //nome do arquivo que estão as imagens
  d = opendir("./images");

  if(argc != 5){
    printf("Formato: \n\t %s \n",argv[0]);
    exit(1);
  }

  FILE *file = fopen(argv[1], "w");
  FILE *arquivo = fopen(argv[2], "w");
  if(!file) exit(2);
  if(!arquivo) exit(3);
   
  for(int i = 0; i<=(atoi(argv[4])*atoi(argv[4])); i++){
    fprintf(file, "%i", i);
    fputs(",", file);
  }

  fclose(file);
  fclose(arquivo);

  if (d){    
   //ler imagens do diretorio(processamento de imagens)
    while ((dir = readdir(d)) != NULL){
    //pula o "." e ".." que vem ao ler a imagem
      if(cont>1){
        printf("\n");
        printf("%s\n", dir->d_name);
        readPGMImage(&img, dir->d_name);
      
      //escreve no relatório a ordem de processamento
        FILE *arquivo = fopen(argv[2], "a");
        fputs(dir->d_name, arquivo);
        fputs("\n", arquivo);

      //declaração de variaveis  
        unsigned char *filtro = (unsigned char *)calloc((img.r + LER/2*2) * (img.c+LER/2*2), sizeof(unsigned char));
        unsigned char *suave = (unsigned char *)calloc((img.r) * (img.c), sizeof(unsigned char));
        unsigned char *scm = (unsigned char *)calloc((atoi(argv[4])*atoi(argv[4])), sizeof(unsigned));
        int quantizacao;
        char *file = "output.txt";
        
      //processamento das funções
        gerarFiltro(&img, atoi(argv[3]), filtro);
        gerarSuave(filtro, suave, atoi(argv[3]), &img);
        quantizar(&img, quantizacao);
        matrizSCM(scm, suave, &img, quantizacao);
        criarArqv(file, scm, quantizacao);
        
      //adiciona no final "epithelium" ou "stroma"
      //quando for 0 -> epithelium e 1 -> stroma
        if(dir->d_name[0] == '0'){
          fprintf(file, "epithelium");
        }else if(dir->d_name[0] == '1'){
          fprintf(file, "stroma");
        }

        fclose(file);
        fclose(arquivo);

      }
      cont++;
    }
    closedir(d);
    end = clock();

  //para de contar o tempo
    time_total = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Tempo Total: %lf\n",time_total);
  }

  return 0;
}		