#include <stdio.h>
#include <stdlib.h>
#define nnn 11 
int find(int a[], int b)
{
	for(int i=0;i<nnn;i++)
	{
		if(a[i]==b) return i;
	}
	return -1;
}
int right(int a[], int b)
{
	int i=find(a,b);
	if (i==nnn-1) return a[0];
	else return a[i+1];
}
int left (int a[], int b)
{
	if (b==nnn) b=1;
	else b=b+1;
	int i=find(a,b);
	if (i==0) i=nnn-1;
	else i=i-1;
	int c=a[i];
	if (c==1) return nnn;
	else return c-1;
}
int move (int a[], int b, bool k)
{
	if (k) return right(a,b);
	else return left (a,b);
}
int distance (int b[], int x)
{
	int i;
	for(i=0;i<2*nnn;i++)
	{
		if(b[i]==x) break;
	}
	for(int j=i+1;j<2*nnn;j++)
	{
		if(b[j]==x) return j-i;
	}
}
int count (int b[],int x)
{
	int j=0;
	for(int i=0;i<2*nnn;i++)
	{
		if(b[i]==x) j++;
	}
	return j;
}
bool check (int b[])
{
	for(int x=1;x<nnn+1;x++)
	{
		if(count(b,x)!=2) return false;
	}
	return true;
}
int *generate (int a[])
{
	bool k=true;
	int x=1;
	static int b[nnn*2];
	for (int i=0;i<nnn*2;i++)
	{
		b[i]=x;
		printf ("%d ",x);
		x=move(a,x,k);
		k=!k;
	}
	return b;
}
int *genegreen (int a[], int *b)
{
	int x;
	static int c[nnn*2];
	for (int i=0;i<nnn*2;i++)
	{
		if(i%2==0) c[i]=find(a,b[i])+1;
		else
		{
			if(b[i]==nnn) x=1;
			else x=b[i]+1;
			x=find(a,x);
			if(x==0) c[i]=nnn;
			else c[i]=x;
		}
		printf ("%d ",c[i]);
	}
	return c;
}
int main()
{
	int a[nnn]={1,10,11,3,2,7,9,4,5,8,6};
	int d;
	int *b,*c;
	printf ("The circle of red is ");
	b=generate(a);
	printf ("\n");
	printf ("The circle of green is ");
	c=genegreen(a,b);
	printf ("\n");
	if(check(b)) printf("This is a minimal filling pair\n");
	else printf("This is not a minimal filling pair\n");
	printf("For red\n");
	for (int i=1;i<nnn+1;i++)
	{
		d=distance(b,i);
		if (d>nnn) d=2*nnn-d;
		printf ("The distance of %d is %d\n",i,d);
	}
	printf("For green\n");
	for (int i=1;i<nnn+1;i++)
	{
		d=distance(c,i);
		if (d>nnn) d=2*nnn-d;
		printf ("The distance of %d is %d\n",i,d);
	}
}
