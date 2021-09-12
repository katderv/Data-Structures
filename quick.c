#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <time.h>

void quick_sort(int list[],int first,int last);

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

	quick_sort(point,0,(size-1));

	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

    printf("quick sorted list: \n");
    for ( int c = 0 ; c < size ; c++ )
		printf("%d\n", point[c]);

	printf("Total time taken by CPU: %f seconds.\n", total_t  );

	fclose(filep);
	free(point);

  return 0;
}

//-----------------------------------------------

void quick_sort(int list[],int first,int last)
{
    int pivot,j,temp,i;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while(list[i]<=list[pivot]&&i<last)
                i++;
            while(list[j]>list[pivot])
                j--;
            if(i<j)
            {
                temp=list[i];
                list[i]=list[j];
                list[j]=temp;
            }
        }

        temp=list[pivot];
        list[pivot]=list[j];
        list[j]=temp;
        quick_sort(list,first,j-1);
        quick_sort(list,j+1,last);

    }
}


