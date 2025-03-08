#pragma once
#include <iostream>

class smartphone_t{
public: 
    // Define the constructor and destructor in scopetimer.cpp
    smartphone_t(int memo);
    ~smartphone_t();
    void add_additional_sd_card(smartphone_t* phone);
    void print_smartphone_configuration(smartphone_t phone);
    // ToDo: Data members?
    char* brand;
    char* model;
    char* color;
    int memory;
};