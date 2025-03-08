#pragma once

#include <cstdint>

/* Implement a generic mathematical Vector.
 * todo: * add template parameters
 *       * implement the required operators
 *       * test all functions
 *       * keep it const correct
 */
namespace Math{

    // The vector should have both a generic numeric type(T) and a number of dimensions(N).
    // The data can be stored in an array of type T and size N.
    template<typename T, int N>
    class Vector
    {
    public:
        Vector() = default;
        int dimen() const { return N;}
        T at(int ind) {return this->data[ind];}
        // Todo: Implement an operator[] overload for reading!
        const T& operator[](int ind) const{return this->data[ind];}

        // Todo: Implement an operator[] overload for read/write access!
        T& operator[](int ind){return this->data[ind];}
        // Todo: Implement a unary operator- overload that returns a copy with all components negated.
        
        // Todo: Implement an operator+ overload that takes a vector of same type and size.
        Vector operator+ (const Vector& c){
            Vector vec;
            for (int i = this->dimen(); i > 0; i--){
                vec[i-1] = this->at(i-1) + c.at(i-1);
            }
            return vec;
        }
        Vector operator- (const Vector& c){
            Vector vec;
            for (int i = this->dimen(); i > 0; i--){
                vec[i-1] = this->at(i-1) - c.at(i-1);
            }
            return vec;
        }
        Vector operator* (int c){
            Vector vec;
            for (int i = this->dimen(); i > 0; i--){
                vec[i-1] = this->at(i-1) * c;
            }
            return vec;
        }
        // Todo: Implement an operator- overload that takes a vector of same type and size.
    private:
        T data[N];
    };
	
    // Todo: Implement an operator* overload that takes a vector from the left and a scalar from the right side.
    // Returns a vector.
	
    // Todo: Implement a operator* overload that takes a vector from the right and a scalar from the left side.
    // Returns a vector.
}
