#ifndef TEST_WORD_H
#define TEST_WORD_H

#include <iostream>
#include "word.h"

using namespace type;

class TestWord{
    public:
        template<typename T>
        T get_val(Word<T>& word) const{
            return word.get();
        }
};

#endif