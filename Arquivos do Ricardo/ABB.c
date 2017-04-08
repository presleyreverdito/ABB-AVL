#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

typedef struct {

   char palavra[30];

}text;

typedef struct nodo{

   text le;

   struct nodo *esq;
   struct nodo *dir;

} NO;

typedef NO *ABB;


// Função para criar uma nova arvore
ABB nova_arv()
{
    return NULL;
}

int VAZIA (ABB a){

    return (a == NULL);
}


//  Função para inserir um novo elemento 'b' na arvore 'a'
ABB insere (ABB a, text b)
{
    ABB nod;

    if (VAZIA(a))
    {
        nod = malloc (sizeof(NO));
        nod->esq = NULL;
        nod->dir = NULL;
        nod->le = b;
        return nod;
    }
    else
    {
        if ( strcmp(a->le.palavra,b.palavra) < 0 )
            a->dir = insere(a->dir, b);
        else
            a->esq = insere(a->esq, b);  // Repeticoes sao inseridas na esquerda
        return a;
    }
}

// Funcao para imprimir em ordem
void inorder(ABB a)
{
    if (! VAZIA(a) )
    {
        inorder(a->esq);

        printf("%s\n ",a->le.palavra);
        inorder(a->dir);
    }
}



int main()
{

    int tmp;

    char string[30];

    ABB a = NULL;
    ABB b = NULL;

    text le;

    FILE *arq;

    arq = fopen("teste.txt", "r");

    if (!arq) return 0; // erro de leitura

    while(!feof(arq) && !ferror(arq)) // ate o fim do arquivo
    {
          tmp = fgetc(arq); // lendo dados
          int i = 0;

        while((tmp != ' ') && (tmp != ',') && (tmp != ';') && (tmp != '.') && (tmp !='\n')) //condicoes para pegar as palavras
        {

            string[i] = tmp;

            tmp = fgetc(arq);

            if(tmp == EOF) //fim do arquivo
                break;
            i++;

        }

        string[i] = '\0'; // fim da string

        strcpy(le.palavra,string); // copia duas string

        a = insere(a,le); // inserindo na arvore


    }

    fclose(arq); // fim leitura
    inorder(a); // ordenando

    return 0;
}
