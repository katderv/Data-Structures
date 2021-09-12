#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void insert(node **tree, students num);
node* deleteNode(node* root, char del[]);
node *search(node **tree, char AM[]);
void print_inorder(node * tree);
node * minValueNode(node* nod);
void insertGrade(node **tree, students num);
node* maxValueNode( node* nod);

int main() {
    FILE *fpoint;
    fpoint = fopen("Foitites-Vathmologio-DS.txt", "r");
    students *stud_point;
    stud_point = (students *) malloc(20 * sizeof(students));

    int i = 0;
    while (!feof(fpoint)) {

        fscanf(fpoint, "%s %s %s %f", stud_point[i].AM, stud_point[i].name, stud_point[i].surname, &stud_point[i].grade);
        i++;

    }

    printf("Type 1 for loading by AM\n");
    printf("Type 2 for loading by grade\n");
    printf(">>");

    int bin_menu;
    scanf("%d", &bin_menu);

    if(bin_menu == 1){

        node *root;
        root = NULL;
        int j = 0;
        for (j = 0; j < i - 1; j++) {

            insert(&root, stud_point[j]);
        }
            while(1>0){

                printf("Type 1 for inorder crossing \n");
                printf("Type 2 for searching a student by AM\n");
                printf("Type 3 for editing a students data \n");
                printf("Type 4 for deleting a student by AM\n");
                printf("Type 5 for exiting the app\n");
                printf(">>");

                int menu;
                scanf("%d", &menu);
                if (menu == 1) {
                    print_inorder(root);

                }

                else if (menu == 2) {
                    char searching[9];

                    printf("Give the AM you are looking for\n");
                    printf(">>");
                    scanf("%s", searching);

                    node *tmp;
                    tmp = search(&root, searching);

                    if(tmp == NULL)
                        printf("not found\n");

                    else{
                            printf("%s %s %s %.2f \n", tmp->data.AM, tmp->data.name, tmp->data.surname, tmp->data.grade);
                    }


                }
                else if (menu == 3){
                    char searching1[9];

                    printf("Give the AM of the student you want to edit\n");
                    printf(">>");
                    scanf("%s", searching1);

                    node *tmp1;
                    tmp1 = search(&root, searching1);

                     if(tmp1 == NULL)
                        printf("not found\n");

                    else{

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

                            char NewSurame[50];
                            scanf("%s", NewSurame);

                             memcpy(tmp1->data.surname, NewSurame, strlen(tmp1->data.surname));

                        }
                        else if(menu1 == 3){

                            printf("Enter new surname \n");
                            printf(">>");

                            float NewGrade;
                            scanf("%f", &NewGrade);
                            tmp1->data.grade = NewGrade;

                        }
                        else
                        {
                            printf("Wrong Input\n");
                        }
                    }
                }
                else if (menu == 4){
                        char searching2[9];

                    printf("Give the AM of the student you want to delete\n");
                    printf(">>");
                    scanf("%s", searching2);

                    node *tmp3;
                    tmp3 = search(&root, searching2);

                     if(tmp3 == NULL)
                        printf("not found\n");

                    else{

                    root= deleteNode(root,searching2);
                    }

                }
                else if (menu == 5){

                    break;
                }

                else
                        {
                            printf("Wrong Input\n");
                        }


            }

    }

    else if(bin_menu == 2){

        node *root_grade;
        root_grade = NULL;
        int k;
        for (k = 0; k < i - 1; k++) {

            insertGrade(&root_grade, stud_point[k]);
        }


                printf("Type 1 for the students with minimum grade\n");
                printf("Type 2 for the students with maximum grade\n");
                printf(">>");

                int menu2;
                scanf("%d", &menu2);

                    if(menu2 == 1){

                        node *minGrade = minValueNode(root_grade);
                        do{
                            printf("AM: %s\t",minGrade->data.AM);
                            printf("Name: %s\t",minGrade->data.name);
                            printf("Surname: %s\t",minGrade->data.surname);
                            printf("Grade: %.2f\n",minGrade->data.grade);
                            minGrade = minGrade->inside;
                        }while(minGrade != NULL);

                    }

                    else if(menu2 == 2){
                            node *maxGrade = maxValueNode(root_grade);
                        do{
                            printf("AM: %s\t",maxGrade->data.AM);
                            printf("Name: %s\t",maxGrade->data.name);
                            printf("Surname: %s\t",maxGrade->data.surname);
                            printf("Grade: %.2f\n",maxGrade->data.grade);
                            maxGrade = maxGrade->inside;
                        }while(maxGrade != NULL);


                    }


                    else{

                    printf("Wrong Input \n");


                    }









    }

    else
    {
        printf("Wrong Input \n");
    }
        return 0;

}
