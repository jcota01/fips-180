#ifndef WORD_H
#define WORD_H

#include <array>
#include <cstdint>
#include <cstring>

namespace type {
    template<typename T>
    class Word{
        protected:
            uint64_t bytes;

        public:
            // Default constructor
            Word() : bytes(0) {}

            // Constructor with integer value
            Word(T val) : bytes(static_cast<uint64_t>(val)) {}

            // Constructor with array of bytes
            Word(std::array<uint8_t, sizeof(T)> new_bytes) : bytes(0) {
                for(int i = 0; i < sizeof(T); i++){
                    bytes |= static_cast<uint64_t>(new_bytes[i]) << ((sizeof(T) - 1 - i) * 8);
                }
            }

            virtual ~Word() = default;

            T get() const { return static_cast<T>(bytes); }

            // Modulo addition
            Word<T> operator+(const Word<T>& rhs) const;
            // Bitwise OR
            Word<T> operator|(const Word<T>& rhs) const;
            // Bitwise AND
            Word<T> operator&(const Word<T>& rhs) const;
            // Bitwise XOR
            Word<T> operator^(const Word<T>& rhs) const;
            // Bitwise NOT
            Word<T> operator~() const;
            // Right bit shift
            Word<T> operator>>(uint32_t n) const;

            Word<T> left_rotate(uint32_t n) const;
            Word<T> right_rotate(uint32_t n) const;

            friend class TestWord;
    };


    template class Word<uint32_t>;
    template class Word<uint64_t>;
}

#endif