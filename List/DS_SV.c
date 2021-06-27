#include <stdio.h>
#include <string.h>
#define Maxlength 40

struct SinhVien{
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
};

typedef struct {
	struct SinhVien A[Maxlength];
	int n;		// So phan tu trong danh sach
}DanhSach;

// Tong diem lt va th cua sinh vien
float TongDiem(struct SinhVien sv){
	return sv.DiemLT + sv.DiemTH1 + sv.DiemTH2;
}

// In danh sach sinh vien
void hienthi(DanhSach L){
	int i;
	for(i = 0; i < L.n; i++){
		float Diem = TongDiem(L.A[i]);
		printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2, Diem);
	}
}

void inSV(struct SinhVien sv){
    float Diem = TongDiem(sv);
    printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", sv.MSSV, sv.HoTen, sv.DiemLT, sv.DiemTH1, sv.DiemTH2, Diem);
}

// Tim kiem vi tri sinh vien co ma so cho truoc
int tim(char x[], DanhSach L){
	if(x[strlen(x)-1] == '\n')
		x[strlen(x)-1] = '\0';
	int i;
	for(i = 0; i < L.n; i++)
		if(strcmp(L.A[i].MSSV, x) == 0)
			return i+1;
	return L.n+1;
}

// Xoa sinh vien o vi tri p trong danh sach
void xoaTai(int p, DanhSach *pL){
	if(p < 1 || p > pL->n)
		printf("Vi tri khong hop le");
	else{
		int i;
		for(i = p-1; i < pL->n; i++)
			pL->A[i] = pL->A[i+1];
		pL->n--;
	}
}

// Xoa sinh vien co ma so x trong danh sach
void xoaSinhVien(char x[], DanhSach *pL){
	int p = tim(x, *pL);
	xoaTai(p, pL);
}

// Them sinh vien s vao cuoi danh sach
void chenCuoi(struct SinhVien s, DanhSach *pL){
	if(pL->n == Maxlength){
		printf("Loi! Danh sach day!");
		return;
	}
	pL->A[pL->n] = s;
	pL->n++;
}


// Khoi tao va tra ve danh sach rong
void dsRong(DanhSach *pL){
	pL->n = 0;
}


int ktRong(DanhSach L){
	return L.n == 0;
}

// Nhap danh sach sinh vien
DanhSach nhap(){
	DanhSach sv;
	dsRong(&sv);
	int n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		struct SinhVien s;
		scanf("\n");
		fgets(s.MSSV, 10, stdin);
		if(s.MSSV[strlen(s.MSSV)-1] == '\n')
    		s.MSSV[strlen(s.MSSV)-1] = '\0';
    	fgets(s.HoTen, 50, stdin);
    	if(s.HoTen[strlen(s.HoTen)-1] == '\n')
    		s.HoTen[strlen(s.HoTen)-1] = '\0';
    	scanf("%f%f%f", &s.DiemLT, &s.DiemTH1, &s.DiemTH2);
    	int p = tim(s.MSSV, sv);
    	if(p == sv.n+1)
    		chenCuoi(s, &sv);	
	}
	return sv;
}


DanhSach chepKhongDat(DanhSach L){
	DanhSach kq;
	dsRong(&kq);
	int i;
	for(i = 0; i < L.n; i++)
		if(TongDiem(L.A[i]) < 4)
			chenCuoi(L.A[i], &kq);
	return kq;
}

DanhSach chepDat(DanhSach L){
	DanhSach kq;
	dsRong(&kq);
	int i;
	for(i = 0; i < L.n; i++)
		if(TongDiem(L.A[i]) >= 4.0)
			chenCuoi(L.A[i], &kq);
	return kq;
}


int main(){
	DanhSach L;
	int i;
	
	L = nhap();	
	for(i=0;i<L.n;i++){
	    printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
	}
}
