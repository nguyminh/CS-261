/* CS261- Assignment 1 - Q.2*/
/* Name: Minh Nguyen
 * Date: 6/30/2014
 * Solution description: declare and initialize 3 variables, double the first, half the second, and compute their addition
 in a return value, all within a function that takes in pointers as arguments.
 */

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = (5) * 2;
    /*Set b to half its original value*/
    *b = (6) / 2;
    /*Assign a+b to c*/
    c = *a+*b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    /*Print the values of x, y and z*/
    printf(" Value of x: %d\n Value of y: %d\n Value of z: %d\n", x, y, z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    foo(&x, &y, z);
    /*Print the value returned by foo*/
    printf("value returned by foo: %d\n", foo(&x, &y, z));
    /*Print the values of x, y and z again*/
    printf(" Value of x: %d\n Value of y: %d\n Value of z: %d\n", x, y, z);

    /*Is the return value different than the value of z?  Why?*/
    /*The return value is different than the return  value of z because z is unchanged, which stays at 7,
    while the return value is an addition of the x and y, which is 13. */
    return 0;
}


