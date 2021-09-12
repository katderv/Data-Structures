#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

	int i,k,temp;

	 start_t = clock();
    printf("Starting of the program, start_t = %ld\n", start_t);

    for (i = 1 ; i <= 100000 - 1; i++){
        k = i;
        while ( k > 0 && point[k] < point[k -1]){


            temp = point[k];
            point[k] = point[k-1];
            point[k-1]= temp;
            k--;
        }
	}

	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;

	for(int m =0; m<=size-1; m++){
	printf("%d\n", point[m]);
	}

	printf("Total time taken by CPU: %f\n", total_t  );

	fclose(filep);
	free(point);

  return 0;


}
