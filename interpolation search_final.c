#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main()
{
   FILE * filep;
    filep = fopen("list.txt", "r");
    int *point;
    point = (int*) malloc(100000 * sizeof(int));
    int size = 0;



  while(!feof(filep))
  {
    fscanf(filep,"%d",&point[size]);
    size++;
  }





 int item;


 printf("Search For : ");
 scanf("%d", &item);

clock_t start,end;
  double cpu_time_used;

  start = clock();

int bottom=0;
int top=size-1;
int mid;
int counter=0;


while (bottom <= top) {
    counter++;
  mid = bottom + (top - bottom)* ((item - point[bottom]) / (point[top] - point[bottom]));
  if (item == point[mid])
     break;
  if (item < point[mid])
   top = mid - 1;
  else
   bottom = mid + 1;
}


end = clock();
  cpu_time_used = ((double)(end-start))/ CLOCKS_PER_SEC;

   printf("\nElement %d found at position %d\n", item, mid + 1);
printf("it took %f seconds to execute and looped %d times\n",cpu_time_used, counter);


 return 0;
}
