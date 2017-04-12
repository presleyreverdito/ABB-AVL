#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include <time.h>
#include <locale.h>
int main()
{
    int tmp, i;
    char aux[21];
    clock_t tempo_i, tempo_f;
    srand(time(NULL));
    tempo_i = clock();
    struct Node *root = NULL;
    FILE *entrada = fopen("entrada.txt","r");
    setlocale(LC_ALL, "Portuguese");

    for(i = 0, tmp = getc(entrada); tmp != EOF; i++, tmp = getc(entrada))
    {
        if((tmp != ' ') && (tmp != ',') && (tmp != ';') && (tmp != '.') && (tmp !='\n') && (tmp !='\0') && (tmp !='?') && (tmp !='!'))
        {
            if(tmp>=65 &&tmp<91)
                tmp=tmp+32;
            aux[i] = tmp;

        }
        else if(i!=0)
        {
            aux[i] = '\0';

                root=insert(root,aux);
            i = -1;
        }
    }
     tempo_f = clock();
    //preOrder(root);
    printf("Arvore AVL: %lu segundos   ", (tempo_f - tempo_i)/CLOCKS_PER_SEC);
    emOrdem_ArvAVL(root);
    fclose(entrada);
    libera_ArvAVL(root);
    return 0;
}

