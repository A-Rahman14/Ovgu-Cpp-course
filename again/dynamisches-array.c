#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char* array;
    int numElems;
    int size;
}Dyn_array_t;

void initArray(Dyn_array_t* array, int desSize){
    //Code goes here
    array->array = (char*) malloc(desSize * sizeof(char));
    array->numElems = 0;
    array->size = desSize;
}

void destroyArray(Dyn_array_t* array){
    //Code goes here
    free(array->array);
    array->array = NULL;
    array->size = 0;
    array->numElems =0;
}

void insert(Dyn_array_t* array, char elem){
    //Code goes here
    if (array->numElems >= array->size) {
        char* newArr = (char*) malloc(array->size * 2 * sizeof(char));
        for (int i=0; i < array->size; i++) {
            newArr[i] = array->array[i];
        }
        free(array->array);
        array->array = newArr;
        array->size *= 2;
    }
    array->array[array->numElems] = elem;
    array->numElems ++;
}

int main() {
   // test your code here
   Dyn_array_t a;
   initArray(&a, 4);
   insert(&a, 'a');
   insert(&a, 'b');
   insert(&a, 'c');
   insert(&a, 'd');
   insert(&a, 'e');
   insert(&a, 'f');
   printf("%s\n", a.array); // Manchmal finde ich hier das Problem, dass die elemnte nicht klar gedruckt werden wie "#?cdef" oder "abcdefP" und kann den Fehler nicht finden
   printf("%d\n", a.numElems);
   printf("%d\n", a.size);
   destroyArray(&a);
   return 0;
}

// Bearbeitet bei Abdelrahman Abdelhalim & Moayad Okal