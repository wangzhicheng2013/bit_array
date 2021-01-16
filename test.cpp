#include "bit_array.hpp"
int main() {
    bit_array<>ba;
    for (int i = 0;i < 2953;i++) {
        if (!ba.add_num(i)) {
            std::cout << i << std::endl;
        }
    }
    for (int L = 0;L < 100000;L++) {    // 2.33s
        for (int i = 0;i < 2953;i++) {
            if (!ba.num_is_in(i)) {
                std::cout << i << std::endl;
            }
        }
    }

    return 0;
}