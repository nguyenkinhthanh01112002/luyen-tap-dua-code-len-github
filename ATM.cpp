#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//pass word
void Changepass(char Pass[],int *Check)
{
	char X[100];
	*Check = 0;
	getchar();
	do
	{
		*Check = *Check+1;
		if(*Check<=3)
		{
		printf("\nmoi ban nhap mat khau cu cua ban\n");
		gets(X);
		}
	}
	while(strcmp(X,Pass)!=0&&*Check<=3);
	if(*Check>3)
	{
		printf("\nTai khoan cua ban tam thoi bi khoa");
		return ;
	}
	printf("\nmoi ban nhap mat khau moi cua ban\n");
	gets(Pass);
	printf("\nChuc mung ban doi mat khau thanh cong");
}
void Nop(long long *Sum)
{
	long long Nap = 0;
	printf("\nVui long nhap so tien ban muon nop\n");
	scanf("%lld",&Nap);
	*Sum = *Sum+Nap;
	printf("\nChuc mung ban da nop %lld dong vao tai khoan",Nap);
	printf("\nSo tien hien co cua ban la %lld dong",*Sum);
}
void Laisuat(long long *Sum,long long *Interest,float *r,int *m)
{
	//lai suat ngan hang hang thang
	long long x;//so tien muon gui ngan hang
	printf("\nvui long nhap so tien ban muon gui vao ngan hang\n");
	scanf("%lld",&x);
	
	if(*Sum>0)
	{
		
		*Interest = x*(pow(1+(*r),(double)*m));
		*Sum = *Sum-x;
		printf("\nSo tien trong TKTK cua quy khach la %lld",*Interest);
	}
	else
	{
		printf("\nso tien trong tai khoan cua quy khach khong du de thuc hien dich vu nay");
	}
}
void ChKhoan(long long *Sum)
{
	lenh2:
	long long t;
	printf("\nnhap vao so tien ban muon chuyen khoan\n");
	scanf("%lld",&t);
	if(*Sum>=t)
	{
		*Sum = *Sum-t;
		printf("\nChuc mung ban da chuyen khoan thanh cong so tien %lld\n",t);
	}
	else
	{
		printf("\nSo tien trong tai khoan cua quy khach khong du de thuc hien giao dich nay");
		return;
	}

	
}
int main()
{

	long long Sum = 50000000;
	long long Interest = 0;//so tien lai+goc
	int count;//kiem tra so lan doi mat khau sai
	float r = 0.08/12;//lai suat ngan hang hang thang
	int m;//so thang gui tien ngan hang
	char Pass[] = {'1','2','3','4'};//mat khau dang nhap
	char N[4];//nhap mat khau dang nhap
	int Check = 0;//neu Check = 3 nhap qua so lan quy dinh thoat khoi man hinh
	do
	{
		Check++;
		if(Check<=3)
		gets(N);
	}
	while(strcmp(N,Pass)!=0&&Check<=3);
	if(Check>3)
	{
		printf("\nTai khoan cua quy khach tam thoi bi khoa do quy khach nop sai qua lan quy dinh");
		return 0;
	}
	while(1)
	{
		
		printf("\n.....................Chao mung quy khach da den voi NT bank......................");
		printf("\n1.Van tin tai khoan");
		printf("\n2.Thay doi mat khau");
		printf("\n3.So tien tai khoan ban da nhan duoc la");
		printf("\n4.Dich vu tiet kiem ca nhan");
		printf("\n5.Dich vu chuyen khoan");
		char n;
		printf("\n.....................Vui long chon dich vu ban muon su dung.....................\n");
		scanf("%c",&n);
		switch(n)
		{
			case '1':
				printf("\nSo tien hien co cua ban la:%lld dong",Sum);
				lenh3:
				printf("\nVui long bam phim 1 de tiep tuc thuc hien giao dich\n");
				int a;
				scanf("%d",&a);
				if(a==1)
				{
					break;
				}
				else
				{
					goto lenh3;
				}
				
			case '2':
				Changepass(Pass,&Check);
				if(Check>3)
				{
					return 0;
				}
				break;
			
			case '3':
				{
					lenh1:
					Nop(&Sum);
					printf("\nneu ban muon tiep tuc thuc hien chuong trinh vui long bam phim 1 nguoc lai bam phim 0\n");
					int a;
					scanf("%d",&a);
					if(a==1)
					{
						goto lenh1;
					}
					else
					{
						break;
					}
					break;
				}
			case '4':
				{
					lenh:
					printf("\nlua chon so thang ma khach hang muon gui lai\n");
					scanf("%d",&m);
					printf("\nlai suat hien tai cua ngan hang la %f",r);
					Laisuat(&Sum,&Interest,&r,&m);
					int a;
					printf("\nneu quy khach muon tiep tuc thuc hien dich vu vui long bam phim 1 nguoc lai bam phim 0\n");
					scanf("%d",&a);
					if(a==1)
					{
						goto lenh;
					}
					else
					{
						break;
					}
				}
			case '5':
				{
					lenh2:
					ChKhoan(&Sum);
					printf("\nneu ban muon tiep tuc thuc hien dao dich vao long bam phim 1 nguoc lai bam phim 0\n");
					int a;
					scanf("%d",&a);
					if(a==1)
					{
						goto lenh2;
					}	
					else
					{
						break;
					}
				}
			default:
			return 0;
	}
	}
}
	
	

