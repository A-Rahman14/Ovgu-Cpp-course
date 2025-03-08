#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_anagram(char* word, char* compared) {
  if (strlen(word) == strlen(compared)) {
    for (int i=0; i<strlen(word); i++) {
      int a = 0;
      for (int j=0; j<strlen(compared);) {
        if (word[i] == compared[j]) {
          a = 1;
          break;
        }
        j++;
        if (j == strlen(compared) && a == 0) {
          return 0;
        }
      }
    }
    for (int i=0; i<strlen(compared); i++) { // deshalb habe ich diese for-schleife copiert aber anderesrum (compared verglichen mit word)
      int a = 0;
      for (int j=0; j<strlen(word);) {
        if (compared[i] == word[j]) {
          a = 1;
          break;
        }
        j++;
        if (j == strlen(word) && a == 0) {
          return 0;
        }
      }
    }
  } else return 0;
  return 1;
}


int main() {
  printf("%d\n", is_anagram("mehl", "helm"));
  printf("%d\n", is_anagram("Mehl", "helm"));
  printf("%d\n", is_anagram("ehem", "helm")); // weil wenn ich nur einmal die for-schleife benutzte und word nach compared vergleichen ergibt dieses Test 1 und soll 0 ergeben ... (sehen Sie oben)
  printf("%d\n", is_anagram("boeing", "airbus"));
  return EXIT_SUCCESS;
}

// Bearbeitet bei Abdelrahman Abdelhalim & Moayad Okal