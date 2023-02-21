int x[10], N;

int main() {
    int a[10], i, j;
    N = 10;
    
    for (i=0; i<N; i++) x[i] = i+1;
    for (j=1; j<=N; j++) {
        a[j-1] = 11-j;
    };

    for (i=0; i<N; i++) {
        if (a[i] == x[i+1]) println(i);
    };

    for (i=1; i<=N; i++) {
        println(a[i-1]);
    };

    for (j=0; j<N; j++) println(x[j]);

    return 0;
};
