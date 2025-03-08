#include <iostream>

#include "vector.hpp"

using Vec3 = Math::Vector<float, 3>;

int main()
{
    
    // Todo: test the functionality of your vector.
    // Test all written functions.
    // Return 0 if everything works, 1 if not.
    Math::Vector<float,3> s = Math::Vector<float,3>() ;
    s[2]=2;
    Math::Vector<float,3> s2 = Math::Vector<float,3>() ;
    s2[2]=5;
    Math::Vector<float,3> s3 =s+s2;
    std::cout << s3[2];
}
