#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(char* string1, char* string2){
   int newlen = (strlen(string1) + strlen(string2)) * sizeof(char) + 1;
   char* s = (char*) malloc(newlen);
   for (int i=0; i<newlen; i++) {
      if (i<strlen(string1)) {
         s[i] = string1[i];
      } else {
         s[i] = string2[i-strlen(string1)];
      }
   }
   printf("%d\n", strlen(s));
   return s;
}

int main() {
   printf("%s\n", concat("Hello ", "World"));
   printf("%s\n", concat("Pog", "Champ"));
   return 0;
}

// Bearbeitet Abdelrahman Abdelhalim & Moayad Okal