#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE_OF_THE_ALPHABET 26
#define LETTERS_IN_STRING 1000000

char* gotTextFromUser(void);
void encrypt(char* enteredLetters, char* key);
void decipher(char* string, char* key);

int main(){
    char key[LETTERS_IN_STRING] = {0};
    char enteredLetters[LETTERS_IN_STRING] = {0};
    printf ("enter the key: ");
    gets(key);
    fflush(stdin);
    printf ("To encrypt text, type a, decipher b: ");
    char c;
    scanf ("%c", &c);
    fflush(stdin);
    char* string = gotTextFromUser();
    if (c == 'a') encrypt (string, key);
    if (c == 'b') decipher (string, key);
    free(string);

    getch(); return 0;
}

char* gotTextFromUser(){
    char* enteredLetters;
    enteredLetters = (char*) malloc(LETTERS_IN_STRING * sizeof(char));
    printf("enter the text for encryption: ");
    gets(enteredLetters);
    fflush(stdin);
    return enteredLetters;
}

void encrypt(char* string, char* key){
    int i, j;
    int countNumberLetter;
    int countKeyEncrypt;
    int sizeOfInputString = strlen(string);
    int sizeOfKey = strlen(key);

    for (i = 0, j = 0; i < sizeOfInputString; i++, j++){

        if (sizeOfKey <= j){
            j = 0;
        }
        if (islower(string[i])){
            countNumberLetter = string[i] - 'a';
            countKeyEncrypt = key[j] - ('a');
            string[i] = (countKeyEncrypt +  countNumberLetter ) %SIZE_OF_THE_ALPHABET +'a';
        }
        if (isupper(string[i])){
            countNumberLetter = string[i] - 'A';
            countKeyEncrypt = key[j] - ('A');
            string[i] = (countKeyEncrypt +  countNumberLetter ) %SIZE_OF_THE_ALPHABET +'A';
        }
            printf ("%c", string[i]);
    }
}

void decipher(char* string, char* key){
    int i, j;
    int countNumberLetter;
    int countKeyEncrypt;
    int sizeOfInputString = strlen(string);
    int sizeOfKey = strlen(key);

    for (i = 0, j = 0; i < sizeOfInputString; i++, j++){

        if (sizeOfKey <= j){
            j = 0;
        }
        if (islower(string[i])){
            countNumberLetter = string[i] - 'a';
            countKeyEncrypt = key[j] - ('a');
            string[i] = (countNumberLetter - countKeyEncrypt + SIZE_OF_THE_ALPHABET) %SIZE_OF_THE_ALPHABET +'a';
        }
        if (isupper(string[i])){
            countNumberLetter = string[i] - 'A';
            countKeyEncrypt = key[j] - ('A');
            string[i] = (countNumberLetter - countKeyEncrypt + SIZE_OF_THE_ALPHABET) %SIZE_OF_THE_ALPHABET +'A';
        }
            printf ("%c", string[i]);
    }
}
