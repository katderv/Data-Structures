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

int  first, last, middle, search;

   printf("Enter value to find\n");
   scanf("%d",&search);

   clock_t start,end;
  double cpu_time_used;

  start = clock();

   first = 0;
   last = size ;
   middle = (first+last)/2;
   int counter=0;

   while( first <= last )
   {
       counter++;
      if ( point[middle] < search )
         first = middle + 1;
      else if ( point[middle] == search )
      {
         printf("%d found at location %d.\n", search, middle+1);
         break;
      }
      else
         last = middle - 1;

      middle = (first + last)/2;
   }
   if ( first > last )
      printf("Not found! %d is not present in the list.\n", search);

end = clock();
  cpu_time_used = ((double)(end-start))/ CLOCKS_PER_SEC;

printf("it took %f seconds to execute and looped %d times\n",cpu_time_used, counter);

   return 0;
}

