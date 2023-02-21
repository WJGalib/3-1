int X[10];

int get_transpose (int i) {
    if (X[9-i] == 0) return X[6-i];
    if (i==3 || i==4) return X[i];
    return X[9-i];
}


int factorial(int n) {
    if(n==1) return n;
    int k;
    k = n * factorial(n-1);
    return k;
}



int main() {
    int x, i;

    // for (i=0; i<10; i++) X[i] = (i+1)*5;

    x = factorial (7);
    println(x);

    // x = get_transpose (2);
    // println(x);

    return 0;
};