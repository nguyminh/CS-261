/* CS261- Assignment 1 - Q.5*/
/* Name: Minh Nguyen
 * Date: 6/30/2014
 * Solution description: Prompt user to enter in a word, word is then printed out in sticky caps
 */

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     if (ch>='a' && ch<='z')
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     if (ch>='A' && ch<='Z')
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
     int i;
     for (i=0; i < strlen(word); i++){
        if (i % 2 ==0)
        {
            if(word[i] >= 'a' && word[i] <= 'z')
            {
                word[i]=toUpperCase(word[i]);
            }
        }
        else
        {
            if(word[i]>='A' && word[i]<='Z')
            {
                word[i]=toLowerCase(word[i]);
            }
        }
     }

}

int main(){
    char word[256];
    char *input;
    input = word;
    /*Read word from the keyboard using scanf*/
    printf("Please input a word: ");
    scanf("%s", input);

    /*Call sticky*/
    sticky(input);

    /*Print the new word*/
    printf("%s", input);
    int i;
    for (i=0;i<sizeof(input);i++){
        if(input[i]=='\n')
        {
            input[i] ='\0';
            break;
        }
    }
    return 0;
}
