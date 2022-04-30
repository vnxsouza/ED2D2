/*
*    Biblioteca Arvore bin�ria de Busca
*
*/
//Arquivo arvoreBinaria.h
typedef struct NO *ArvAVL;

//Arquivo arvoreBinaria.h
ArvAVL *cria_ArvAVL();

//Arquivo arvoreBinaria.h
void liberar_ArvAVL(ArvAVL *raiz);

//Arquivo arvoreBinaria.h
int vazia_ArvAVL(ArvAVL *raiz);

//Arquivo arvoreBinaria.h
int altura_ArvAVL(ArvAVL *raiz);

//Arquivo arvoreBinaria.h
int totalNO_ArvAVL(ArvAVL *raiz);

//Arquivo arvoreBinaria.h
void preOrdem_ArvAVL(ArvAVL *raiz);

//Arquivo arvoreBinaria.h
void emOrdem_ArvAVL(ArvAVL *raiz);

//Arquivo arvoreBinaria.h
void posOrdem_ArvAVL(ArvAVL *raiz);

//Arquivo arvoreBinaria.h
int insere_ArvAVL(ArvAVL *raiz, int valor);

//Arquivo arvoreBinaria.h
int remove_ArvAVL(ArvAVL *raiz, int valor);

//Arquivo arvoreBinaria.h
int consulta_ArvAVL(ArvAVL *raiz, int valor);

int consulta_ArvAVL(ArvAVL *raiz, int valor);

void rotacaoLL(arvAVL *raiz);

void rotacaoRR(arvAVL *raiz);

void rotacaoLR(arvAVL *raiz);

void rotacaoRL(arvAVL *raiz);

int alt_no(struct NO *no);

int fatorBalanceamento_NO;

int maior(int x, int y);
