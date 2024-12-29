#include <catch2/catch_test_macros.hpp>
#include "test_word.h"

TEST_CASE("Word Operations", "[Word]"){
    SECTION("32 bit word"){
        uint32_t v1 = 0x01020304;
        uint32_t v2 = 0xFF030201;

        Word w1 = Word<uint32_t>(v1);
        Word w2 = Word<uint32_t>(v2);
        TestWord t;

        SECTION("Modulo Addition"){
            Word w3 = w1 + w2;
            uint32_t v = t.get_val(w3);

            CHECK(v == 0x00050505);
        }

        SECTION("Bitwise OR"){
            Word w3 = w1 | w2;
            uint32_t v = t.get_val(w3);

            uint32_t expected = v1 | v2;
            CHECK(v == expected);
        }

        SECTION("Bitwise AND"){
            Word w3 = w1 & w2;
            uint32_t v = t.get_val(w3);

            uint32_t expected = v1 & v2;
            CHECK(v == expected);
        }

        SECTION("Bitwise XOR"){
            Word w3 = w1 ^ w2;
            uint32_t v = t.get_val(w3);

            uint32_t expected = v1 ^ v2;
            CHECK(v == expected);
        }

        SECTION("Bitwise NOT"){
            Word w3 = ~w1;
            uint32_t v = t.get_val(w3);

            uint32_t expected = ~v1;
            CHECK(v == expected);
        }
    }

    SECTION("64 bit word"){
        uint64_t v1 = 0x0201020500010205;
        uint64_t v2 = 0xFF01020500010205;

        Word w1 = Word<uint64_t>(v1);
        Word w2 = Word<uint64_t>(v2);
        TestWord t;

        SECTION("Modulo Addition"){
            Word w3 = w1 + w2;
            uint64_t v = t.get_val(w3);
            
            CHECK(v == 0x0102040A0002040A);
        }

        SECTION("Bitwise OR"){
            Word w3 = w1 | w2;
            uint64_t v = t.get_val(w3);

            uint64_t expected = v1 | v2;
            CHECK(v == expected);
        }

        SECTION("Bitwise AND"){
            Word w3 = w1 & w2;
            uint64_t v = t.get_val(w3);

            uint64_t expected = v1 & v2;
            CHECK(v == expected);
        }

        SECTION("Bitwise XOR"){
            Word w3 = w1 ^ w2;
            uint64_t v = t.get_val(w3);

            uint64_t expected = v1 ^ v2;
            CHECK(v == expected);
        }

        SECTION("Bitwise NOT"){
            Word w3 = ~w1;
            uint64_t v = t.get_val(w3);

            uint64_t expected = ~v1;
            CHECK(v == expected);
        }
    }
}