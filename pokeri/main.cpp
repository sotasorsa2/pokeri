#include <iostream>
#include <algorithm>

// Straight table initialization
bool straight_table[1 << 15] = {false};

void init_straight_table() {
    for (int i = 1; i <= 10; ++i) {
        int straight_mask = 0;
        for (int j = i; j < i + 5; ++j) {
            straight_mask |= 1 << j;
        }
        straight_table[straight_mask] = true;
    }
    straight_table[0b10000011111] = true;  // Ace special case
}

// Function to check if a hand is a straight using the straight table
bool is_straight(int hand[5]) {
    int hand_mask = 0;
    for (int i = 0; i < 5; ++i) {
        hand_mask |= 1 << hand[i];
    }
    return straight_table[hand_mask];
}

// Function to check if a hand is quads
bool is_quads(int hand[5]) {
    std::sort(hand, hand + 5);
    return (hand[0] == hand[1] && hand[1] == hand[2] && hand[2] == hand[3]) ||
           (hand[1] == hand[2] && hand[2] == hand[3] && hand[3] == hand[4]);
}

// Function to check if a hand is full house
bool is_fullhouse(int hand[5]) {
    std::sort(hand, hand + 5);
    return (hand[0] == hand[1] && hand[1] == hand[2] && hand[3] == hand[4]) ||
           (hand[0] == hand[1] && hand[2] == hand[3] && hand[3] == hand[4]);
}

int main() {
    init_straight_table();

    int straight_count = 0;
    int quads_count = 0;
    int fullhouse_count = 0;

    // Generate all possible 5-card hands
    int hand[5] = {0, 1, 2, 3, 4};
    do {
        if (is_straight(hand)) {
            ++straight_count;
        }
        if (is_quads(hand)) {
            ++quads_count;
        }
        if (is_fullhouse(hand)) {
            ++fullhouse_count;
        }
    } while (std::next_permutation(hand, hand + 5));

    std::cout << "Suorat: " << straight_count << std::endl;
    std::cout << "Neloset: " << quads_count << std::endl;
    std::cout << "Täyskädet: " << fullhouse_count << std::endl;

    return 0;
}
