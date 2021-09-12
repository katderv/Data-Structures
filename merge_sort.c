#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <time.h>

void merge(int [],int ,int ,int, int);
void part(int [],int ,int, int );


int main(){

	FILE * filep;
    filep = fopen("integers.txt", "r");
    int *point;
    point = (int*) malloc(100000 * sizeof(int));
    int size = 0;

	clock_t start_t, end_t;
	double total_t;

	while(!feof(filep)){
    	fscanf(filep, "%d" , &point[size]);
		size++;
	}

	start_t = clock();
	printf("Starting of the program, start_t = %ld\n", start_t);

	part(point,0,(size-1), size);

	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

	printf("\n\t------- Merge sorted elements -------\n\n");
	for(int i=0; i<size; i++)
 		printf("%d \n ",point[i]);

	printf("Total time taken by CPU: %f seconds.\n", total_t  );


 return 0;

}

//--------------------------------------------------

void part(int arr[],int min,int max, int size)
{
 int mid;
 if(min<max)
 {
   mid=(min+max)/2;
   part(arr,min,mid, size);
   part(arr,mid+1,max, size);
   merge(arr,min,mid,max, size);
 }
}


void merge(int arr[],int min,int mid,int max, int size)
{
  int tmp[size];
  int i,j,k,m;
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(arr[j]<=arr[m])
     {
         tmp[i]=arr[j];
         j++;
     }
     else
     {
         tmp[i]=arr[m];
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         tmp[i]=arr[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        tmp[i]=arr[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
     arr[k]=tmp[k];
}

//--------------------------------------------------



