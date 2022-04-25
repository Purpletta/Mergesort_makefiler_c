#include "../include/functions.h"

int sum(int n) {
    int summary = 0;
    for (int j = 1; j != n; j++) {
        summary += j;
    }
    return summary;
}
