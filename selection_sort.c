#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int *list, int n);

int main(){

        FILE * filep;
    filep = fopen("integers.txt", "r");
    int *point;
    point = (int*) malloc(100000 * sizeof(int));
    int size = 0;

    int c;

        clock_t start_t, end_t;
        double total_t;

	while(!feof(filep)){
    	fscanf(filep, "%d" , &point[size]);
		size++;
  }

	start_t = clock();
	printf("Starting of the program, start_t = %ld\n", start_t);

	selection_sort(point, size);

	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

	printf("Selection sorted list:");
	for(c=0; c<size; c++)
		printf("%d\n", point[c]);

	printf("Total time taken by CPU: %f\n", total_t  );

	fclose(filep);
	free(point);

  return 0;



}

// selection sort stuff
void selection_sort(int *list, int n){
    int i,j,swap,position;

    for ( i = 0 ; i < ( n - 1 ) ; i++ ){

        position = i;

        for ( j = i + 1 ; j < n ; j++ ){
            if ( list[position] > list[j] )
                position = j;
        }
        if ( position != i ){
            swap = list[i];
            list[i] = list[position];
            list[position] = swap;
        }
    }
}
