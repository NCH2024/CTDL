	#include <stdio.h>
	#include <conio.h>
	#include <malloc.h>
	#include <string.h>
	//Khai bao cau truc
	//STACK
	typedef unsigned char ElementType;
	typedef struct Node {
		ElementType Elements;
		Node* Next;
	};
	typedef Node* Position;
	typedef Position Stack;
	Stack S;
	//QUEUE
	typedef struct{
		Position Front, Rear;
	} Queue;
	//Danh sach cac chuong trinh con
	//STACK
		//Ham khoi tao Stack rong
		void MakeNull_Stack (Stack *S);
		//Ham kiem tra rong
		int Empty_Stack(Stack S);
		//Ham them phan tu
		void Push(ElementType X, Stack *S);
		//Ham xoa phan tu
		void Pop (Stack *S);
		//Ham lay phan tu
		ElementType Top(Stack S);
	//QUEUE
		//Khoi tao rong
			void MakeNull_Queue(Queue *Q);
			//Kiem tra rong
			int Empty_Queue(Queue Q);
			//Xoa phan tu 
			void DeQueue(Queue *Q);
			//Them phan tu
			void EnQueue(ElementType X,Queue *Q);
			//lay phan tu dau
			ElementType Front(Queue Q);
	//CTR con
		//Ham doi sang nhi phan
		void DoiNP(unsigned int n);
		//Ham doi sang co so b
		void DoiCoSo(unsigned int n, unsigned int b );
		//kiem tra chuoi
		unsigned int KTChuoiDauNgoac(char ChuoiDauNgoac[]);
		//Kiem tra doi xung
		unsigned int KTDoiXungChuoi(char ChuoiDoiXung[]);
	//Chuong trinh chinh
	int main(){
		unsigned int n,b,KQ, DX;
		char ChuoiDauNgoac[20], ChuoiDoiXung[20];
		Stack S;
		Queue Q;
		
		//a. Doi sang nhi phan
		printf("\n Nhap vao so nguyen n = "); scanf("%d", &n);
		printf("\n Gia tri nhi phan: ");
		DoiNP(n);
		
		//b. Doi co so b
		printf("\n Nhap vao co so b = ");
		scanf("%d", &b);
		printf("\n Gia tri Doi sang co so b: ");
		DoiCoSo(n,b);
		
		//c. Nhap vao mot chuoi dau ngoac don va kiem tra xem chuoi dung hay khong
		 printf("\n Nhap chuoi dau ngoac don can kiem tra quy tac:");
		 fflush(stdin);
		 gets(ChuoiDauNgoac);
		//Kiem tra chuoi dau ngoac co dung quy tac toan hoc khong?
		KQ = KTChuoiDauNgoac(ChuoiDauNgoac);
	    if(KQ==1)
	       printf ("\n Chuoi dung quy tac toan hoc!!!");
	    else
		   printf ("\n Chuoi khong dung quy tac toan hoc!!!");
		   
		//2 Ket hop stack va queue de kiem tra chuoi doi xung
		 printf("\n Nhap chuoi can kiem tra doi xung: "); 
		 fflush(stdin);
		 gets(ChuoiDoiXung);
		 //kiem tra doi xung
		 DX = KTDoiXungChuoi(ChuoiDoiXung);
		 if(DX == 1)
		 	printf("\n Chuoi vua nhap da doi xung!!!");
		 else 
		 	printf("\n Chuoi vua nhap khong doi xung!!!");
		//Ket thuc chuong trinh
		getch();
		return 0;
	}
	//Danh sach cai dat cac chuong trinh con
	//STACK
		//Ham khoi tao Stack rong
		void MakeNull_Stack (Stack *S){
			(*S)=(Node*)malloc(sizeof(Node));
			(*S)->Next= NULL;
		}
		//Ham kiem tra rong
		int Empty_Stack(Stack S){
			return (S->Next == NULL);
		}
		//Ham them phan tu
		void Push(ElementType X, Stack *S){
			Position T;
			T=(Node*)malloc(sizeof(Node));
			T->Elements = X;
			T->Next = (*S)->Next;
			(*S) ->Next= T;
		}
		//Ham xoa phan tu
		void Pop (Stack *S){
			if (!Empty_Stack(*S)){
				Position T = (*S)->Next;
				(*S)->Next = T->Next;
				free(T);
			}
			else printf ("stack rong!!! ");
		}
		//Ham lay phan tu
		ElementType Top(Stack S){
			if (Empty_Stack(S))
				printf("Loi! Ngan xep rong!");
			else
			return (S->Next-> Elements);
		}
	//QUEUE
		//QUEUE
		//Khoi tao rong
			void MakeNull_Queue(Queue *Q){
				Position Header;
				Header = (Node*) malloc(sizeof(Node));
				Header->Next=NULL;
				Q->Front=Header;
				Q->Rear=Header;
			}
			//Kiem tra rong
			int Empty_Queue(Queue Q){
				return (Q.Front == Q.Rear);
			}
			//Xoa phan
			void DeQueue(Queue *Q){
				if (!Empty_Queue(*Q)){
					Position Tempt;
					Tempt=Q->Front->Next;
					Q->Front->Next=Tempt->Next;
					free (Tempt);
				}
				else printf("Loi: Hang rong");
			}
			//Them phan tu
			void EnQueue(ElementType X,Queue *Q){
				Q->Rear->Next=(Node*)malloc(sizeof(Node));
				Q->Rear=Q->Rear->Next;
				Q->Rear->Elements=X;
				Q->Rear->Next=NULL;
			}
			//lay phan tu dau
			ElementType Front(Queue Q){
				if (!Empty_Queue(Q))
					return (Q.Front->Next->Elements);
				else
					printf("Loi: Hang rong");
			}
		//Ham doi sang nhi phan
		void DoiNP(unsigned int n){
			Stack S;
			ElementType SoDu, PTu;
			MakeNull_Stack(&S);
			//doi nhi phan
			while(n > 0){
				SoDu = n%2; //lay du
				Push(SoDu, &S); //luu so du vao stack
				n = n/2; // cap nhat so bi chia
			}
			//in ket qua
			while(!Empty_Stack(S)){
				PTu = Top(S); // lay ptu
				printf("%d ", PTu); // xuat ptu
				Pop(&S); // xoa ptu dau stack
			}
			
		}
		//Ham doi sang co so b
		void DoiCoSo(unsigned int n, unsigned int b ){
			Stack S;
			ElementType Du, X;
			MakeNull_Stack (&S);
			while (n!=0){
				Du=n%b;
				if(Du<10)
					Push(Du, &S);	
				else
					if(Du==10)
						Push('A',&S);
					else
						if(Du==11)
							Push('B',&S);
						else
							if(Du==12)
								Push('C',&S);
							else
								if(Du==13)
									Push('D',&S);
								else
									if(Du==14)
										Push('E',&S);
									else Push('F',&S);
				n=n/b;
			}
			
			while(!Empty_Stack(S)){
				X=Top(S);
				if(X<10)
					printf("%d",X);
				else
					printf("%c",X);
				Pop(&S);	
			}
		}
	unsigned int KTChuoiDauNgoac(char ChuoiDauNgoac[]){
	   Stack S;
	   int l, QT, i;
	   
	   //Khoi tao stack rong
	   MakeNull_Stack(&S);
	   //Lay do dai chuoi
	   l = strlen(ChuoiDauNgoac);	
	   QT = 1;  //Chuoi da ngoac dung Quy tac
	   i = 0;  //Xet tu du chuoi dau ngoac
	   //Xet cho den khi het chuoi dau ngoac va chuoi dau ngoac con dung quy tac toan hoc
	   while((i<l) && (QT==1)){
	   	  //Gap dau '(' dua vao Stack S
	   	  if((ChuoiDauNgoac[i])=='('){
	   	     Push(ChuoiDauNgoac[i],&S);
	   	     i++; //Xet phan tu ke tiep trong chuoi dau ngoac
	       }
	   	  else
	   	      //Gap dau ')' va Stack S chua rong thi xoa phan tu dau Stack S
			  if(((ChuoiDauNgoac[i])==')') && (!Empty_Stack(S))){
			     //Xoa phan tu dau Stack S
				 Pop(&S);  
				 i++;  //Xet phan tu ke tiep trong chuoi dau ngoac
			 }
			  else
			     //Chuoi sai quy tac
				 QT = 0;	 
	   } // while
	   //Neu da xet het chuoi va Stack S rong thi chuoi dung quy tac
	   if((i==l) && (Empty_Stack(S)))
	      return 1;  // Chuoi dung quy tac
	   else  //Chuoi khong dung quy tac
	      return 0;   
	}
	//ham kiem tra doi xung chuoi
		unsigned int KTDoiXungChuoi(char ChuoiDoiXung[]){
			Stack S;
			Queue Q;
		   int l, DX, i=0;
		   //Khoi tao stack rong
		   MakeNull_Stack(&S);
		   //khoi tao Queue rong
		   MakeNull_Queue(&Q);
		   //Lay do dai chuoi
		   l = strlen(ChuoiDoiXung);	
		   DX = 1;  //Chuoi doi xung
		   for(int i = 0; i < l; i++){
		   	Push(ChuoiDoiXung[i], &S);
		   	EnQueue(ChuoiDoiXung[i], &Q);
		   }
		   while((i<l)&& (DX == 1) && (!Empty_Stack(S))&& (!Empty_Queue(Q))){
		   	if((Top(S)) == Front(Q)){
		   		Pop(&S);
		   		DeQueue(&Q);
		   		i++;
			   }
			else 
				DX = 0;
		   }
		   if((i==l) && (Empty_Stack(S)) &&(Empty_Queue(Q)-1))
	      		return 1; 
	  		else  
	      		return 0;   

		}
