
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
}
