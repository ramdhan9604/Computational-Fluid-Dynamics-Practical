#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

float pi=3.14;

float f(float x){
    return sin(pi*x);
}

int main(){

    int m,n;
    float c,k,h,r,U[10][10]={0};

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
    

    for(int j=0;j<=m;j++){
        U[0][j]=0;
        U[n][j]=0;
    }

    for(int i=1;i<n;i++){
        U[i][0]=f(i*h);
    }
    
    r=(k*c*c)/(h*h);

    for(int j=0;j<m;j++){
        for(int i=1;i<n;i++){
            U[i][j+1]=(1-2*r)*U[i][j]+r*(U[i+1][j]+U[i-1][j]);
        }
    }

    cout<<"The solution are: "<<endl;
    cout<<fixed<<setprecision(2)<<endl;
    for(int j=0;j<=m;j++){
        for(int i=0;i<=n;i++){
            cout<<U[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;

}

****************************************OUTPUT*******************************************
// Enter the value of c: 1
// Enter the value of h: 0.2
// Enter the value of k: 0.02
// Enter the value of m: 3
// Enter the value of n: 5
// The solution are:

// 0.00 0.59 0.95 0.95 0.59 0.00
// 0.00 0.48 0.77 0.77 0.48 0.00
// 0.00 0.38 0.62 0.62 0.38 0.00
// 0.00 0.31 0.50 0.50 0.31 0.00
