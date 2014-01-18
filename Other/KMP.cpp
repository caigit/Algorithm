#include <iostream>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int prestr(char *,int *,int ); 
int KMPmatch(char *,char *);

int main(int argc, char *argv[]) {
	

	char	s[128]="bc";
	char	p[32]="bcd";
		
	std::cout<<"S: "<<s<<"\n"<<"P: "<<p<<endl;
	
	//std::cout<<"Input target  string : ";
	//std::cin >>s;
	//std::cout<<"Input pattern string : ";
	//std::cin >>p;
	
	std::cout<<"match times: "<<KMPmatch(p,s)<<std::endl;
	
	return 0;
}

int prestr(char *p,int *pre,int length)
{
	if(!p)
		return -1;
		
	if(!pre)
		return -2;

	*pre=0;
	if(length==1)
		return -3;
	
	int current;
	int front;
	
	for(front=0,current=1;current<length;current+=1)
	{
		if(*(p+front)==*(p+current))
		{
			*(pre+current)=*(pre+current-1)+1;
			front+=1;
		}
		else
		{
			*(pre+current)=0;
			front=0;	
		}
	}
	
	return 0;
} 

int KMPmatch(char *p,char *s)
{
	
	if(!p||!s)
		return -1;
		
	int si=0;				//string  index
	int ml=0;				//matched length
	int pl=strlen(p);		//pattren length
	int *pre=new int[pl];	//contain prefix num
	int count=0;
	
	prestr(p,pre,pl);
	
	while(si<strlen(s))
	{
		if(p[ml]!=s[si])
		{
			if(ml==0)
			{
				si+=1;
			}else
			{
				ml=pre[ml-1];
			}			
		}
		else
		{
			si+=1;
			ml+=1;
			if(ml==pl)
			{
				count+=1;
				ml=0;
				std::cout<<"match index: "<<si-pl<<std::endl;
			}
		}
	}
	delete pre;
	return count;
}
