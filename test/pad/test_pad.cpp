#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <algorithm>
#include "pad.h"

template <typename T>
std::size_t get_data_len(std::vector<uint8_t> message){
    std::size_t len_buffer_size = sizeof(T) * 2;
    std::vector<uint8_t> len_buffer;

    for (std::size_t i = 0; i < len_buffer_size; i++){
        // offset iterator by i 
        std::size_t offset = message.size() - len_buffer_size + i;
        len_buffer.push_back(message[offset]);
    }

    std::reverse(len_buffer.begin(), len_buffer.end());
    std::size_t data_len = 0;
    std::memcpy(&data_len, len_buffer.data(), sizeof(data_len));

    return data_len;
}

TEST_CASE("Pad", "[Pad]"){
    SECTION("Pad 32 bit message"){
        SECTION("Message Length is 0"){
            std::vector<uint8_t> message;
            CHECK_THROWS_AS(pad<uint32_t>(message), std::invalid_argument);
        }

        SECTION("Message Length is < 512 bits"){
            std::vector<uint8_t> message(16, 0);
            message = pad<uint32_t>(message);

            CHECK(message.size() == 64);
            CHECK(get_data_len<uint32_t>(message) == 16);
        }

        SECTION("Message Length is 512 bits"){
            // Message length is 512 bits with 0b1000_000 and 64 bits for length
            std::vector<uint8_t> message(55, 0);
            message = pad<uint32_t>(message);

            std::cout << "Message: ";
            for (auto i : message){
                std::cout << std::hex << (int)i << " ";
            }
            std::cout << std::endl;

            CHECK(message.size() == 64);
            CHECK(get_data_len<uint32_t>(message) == 55);
        }

        SECTION("Message Length is > 512 bits"){
            // Message length is 512 bits not including 0b1000_000 and 64 bits for length
            std::vector<uint8_t> message(64, 0);
            message = pad<uint32_t>(message);

            CHECK(message.size() == 128);
            CHECK(get_data_len<uint32_t>(message) == 64);
        }
    }

    SECTION("Pad 64 bit message"){
        SECTION("Message Length is 0"){
            std::vector<uint8_t> message;
            CHECK_THROWS_AS(pad<uint64_t>(message), std::invalid_argument);
        }

        SECTION("Message Length is < 1024 bits"){
            std::vector<uint8_t> message(32, 0);
            message = pad<uint64_t>(message);
            CHECK(message.size() == 128);
            CHECK(get_data_len<uint64_t>(message) == 32);
        }

        SECTION("Message Length is 1024 bits"){
            // Message length is 1024 bits with 0b1000_000 and 128 bits for length
            std::vector<uint8_t> message(111, 0);
            message = pad<uint64_t>(message);

            CHECK(message.size() == 128);
            CHECK(get_data_len<uint64_t>(message) == 111);
        }

        SECTION("Message Length is > 1024 bits"){
            // Message length is 1024 bits not including 0b1000_000 and 128 bits for length
            std::vector<uint8_t> message(128, 0);
            message = pad<uint64_t>(message);

            CHECK(message.size() == 256);
            CHECK(get_data_len<uint64_t>(message) == 128);
        }
    }
}