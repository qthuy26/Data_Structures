#include "PListLib.c"

float getAvg(List L){
    float S = 0, avg, dem = 0;
    Position P;
    if(emptyList(L))
        return -10000.0;
    else{
        P = First(L);
        while(P != NULL && P->Next != NULL){
            S += Retrieve(P, L);
            dem++;
            P = P->Next;
        }
        avg = S / dem;
        return avg;
    }
}
