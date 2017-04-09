#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"
#include <string.h>
#include <ctype.h>
int zeraString(char string[], int tam){
    int i=0;
    for(i=0;i<tam+1;i++)
        string[i] = '\0';
    return 1;

}
int main()
{

    int tmp;
     ArvBin palavra;
    //const char fim[3]= "\0";
    char aux[21];
    ArvBin* raiz = cria_ArvBin();
    FILE *entrada = fopen("entrada.txt","r");

    int i=0;
    while(!feof(entrada) && !ferror(entrada))
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
        //printf("aux:%s\n",aux);
//        *palavra = strtok(aux,fim);
        strcpy(palavra->info,aux);

        insere_ArvBin(raiz,palavra->info);

       // printf("palavra:%s     aux:%s\n",palavra,aux);

    }
    //zeraString(*palavra,21);
    //zeraString(aux,21);
    //preOrdem_ArvBin(raiz);
    emOrdem_ArvBin(raiz);
    //posOrdem_ArvBin(raiz);



    fclose(entrada);
    libera_ArvBin(raiz);
    return 0;
}
