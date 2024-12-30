#ifndef BLOCK_H
#define BLOCK_H

#include <array>
#include <word.h>

namespace type{
    template<typename T>
    class Block{
        protected:
            std::array<Word<T>, 16> words;

        public:
            Block(): words({}) {}
            Block(std::array<Word<T>, 16> new_words): words(new_words) {}
            virtual ~Block() = default;

            Word<T> operator[](uint32_t i) const { return words[i]; }

            friend class TestBlock;
    };
};
#endif