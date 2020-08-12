#include <stdio.h>
#include <stdlib.h>
#define nnn 9
FILE *f=fopen("n9.txt","w");
int a[nnn];
int *b;
int cnt=0;
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
		if(distance(b,x)%2==0) return false;
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
		x=move(a,x,k);
		k=!k;
	}
	return b;
}
bool avilable(int i,int k)
{
	for (int j=0;j<i;j++)
	{
		if(k==a[j]) return false;
	}
	return true;
}
void printorder(void)
{
	int i;  
    for(i = 0; i < nnn; i++)	fprintf(f,"%d,",a[i]);  
  
}
void perm (int i)
{
	int k;
	if (i==nnn)
	{
		b=generate(a);
		if(check(b))
		{
			printorder();
			k=0;
			for (int x=1;x<nnn+1;x++)
			{
				if (distance(b,x)==nnn) k++;
			}
			fprintf(f,"This is a minimal filling pair with %d opposite sides\n", k);
			cnt++;
		}
		// else fprintf(f,"This is not a minimal filling pair\n");
	}
	else
	{
		for (int j=1;j<nnn+1;j++)
		{
			if(avilable(i,j))
			{
				a[i]=j;
				perm (i+1);
			}
		}
	}
}
int main()
{
	a[0]=1;
	perm(1);
	fprintf(f,"There are %d ordered pair of coherent minimal intersecting pairs",cnt/(2*nnn));
	return 0;	
}
