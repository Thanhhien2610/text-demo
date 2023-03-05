#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <ctype.h>

using namespace std;

struct SinhVien{
	char maSv[9];
	char hoTen[32];
	char gioiTinh[5];
	float diemToan, diemVan, diemAnh;
	float diemTrungBinh;
};
struct NODE {
	SinhVien data;
	NODE *link;
};
struct LIST {
	NODE *fisrt;
	NODE *last;
};
void Init(LIST &l){
	l.fisrt = l.last = NULL;
}

NODE *getNode(SinhVien x){
	NODE *p = new NODE;
	if(p==NULL){
		printf("khong du bo nho");
		exit(0);
	}
	p -> data = x;
	p -> link = NULL;
	return p;
}

void addLast(LIST &l, NODE *p){
	if(l.fisrt == NULL){
		l.fisrt = l.last = p;
	}else{
		l.last -> link = p;
		l.last = p; 
		printf("them sinh vien thanh cong");
	}
}
void inputSinhvien(LIST &l, int n){
	printf("nhap so luong sinh vien : ");
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		SinhVien x;
		printf("nhap Sinh Vien thu %d \n",i+1);
		
		printf("nhap MA SINH VIEN : ");
		fflush(stdin);
		gets(x.maSv);
		
		printf("nhap HO TEN : ");
		fflush(stdin);
		gets(x.hoTen);
		
		printf("nhap gioi tinh : ");
		fflush(stdin);
		gets(x.gioiTinh);
		
		do{
			printf("nhap diem Toan: ");
			scanf("%f",&x.diemToan);	
		}while(x.diemToan>10 || x.diemToan <0);

		do{
			printf("nhap diem Van: ");
			scanf("%f",&x.diemVan);
		}while(x.diemToan>10 || x.diemToan <0);
		
		do{
			printf("nhap diem Anh: ");
			scanf("%f",&x.diemAnh);
		}while(x.diemToan>10 || x.diemToan <0);
		
		NODE * p = getNode(x);
		addLast(l,p);
	}
	printf("\n\n");
}

void output(LIST l){
	printf("\n---------------------------------------------------------------------------------------------\n");
	printf(" MSV \t HO TEN \t GIOI TINH \t Diem Toan \t Diem Van \t Diem Anh \t DTB ");
	printf("\n---------------------------------------------------------------------------------------------\n");
	for(NODE*k=l.fisrt; k!=NULL; k = k->link){
		k->data.diemTrungBinh = (k ->data.diemToan+ k->data.diemVan+ k->data.diemAnh)/3;
		printf("%s \t %s \t %s \t\t %.2f \t %.2f \t \%.2f \t %.2f \n",
		k->data.maSv, k-> data.hoTen,k->data.gioiTinh, k->data.diemToan, k->data.diemVan, k->data.diemAnh, k->data.diemTrungBinh);
	}
	printf("\n\n");
}

void suaSv(LIST l){
	char st[9];
	printf("nhap Ma Sinh Vien can xoa : ");
	fflush(stdin);
	gets(st);
	int selectDel;
	for(NODE *k = l.fisrt; k!=NULL;k=k->link){
		if(strcmp(k->data.maSv, st)==0 ){
			do{
				printf("\t\t\t*========================*\n");
				printf("\t\t\t|       MENU SUA         |\n");
				printf("\t\t\t|  1. Sua ho ten         |\n");
				printf("\t\t\t|  2. Sua gioi tinh      |\n");
				printf("\t\t\t|  3. Sua diem toan      |\n");
				printf("\t\t\t|  4. Sua diem van       |\n");
				printf("\t\t\t|  5. Sua diem anh       |\n");
				printf("\t\t\t|  nhap -1 de thoat sua  |\n");
				printf("\t\t\t*========================*\n");
				do{
					printf("nhap menu sua : ");
					scanf("%d",&selectDel);
				}while(selectDel>5);
				
				switch(selectDel){
					case 1: 
						printf("nhap ho ten can sua : \n");
						fflush(stdin);
						gets(k->data.hoTen);
						break;
					case 2: 
						printf("nhap gioi tinh can sua : \n");
						fflush(stdin);
						gets(k->data.gioiTinh);
						break;
					case 3: 
						printf("nhap diem Toan can sua: \n");
						scanf("%f",&k->data.diemToan);
						break;
					case 4: 
						printf("nhap diem Van can sua: \n");
						scanf("%f",&k->data.diemVan);
						break;
					case 5: 
						printf("nhap diem Anh can sua: \n");
						scanf("%f",&k->data.diemAnh);
						break;
					default:
						printf("da thoat sua, moi tiep tuc");
						break;
				};
				
			}while(selectDel!=-1);
		}else{
			printf("ma sv khong co trong danh sach!!! \n");
		}
		
	}
	
}
void XoaMotSinhvien(LIST &l){
	char st[9];
	printf("nhap Ma Sinh Vien can xoa : ");
	fflush(stdin);
	gets(st);
	NODE *p = l.fisrt;
	NODE *q = NULL;
	while(p!=NULL){
		if(strcmp(p->data.maSv, st)==0)
			break;
		 q = p;
		 p = p ->link;
	}
	if(p ==NULL){
		printf("xoa khong thanh cong (khong co Ma Sinh Vien trong danh sach)");
	}else if( q == NULL){
		l.fisrt = l.fisrt ->link;
		delete p;
		printf("xoa thanh cong");
	}else{
		NODE *h = p->link;
		q -> link = h;
		p -> link = NULL;
		delete p;
		printf("xoa thanh cong \n");
	}
}
void sapXepDtbTangDan(LIST &l){
	for(NODE *k= l.fisrt; k!=NULL; k = k->link){
		for(NODE *h = k->link; h!=NULL;h =h ->link){
			if( k-> data.diemTrungBinh > h->data.diemTrungBinh){
				SinhVien t;
				t =k ->data;
				k-> data = h->data;
				h->data =t;
			}
		}
	}
}

int main(){
	int n;
	LIST l;
	Init(l);

	int select;
	do{
		printf("\t*=========================================*\n");
		printf("\t|  1. Them Sinh Vien                      |\n");
		printf("\t|  2. Xuat Danh Sach Sinh Vien            |\n");
		printf("\t|  3. Sua SINH VIEN                       |\n");
		printf("\t|  4. Xoa Mot SINH VIEN                   |\n");
		printf("\t|  5. Sap xep DTB                         |\n");
		printf("\t|      Nhap 0 de KET THUC CHUONG TRINH    |\n");
		printf("\t*=========================================*\n");
		do{
			printf("Nhap lua chon menu sua : ");
			scanf("%d",&select);
		}while(select>5);
		
		switch(select){
			case 1:
				inputSinhvien(l,n);
				break;
			case 2: 
				output(l);
				break;
			case 3:
				suaSv(l);
				break;
			case 4:
				XoaMotSinhvien(l);
				break;
			case 5: 
				sapXepDtbTangDan(l);
				break;
			default:
				printf("ket thuc chuong trinh !!!");
		}
		
		
	}while(select!=0);
}





