#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>


typedef unsigned char TData;
struct TNode{
	TData Data;
	TNode* left;
	TNode* right;
};
typedef TNode* TTree;



//CT con
//bai1
//tao cay rong
void MakeNullTree(TTree *T);
//tao cay moi
TTree Create2(TData v,TTree l,TTree r);
//KT rong
int EmptyTree(TTree T);
//xac dinh con trai nut
TTree LeftChild(TTree n);
//xac dinh con phai nut
TTree RightChild(TTree n);
//duyet tien tu
void PreOrder(TTree T);
//duyet trung tu
void InOrder(TTree T);
//duyet hau tu
void PosOrder(TTree T);
////xac dinh do nut cua cay
int nb_nodes(TTree T);
//bai2
//tim kiem nut
TTree Search(TData x,TTree Root);
//them nut
void InsertNode(TData x,TTree *Root );
//
TData DeleteMin (TTree *Root );
//xoa mot nut 
void DeleteNode(TData X,TTree *Root);
//ham tao 
TTree taocay(TTree *Root); 



int main(){
	TTree T;
	
	
	
	//1
	MakeNullTree(&T);
	//1a
	TTree T121 = Create2('G',NULL,NULL);
	TTree T12  = Create2('E',T121,NULL);
	TTree T11  = Create2('D',NULL,NULL);
	TTree T1   = Create2('B',T11,T12);
	
	TTree T2121 = Create2('J',NULL,NULL);
	TTree T212  = Create2('I',NULL,T2121);
	TTree T211  = Create2('H',NULL,NULL);
	TTree T21   = Create2('F',T211,T212);
	TTree T2    = Create2('C',NULL,T21);
	
	T     = Create2('A',T1,T2);
	//1b
	PreOrder(T);printf("\n");
	InOrder(T);printf("\n");
	PosOrder(T);printf("\n");
	//1c
	printf("%d\n",nb_nodes(T));
	
	
	//2a
	
	TTree TT;
	MakeNullTree(&TT);
	taocay(&TT);

	//2b
	printf("\nDay da nhap sap xep theo thu tu tang dan la:\n");
	InOrder(TT);printf("\n");
	
	//2c
	unsigned char A;
	fflush(stdin);
	printf("\nNhap ki tu can tim: "); scanf("%c",&A);
	if(Search(A,TT)==NULL) printf("\nKhong tim thay %c tren cay tim kiem NP\n",A);
	else printf("\nTim thay %c tren cay tim kiem NP\n",A);
	
	//2d
	unsigned char B;
	fflush(stdin);
	printf("\nNhap ki tu can xoa: "); scanf("%c",&B);
	DeleteNode(B,&TT);
	printf("\nCay ti kiem sau khi xoa la:\n");
	InOrder(TT);printf("\n");

	
	getch();
	return 0;
}



//cai dat CT con
//bai1
//tao cay rong
void MakeNullTree(TTree *T){
(*T)=NULL;
}
//tao cay moi
TTree Create2(TData v,TTree l,TTree r){
TTree N;
N=(TNode*)malloc(sizeof(TNode));
N->Data=v; N->left=l; N->right=r;
return N;
}
//KT rong
int EmptyTree(TTree T){
return (T==NULL);
}
//xac dinh con trai nut
TTree LeftChild(TTree n){
if (n!=NULL) return n->left;
else return NULL;
}
//xac dinh con phai nut
TTree RightChild(TTree n){
if (n!=NULL) return n->right;
else return NULL;
}
//duyet tien tu
void PreOrder(TTree T){
printf("%c ",T->Data);
if (LeftChild(T)!=NULL) PreOrder(LeftChild(T));
if (RightChild(T)!=NULL)PreOrder(RightChild(T));
}
//duyet trung tu
void InOrder(TTree T){
if (LeftChild(T)!=NULL)InOrder(LeftChild(T));
printf("%c ",T->Data);
if (RightChild(T)!=NULL) InOrder(RightChild(T));
}
//duyet hau tu
void PosOrder(TTree T){
if (LeftChild(T)!=NULL) PosOrder(LeftChild(T));
if (RightChild(T)!=NULL)PosOrder(RightChild(T));
printf("%c ",T->Data);
}
//xac dinh do nut cua cay
int nb_nodes(TTree T){
if(EmptyTree(T)) return 0;
else
return (1+nb_nodes(LeftChild(T))+
nb_nodes(RightChild(T)));
}
//bai2
//tim kiem nut
TTree Search(TData x,TTree Root){
if (Root == NULL)
return NULL; //kh�ng t�m th?y kho� x
else
if (Root->Data == x) // t�m th?y kho� x
return Root;
else
if (Root->Data < x) //t�m tr�n c�y ph?i
return Search(x,Root->right);
else // t�m ti?p tr�n c�y b�n tr�i
return Search(x,Root->left);
}
//them nut
void InsertNode(TData x,TTree *Root ){
if (*Root == NULL){ // th�m n�t m?i
(*Root)=(TNode*)malloc(sizeof(TNode));
(*Root)->Data = x;
(*Root)->left = NULL;
(*Root)->right = NULL; }
else if (x < (*Root)->Data)
InsertNode(x,&(*Root)->left);
else if (x>(*Root)->Data)
InsertNode(x, &(*Root)->right);
else printf("Nut da co tren cay khong xen");
}
//xoa mot nut 
//
TData DeleteMin (TTree *Root ){
TData k;
if ((*Root)->left == NULL){
k=(*Root)->Data;
(*Root) = (*Root)->right;
return k;
}
else
return DeleteMin(&(*Root)->left);
}
//
void DeleteNode(TData x,TTree *Root){
if ((*Root)!=NULL)
if (x < (*Root)->Data) DeleteNode(x,&(*Root)->left);
else if (x > (*Root)->Data)
DeleteNode(x,&(*Root)->right);
else
if (((*Root)->left==NULL) &&((*Root)->right==NULL))
(*Root)=NULL;
else
if ((*Root)->left == NULL)
(*Root) = (*Root)->right;
else
if ((*Root)->right==NULL)
(*Root) = (*Root)->left;
else
(*Root)->Data =DeleteMin(&(*Root)->right);
}

TTree taocay(TTree *Root){
	char X[20];
	int khac=0;
	while (khac==0){
		printf("\nNhap chuoi n ki tu khong trung: "); 
		gets(X);
		int n=strlen(X);
		int bang=0;
		for(int i=0; i<n-1; i++){
			for(int j=i+1; j<n; j++){
				if(X[i]==X[j]) bang=1;
			}	
		}
		if(bang == 0)	khac=1;
	}
	int n=strlen(X);
	for(int i=0; i<n; i++){
		InsertNode(X[i],&(*Root));
	}
}





