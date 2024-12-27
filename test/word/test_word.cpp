#include <catch2/catch_test_macros.hpp>
#include "test_word.h"

TEST_CASE("Word class stores bytes correctly", "[Word]"){
    SECTION("32 bit word"){
        SECTION("From Integer"){
            Word w = Word<uint32_t>(0x00010205);
            TestWord t;

            uint32_t v = t.get_val(w);

            CHECK(v == 0x00010205);
        }

        SECTION("From Bytes"){
            std::array<uint8_t, 4> bytes = {0, 1, 2, 5};
            Word w = Word<uint32_t>(bytes);
            TestWord t;

            uint32_t v = t.get_val(w);

            CHECK(v == 0x00010205);
        }
    }

    SECTION("64 bit word"){
        SECTION("From Integer"){
            Word w = Word<uint64_t>(0x0001020500010205);
            TestWord t;

            uint64_t v = t.get_val(w);

            CHECK(v == 0x0001020500010205);
        }

        SECTION("From Bytes"){
            std::array<uint8_t, 8> bytes = {0, 1, 2, 5, 0, 1, 2, 5};
            Word w = Word<uint64_t>(bytes);
            TestWord t;
            
            uint64_t v = t.get_val(w);

            CHECK(v == 0x0001020500010205);
        }
    }
}