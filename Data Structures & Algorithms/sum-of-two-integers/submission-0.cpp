class Solution {
public:
    int getSum(int a, int b) {
        // Continue until there is no carry left
        while (b != 0) {

            // Find carry bits:
            // AND (&) identifies positions where both bits are 1.
            // Shift left because a carry affects the next higher bit.
            unsigned int carry = (unsigned int)(a & b) << 1;

            // XOR (^) adds bits without considering carries.
            a = a ^ b;

            // Update b to be the carry for the next iteration.
            b = carry;
        }

        // When no carry remains, a contains the final sum.
        return a;
    }
};