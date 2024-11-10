#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float f(float x) {
    return 10.0 * x * (5.0 - x);
}

int main() {
    int m, n;
    float c, h, k, r, U[10][10] = {0}, temp, e;

    cout<<"Enter the value of c: ";
    cin>>c;
    cout<<"Enter the value of h: ";
    cin>>h;
    cout<<"Enter the value of k: ";
    cin>>k;
    cout<<"Enter the value of m: ";
    cin>>m;
    cout<<"Enter the value of n: ";
    cin>>n;


    
    for (int j = 0; j <= m; j++) {
        U[0][j] = 0.00;
        U[n][j] = 0.00;
    }

    for (int i = 1; i < n; i++) {
        U[i][0] = f(i * h);
    }

    r = (k * c * c) / (h * h);

    for (int j = 0; j < m; j++) {
        bool flag = true;
        while (flag == true) {
            flag = false;
            
            for (int i = 1; i < n; i++) {
                temp = U[i][j + 1];
                U[i][j + 1] = (1 / (1 + 2 * r)) * (r * (U[i + 1][j + 1] + U[i - 1][j + 1]) + U[i][j]);
                
                e = abs(temp - U[i][j + 1]); 
                if (e > 0.001) {
                    flag = true;
                }
            }
        }
    }
    
    cout << "The solutions are: " << endl;
    cout << fixed << setprecision(2) << endl;
    for (int j = 0; j <= m; j++) {
        for (int i = 0; i <= n; i++) {
            cout << U[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;
}


************************************************OUTPUT*************************************************

// Enter the value of c: 1
// Enter the value of h: 1.0
// Enter the value of k: 0.5
// Enter the value of m: 6
// Enter the value of n: 6
// The solutions are:

// 0.00 40.00 60.00 60.00 40.00 0.00 0.00
// 0.00 32.77 51.08 51.54 35.08 8.77 0.00 
// 0.00 27.26 43.50 44.59 31.77 12.33 0.00
// 0.00 22.93 37.19 38.82 28.94 13.40 0.00 
// 0.00 19.45 31.95 33.97 26.28 13.27 0.00
// 0.00 16.62 27.58 29.81 23.73 12.57 0.00 
// 0.00 14.29 23.92 26.22 21.33 11.62 0.00
