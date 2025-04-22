#include <iostream>
#include <random>
using namespace std;
int Dice(int max_num) {
    int min = 1;
    int max = max_num;
    int dice;
    dice = rand() % (max - min + 1) + min;
    return dice;
}
int roll_dice(int Die_num) {
    srand(time(0));
    return Dice(Die_num);
}
int main() {
    cout<<roll_dice(20);
}