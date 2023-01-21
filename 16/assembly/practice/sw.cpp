#include <iostream> 
using namespace std;

int main() {
    int i, j, n;
    cin >> n;
    if (n%2 == 0) n++;
    
    for (i=0; i<n/2; i++) {
        cout << "[]";
        for (j=1; j<n/2; j++) {
            if (j == 0) cout << "[]";
            else cout << "  ";
        };

        if (i==0) cout << "[]";
        else cout << "[]";

        for (j=n/2+1; j<n; j++) { 
            if (i == 0) cout << "[]";
            else cout << "  ";
        };
        cout << endl;
    };
    
    for (j=0; j<n; j++) cout << "[]";
    cout << endl;

    for (i=n/2+1; i<n; i++) {
        for (j=0; j<n/2; j++) {
            if (i == n-1) cout << "[]";
            else cout << "  ";
        };

        if (i==n-1) cout << "[]";
        else cout << "[]";

        for (j=n/2+1; j<n-1; j++) { 
            cout << "  ";
        };
        cout << "[]";
        cout << endl;
    };

    cout << endl;
};