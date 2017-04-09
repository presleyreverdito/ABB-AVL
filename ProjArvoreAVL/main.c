#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h"
#include <time.h>
#include<locale.h>
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
    int tmp, i;
    char aux[21];
    ArvAVL* avl;
    avl = cria_ArvAVL();
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

            insere_ArvAVL(avl,devolvePalavra(aux));
            i = -1;
        }
    }



    //preOrdem_ArvBin(raiz);
    emOrdem_ArvAVL(avl);
    //posOrdem_ArvBin(raiz);

    fclose(entrada);
    libera_ArvAVL(avl);
    return 0;
}

