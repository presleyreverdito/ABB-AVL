#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
#include <string.h>

#include<locale.h>

int zeraString(char string[], int tam){
    int i=0;
    for(i=0;i<tam+1;i++)
        string[i] = '\0';
    return 1;

}
char *devolvePalavra(char palavra[]){

    char *aux = malloc(sizeof(char) * 21);
    int i;
    for(i = 0; palavra[i]!='\0'; i++){
        aux[i] = palavra[i];
    }
    aux[i] = palavra[i];
    //printf("%s\n",aux);
    return aux;
}
int main()
{
    int tmp;
<<<<<<< HEAD
    char palavra[21], aux[21];
=======

     ArvBin palavra;
    //const char fim[3]= "\0";
    char aux[21];
>>>>>>> origin/master

    ArvBin* raiz = cria_ArvBin();
    FILE *entrada = fopen("entrada.txt","r");
    setlocale(LC_ALL, "Portuguese");

    int i=0,j;
    for(i = 0, tmp = getc(entrada); tmp != EOF; i++, tmp = getc(entrada)){
        if((tmp != ' ') && (tmp != ',') && (tmp != ';') && (tmp != '.') && (tmp !='\n') && (tmp !='\0') && (tmp !='?') && (tmp !='!')){
            if(tmp>=65 &&tmp<91)
                tmp=tmp+32;
            aux[i] = tmp;
        }
        else if(i!=0){
            aux[i] = '\0';

            insere_ArvBin(raiz,devolvePalavra(aux));
            i = -1;
        }
    }
<<<<<<< HEAD
=======
    /*while(!feof(entrada) && !ferror(entrada))
    {
        // ate o fim do arquivo

        tmp = fgetc(entrada); // lendo dados

        while((tmp != ' ') && (tmp != ',') && (tmp != ';') && (tmp != '.') && (tmp !='\n') && (tmp !='\0') && (tmp !='?') && (tmp !='!')) //condicoes para pegar as palavras
        {
            if(tmp>=65 &&tmp<91){
                tmp=tmp+32;
                }
            aux[i]=tmp;
            //printf("aux:%c eh tmp=%d\n",aux[i],tmp);
            tmp =fgetc(entrada);
            if(tmp == EOF) //fim do arquivo
                break;
            i++;
        }

        aux[i]='\0';
        printf("%s\n",aux);
        //printf("aux:%s\n",aux);
//        *palavra = strtok(aux,fim);
        strcpy(palavra->info,aux);

        insere_ArvBin(raiz,palavra->info);

       // printf("palavra:%s     aux:%s\n",palavra,aux);


    }*/
>>>>>>> origin/master


    //preOrdem_ArvBin(raiz);
    emOrdem_ArvBin(raiz);
    //posOrdem_ArvBin(raiz);

    fclose(entrada);
    libera_ArvBin(raiz);
    return 0;
}
