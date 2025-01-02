#include "pad.h"

#include <stdexcept>
#include <cstring>

template <typename T>
std::vector<uint8_t> pad(std::vector<uint8_t> message){
    if (message.size() == 0){
        throw std::invalid_argument("Message length must be greater than 0");
    }

    std::size_t t_size = sizeof(T);
    std::size_t desired_len = t_size * 16;
    std::size_t message_len = message.size();

    // Get size of pad by subtracting msg len, 1 byte for 0b1000_0000 and 8 or 16 bytes for length
    // Use mod desired_len to get the number of bytes to pad
    std::size_t pad_len = (desired_len - (message_len + 1 + (t_size * 2))) % desired_len;

    // Add 0b1000_0000
    message.push_back(0b1000'0000);

    // Add pad_len number of 0s
    for(std::size_t i = 0; i < pad_len; i++){
        message.push_back(0);
    }

    // Add length of message
    uint8_t len_bytes[t_size * 2] = {0};
    // Copy message_len to len_bytes, big endian format (most significant byte first)
    std:memcpy(len_bytes, &message_len, sizeof(message_len));

    // Add backwards to store MSB first
    for (std::size_t i = (t_size * 2); i > 0; i--){
        message.push_back(len_bytes[i - 1]);
    }

    return message;
};

template std::vector<uint8_t> pad<uint32_t>(std::vector<uint8_t> message);
template std::vector<uint8_t> pad<uint64_t>(std::vector<uint8_t> message);