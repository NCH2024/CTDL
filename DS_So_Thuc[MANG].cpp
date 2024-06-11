#include <stdio.h>
#include <conio.h>

//1. Khai bao cau truc danh sach
#define MaxLength 50 		// Do dai toi da 
typedef float ElementType;	//Kieu phan tu trong ds
typedef int Position;		//Kieu vi tri ptu
typedef struct{
	ElementType Elements[MaxLength]; 	//mang chua cac phan tu
	Position Last; 			// giu do dai danh sach
} List;

	//Ds cac chuong trinh con
	//Ham khoi tao ds rong
	void MakeNull_List(List *L);
	//Kiem tra danh sach day
	int Full_List(List L);
	//Ham xen ptu vao vi tri P cua ds L
	void Insert_List(ElementType X, Position P, List *L);
	//Ham lay phan tu tai vi tri P
	ElementType Retrieve (Position P, List L);
	//Ham kiem tra rong
	int Empty_List(List L);
	//Ham xoa phan tu
	void Delete_List(Position P,List *L);
	//Ham tra ve vi tri dau tien
	Position First(List L);
	//Ham tra ve vi tri cuoi cung
	Position EndList(List L);
	//ham phan tu ke tiep
	Position Next (Position P, List L);
	//Ham tim kiem
	Position Locate (ElementType X,List L);
	//Nhap n phtu luu tru vao L
	void Nhap_DS(List *L, int n);
	//In ds L
	void In_DS(List L);
	//Tinh gia tri TB
	float TinhTB(List L);

//Chuong Trinh chinh:
int main(){
	int n;
	List L;
	//2. nhap n so thuc vao danh sach
	printf("\n Nhap so phan tu cua danh sach n = "); scanf("%d", &n);
	//khoi tao ds rong
	MakeNull_List(&L);
	//Nhap danh sach
	Nhap_DS(&L,n);
	//In danh sach
	printf("\nDanh Sach vua nhap la:\n");
	In_DS(L);
	
	//3.Tinh gia tri TB
	printf("\nGia tri Trung Binh: %.2f",TinhTB(L));
	
	//4.Nhap vao so nguyen K va xoa
	Position P;
	printf("\nNhap vao vi tri can xoa: ");
	scanf("%d", &P);
	Delete_List(P, &L);
	In_DS(L);
	
	//5. Tim va xen X
	ElementType X;
	printf("\nNhap phan tu can xen X = ");
	scanf("%f", &X);
	//Tim X
	P = Locate(X,L);
	if(P!=EndList(L))
		printf("\nPhan tu %.2f da co trong danh sach!");
	else {
		Insert_List(X, First(L), &L);
		printf("\nDanh sach sau khi xen %.2f vao dau danh sach:\n", X);
		In_DS(L);
	}
	//ket thuc chuong trinh
	getch();
	return 0;
}

//Cai dat cac chuong trinh con
//Ham khoi tao Ds rong
void MakeNull_List(List *L){
	L->Last=0;
}
//Kiem tra danh sach day
int Full_List(List L){
	return L.Last==MaxLength;
}
//Ham xen ptu vao vi tri P cua ds L
void Insert_List(ElementType X, Position P, List *L){
	if(Full_List(*L))
		printf("Danh sach day");
	else
		if((P<1) || (P>L->Last+1))
			printf("Vi tri khong hop le");
		
		else { Position Q;
		for(Q=(L->Last-1)+1;Q>P-1;Q--)
			L->Elements[Q]= L->Elements[Q-1];
		L->Elements[P-1]=X; 
		L->Last++; 
	}
}
//Ham lay phan tu tai vi tri P
ElementType Retrieve (Position P, List L){
	return (L.Elements[P-1]);
};
//Ham kiem tra rong
int Empty_List(List L){
	return L.Last==0;
}
//Ham xoa phan tu
void Delete_List(Position P,List *L){
	if (Empty_List(*L))
		printf("Danh sach rong!");
	else
	if ((P<1) || (P>L->Last))
		printf("Vi tri khong hop le");
	else{
		Position Q;
	for(Q=P-1;Q<L->Last-1;Q++)
		L->Elements[Q]=L->Elements[Q+1];
		L->Last--;
	}
}
//Ham tra ve vi tri dau tien
Position First(List L){
	return 1;
}
//Ham tra ve vi tri cuoi cung
Position EndList(List L){
return L.Last+1;
}
//ham phan tu ke tiep
Position Next (Position P, List L){
	return (P+1);
}
//Ham tim kiem
Position Locate (ElementType X,List L){
	Position P;
	int Found = 0;
		P = First(L);
	while((P != EndList(L)) &&(Found == 0))
	if (Retrieve(P,L) == X)
		Found = 1;
	else
		P = Next(P, L);
	return P;
}

//Nhap n phtu luu tru vao L
void Nhap_DS(List *L, int n){
	ElementType X;
	for(int i = 0; i < n; i++){
		printf("\n Nhap vao phan tu thu %d = ", i+1);
		scanf("%f",&X);
		Insert_List(X, i+1, L);
	}
}
//In ds L
void In_DS(List L){
	Position P;
	ElementType X;
	for( P = 1; P <= L.Last ; P++){
		X = Retrieve(P, L);
		printf("%.2f", X);
		printf ("\n");
	}
}
//Tinh gia tri TB
float TinhTB(List L){
	Position P;
	ElementType X;
	ElementType Tong;
	for( P = 1; P <= L.Last ; P++){
		X = Retrieve(P, L);
		Tong += X;
	}	
	return (Tong/L.Last);
}


