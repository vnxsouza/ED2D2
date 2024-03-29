//Arquivo arvoreBinaria.c
#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

struct NO{
    int info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};

//Arquivo arvoreBinaria.c
ArvAVL *cria_ArvAVL(){
    ArvAVL *raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}
//Arquivo arvoreBinaria.c
void liberar_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    libera_NO(*raiz);
    free(raiz);
}

//Arquivo arvoreBinaria.c
void libera_NO(struct NO *no){
    if(no == NULL){
        return;
    }
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

//Arquivo arvoreBinaria.c
int vazia_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
}

//Arquivo arvoreBinaria.c
int altura_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if(alt_esq > alt_dir){
        return(alt_esq + 1);
    }else{
        return(alt_dir + 1);
    }
}

//Arquivo arvoreBinaria.c
int totalNO_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

//Arquivo arvoreBinaria.c
void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

//Arquivo arvoreBinaria.c
void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

//Arquivo arvoreBinaria.c
void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL){
        return;
    }
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

int alt_no(struct NO *no){
    if(no == NULL){
        return -1;
    }else{
        return no->alt;
    }
}
int fatorBalanceamento_NO(struct NO *no){
    return labs(alt_no(no->esq) - alt_no(no->dir));
}

int maior(int x, int y){
    if(x>y){
        return (x);
    }else{
        return (y);
    }
}

/*
//Arquivo arvoreBinaria.c
int insere_ArvAVL(ArvAVL *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO *novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL){
        return 0;
    }
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    if(*raiz == NULL){
        *raiz = novo;
    }else{
        struct NO *atual = *raiz;
        struct NO *ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);//elemento j� existe!
                return 0;
            }
            if(valor > atual->info){
                atual = atual->dir;
            }else{
                atual = atual->esq;
            }
        }
        if(valor > ant->info){
            ant->dir = novo;
        }else{
            ant->esq = novo;
        }
    }
    return 1;
}


//Arquivo arvoreBinaria.c
//fun��o auxiliar para remo��o o n� especifico

struct NO *remove_atual(struct NO *atual){
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

//Arquivo arvoreBinaria.c
int remove_ArvAVL(ArvAVL *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO *ant = NULL;
    struct NO *atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz){
                *raiz = remove_atual(atual);
            }else{
                if(ant->dir == atual){
                    ant->dir = remove_atual(atual);
                }else{
                    ant->esq = remove_atual(atual);
                }

            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
}
*/

//Arquivo arvoreBinaria.c
int consulta_ArvAVL(ArvAVL *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    struct NO *atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;
}


void rotacaoLL(ArvAVL *raiz){
    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    no->alt = maior(alt_no(no->esq), (*raiz)->alt +1);
    *raiz = no;
}



void rotacaoRR(ArvAVL *raiz){
    struct NO *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = (*raiz);
    (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir))+1;
    (*raiz)=no;

}

void rotacaoLR(ArvAVL *raiz){
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

void rotacaoRL(ArvAVL *raiz){
    rotacaoRL(&(*raiz)->dir);
    rotacaoRL(raiz);
}

int insere_ArvAVL(ArvAVL *raiz, int valor){
    int res; //pega as respostas da chamada de fun��o
    if(*raiz==NULL){
        struct NO *novo;
        novo = (struct NO*) malloc(sizeof(struct NO));
        if(novo == NULL){
            return 0;
        }
        novo->info = valor;
        novo->alt = 0;
        novo ->esq = NULL;
        novo->dir =  NULL;
        *raiz = novo;
        return 1;
    } // se n�o... fa�a:

    struct NO *atual = *raiz;
    if(valor < atual->info){
        if((res  = insere_ArvAVL(&(atual->esq),valor ))==1){
                if(fatorBalanceamento_NO(atual)>=2){
                    if(valor < (*raiz)->esq->info){
                        rotacaoLL(raiz);
                    }else{
                        rotacaoLR(raiz);
                    }
                }
        }
    }else{ //Se o valor a inserir n�o era menor do que o atual..

        if(valor > atual->info){
            if((res = insere_ArvAVL(&(atual->dir),valor ))==1){
                if(fatorBalanceamento_NO(atual)>=2){
                    if(valor < (*raiz)->esq->info){
                        rotacaoRR(raiz);
                    }else{
                    rotacaoRL(raiz);
                    }
                }

            }
        }else{
            printf("Valor Duplicado!!\n");
            return 0;
        }
    }
    atual->alt = maior(alt_no(atual->esq), alt_no(atual->dir)) +1;
    return res;
}
/*
int remove_ArvAVL(ArvAVL *raiz, int valor){

}*/




























