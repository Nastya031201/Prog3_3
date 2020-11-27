#include "Set.h"

using namespace prog3_3;
const char* msgs[] = { " [0] Exit",
                       " [1] Set + Set",   //объединение двух множеств
                       " [2] Set + char",  //добавление к множеству элементов
                       " [3] Set * Set",   //пересечение двух множеств
                       " [4] Set - Set",   //разность двух множеств
                       " [5] Set message in set1 and set2",
                       " [6] Get message in set1 and set2\n"


};

const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

int (*functions[])(Set&, Set&, Set&) = { nullptr, dialogSumm, dialogSummChar, dialogMultiplication, dialogSubtraction, dialogSetMessage, dialogGetArr };

int main() {
    try {
        Set S1("helLo"), S2(" bay_BAY"), S3;
        int rc;
        std::cout << S1 << S2 << S3;
        S3 = S1 + S2 + "w";
        std::cout << S3;
        while ((rc = dialog(msgs, NMsgs))) {
            if (!functions[rc](S1, S2, S3))
                break;
        }
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}