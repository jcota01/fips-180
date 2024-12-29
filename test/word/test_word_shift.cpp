#include <catch2/catch_test_macros.hpp>
#include "test_word.h"

TEST_CASE("Word Bit Shift", "[Word]"){
    TestWord t;

    SECTION("32 Bit Word"){
        SECTION("Left Rotate"){
            Word w = Word<uint32_t>(0xEE000000);
            Word res = w.left_rotate(3);

            uint32_t v = t.get_val(res);

            CHECK(v == 0x70000007);
        }

        SECTION("Right Rotate"){
            Word w = Word<uint32_t>(0x000000EE);
            Word res = w.right_rotate(3);

            uint32_t v = t.get_val(res);

            CHECK(v == 0xC000001D);
        }
    }

    SECTION("64 Bit Word"){
        SECTION("Left Rotate"){
            Word w = Word<uint64_t>(0xEE00000000000000);
            Word res = w.left_rotate(3);

            uint64_t v = t.get_val(res);

            CHECK(v == 0x7000000000000007);
        }

        SECTION("Right Rotate"){
            Word w = Word<uint64_t>(0x00000000000000EE);
            Word res = w.right_rotate(3);

            uint64_t v = t.get_val(res);

            CHECK(v == 0xC00000000000001D);
        }
    }
}