#pragma once

#include "Person.h"

#define MAX 1000

struct Addressbooks{ 
    Addressbooks() : size_(0)
    {}

    struct Person personArray[MAX];
    int size_;
};