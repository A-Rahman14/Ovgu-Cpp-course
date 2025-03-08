#include "smartphone_t.hpp"

smartphone_t::smartphone_t(int memo) {
    brand = "suck";
    model = "secs";
    color = "black";
    memory = memo;
}
smartphone_t::~smartphone_t(){
    std::cout << "np dude it sucked anyways\n" ;
}
void print_smartphone_configuration(smartphone_t phone) {
    // ToDo
    printf("Your Configuration:\n    Brand: ""%s\n",phone.brand);
    printf("    Model: ""%s\n",phone.model);
    printf("    Color: ""%s\n",phone.color);
    printf("    Total Memory: ""%i\n",phone.memory);
}
void add_additional_sd_card(smartphone_t* phone) {
    //ToDo
    phone->memory += 100;
}