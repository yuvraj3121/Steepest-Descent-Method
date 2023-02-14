#include<bits/stdc++.h>
using namespace std;

void fx(double x1, double x2,double y){
    y = 4*pow(x1,2) + pow(x2,2) - 3*x1*x2 + 6*x1 + 12*x2;
    cout<<y<<endl<<endl;
}

void dfx(double x[2], double s[2]){
    s[0] = -(8*x[0] - 3*x[1] + 6);
    s[1] = -(2*x[1] - 3*x[0] + 12);
}

int main(){
    double x[2]={0,0};
    int i=1;
    while (true)
    {
        cout<<"iteration "<<i<<" :"<<endl;
        double s[2],y;
        dfx(x,s);
        cout<<"S"<<i<<" : "<<"{"<<s[0]<<" "<<s[1]<<"}"<<endl;
        double h,a,b;
        a=(4*s[0]*s[0])+(s[1]*s[1])-(3*s[0]*s[1]);
        b=(8*s[0]*x[0])+(2*s[1]*x[1])-(3*(s[0]*x[1]+s[1]*x[0]))+6*s[0]+12*s[1];
        h=-b/(2*a);
        cout<<"lambda"<<i<<" : "<<h<<endl<<"X"<<i+1<<" : ";
        for (int i = 0; i < 2; i++)
        {
            x[i]=x[i]+h*s[i];
            cout<<x[i]<<" ";
        }
        cout<<endl<<"fx"<<i+1<<" : ";
        fx(x[0],x[1],y);
        i++;
        if(abs(s[0])<=0.001 && abs(s[1])<=0.001){
            cout<<"optimum points | Xopt : "<<"{"<<x[0]<<" , "<<x[1]<<"}"<<endl;
            cout<<"optimum solution | fopt : ";
            fx(x[0],x[1],y);
            break;
        }
    }
    return 0;
}