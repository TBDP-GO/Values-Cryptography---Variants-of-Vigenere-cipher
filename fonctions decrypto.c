int readRC(char *resultCode, int length)
{
  char *entryPosition = NULL;

  // On lit le texte saisi au clavier
  if (fgets(resultCode, length, stdin) != NULL)  // Pas d'erreur de saisie ?
    {
      entryPosition = strchr(resultCode, '\n'); // On recherche l'"Entrée"
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

int readKC(char *keyCode, int length) {
  char *entryPosition = NULL;

  // On lit le texte saisi au clavier
  if (fgets(keyCode, length, stdin) != NULL)  // Pas d'erreur de saisie ?
    {
      entryPosition = strchr(keyCode, '\n'); // On recherche l'"Entrée"
      if (entryPosition != NULL) // Si on a trouvé le retour à la ligne
        {
	  *entryPosition = '\0'; // On remplace ce caractère par \0
	  *entryPosition = '\0'; // On remplace ce caractère par \0
        }
      return 1; // On renvoie 1 si la fonction s'est déroulée sans erreur
    }
  else
    {
      return 0; // On renvoie 0 s'il y a eu une erreur
    }
}

int assessLength(unsigned char resultCode[50000], unsigned char keyCode[50000], int lengthRC, int lengthKC) {
  int i;
  lengthRC = strlen(resultCode);
  //  printf("Length of the string of password = %d\n", lengthSC);

  lengthKC = strlen(keyCode);
  //  printf("Length of the string of password = %d\n", lengthKC);

  //  for (i = 0; i < lengthSC; i++) {
  //    printf("%c equivalent en decimale : %d\n", resultCode[i], resultCode[i]);
  //  }

  //  for (i = 0; i < lengthKC; i++) {
  //    printf("%c equivalent en decimale : %d\n", keyCode[i], keyCode[i]);
  //  }
  return 0;
}

int copyElements(unsigned char resultCode[50000], unsigned char keyCode[50000], size_t lengthRC) {
  char tmp[50000];
  int i;

  lengthRC = strlen(resultCode);

  strcpy(tmp, keyCode);

  for (i = 0; i < lengthRC; i++) {
    strncat(keyCode, tmp, lengthRC);

  }
  return keyCode[50000];
}

int subtraction(unsigned char resultCode[50000], unsigned char keyCode[50000], unsigned char startCode[50000]) {
  int i, lengthRC;

  lengthRC = strlen(resultCode);

  for (i = 0; i < lengthRC; i++) {
    startCode[i] = resultCode[i] - keyCode[i];
    if ( (unsigned char) startCode[i] <= 32) // ok from [_ = 99] to [o = 111]
      {
        startCode[i] += 95;
      }
    else if ( (unsigned char) startCode[i] > 190)
      {
        startCode[i] += 95;
      }

    // printf("resultCode sum: %c %d\n", resultCode[i], resultCode[i]);
    // printf("keyCode sum: %c %d\n", keyCode[i], keyCode[i]);
    // printf("\nsum (result code - key code) : %c %d\n", startCode[i], startCode[i]);
  }

  printf("\nYour encrypted message was: \n%s", startCode);

  FILE* file = NULL;
  file = fopen("Decrypted message.txt", "w");
  if (file != NULL)
    {
      fprintf(file, "Your encrypted message is: \n%s\n\n", resultCode);
      fprintf(file, "Your original message was: \n%s\n", startCode);
      fclose(file);

      return 0;

    }
}
