#include <iostream>
#include <cmath>
#include <iomanip> 

using namespace std;

float f(float x) {
    return 4 * x - (x * x) / 2;
}

int main() {
    float r, k, h, c, U[10][10] = {0};  
    int m, n;

    cout << "Enter the value of c: ";
    cin >> c;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << "Enter the value of h: ";
    cin >> h;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of cols: ";
    cin >> n;

    
    for (int i = 0; i <= m; i++) {
        U[0][i] = 0;
        U[n][i] = 0;
    }

    for (int j = 1; j < n; j++) {
        U[j][0] = f(j * h);
    }

    r = (k * c * c) / (h * h);

    
    for (int j = 0; j < m ; j++) {
        for (int i = 1; i < n; i++) {
            U[i][j + 1] = (1 - 2 * r) * U[i][j] + r * (U[i + 1][j] + U[i - 1][j]);
        }
    }

    
    cout << "The solution is: " << endl;
    cout << fixed << setprecision(2); 
    for (int j = 0; j <= m; j++) {
        for (int i = 0; i <= n; i++) {
            cout << U[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

***********************************OUTPUT***********************************
// Enter the value of c: 1
// Enter the value of k: 0.125
// Enter the value of h: 1
// Enter the number of rows: 5
// Enter the number of cols: 8
// The solution is:
// 0.00 3.50 6.00 7.50 8.00 7.50 6.00 3.50 0.00
// 0.00 3.38 5.88 7.38 7.88 7.38 5.88 3.38 0.00
// 0.00 3.27 5.75 7.25 7.75 7.25 5.75 3.27 0.00 
// 0.00 3.17 5.63 7.12 7.62 7.12 5.63 3.17 0.00
// 0.00 3.08 5.51 7.00 7.50 7.00 5.51 3.08 0.00 
// 0.00 3.00 5.39 6.88 7.38 6.88 5.39 3.00 0.00
