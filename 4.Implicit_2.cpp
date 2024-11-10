#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float f(float x) {
    return ((x * (8.0 - x)) / 2.0);
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


*******************************************OUTPUT**********************************

// Enter the value of c: 2
// Enter the value of h: 1
// Enter the value of k: 0.125
// Enter the value of m: 5
// Enter the value of n: 8
// The solutions are:

// 0.00 3.50 6.00 7.50 8.00 7.50 6.00 3.50 0.00 
// 0.00 3.13 5.54 7.01 7.51 7.01 5.54 3.13 0.00
// 0.00 2.85 5.11 6.54 7.02 6.54 5.11 2.85 0.00 
// 0.00 2.61 4.73 6.09 6.56 6.09 4.73 2.61 0.00
// 0.00 2.40 4.38 5.67 6.11 5.67 4.38 2.40 0.00 
// 0.00 2.21 4.06 5.27 5.69 5.27 4.06 2.22 0.00
