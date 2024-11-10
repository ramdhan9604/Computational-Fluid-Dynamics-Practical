#include <iostream>
#include<cmath>
using namespace std;

int main(){
    int i,j,n,iter,k;
    float u[10][10], u_new[10][10], f[10][10], x[10], y[10];
    float tolerance = 0.0001, h=1;
    cout<<"Enter no. of mesh points, no. of iterations : ";
    cin>>n>>iter;
    
    for(i=0; i<=n; i++){
        u[i][0] = 0;
        u[i][n] = 0;
    }
    for(j=1; j<n; j++){
        u[0][j] = 0;
        u[n][j] = 0;
    }

    // Define the x and y coordinates based on the grid spacing
    for (i = 0; i <= n; i++) {
        x[i] = i * h;
        y[i] = i * h;
    }

    // Initialize inner grid points to 0.0 and compute the source term f
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            u[i][j] = 0.0;  // Initial guess for interior points
            f[i][j] = -10 * (pow(x[i], 2) + pow(y[j], 2) + 10);  // Source term f(x, y)
        }
    }
    for(i=0; i<=n; i++)
        for(j=0; j<=n; j++)
            u_new[i][j] = u[i][j];

    // Start Gauss-Seidel iterations
    for (k = 1; k <= iter; k++) {
        float max_error = 0.0;

        for (i = 1; i < n; i++) {
            for (j = 1; j < n; j++) {
                if(i != j){
                    u_new[i][j] = 0.25 * (u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1] - (h*h) * f[i][j]);
                    max_error = max(max_error, fabs(u_new[i][j] - u[i][j]));
                }
            }
        }
        for (i = 1; i < n; i++) {
            for (j = 1; j < n; j++) {
                if(i == j){
                    u_new[i][j] = 0.25 * (u_new[i-1][j] + u_new[i+1][j] + u_new[i][j-1] + u_new[i][j+1] - (h*h) * f[i][j]);
                    max_error = max(max_error, fabs(u_new[i][j] - u[i][j]));
                }
            }
        }
        for (i = 1; i < n; i++)
            for (j = 1; j < n; j++)
                u[i][j] = u_new[i][j];  // Update the current grid point

        // Print the current solution
        cout << "\n\nIteration - " << k << ": \nThe Solution of Poisson Equation is-\n";
        for (j = n; j >= 0; j--) {  // Print from top row to bottom row
            for (i = 0; i <= n; i++) {
                cout << u[i][j] << "\t";
            }
            cout << endl;
        }

        // Check if the solution has converged
        if (max_error < tolerance) {
            cout << "\nConvergence achieved after " << k << " iterations.\n";
            break;
        }
    }
    return 0;
}


***************************************OUTPUT***********************************************

// Enter no. of mesh points, no. of iterations : 3
// 20


// Iteration - 1:
// The Solution of Poisson Equation is-
// 0       0       0       0
// 0       37.5    63.75   0
// 0       48.75   37.5    0
// 0       0       0       0


// Iteration - 2:
// The Solution of Poisson Equation is-
// 0       0       0       0
// 0       65.625  77.8125 0
// 0       62.8125 65.625  0
// 0       0       0       0


// Iteration - 3:
// The Solution of Poisson Equation is-
// 0       0       0       0
// 0       72.6562 81.3281 0
// 0       66.3281 72.6562 0
// 0       0       0       0


// Iteration - 4:
// The Solution of Poisson Equation is-
// 0       0       0       0
// 0       74.4141 82.207  0
// 0       67.207  74.4141 0
// 0       0       0       0


// Iteration - 5:
// The Solution of Poisson Equation is-
// 0       0       0       0
// 0       74.8535 82.4268 0
// 0       67.4268 74.8535 0
// 0       0       0       0


// Iteration - 6: 
// The Solution of Poisson Equation is-
// 0       0       0       0
// 0       74.9634 82.4817 0
// 0       67.4817 74.9634 0
// 0       0       0       0


// Iteration - 7:
// The Solution of Poisson Equation is-
// 0       0       0       0
// 0       74.9908 82.4954 0
// 0       67.4954 74.9908 0
// 0       0       0       0


// Iteration - 8:
// The Solution of Poisson Equation is-
// 0       0       0       0
// 0       74.9977 82.4989 0
// 0       67.4989 74.9977 0
// 0       0       0       0


// Iteration - 9:
// The Solution of Poisson Equation is-
// 0       0       0       0
// 0       74.9994 82.4997 0
// 0       67.4997 74.9994 0
// 0       0       0       0


// Iteration - 10:
// The Solution of Poisson Equation is-
// 0       0       0       0
// 0       74.9999 82.4999 0
// 0       67.4999 74.9999 0
// 0       0       0       0


// Iteration - 11:
// The Solution of Poisson Equation is-
// 0       0       0       0
// 0       75      82.5    0
// 0       67.5    75      0
// 0       0       0       0


// Iteration - 12:
// The Solution of Poisson Equation is-
// 0       0       0       0
// 0       75      82.5    0
// 0       67.5    75      0
// 0       0       0       0

// Convergence achieved after 12 iterations.
