#include <stdio.h>
#include <string.h>
#include <iostream>
static const short SHIFT = 3;
static const short MASK = 0x7;
template <size_t SIZE = 512>
class bit_array {
public:
    bit_array() {
        memset(array_, 0, sizeof(array_));
        max_num = 8 * SIZE;
    }
    virtual ~bit_array() {
    }
public:
    inline bool add_num(int num) {
        if (num < 0 || num > max_num) {
            return false;
        }
        array_[num >> SHIFT] |= (1 << (num & MASK));
        return true;
    }
    inline bool num_is_in(int num) {
        if (num < 0 || num > max_num) {
            return false;
        }
        return array_[num >> SHIFT] & (1 << (num & MASK));
    }
    inline bool clear_num(int num) {
        if (num < 0 || num > max_num) {
            return false;
        }
        array_[num >> SHIFT] &= ~(1 << (num & MASK));
        return true;
    }
private:
    char array_[SIZE];
    int max_num;
};