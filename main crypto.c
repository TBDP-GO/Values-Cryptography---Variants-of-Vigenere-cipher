// Chiffrement par substitution - Variante de Chiffrement de Vigenère

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions crypto.c"

int main(int argc, char * argv[]) {

  unsigned char keyCode[50000], secretCode[50000], resultCode[50000], startCode[50000];
  int lengthSC, lengthKC, i;

  printf ("                          #########################################\n");
  printf ("                          # DEMONSTRATION OF VIGENERE CIPHER v1.0 #\n");
  printf ("                          #########################################\n\n");

  printf("The Vigenere cipher is a polyalphabetic encrypting method that \
defeats simple frequency analysis because letters can be enciphered as different ciphertext ones \
at different points in the message. In other word, the same letter can be represented by different ones in the \
encrypted message. \n\
(Software explication source: https://en.wikipedia.org/wiki/Vigenere_cipher)\n\n\n");

  printf("     In order to encrypt your message, can you insert the text? (After, push the ENTER button on keyboard)\n");
  printf("     ");
  readSC(secretCode, 50000);
  printf("\n     Please, type your password and after push again the ENTER button on keyboard:\n");
  printf("     ");
  readKC(keyCode, 50000);

  assessLength(secretCode, keyCode, lengthSC, lengthKC);
  copyElements(keyCode, secretCode, lengthSC);
  sum(secretCode, keyCode, resultCode);

  printf("\n\nYour encrypted message is also in the file \"Encrypted message.txt\" that you can find in the same folder of \
this software.\nThanks for using!\n\n");

  printf ("-----------------------------------------\n");
  printf (" Demonstration of Vigenere cipher - v1.0\n");
  printf (" Software realized by Gianluca Odoardi\n");
  printf (" odoardigianluca@gmail.com\n");
  printf ("-----------------------------------------\n\n");

  printf("Press Any Key to close the software\n");
  getch();


  return 0;
}
