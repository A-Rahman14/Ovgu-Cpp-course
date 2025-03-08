#include <math.h>
#include <stdio.h>

int is_prime(int num){
    // ToDo
    int t = 2;
    int a = 0;
    while (num > t*2-1) {
        if (num%t == 0) {
            a = 1;
            t = num;
        } else t++;
    }
    if (a == 1 || num<2) {
        return 0;
    } else return 1;
}

int calculate_nth_prime_number(int n){
    // ToDo
    int h = 0;
    for (int i=0; i<n;) {
        h++;
        if (is_prime(h)) {
            i++;
        }
    }
    return h;
}

int main(void){
    // Test your code

    printf("%d\n",is_prime(1));
    printf("%d\n",is_prime(2));
    printf("%d\n",is_prime(3));
    printf("%d\n",is_prime(9));
    printf("%d\n",is_prime(31));
    printf("-----------------\n");
    printf("%d\n",calculate_nth_prime_number(1));
    printf("%d\n",calculate_nth_prime_number(2));
    printf("%d\n",calculate_nth_prime_number(3));
    printf("%d\n",calculate_nth_prime_number(10));

    return 0;
}
