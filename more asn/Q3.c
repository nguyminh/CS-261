/* CS261- Assignment 1 - Q.3*/
/* Name: Minh Nguyen
 * Date: 6/30/2014
 * Solution description: fill an array of 20 using malloc, then sorting it
 with a sort function
 */

#include <stdio.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/
    int i,j, temp;
    for(i=0; i < n; i++){
        for(j=0; j<n; j++){
            if (number[i] < number[j])
            {
                temp = number[i];
                number[i] = number[j];
                number[j] = temp;

            }
        }
    }

}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;

    /*Allocate memory for an array of n integers using malloc.*/
    int *array = malloc(n* sizeof(int));
    /*Fill this array with random numbers, using rand().*/
    int i;
    srand((unsigned)time(NULL));
    for (i = 0; i < 20; i++){
           array[i] = rand()%((100 -0 +1)+0);

    }

    /*Print the contents of the array.*/
    for (i = 0; i < 20; i++){
        printf("array[%d] = %d\n", i, array[i]);
    }
    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);
    printf("Sorting begins after this statement in ascending order --\n\n");

    /*Print the contents of the array.*/
     for (i = 0; i < 20; i++){

        printf("array[%d] = %d\n", i, array[i]);
    }
    return 0;
}
