#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    FILE * filep;
    filep = fopen("list.txt", "r");
    int *point;
    point = (int*) malloc(100000 * sizeof(int));
    int size = 1;



  while(!feof(filep))
  {
    fscanf(filep,"%d",&point[size]);
    size++;
  }

int x;

printf("Give the number you are looking for \n");
scanf("%d", &x);

int left = 1;
int right = size;
int area = right - left +1;

int next =(int)( area*(x - point[left])/(point[right] - point[left]) +1);
printf("%d",next);
if(next> right)
    next= right;

if(next < left)
    next=left;


while(x != point[next]){

    int i=0;
    area = right - left +1;

    if(area <= 3){

        i=left;

        while(x != point[i] && i< right){
                if(point[i] == x) {
                return i;
                }
            i++;
        }

    }


    else if(x >= point[next]){
        while(x > point[next + i* (int)sqrt(area) -1]){
            if((next + i* (int)sqrt(area) -1)> right)
                next = right;
                i++;
        }

        right= next + i* (int)sqrt(area) ;
        left = next + (i-1)* (int)sqrt(area) ;

    }

    else if(x < point[next]){
        while(x < point[next - i* (int)sqrt(area) +1]){
              if((next - i* (int)sqrt(area) +1)< left)
                next = left;
            i++;
        }

        right = next - (i-1)* (int)sqrt(area) ;
        left = next - i* (int)sqrt(area);

    }

    next=(int)(left +  (right - left +1)*(x - point[left])/(point[right] - point[left]) -1);
}

if(x == point[next]){
    printf("Place of element %d" , next);
}

else{
    printf("Element not found");
}
    return 0;
}
