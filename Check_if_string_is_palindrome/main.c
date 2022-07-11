//
//  main.c
//  check_if_string_is_palindrome
//
//  Created by MrSigma123 on 11/07/2022.
//

#include <stdio.h>
#include <string.h>
#define SIZE 100

void scan_the_string(char *string);
int check_if_the_string_is_palindrome(char *string);
void print_closing_message(int flag);

void scan_the_string(char *string)
{
    printf("Please enter the string: ");
    fgets(string, SIZE, stdin);
    // printf("%d", (int)strlen(string));   // for tests
}

int check_if_the_string_is_palindrome(char *string)
{
    /*
     We have to notice, that the string stores SIZE elements, but the actual element's
     indexes are from 0, to SIZE - 2, because SIZE - 1 stores '\0' element
     */
    int i;
 
    for (i = 0; string[i] == string[strlen(string) - 2 - i]
         || strlen(string) == 1; i++)
    {
        // printf("ok\n");  // for tests
        if (i >= (strlen(string))/2
            || (i == 0 && strlen(string) == 2))
            return 1;
    }
    return 0;
}

void print_closing_message(int flag)
{
    if (flag == 1)
        printf("\nThis string is PALINDROME!!! :O\n");
    else if (flag == 0)
        printf("\nThis string is not PALINDROME... :/\n");
}

int main(void)
{
    int flag;
    char string[SIZE];
    
    scan_the_string(string);
    flag = check_if_the_string_is_palindrome(string);
    print_closing_message(flag);
    
    return 0;
}
