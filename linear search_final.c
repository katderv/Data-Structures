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


 int  search,c;
 int counter=0;
   printf("Enter the number to search\n");
   scanf("%d", &search);

clock_t start,end;
  double cpu_time_used;

  start = clock();

   for (c = 0; c < size; c++)
   {  counter++;
      if (point[c] == search)     /* if required element found */
      {
         printf("%d is present at location %d.\n", search, c+1);
         break;
      }
   }
   if (c == size)
      printf("%d is not present in array.\n", search);

end = clock();
  cpu_time_used = ((double)(end-start))/ CLOCKS_PER_SEC;
printf("Counter: %d\n", counter);
printf("it took %f seconds to execute\n",cpu_time_used);

   return 0;
}
