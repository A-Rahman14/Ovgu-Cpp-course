#include <stdio.h>

/*
    *
   ***
  *****
 *******
    *
 */

void print_tree_char(int height, char sym){
    // ToDo
    int h = 1;
    for (int i=1; i<=height; i++) {
        for (int j=1; j<=height-i; j++) {
            printf(" ");
        }
        for (int j=1; j<=h; j++) {
            printf("%c", sym);
        }
        h+=2;
        printf("\n");
    }
    for (int j=1; j<=height-1; j++) {
            printf(" ");
    }
    printf("%c\n", '*');
}

void print_tree(int height){
    // ToDo
    print_tree_char(height, '*');
}

int main(void){
    print_tree(1);
    print_tree(2);
    print_tree(3);
    print_tree(4);
    print_tree(10);
    print_tree_char(10,'+');
    print_tree_char(10,'o');
}
// Bearbeitet bei Abdelrahman Abdelhalim & Moayad Okal