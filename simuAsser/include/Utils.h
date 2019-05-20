#ifndef UTILS_H
#define UTILS_H

#define Swap(value1, value2)\
{\
    value1 = value1 ^ value2;\
    value2 = value1 ^ value2;\
    value1 = value1 ^ value2;\
}\

#endif