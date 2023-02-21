#include "include.h"

int X[10];

int get_transpose (int i) {
    return X[9-i];
}

int main() {
    int x, i;

    for (i=0; i<10; i++) X[i] = (i+1)*5;

    x = get_transpose (2);
    println(x);

    return 0;
};