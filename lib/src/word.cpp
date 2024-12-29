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

template<typename T>
Word<T> Word<T>::operator>>(uint32_t n) const{
    T result = this->get() >> n;
    return Word<T>(result);
}

template<typename T>
Word<T> Word<T>::left_rotate(uint32_t n) const{
    T result = (this->get() << n) | (this->get() >> (sizeof(T) * 8 - n));
    return Word<T>(result);
}

template<typename T>
Word<T> Word<T>::right_rotate(uint32_t n) const{
    T result = (this->get() >> n) | (this->get() << (sizeof(T) * 8 - n));
    return Word<T>(result);
}