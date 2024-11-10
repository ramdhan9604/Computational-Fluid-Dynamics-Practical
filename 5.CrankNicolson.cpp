#include<iostream>
#include<cmath>
#include<iomanip>


using namespace std;

float x[10];


float *tridiagonal(float r,float d[],int n){
    int i;
    float a=-r/2,b=1+r,c=-r/2;
    float alpha[10],beta[10];

    alpha[1]=b;
    beta[1]=d[1]/b;

    for(int i=2;i<n;i++){
        alpha[i]=b-(a*c/alpha[i-1]);
        beta[i]=(d[i]-a*beta[i-1])/alpha[i];
    }

    x[n]=beta[n];

    for(i=n;i>0;i--){
        x[i]=beta[i]-(c*x[i+1])/alpha[i];
    }
    
    return x;
}

float f(float x){
    return (x*(16-x*x))/3.0;
}


int main(){
    int m,n;
    float U[100][100],h=1,k=0.1,c=1,r;
    r=(k*c*c)/(h*h);
    m=5;
    n=4;
    float d[n]={0};

    cout<<"The value of Diffusion coefficient(r) is"<<r<<endl;
    
    for(int j=0;j<=m;j++){
        U[0][j]=0;
        U[n][j]=0;
    }

    for(int i=1;i<n;i++){
        U[i][0]=f(i*h);
    }

    for(int j=0;j<m;j++){
        for(int i=1;i<n;i++){
            d[i]=(r/2)*U[i+1][j]+(1-r)*U[i][j]+(r/2)*U[i-1][j];
        }
        float *y=tridiagonal(r,d,n);
        for(int i=1;i<n;i++){
            U[i][j+1]=y[i];
        }
        
    }

    cout<<"The value of all u(i,j): "<<endl;
    cout<<fixed<<setprecision(2)<<endl;
    for(int j=m;j>=0;j--){
        for(int i=0;i<=n;i++){
            cout<<U[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

********************************************OUTPUT***************************************

// The value of Diffusion coefficient(r) is0.1
// The value of all u(i,j):

// 0.00 4.01 6.11 4.75 0.00
// 0.00 4.21 6.46 5.10 0.00 
// 0.00 4.40 6.83 5.50 0.00
// 0.00 4.60 7.21 5.94 0.00
// 0.00 4.80 7.60 6.44 0.00
// 0.00 5.00 8.00 7.00 0.00
