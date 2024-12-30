#include <catch2/catch_test_macros.hpp>
#include "block.h"
#include "../word/test_word.h"

TEST_CASE("Block Access", "[Block]"){
    TestWord tw;

    SECTION("32 Bit Block"){
        std::array<Word<uint32_t>, 16> words;
        for(int i = 0; i < 16; i++){
            words[i] = Word<uint32_t>(i);
        }

        Block<uint32_t> b = Block<uint32_t>(words);

        for (int i = 0; i < 16; i++){
            Word<uint32_t> w = b[i];
            uint32_t v = tw.get_val(w);

            CHECK(v == i);
        }
        
    }

    SECTION("64 Bit Block"){
        std::array<Word<uint64_t>, 16> words;
        for(int i = 0; i < 16; i++){
            words[i] = Word<uint64_t>(i);
        }

        Block<uint64_t> b = Block<uint64_t>(words);

        for (int i = 0; i < 16; i++){
            Word<uint64_t> w = b[i];
            uint64_t v = tw.get_val(w);

            CHECK(v == i);
        }
    }
}