#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <time.h>

void create(int []);
void down_adjust(int [],int);

int main()
{
	int i,last,temp;
	int j=0;


	FILE * filep;
    filep = fopen("integers.txt", "r");
    int *heapy;
    heapy = (int*) malloc(100000 * sizeof(int));
	clock_t start_t, end_t;
	double total_t;

  while(!feof(filep)){
    fscanf(filep, "%d" , &heapy[j]);
	j++;
  }

	//create a heap
	start_t = clock();
	heapy[0]=j;
	create(heapy);

	//sorting
	while(heapy[0] > 1)
	{
		//swap heap[1] and heap[last]
		last=heapy[0];
		temp=heapy[1];
		heapy[1]=heapy[last];
		heapy[last]=temp;
		heapy[0]--;
		down_adjust(heapy,1);
	}

	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

	//print sorted data
	printf("\nArray after sorting:\n");
	for(i=1;i<j;i++)
		printf("%d\n ",heapy[i]);

	printf("Total time taken by CPU: %f seconds.\n", total_t  ); //<----

  	fclose(filep);
	free(heapy);


}

void create(int heapy[])
{
	int i,j;
	j=heapy[0]; //no. of elements
	for(i=j/2;i>=1;i--)
		down_adjust(heapy,i);
}

void down_adjust(int heapy[],int i)
{
	int j,temp,n,flag=1;
	n=heapy[0];

	while(2*i<=n && flag==1)
	{
		j=2*i;	//j points to left child
		if(j+1<=n && heapy[j+1] > heapy[j])
			j=j+1;
		if(heapy[i] > heapy[j])
			flag=0;
		else
		{
			temp=heapy[i];
			heapy[i]=heapy[j];
			heapy[j]=temp;
			i=j;
		}
	}
}
