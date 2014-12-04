/* CS261- Assignment 1 - Q.1*/
/* Name: Minh Nguyen
 * Date: 6/30/2014
 * Solution description: assigns 10 random student ID's, 10 random student scores, and compute min/max and average of scores.
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student* s = malloc(10 * sizeof(struct student));
     /*return the pointer*/
     return s;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    srand((unsigned)time(NULL));
    int i;
    for (i=1; i < 11; i++){
        students[i].id = (rand()%10 + 1);
        students[i].score = (rand()%(100 -0 +1)+0);

    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int i;
    for (i=1; i < 11; i++){
    printf("ID[%d]: %d, score[%d]: %d\n", i, students[i].id, i, students[i].score);
    }

}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int i=1;
    int min=100;
    int max=0;
    int avg = 0;
    for(i=1; i < 11; i++){
        if (students[i].score < min){
            min = students[i].score;
        }
        if (students[i].score > max){
            max = students[i].score;
        }
            avg = avg + students[i].score;

    }
    avg = avg/10;
    printf("Minimum score: %d, Maximum score: %d, Average score: %d\n", min, max, avg);

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     free (stud);
}

int main(){
    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
