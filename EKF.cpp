//
// Created by slam on 18-5-16.
//
#include <cmath>
#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

int main(){


    //initial parameters
    double g = 9.8;
    double kx=0.01,ky=0.05;//阻尼系数
    int t = 15;//simulaition time
    int num = 100;//采样步数
    double T = t/num;//采样周期




    //status variables
    double x[num];
    double y[num];
    double vx[num];
    double vy[num];
    Matrix<float,num,4> status;
    status = [x,vx,y,vy];

    //measurement variables
    double r[num];
    double a[num];
    Matrix<float,num,2> mears;
    mears = [r,a];


    //first value of the status
//    x[0] = 0;
//    y[0] = 500;
//    vx[0] = 50;
//    vy[0] = 0;
    status[0]<<0,500,50,0;

    //EKF loop
    for (int i=1; i<num; i++){
        //状态量先验估计
        x[i] = x[i-1]+vx[i-1]*T;
        vx[i] = vx[i-1]-kx*pow(vx[i-1],2)*T;
        y[i]=y[i-1]+vy[i-1]*T;
        vy[i]=vy[i-1]+(ky*pow(vy[i-1],2)-g)*T;

        //观测值，这里用公式算观测值模拟从雷达读数据了
        r[i] = sqrt(pow(x[i-1],2)+pow(y[i-1],2));
        a[i] = atan(x[i-1]/y[i-1]);




    }


    return 0;
}
