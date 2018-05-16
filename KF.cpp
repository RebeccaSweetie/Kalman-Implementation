#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>

using namespace std;
int main() {
    double x = 23.5;//真实值
    int num = 10;
    double Q = 0.25;//过程方差
    double R = 0.03;//测量方差
    double xhy[num];
    double xxy[num];
    double phy[num];
    double pxy[num];
    double z[num];
    double Kg[num];

    for(int i = 0; i<num; i++){
        z[i] = x+sqrt(Q)*random();//100次测量值，包括了白噪声
    }

    //初始预测
    xhy[0] = xxy[0] = 23.5;
    pxy[0] = 1;

    //自回归预测
    for (int i=1; i<num; i++){
        xxy[i] = xxy[i-1];//1
        pxy[i] = pxy[i-1]+Q;//2
        Kg[i] = pxy[i]/(pxy[i]+R);//3
        xhy[i] = xxy[i]+Kg[i]*(z[i]-xxy[i]);
        phy[i] = (1-Kg[i])*pxy[i];
        cout<<xhy[i]<<endl;
    }

}