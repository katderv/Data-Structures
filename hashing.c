#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct students{
    char AM[9];
    char name[13];
    char surname[17];
    float grade;

};

typedef struct students students;

struct node {
    students data;
struct    node *next;
};
typedef struct node node;


struct hash {
    node *head;
    int count;
};

struct hash *hashTable = NULL;
int eleCount = 11;

node *createNode(students num) {
    node *newnode;

    newnode = (node *) malloc(sizeof(node));
    newnode->data=num;
    newnode->next = NULL;
return newnode;
}

int add(char *str){
	int sum=0;
	int i, len;

	len = strlen(str);

	for (i=0; i<len; i++){
	printf("Ascii value of %c: %d \n" , str[i], str[i]);
		sum = sum + str[i];
	}

	printf("\nSum of all ascii values: %d\n", sum);

	return sum;

}


void insertToHash(students num) {
int hashIndex = add(num.AM) % eleCount;
node *newnode = createNode(num);
/* head of list for the bucket with index "hashIndex" */
if (!hashTable[hashIndex].head) {
hashTable[hashIndex].head = newnode;
hashTable[hashIndex].count = 1;
return;
}
/* adding new node to the list */
newnode->next = (hashTable[hashIndex].head);
/*
* update the head of the list and no of
* nodes in the current bucket
*/
hashTable[hashIndex].head = newnode;
hashTable[hashIndex].count++;
return;
}




void display() {
	    struct node *myNode;
	    int i;
	    for (i = 0; i < eleCount; i++) {
	        if (hashTable[i].count == 0)
	            continue;
	        myNode = hashTable[i].head;
	        if (!myNode)
	            continue;
	        printf("\nData at index %d in Hash Table:\n", i);
	        printf("AM     Name      Surname   Grade   \n");
	        printf("--------------------------------\n");
	        while (myNode != NULL) {
	           printf("%-12s", myNode->data.AM);
	            printf("%-15s", myNode->data.name);
	            printf("%-15s", myNode->data.surname);
	           printf("%-15f\n", myNode->data.grade);
	            myNode = myNode->next;
	        }
	    }
	    return;
	}


    node *searchInHash( char AM[]) {
	    int hashIndex = add(AM) % eleCount;
	    int flag = 0;
	    struct node *myNode;
	       myNode = hashTable[hashIndex].head;
	   // if (!myNode) {

	    //   printf("Search element unavailable in hash table 1\n");
	     //   return;
	   //}

	    while (myNode != NULL) {
	        int retu = memcmp(AM, myNode->data.AM, 9);
	        if (retu==0) {



                 return myNode;
                 flag = 1;
                 break;

	        }
        myNode = myNode->next;

	    }
	    if (flag == 0)
	        printf("Search element unavailable in hash table\n");
	        return NULL;



	}

	node *deleteFromHash(char AM[]) {
/* find the bucket using hash index */
int hashIndex = add(AM) % eleCount, flag = 0;
node *temp, *myNode;
/* get the list head from current bucket */
myNode = hashTable[hashIndex].head;
if (!myNode) {
printf("Given data is not present in hash Table!!\n");
return NULL;
}
temp = myNode;
while (myNode != NULL) {
/* delete the node with given key */
int retu = memcmp(AM, myNode->data.AM, 9);
if (retu==0) {
flag = 1;
if (myNode == hashTable[hashIndex].head)
hashTable[hashIndex].head = myNode->next;
else
temp->next = myNode->next;

hashTable[hashIndex].count--;
free(myNode);
break;
}
temp = myNode;
myNode = myNode->next;
}
if (flag)
printf("Data deleted successfully from Hash Table\n");
else
	        printf("Given data is not present in hash Table!!!!\n");
	    return NULL;
	}








int main()
{
       FILE *fpoint;
    fpoint = fopen("Foitites-Vathmologio-DS.txt", "r");
    students *stud_point;
    stud_point = (students *) malloc(20*sizeof(students));

    int i = 0;
    while (!feof(fpoint)) {

        fscanf(fpoint, "%s %s %s %f", stud_point[i].AM, stud_point[i].name, stud_point[i].surname, &stud_point[i].grade);
        //printf("%s %s %s %s\n", stud_point[i].AM, stud_point[i].name, stud_point[i].surname, stud_point[i].grade);
        i++;

    }

    int m,n;
    printf("Give m");
    scanf("%d",&m);
    m=n;

    hashTable = (struct hash *) calloc(n, sizeof(struct hash));

    for(int j=0; j<i-1; j++)
    {
        insertToHash(stud_point[j]);
    }

    int menu;
    char searching[20];
    char searching1[20];
    char searching2[20];

    node *tmp1;
    node *tmp;



    while(1>0){

    printf("\n1.Searching\t2. Edit\n");
    printf("3.Delete\t4.Display\n5.Exit\n");
    printf("Enter your choice: ");

    scanf("%d",&menu);
    switch(menu)
    {

    case 1:



        printf("Give the AM you are looking for\n");
        printf(">>");
        scanf("%s", searching);
        tmp=searchInHash(searching);
        if (tmp == NULL)
            break;


        printf("%s %s %s %f \n", tmp->data.AM, tmp->data.name, tmp->data.surname, tmp->data.grade);
        break;

    case 2:

        printf("Give the AM you are looking for\n");
        printf(">>");
        scanf("%s",searching2);
        tmp1 = searchInHash(searching2);
        if (tmp1 == NULL)
            break;

        printf("Type 1 for editing the name \n");
        printf("Type 2 for editing the surname\n");
        printf("Type 3 for editing the grade \n");
        printf(">>");

        int menu1;
        scanf("%d", &menu1);

                        if(menu1 == 1){
                            printf("Enter new name \n");
                            printf(">>");

                            char NewName[50];
                            scanf("%s", NewName);


                            memcpy(tmp1->data.name, NewName, strlen(tmp1->data.name));








                        }
                        else if(menu1 == 2){

                            printf("Enter new surname \n");
                            printf(">>");

                            char NewSurname[50];
                            scanf("%s", NewSurname);

                             memcpy(tmp1->data.surname, NewSurname, strlen(tmp1->data.surname));

                        }
                        else if(menu1 == 3){

                            printf("Enter new Grade \n");
                            printf(">>");

                            float NewGrade;
                            scanf("%f", &NewGrade);

                            tmp1->data.grade = NewGrade;


                        }
                        else
                        {
                            printf("Wrong Input\n");
                        }

                    break;

    case 3:

         printf("Give the AM of the student you want to delete\n");
         printf(">>");
         scanf("%s", searching1);

      node *temp2 = deleteFromHash(searching1);
        break;




    case 4:
      display();
        break;

    case 5:
       exit(0);
       break;



    default:
        printf("u dumb as fuck");

    }
}


    return 0;
}
