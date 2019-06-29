#include <stdbool.h>

#define EH 0；
#define LH 1;
#define RH -1;

typedef struct BinTree
{
    int data;
    int bf;
    struct BinTree *lchild, *rchild;
}BiTNode, *BinTree;

void R_Rotate(BinTree *T)
{
    BinTree L;
    L = (*T)->lchild;
    (*T)->lchild = L->rchild;
    L->rchild = (*T);
    (*T) = L;
}

void L_Rotate(BinTree *T)
{
    BinTree R;
    R = (*T)->rchild;
    (*T)->rchild = R->lchild;
    R->lchild = (*T);
    (*T) = R;
}

void leftbalance(BinTree *T)
{
    BinTree L, Lr;
    L = (*T)->lchild;

    switch (L->bf)
    {
        case LH:
            (*T)->bf = EH;
            L->bf = EH;
            R_Rotate(T);
            break;
    
        case RH:
            Lr = L->rchild;
            switch (Lr->bf)
            {
                case LH:
                    (*T)->bf = RH;
                    L->bf = EH;
                    break;
            
                case EH:
                    (*T)->bf = EH;
                    L->bf = EH;
                    break;
                
                case RH:
                    (*T)->bf = EH;
                    L->bf = LH;
                    break;
            }

            Lr->bf = EH;
            L_Rotate(&(*T)->lchild);
            R_Rotate(T);
    }
}

void rightbalance(BinTree *T)
{
    
}


bool InsertAVL(BinTree *T, int e, bool *taller)
{
    if(!*T){
        *T = (BinTree)malloc(sizeof(BiTNode));
        (*T)->bf = EH;
        (*T)->data = e;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
        *taller = true;
        return true;
    }

    if(e == (*T)->data){
        *taller = false;
        return false; 
    }

    if(e < (*T)->data)){
        if(!InsertAVL(&(*T)->lchild, e, taller){
            return false;
        }

        if(*taller){
            switch ((*T)->bf)
            {
                case RH:
                    (*T)->bf = EH;
                    *taller = false;
                    break;
                
                case EH:
                    (*T)->bf = LH;
                    *taller = true；
                    break;

                case LH:
                    leftbalance(T);
                    (*T)->bf = EH;
                    *taller = false;
            
                default:
                    break;
            }

        }
    }
    else if(e > (*T)->data)){
        if(!InsertAVL(&(*T)->rchild, e, taller){
            return false;
        }

        if(*taller){
            switch ((*T)->bf)
            {
                case LH:
                    (*T)->bf = EH;
                    *taller = false;
                    break;
                
                case EH:
                    (*T)->bf = RH;
                    *taller = true；
                    break;

                case RH:
                    rightbalance(T);
                    (*T)->bf = EH;
                    *taller = false;
            
                default:
                    break;
            }

        }
    }

    return true;
}