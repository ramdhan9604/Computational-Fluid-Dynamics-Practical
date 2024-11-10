#include<iostream>
#include<iomanip>
using namespace std;
float x[10];

float *tridiagonal(float r, float d[],int n){
    int i;
    float a=-r/2,b=(1+r),c=-r/2;
    float alpha[10],beta[10];

    alpha[1]=b;
    beta[1]=d[1]/b;

    for(i=2;i<n;i++){
        alpha[i]=b-(a*c/alpha[i-1]);
        beta[i]=(d[i]-a*beta[i-1])/alpha[i];
    }
    x[n]=beta[n];
    for(i=n-1;i>=1;i--)
        x[i]=beta[i]-(c*x[i+1])/alpha[i];
    return x;
}

float f(float x){
	return 10 * x * (5 - x);
}
int main(){
    int i,j,n,m;
    float u[100][100],h=1,k=0.1,c=1,r;
    r = (k * c * c) / (h * h);
    m = 5;
    n = 5;

    cout<<"The value of Diffusion coefficient(r) is "<< r <<endl;

    for(j=0;j<=m;j++){
        u[0][j]=0;
        u[n][j]=0;
    }
    
    for(i=1;i<n;i++)
        u[i][0]=f(i*h);

    float d[n]={0};
    
    for(j=0;j<m;j++){
        for(i=1;i<n;i++)
            d[i]=(r/2)*u[i+1][j]+(1-r)*u[i][j]+(r/2)*u[i-1][j];
        float *y=tridiagonal(r,d,n);
        for(i=1;i<n;i++)
            u[i][j+1]=y[i];
    }
    
    cout<<"The value of all u(i,j): \n";
    cout<<fixed<<setprecision(2);
    for(j=m;j>=0;j--){
        for(i=0;i<=n;i++)
           cout<<"\t"<<u[i][j];
       cout<<endl;
    }
}

*********************************************OUTPUT********************************

// The value of Diffusion coefficient(r) is 0.1
// The value of all u(i,j):
//         0.00    31.87   50.30   50.30   31.87   0.00
//         0.00    33.26   52.16   52.16   33.26   0.00
//         0.00    34.74   54.07   54.07   34.74   0.00
//         0.00    36.35   56.02   56.02   36.35   0.00
//         0.00    38.09   58.00   58.00   38.09   0.00
//         0.00    40.00   60.00   60.00   40.00   0.00
