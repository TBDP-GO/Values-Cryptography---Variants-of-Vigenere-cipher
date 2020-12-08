// Dechiffrement par substitution - Variante de Chiffrement de Vigenère

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions decrypto.c"

int main(int argc, char * argv[]) {

  unsigned char startCode[50000], keyCode[50000], resultCode[50000]; //secretcode
  int lengthRC, lengthKC, i;

  printf("Can you insert your encrypted message? (After, push the ENTER button on keyboard)\n");
  readRC(resultCode, 50000);

  printf("\nPlease, type your password and after push again the ENTER button on keyboard:\n");
  readKC(keyCode, 50000);

  assessLength(resultCode, keyCode, lengthRC, lengthKC);
  copyElements(resultCode, keyCode, lengthRC);

  subtraction(resultCode, keyCode, startCode);

  printf("\n\nYour original message is in the file \"Decrypted message.txt\" that you can find in the same folder of \
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
