#include<iostream>
using namespace std;


void swap(int *value_1,int *value_2)
{
int temp=*value_1;
*value_1=*value_2;
*value_2=temp;
}

int checkCondision(int ary[],int fst,int last,int i,int j)
{
	if (fst==last)
		return j;
	else
	{
		if(ary[fst]<=i)
		{
			j++;
			swap(&ary[j],&ary[fst]);
		}
	}
	return checkCondision(ary,fst+1,last,i,j);
}
	
	
int arrayCheck(int array[], int first, int last)
{
	int i = array[last];
	int j = (first - 1);
	
	j=checkCondision(array,first,last,i,j);
	swap (&array[j + 1], &array[last]);
	return (j + 1);
}

void quickSort(int Ary[], int i, int j)
{
	if (i < j)
	{
		int integr = arrayCheck(Ary,i,j); 
		quickSort(Ary, i, integr - 1); 
		quickSort(Ary, integr + 1,j);
	}
}


int main()
{
	int ary[10];
	for (int i=0; i<10; i++)
	{
		cout<<"Enter "<<i+1<<" number :";
		cin>>ary[i];
	}
	quickSort(ary,0,9);
	for (int i=0; i<10; i++)
	{
		cout<<ary[i]<<" ";
	}
}
