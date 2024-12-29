#include "word.h"

using namespace type;

template<typename T>
Word<T> Word<T>::operator+(const Word<T>& rhs) const{
    T result = this->get() + rhs.get();
    return Word<T>(result);
}

template<typename T>
Word<T> Word<T>::operator|(const Word<T>& rhs) const{
    T result = this->get() | rhs.get();
    return Word<T>(result);
}

template<typename T>
Word<T> Word<T>::operator&(const Word<T>& rhs) const{
    T result = this->get() & rhs.get();
    return Word<T>(result);
}

template<typename T>
Word<T> Word<T>::operator^(const Word<T>& rhs) const{
    T result = this->get() ^ rhs.get();
    return Word<T>(result);
}

template<typename T>
Word<T> Word<T>::operator~() const{
    T result = ~this->get();
    return Word<T>(result);
}