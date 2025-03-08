#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "smartphone_t.cpp"

// ToDo define data type smartphone_t as struct
/*typedef struct {
    char* brand;
    char* model;
    char* color;
    int memory;
} smartphone_t;
void add_additional_sd_card(smartphone_t* phone) {
    //ToDo
    phone->memory+=128;
}

void print_smartphone_configuration(smartphone_t phone) {
    // ToDo
    printf("Your Configuration:\n    Brand: ""%s\n",phone.brand);
    printf("    Model: ""%s\n",phone.model);
    printf("    Color: ""%s\n",phone.color);
    printf("    Total Memory: ""%i\n",phone.memory);
}*/

int main() {
    //smartphone_t phone = {"Sumsang", "Milkyway S3", "black", 16};
    smartphone_t phone = {10};
    std::cout << "1-----------------------------\n";
    add_additional_sd_card(&phone);
    std::cout << "2-----------------------------\n";
    print_smartphone_configuration(phone);
    std::cout << "3-----------------------------\n";
    add_additional_sd_card(&phone);
    std::cout << "4-----------------------------\n";
    print_smartphone_configuration(phone);
    std::cout << "5-----------------------------\n";
    phone.~smartphone_t();
    std::cout << "6-----------------------------\n";
    add_additional_sd_card(&phone);
    std::cout << "7-----------------------------\n";
    print_smartphone_configuration(phone);
    std::cout << "8-----------------------------\n";
    return 0;
}