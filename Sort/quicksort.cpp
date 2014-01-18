//OK
#include <iostream>

int   qpart(int *a,int length); 
int *search(int *a,int length,int v);
int   qsort(int *a,int length);

int main(int argc, char *argv[]) {
	
	
	#define N 4
	int a[N]={7,1,3,4};
	 
	std::cout<<qpart(a,N)<<std::endl; 

	qsort(a,N); 
	
	for(int i=0;i<N;i+=1)
	std::cout<<a[i]<<" ";
	
	#undef N
	return 0;
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
			return i+1;
		}
		else
		{
			t=a[i];a[i]=a[j];a[j]=t;
		}
		
	}
	
	return 0;
}


int qsort(int *a,int length)
{
	if(!a||length<=1)
	{
		return -1;
	}
	
	int i=qpart(a,length);
	
	qsort(a,i);
	qsort(a+i,length-i);
	
}
