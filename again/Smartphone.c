#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ToDo define data type smartphone_t as struct
typedef struct {
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
}

int main() {
    smartphone_t phone = {
        .brand = "Sumsang",
        .model = "Milkyway S3",
        .color = "black",
        .memory = 16,
    };
    print_smartphone_configuration(phone);
    add_additional_sd_card(&phone);
    print_smartphone_configuration(phone);
    return 0;
}
