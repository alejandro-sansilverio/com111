#include "FilaEnc.h"

struct no
{
    float info;
    struct no* prox;
};

struct filaEnc
{
    No* inicio;
    No* fim;
};

int ok, cont;
float v;

FilaEnc* Fenc_criar()
{
    FilaEnc f = (*filaEnc)malloc(sizeof(FilaEnc));
    if(!f)
    {
        printf("Erro ao alocar memoria/n");
    }
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

int Fenc_liberar(FilaEnc* f)
{
    ok=Fenc_esvaziar(f);
    if(ok==1||ok!=-2)
    {
        free(f);
        ok=1;
    }

    return ok;
}

int Fenc_enfileirar(FilaEnc* f, float v)
{
    return ok;
}

float Fenc_desenfileirar(FilaEnc* f)
{
    return v;
}

float Fenc_comeco (FilaEnc* f)
{
    return v;
}

int Fenc_esvaziar(FilaEnc* f)
{
    return ok;
}

int Fenc_vazia(FilaEnc* f)
{
    return ok;
}

int Fenc_tamanho(FilaEnc* f)
{
    return cont;
}

int Fenc_imprimir(FilaEnc* f)
{
    return ok;
}
