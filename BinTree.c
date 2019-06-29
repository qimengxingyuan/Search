#include <stdbool.h>
#include <stdlib.h>

typedef struct BinTree
{
    int Node;
    struct BinTree *lchild, *rchild;
}BiNode, *BinTree;

bool SearchBST(BinTree T, int key, BinTree f, BinTree *p)
{
    if(!T){
        *p = f;
        return false;
    }
    
    if(key == T->Node){
        *p = T;
        return true;
    }
    else if(key < T->Node){
       return SearchBST(T->lchild, key, T, p);
    }
    else{
        return SearchBST(T->rchild, key, T, p);
    }
}

bool InsertBST(BinTree *T, int key)
{
    BinTree p, s;

    if(!SearchBST(*T, key, NULL, &p)){
        s = (BinTree)malloc(sizeof(BiNode));
        s->rchild = NULL;
        s->lchild = NULL;
        s->Node = key;

        if(!p){
            *T = s;
        }
        else if(key < p->Node){
            p->lchild = s;
        }
        else{
            p->rchild = s;
        }
        return true;
    }

    return false;
}


bool Delete(BinTree *T)
{
    BinTree p, s;

    if((*T)->lchild == NULL){
        p = (*T);
        (*T) = (*T)->rchild;
        free(p);
    }
    else if((*T)->rchild == NULL){
        p = (*T);
        (*T) = (*T)->lchild;
        free(p);
    }
    else
    {
        p = (*T);
        s = (*T)->lchild;

        while(s->rchild){
            p = s;
            s = s->rchild;
        }
        (*T)->Node = s->Node;

        if(p != (*T)){
            p->rchild = s->lchild;
        }
        else{
            p->lchild = s->lchild;
        }

        free(s);
    }
    
    return true;
}

bool DeleteBST(BinTree *T, int key)
{
    if(!*T){
        return false;
    }

    if((*T)->Node == key){
        return Delete(T);
    }
    if((*T)->Node < key){
        DeleteBST(&(*T)->rchild);
    }
    else{
        DeleteBST(&(*T)->lchild);
    }
}
