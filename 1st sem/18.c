/*
print
2
4 6
12 14 16
32 34 36 38
*/
#include<stdio.h>
int main()
{
	int n,i,j,a=2;
	printf("Enter a size:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d",a);
			printf(" ");
	        if(i!=j)
	        {
	        	a=a+2;
		    }
	    }
	    a=a*2;
		printf("\n");
	}
	return 0;
}