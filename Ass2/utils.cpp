#include "utils.hpp"

// Is the given array a valid permutation?
// This means that every number in [0,count-1] appears exactly once.
bool isPermutation(int* perm, int count)
{
    for (int i=0; i<count; i++) {
        for (int j=i+1; j<count; j++) {
            if (perm[i] == perm[j]) {
                return false;
            }
        }
    }
    return true;
}

// Checks whether data reordered using perm
// as indicies would be in ascending order.
// Does not change any of the input arrays.
bool isSorted(double* data, int dataCount, int* perm)
{
    for (int i=0; i<dataCount-1; i++) {
        if (data[i] > data[i+1]) {
            if (perm[i] <= perm[i+1]) {
                return false;
            }
        }
    }
    return true;
}