#include <stdio.h>
#define SoPhanTu 10

typedef struct{
    int DuLieu[SoPhanTu];
    int Dinh;
} NganXep;

// Khoi tao ngan xep rong
void khoitao(NganXep *pS){
    pS->Dinh = SoPhanTu;
}

// Kiem tra ngan xep rong
int ktRong(NganXep S){
	return S.Dinh == SoPhanTu;
}

// Kiem tra ngan xep day
int ktDay(NganXep S){
	return S.Dinh == 0;
}

// Lay gia tri trong ngan xep
int giatriDinh(NganXep S){
	return S.DuLieu[S.Dinh];
}

// Them mot phan tu vao ngan xep
void them(int x, NganXep *pS){
	if(!ktDay(*pS)){
		pS->Dinh--;
		pS->DuLieu[pS->Dinh] = x;
	}
}

// Xoa mot phan tu trong ngan xep
void xoa(NganXep *pS){
    if(!ktRong(*pS))
        pS->Dinh++;
}

// In ngan xep
void printStack(NganXep S){
	int i;
    for(i = S.Dinh; i < SoPhanTu; i++)
    	printf("%d ", S.DuLieu[i]);
    printf("\n");
}

void hienthi(NganXep *pS){
	while(!ktRong(*pS)){
		printf("%d ", giatriDinh(*pS));
		xoa(pS);
	}
}

int main(){
    NganXep S;
    khoitao(&S);
	them(6, &S);
	them(5, &S);
	them(4, &S);
	them(7, &S);
	them(5, &S);
	them(4, &S);
	them(5, &S);
	them(6, &S);
	them(7, &S);
    printStack(S);
    xoa(&S);
    xoa(&S);
    hienthi(&S);
    printStack(S);
    return 0;
}
