/**
 * @file references.hpp
 * @brief Declaration of arraytype and reference type objects
 */

#ifndef _REFERENCES_HPP
#define _REFERENCES_HPP

#include "types.hpp"
#include <vector>

using namespace std;

struct array_t
{
    int type;
    u4 max_size;
    vector<void*> items;

    array_t(u4 max_size) : max_size(max_size) {};
    void insert(u4 index);
    void* operator[](u4 index) { return items[index]; }
};

#endif // _REFERENCES_HPP