/* CS261- Assignment 1 - Q.4*/
/* Name: Minh Nguyen
 * Date: 6/30/2014
 * Solution description: Creating and sorting an array of a struct with student id and scores.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
     int i,j, temp;
    for(i=0; i < n; i++){
        for(j=0; j<n; j++){
            if (students[i].score < students[j].score)
            {
                temp = students[i].score;
                students[i].score = students[j].score;
                students[j].score = temp;

            }
        }
    }

}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 20;

    /*Allocate memory for n students using malloc.*/
    struct student *stud = malloc(n* sizeof(int));

    /*Generate random IDs and scores for the n students, using rand().*/
    srand((unsigned)time(NULL));
    int i;
    for (i=0; i < n; i++){
        stud[i].id = (rand()%10 + 1);
        stud[i].score = (rand()%(100 -0 +1)+0);
    }

    /*Print the contents of the array of n students.*/
    for (i=0; i < n; i++){
    printf("ID[%d]: %d, score[%d]: %d\n", i, stud[i].id, i, stud[i].score);
    }

    /*Pass this array along with n to the sort() function*/
    sort(stud, n);
    printf("\n\n\n\n");

    /*Print the contents of the array of n students.*/
     for (i=0; i < n; i++){
    printf("ID[%d]: %d, score[%d]: %d\n", i, stud[i].id, i, stud[i].score);
    }

    return 0;
}
