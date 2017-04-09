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
    return aux;
}
int main()
{
    int tmp, i;
    char aux[21];

    ArvBin* raiz = cria_ArvBin();
    FILE *entrada = fopen("entrada.txt","r");
    setlocale(LC_ALL, "Portuguese");

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



    //preOrdem_ArvBin(raiz);
    emOrdem_ArvBin(raiz);
    //posOrdem_ArvBin(raiz);

    fclose(entrada);
    libera_ArvBin(raiz);
    return 0;
}
