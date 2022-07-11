//  main.c
//  Exercise_count_the_words_in_the_string
//
//  Created by MrSigma123 11 Jul 2022
//

#include <stdio.h>
#include <string.h>
#define SIZE 100

void string_input(char *string);
int determine_string_length(char *string);
int count_the_words_in_the_string(char *string, int string_length);
void print_closing_message(int word_counter);

void string_input(char *string)
{
    printf("Please input the string: ");
    fgets(string, SIZE, stdin);
}

int determine_string_length(char *string)
{
    int string_length = (int)strlen(string); // strlen returns unsigned long (be aware)
    
    return string_length;
}

int count_the_words_in_the_string(char *string, int string_length)
{
    int i;  // for loops
    int word_counter = 0;
    
    // At the beginning let's check, if the input character is a newline character
    if (string[0] == '\n')
    {
        return 0;
    }
    // if that's not the case let's proceed to the further steps
    
    // firstly let's remove the space characters at the beginning
    for (i = 0; string[i] == ' '; i++)
        string[i] = '.';        // assign the dot character instead the space character
    
    // secondly let's remove the space characters after the last non space character
    for (i = 0; string[string_length - 2 - i] == ' '; i++)
        string[string_length - 2 - i] = '.'; // similarly like above,
                                             // let's remove the spaces,
                                             // this time at the end of the string
        
    // thirdly, let's ignore all repeating spaces
    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == ' ' && string[i+1] == ' ')
            string[i] = '.';
    }
    
    // fourthly let's count all remaining spaces, which will be our 'word counter'
    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == ' ')
            word_counter++;
    }
    word_counter += 1;  // there is always one space character less than there is words
                        // so we have to add one to the result
    
    return word_counter;
}

void print_closing_message(int word_counter)
{
    printf("This string has %d words.\n", word_counter);
}

int main(void)
{
    int string_length, word_counter;
    char string[SIZE];   // string, which can store up to a 100 characters
    
    string_input(string);
    string_length = determine_string_length(string);
    word_counter = count_the_words_in_the_string(string, string_length);
    print_closing_message(word_counter);
    
    return 0;
}

// Thank you
