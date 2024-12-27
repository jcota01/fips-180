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

            T get() const {
                return static_cast<T>(bytes);
            }


            friend class TestWord;
    };
}

#endif