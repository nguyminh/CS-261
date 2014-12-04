//Minh Nguyen
//Due Date: 7/13/2014
//Assignment #2. RPN calculator file



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	if(sizeDynArr(stack) < 2) //check to make sure there are 2 numbers
	{
		printf("Needs at least 2 numbers to use '+'\n");
		return;
	}
	double first;    //declaring variable for first number
	double second;   //declaring variable for second number
	first = topDynArr(stack);  //storing first number into local variable  
	popDynArr(stack);   //pops first number from underlying  stack
	
	second = topDynArr(stack); //storing second number into local variable
	popDynArr(stack);   //pops second number from underlying stack

	pushDynArr(stack, first + second); //adds 2 local variable
					   //pushes onto underlying stack

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{	
	if(sizeDynArr(stack) < 2)
	{
		printf("Needs at least 2 numbers to use '-'\n");
		return;
	}
	double first;
	double second;
	first = topDynArr(stack);
	popDynArr(stack);
	
	second = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, second -  first); //subtracts the two numbers
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	if(sizeDynArr(stack) < 2)
	{
		printf("Needs at least 2 numbers to use '/'\n");
		return;
	}
	double first;
	double second;
	first = topDynArr(stack);
	popDynArr(stack);
	
	second = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, second/first); //divides second by first number
}


void multiply(struct DynArr *stack)
{

   if(sizeDynArr(stack) < 2){
	printf("Needs at least 2 numbers to use 'x'\n");
        return;
    }

    double first;
    double second;

    first = topDynArr(stack);
    popDynArr(stack);

    second = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, first * second); //multiplies two numbers
}

void power(struct DynArr *stack)
{

    if(sizeDynArr(stack) < 2){
	printf("Needs at least 2 numbers to use '^'\n");
        return;
    }

    double first;
    double second;

    first = topDynArr(stack);
    popDynArr(stack);

    second = topDynArr(stack);
    popDynArr(stack);
   
    pushDynArr(stack, pow(second,first)); //use second number as power for first

}

void square(struct DynArr *stack)
{
    if(sizeDynArr(stack) < 1){
	printf("Needs at least 1 numbers to use '^2'\n");
        return;
    }

    double first;

    first = topDynArr(stack);
    popDynArr(stack);

   
    pushDynArr(stack, pow(first,2)); //take one number and square it
}

void cube(struct DynArr *stack)
{

   if(sizeDynArr(stack) < 1){
        printf("Need at least 1 number to use '^3'\n");
        return;
    }

    double first;

    first = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, pow(first,3)); //takes a number and cube it
}

void absolute(struct DynArr *stack)
{
    if(sizeDynArr(stack) < 1){
        printf("Need at least 1 number to use 'abs'\n");
        return;
    }
    double first;
    
    first = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, abs(first)); //aboslute value of a number

}

void squarert(struct DynArr *stack)
{
    if(sizeDynArr(stack) < 1){
        printf("Need at least 1 number to use 'sqrt'\n");
        return;
    }
    double first;

    first = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, sqrt(first)); //sqrt of a number

}

void exponential(struct DynArr *stack){
    if(sizeDynArr(stack) < 1){
        printf("Need at least 1 number to use 'exp'\n");
       return;
    }
    double first;

    first = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, exp(first)); //exponent of number
}

void naturalLog(struct DynArr *stack){

    if(sizeDynArr(stack) < 1){
        printf("Need at least 1 number to use 'ln'\n");
        return;
    }

    double first;

    first= topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, log(first)); //Ln of a number
}

void Log_10(struct DynArr *stack)
{
   if(sizeDynArr(stack) < 1){
        printf("Need at least 1 number to use 'log'\n");
        return;
    }
    double first;

    first = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, log10(first)); //log base 10 of a number
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;
	double num;
	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
		{	
			add(stack);
			printf("Adding\n");
		}
		else if(strcmp(s,"-") == 0)
		{
			subtract(stack);
			printf("Subtracting\n");
		}
		else if(strcmp(s, "/") == 0)
		{
			divide(stack);
			printf("Dividing\n");
		}
		else if(strcmp(s, "x") == 0)
		{
			multiply(stack);			
			printf("Multiplying\n");
		}
		else if(strcmp(s, "^") == 0)
		{
			power(stack);
			printf("Power\n");
		}
		else if(strcmp(s, "^2") == 0)
		{
			square(stack);
			printf("Squaring\n");
		}
		else if(strcmp(s, "^3") == 0)
		{
			cube(stack);
			printf("Cubing\n");
		}
		else if(strcmp(s, "abs") == 0)
		{
			absolute(stack);
			printf("Absolute value\n");
		}
		else if(strcmp(s, "sqrt") == 0)
		{
			squarert(stack);
			printf("Square root\n");
		}
		else if(strcmp(s, "exp") == 0)
		{
			exponential(stack);
			printf("Exponential\n");
		}
		else if(strcmp(s, "ln") == 0)
		{
			naturalLog(stack);
			printf("Natural Log\n");
		}
		else if(strcmp(s, "log") == 0)
		{
			Log_10(stack);
			printf("Log\n");
		}
		else if(isNumber(s, &num))
			pushDynArr(stack, num);
		else if (strcmp(s, "pi") == 0)
			pushDynArr(stack, 3.14159265);
		else if(strcmp(s, "e") == 0)
			pushDynArr(stack, 2.7182818); 
			
	}	 

	
	if(sizeDynArr(stack) == 1)
	{
		printf("Answer = %f\n", topDynArr(stack));
		return result;
	}
	else
	{
		printf("ERROR! Please try again! \n");
		return 0;
	}
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	calculate(argc,argv);
	return 0;
}
