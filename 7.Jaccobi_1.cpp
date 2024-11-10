#include <iostream>
using namespace std;

int main(){
    int i,j,n,iter,k;
    float u[10][10], u_prev[10][10];
    cout<<"Enter no. of mesh points, no. of iterations : ";
    cin>>n>>iter;
    
    for(i=0; i<=n; i++){
        cout<<"Enter u("<<i<<",0): ";
        cin>>u[i][0];
    }
    for(i=0; i<=n; i++){
        cout<<"Enter u("<<i<<","<<n<<"): ";
        cin>>u[i][n];
    }
    for(j=1; j<n; j++){
        cout<<"Enter u(0,"<<j<<"): ";
        cin>>u[0][j];
    }
    for(j=1; j<n; j++){
        cout<<"Enter u("<<n<<","<<j<<"): ";
        cin>>u[n][j];
    }

    for(i=1; i<n; i++){
        for(j=1; j<n; j++){
            u[i][j] = 0;
        }
    }

    for(i = 0; i <= n; i++)
        for(j = 0; j <= n; j++)
            u_prev[i][j] = u[i][j];

    for(k=1;k<=iter;k++){
    	if(k==1){
    		u[1][2] = (u[0][3] + u[2][3] + u[0][1] + u[2][1]) / 4;
    		
            for(i=1;i<n;i++){
                for(j=n-1;j>0;j--){
            	    if(k==1 && i==1 && j==2)
            		    continue;
            	    else
                	    u[i][j] = (u[i-1][j] + u[i+1][j] + u[i][j-1] + u[i][j+1])/4;
                }
            }
        }
        else{
            for(i=1;i<n;i++)
                for(j=n-1;j>0;j--)
                	u[i][j] = (u_prev[i-1][j] + u_prev[i+1][j] + u_prev[i][j-1] + u_prev[i][j+1])/4;
        }
        for (i = 1; i < n; i++) 
            for (j = 1; j < n; j++) 
                u_prev[i][j] = u[i][j];

        printf("\n\nIteration - %d: \nThe Solution of Laplace Equation is-\n",k);
        for(j=n;j>=0;j--)
        {
            for(i=0;i<=n;i++)
            {
                cout<<u[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    return 0;
}


***********************************OUTPUT********************************
// Enter no. of mesh points, no. of iterations : 3
// 2
// Enter u(0,0): 1000
// Enter u(1,0): 500
// Enter u(2,0): 0
// Enter u(3,0): 0
// Enter u(0,3): 1000
// Enter u(1,3): 1000
// Enter u(2,3): 1000
// Enter u(3,3): 1000
// Enter u(0,1): 2000
// Enter u(0,2): 2000
// Enter u(3,1): 0
// Enter u(3,2): 500


// Iteration - 1:
// The Solution of Laplace Equation is-
// 1000    1000    1000    1000
// 2000    1000    625     500
// 2000    875     375     0
// 1000    500     0       0


// Iteration - 2:
// The Solution of Laplace Equation is-
// 1000    1000    1000    1000
// 2000    1125    718.75  500
// 2000    968.75  375     0
// 1000    500     0       0
