int readSC(unsigned char *secretCode, int length) {
  char *entryPosition = NULL;

  // On lit le texte saisi au clavier
  if (fgets(secretCode, length, stdin) != NULL)  // Pas d'erreur de saisie ?
    {
      entryPosition = strchr(secretCode, '\n'); // On recherche l'"Entrée"
      if (entryPosition != NULL) // Si on a trouvé le retour à la ligne
        {
	  *entryPosition = '\0'; // On remplace ce caractère par \0
        }
      return 1; // On renvoie 1 si la fonction s'est déroulée sans erreur
    }
  else
    {
      return 0; // On renvoie 0 s'il y a eu une erreur
    }
}

int readKC(unsigned char *keyCode, int length) {
  char *entryPosition = NULL;

  // On lit le texte saisi au clavier
  if (fgets(keyCode, length, stdin) != NULL)  // Pas d'erreur de saisie ?
    {
      entryPosition = strchr(keyCode, '\n'); // On recherche l'"Entrée"
      if (entryPosition != NULL) // Si on a trouvé le retour à la ligne
        {
	  *entryPosition = '\0'; // On remplace ce caractère par \0
        }
      return 1; // On renvoie 1 si la fonction s'est déroulée sans erreur
    }
  else
    {
      return 0; // On renvoie 0 s'il y a eu une erreur
    }
}

int assessLength(unsigned char secretCode[50000], unsigned char keyCode[50000], int lengthSC, int lengthKC) {
  int i;
  lengthSC = strlen(secretCode);
  //  printf("Length of the string of password = %d\n", lengthSC);

  lengthKC = strlen(keyCode);
  //  printf("Length of the string of password = %d\n", lengthKC);

  //  for (i = 0; i < lengthSC; i++) {
  //    printf("%c equivalent en decimale : %d\n", secretCode[i], secretCode[i]);
  //  }

  //  for (i = 0; i < lengthKC; i++) {
  //    printf("%c equivalent en decimale : %d\n", keyCode[i], keyCode[i]);
  //  }
  return 0;
}

int copyElements(unsigned char keyCode[50000], unsigned char secretCode[50000], size_t lengthSC) {
  unsigned char tmp[50000];
  int i;

  lengthSC = strlen(secretCode);

  strcpy(tmp, keyCode);

  for (i = 0; i < lengthSC; i++) {
    strncat(keyCode, tmp, lengthSC);
  }
  return keyCode[50000];
}

int sum(unsigned char secretCode[50000], unsigned char keyCode[50000], unsigned char resultCode[50000]) {
  int i, lengthSC;

  lengthSC = strlen(secretCode);

  for (i = 0; i < lengthSC; i++) {
    resultCode[i] = secretCode[i] + keyCode[i];
    if ( (unsigned char) resultCode[i]> 127 && resultCode[i] <= 317)
      {
        resultCode[i] -= 95;
      }
    // printf("sum: %c %d\n", secretCode[i], secretCode[i]);
    // printf("sum: %c %d\n", keyCode[i], keyCode[i]);
    // printf("sum: %c %d\n", resultCode[i], resultCode[i]);

  }
  printf("\n     Your encrypted message is: \n     %s\n\n", resultCode);


  FILE* file = NULL;
  file = fopen("Encrypted message.txt", "w");
  if (file != NULL)
    {
      fprintf(file, "Your original message is: \n%s\n", secretCode);
      fprintf(file, "\nYour encrypted message is: \n%s\n\n", resultCode);
      fclose(file);

    }
  return 0;
}
