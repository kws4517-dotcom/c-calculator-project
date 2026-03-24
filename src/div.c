#include "calc.h"

int divide(int a, int b, int *result) {
    if (b == 0) {
        return 0;
    }
    *result = a / b;
    return 1;
}

