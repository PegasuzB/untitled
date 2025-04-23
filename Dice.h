#ifndef DICE_H
#include <cstdlib>
#define DICE_H
namespace Dice {
    inline int Dice(int max_num) {
        int min = 1;
        int max = max_num;
        int dice = rand() % (max - min + 1) + min;
        return dice;
    }

    inline int roll_dice(int Die_num) {
        srand(time(nullptr));
        return Dice(Die_num);
    }
}
#endif //DICE_H
