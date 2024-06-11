	#include <stdio.h>
	#include <conio.h>
	#include <malloc.h>
	
	//1. Khai bao cau truc
	typedef float ElementType;		//Kieu du lieu phan tu trong danh sach
	typedef struct Node {
		ElementType Elements; 	
		Node* Next; 				//Con tro ke tiep
	};
	typedef Node* Position;			//kieu vi tri
	typedef Position List;
	
	//Danh sach cac chuong trinh con
	
	//Khoi tao danh sach rong
	void MakeNull_List(List *L);
	//Ham chen phan tu
	void Insert_List(ElementType X, Position P, List *L);
	//Ham lay noi dung
	ElementType Retrieve (Position P, List L);
	//Ham xoa phan tu tai P
	void Delete_List(Position P, List *L);
	//Nhap danh sach n so thuc
	void Nhap_DS(List *L, int n);
	//In danh sach
	void In_DS(List L);
	//Tinh trung binh
	float Tinh_TB(List L);
	//Xoa ptu tai k
	void Xoa_K(int K,List *L);
	//Tim X
	Position Locate(ElementType X, List L);
	
	//Chuong trinh chinh
	int main(){
		List L;
		int n;
		Position P;
		//2. Nhap n so thuc va luu tru vao ds
		printf("\n Nhap so phan tu co trong danh sach (n): ");
		scanf("%d", &n);
		MakeNull_List(&L);
		Nhap_DS(&L,n);
			//In danh sach
		In_DS(L);
		
		//3. Tinh gia tri trung binh cua danh sach
		printf("\n Gia tri TB cua danh sach tren: %.2f ",Tinh_TB(L));
		
		//4. Xoa phan tu tai vi tri K
		int K;
		printf("\n Nhap vao vi tri can xoa: "); scanf("%d", &K);
		Xoa_K(K, &L);
		//5. Tim X va Xen
		ElementType X;
		printf("\nNhap phan tu can xen X = ");
		scanf("%f", &X);
			//Tim X
		P = Locate(X,L);
		if(P !=NULL)
			printf("\nPhan tu %.2f da co trong danh sach!", X);
		else {
			Insert_List(X, L, &L);
			printf("\nDanh sach sau khi xen %.2f vao dau danh sach:\n", X);
			In_DS(L);
		}
		
		//Ket thuc chuong trinh
		getch();
		return 0;
	}
	
	//Danh sach cai dat cac chuong trinh con
	
	//Khoi tao danh sach rong
	void MakeNull_List(List *L){
		(*L)=(Node*)malloc(sizeof(Node));
		(*L)->Next= NULL;
	}
	//Ham chen phan tu
	void Insert_List(ElementType X, Position P, List *L){
		Position T;
		T=(Node*)malloc(sizeof(Node));
		T->Elements=X;
		T->Next=P->Next;
		P->Next=T;
	}
	//Ham lay noi dung
	ElementType Retrieve (Position P, List L){
		if (P->Next !=NULL)
		return (P->Next->Elements);
	}
	//Ham xoa phan tu tai P
	void Delete_List(Position P, List *L){
		Position Temp;
		if (P->Next!=NULL){
			Temp = P->Next;
			P->Next = Temp->Next;
			free(Temp);
		}
	}
	//Nhap danh sach n so thuc
	void Nhap_DS(List *L, int n){
		ElementType X;
		Position P;
		P = *L;
		for(int i = 0; i < n; i++){
			printf("\n Nhap phan thu thu %d = ", i+1);
			scanf("%f", &X);
			Insert_List(X, P,L); P = P->Next ;
		}
	}
	//In danh sach
	void In_DS(List L){
		ElementType X;
		Position P; 
		P = L;
		while ( P->Next != NULL){
			X = Retrieve(P, L);
			printf(" %.2f",X);
			P = P->Next ;
			printf("\n");
		}
	}
	//Tinh trung binh
	float Tinh_TB(List L){
		ElementType X;
		Position P; 
		P = L;
		float Tong = 0; int Temp = 0;
		while ( P->Next != NULL){
			X = Retrieve(P, L);
			Tong += X;
			P = P->Next ;
			Temp++;
		}
		return (Tong/Temp);
	}
	//Xoa ptu tai vi tri k
	void Xoa_K(int K,List *L){
		Position P; 
		P = *L;
		int i = 0;
			while ((i <= K - 1) && (P->Next != NULL)){
				P = P->Next ;
				i++;
			}
			if(P != NULL){
				Delete_List(P,L);
				printf("\n Danh sach sau khi xoa: ");
				In_DS(*L);
			}
			else printf("\n Loi danh khong du %d phan tu!", K);
	}
	//Tim x
	Position Locate(ElementType X, List L){
		Position P;
		int Found = 0;
		P = L;
		while ((P->Next != NULL) && (Found == 0))
			if (P->Next->Elements == X) Found = 1;
			else
				P = P->Next;
		if (Found == 1) return P;
		else return NULL;
	}

