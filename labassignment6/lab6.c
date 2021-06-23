//enter your name here
//enter your email here

#include <stdio.h>
#include <string.h>
#include<ctype.h>

/* function to encrypt the data*/
void encrypt(char text[], int key)
{
    //insert your code here
}

/*function to decrypt the data*/
void decrypt(char text[],int key)
{
    
    //insert your code here
    
}


/*----------- Main program---------------*/
int main()
{
    char text[20] ;
    /*Input string */
    printf("Enter the message:  ");
    scanf("%s",text);
    printf("text input   = %s\n",text);
    /*call function to encrypt the data*/
    encrypt(text,3);
    printf("Encrypted value = %s\n",text);
    /*call function to decrypt the data*/
    decrypt(text,3);
    printf("Decrypted value = %s\n",text);
    
    return 0;
}
