int main() {
    int x[5], i;

    for (i=0; i<5; i++) x[i] = i+1;
    for (i=5; i>0; i--) println(x[i-1]);

    return 0;
}
