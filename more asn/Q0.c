/* CS261- Assignment 1 - Q. 0*/
/* Name: Minh Nguyen
 * Date: 6/30/2014
 * Solution description: prints out address of x, value of iptr, address pointed to by iptr, address of ptr, and value of x
 */

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
    printf("value pointed to by iptr: %d\n", *iptr);
     /*Print the address pointed to by iptr*/
    printf("address pointed to by iptr: %d\n", iptr);
     /*Print the address of iptr itself*/
    printf("address of iptr itself: %d\n", &iptr);
}

int main(){

    /*declare an integer x*/
    int x;
    /*print the address of x*/
    printf("address of x: %d\n", &x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    printf("value of x: %d", x);
    return 0;
}
