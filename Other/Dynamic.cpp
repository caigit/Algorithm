// Dynamic.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<time.h>
#include<stdlib.h>
#include<iostream>
int   qpart(int *a,int length); 
int *search(int *a,int length,int v);
int   qsort(int *a,int length);

#define N 6


long n[N+1];
long M[N][N+1];


long computeM(int i,int j);
int  initM();
int  getM();
void prints();


int _tmain(int argc, _TCHAR* argv[])
{
	/*
	initM();
	getM();
	
		int i,j;
	for(i=0;i<N;i+=1){
		for(j=0;j<=N;j+=1)
		{
			printf("%d	",M[i][j]);
		}
	printf("\n");
	}
	*/

	#define NN 12
	int a[NN]={3,1,7,4,5,9,9,9,45,23,11,12};
	//int *p=search(a,N,2);

	
//	if(!p)
//	{
//		std::cout<<"not find it\n";	
//	}else
//	{
//		std::cout<<p-a<<std::endl;	
//	}
	
	//int qpart( int *a, int length,int v)
	 
	//std::cout<<qpart(a,NN)<<std::endl; 

	qsort(a,NN); 
	
	for(int i=0;i<NN;i+=1)
	std::cout<<a[i]<<" ";
	
	#undef NN
	return 0;
}
int qsort(int *a,int length)
{
	if(!a||length<=1)
	{
		return -1;
	}
	
	int i=qpart(a,length);
	
	qsort(a,i+1);
	qsort(a+i+1,length-i-1);
	
}
int qpart( int *a, int length)
{
	//return a index for partition;

	if(!a||length<1)
	{
		return -1;
	}

	int i=0;
	int j=length-2;
	int *p=a+length-1;
	int t;
	
	while(1)
	{
		while(i<j&&a[i]<=*p)
		{
			i+=1;
		}
		while(j>i&&a[j]>*p)
		{
			j-=1;
		}
		
		if(i==j)
		{
			if(a[i]>*p)
			{
			t=a[i];a[i]=*p	;*p=t;
			}

			return i;
		}
		else
		{
			t=a[i];a[i]=a[j];a[j]=t;
		}
	}
	
	return 0;
}

int *search(int *a,int length,int v)
{

	
	if(!a||length<1)
	{
		return 0;		
	}
	
	int i=0;
	int j=length-1;
	int m;
	
	while(i<=j)
	{
		m=(i+j)/2;
		if(v==a[m])	return a+m;
		if(v> a[m])	i=m+1;
		if(v< a[m]) j=m-1;	
	}
		return 0;	
	
	system("pause");
	return 0;
}
















int initM()
{
	int i,j;
	srand((int)time(0));

	for(j=0;j<=N;j+=1)	
	{
		n[j]=rand()%10+5;
	}

	for(i=0;i<N;i+=1)
		for(j=0;j<=N;j+=1)
		{
			M[i][j]=0;
		}
	
	n[0]=30;
	n[1]=35;
	n[2]=15;
	n[3]=5;
	n[4]=10;
	n[5]=20;
	n[6]=25;

	printf("\n");
	return 0;
}


int getM()
{

	int i;
	int j;
	for(i=1;i<N;i+=1)
		for(j=0;j<N-i;j+=1)
		{
			M[i][j]=computeM(i,j);
		}
	return 0;
}

long computeM(int i,int j)
{

	// the chain start:j end:j+i+1	length:i+1
	int k;
	for(k=0;k<=i-1;k+=1)
	{
		M[N-1][N-k]=M[k][j] + M[i-k-1][j+k+1] + n[j]*n[j+i+1]*n[j+k+1];
	}
	

	long x=M[N-1][N];
	for(k=0;k<i;k+=1)
	{
		if(x>M[N-1][N-k])
		   x=M[N-1][N-k];
	}

	return x;

}






