//
//  main.cpp
//  TermProject
//
//  Created by Altay Avcı on 16.12.2021.
//


//Altay Avcı
//090200704


//This code is the term project of the symbolic and numerical techniques course I took this semester. This code includes Simpson's method, Euler's method and Trapezoidal method. These three methods are methods of finding the numerical integral area of the desired curve and region.

#include <iostream>
#include <math.h>
#include <fstream>
#include <valarray>
#define pi 3.14158
#define d1valarray valarray <double>
#define g 9.80665 // m/s^2
#define lambdaAA 0.000121 //1/year

using namespace std;


//Problem-1

/* In the problem, we are asked to find the half-life of the Carbon-14 atom. We need to find out when the carbon-14 atom will radiate and the number of nuclei present will be halved after a period of time. We determine the half-life of the element with the difference between the theoretical result(N0/2) and our result, which should be lower than the 10^-6. Afterward, we need to find the number of nuclei in the half-life of the Carbon-14 atom with the Euler method. Afterward, we should test this situation with different numbers of nuclei to show that the half-life is constant.
 */



double Euler(double x_0 ,double N0,double N,double&res) {
    
    /* Thanks to the Euler method, we find how many nuclei remain in the Carbon-14 atom, which reaches the half-life time, with the pointer we assign to the function. We also determine the half-life by returning the function to half-life.
     */

    valarray <double> yValarray(N+1),xValarray(N+1); //y is for the value of the remaining nucleis; x is for the half-time.
    
    double halfLife = 0.; //for the clean coding firstly, halfLife has to be initialzing.
    
    double h =1.; //step (one year)
    
    xValarray[0] = x_0; //initial boundry condition
    
    yValarray[0] = N0; //initial number of nuclei
    
    for (int k = 0; k < N+1; k++) { //euler method application
        
        xValarray[k] = x_0+ ((k * h));
        
        yValarray[k+1] = yValarray[k] -h*yValarray[k]*lambdaAA; // N(t)*-lambdaAA
        
        
        if (yValarray[k+1]-N0/2.< pow(10,-6)) {
            
            halfLife=xValarray[k]; //year
            
            res=yValarray[k];    //nuclei
            
            break;
            
            return halfLife; //year
        }
        
        }
    return halfLife; //year
    
}



//Reference: https://www.calculator.net/half-life-calculator.html

//************************************************************************


//Problem-2

/*  In this problem we are asked to find the period of an oscillating oscillator. The formula used to find the period of oscillators that oscillate at small angles is different from the one used for those that do not oscillate at small angles. We calculate the periods of oscillators that do not oscillate at small angles with the Trapezoidal and Simpson's methods and call these values the exact period values. The calculated period of oscillators oscillating at small angles is also called approximation. If the absolute value of the difference between the approximate value and the exact value is not greater than 0.01, we increase the thetaZero value by 0.05 to make the error difference greater than 0.01. In this way, we examine the periods of the oscillators by comparing them.
 */


double L=4; //meters

double thetaZeroAA=0.05; //degree

double Tapprox() {
    
    //This function calculates the period of the oscillator approximately.
    
    return 2*pi*sqrt(L/g); //second
    
}

double myfuncAA(double z,double thetaZero) {
    
    /* This function is for finding the periods of oscillators that do not oscillate at small angles.
     */
    
    return  4*sqrt(L/g)*(1/sqrt(1-pow(sin(thetaZero/2),2)*pow(sin(z),2)));
    
}



void trapezoidalAA (double x_0, double x_n,double&res) {
    
    /* Thanks to the trapezoidal method, we can calculate the area under the curve of the myfuncAA function. As a result, we find the period of the oscillating oscillator in this function.
     */
    
    double N=10000.; //number of gap
    
    double sum=0.;
    
    double h= (x_n-x_0)/N; //step
    
    for (int i=1;i<N;i++) { //trapezoidal rule application
        
        sum+=myfuncAA(x_0+(i*h),thetaZeroAA);
        
    }
    
    res=(((myfuncAA(x_0,thetaZeroAA)+myfuncAA(x_n,thetaZeroAA)/2.)) +sum )*h; //second
    
    
}

double simpsonAA (double x_0,double x_n) {
    
    /* Thanks to Simpson's rule, we can find the area under the curve of the myfuncAA function.As a result, we find the period of the oscillating oscillator in this function.
     */
    
    double N=10000.; //number of gap
    
    double h=(x_n-x_0)/N; //step
    
    double sumForCoeff2=0.; //due to Simpson's Rule, some functions have coefficient of 2
    
    double sumForCoeff4=0.; //due to Simpson's Rule, some functions have coefficient of 4
    
    valarray <double> n(N); //valarray of the variables (xi)
    
    for (int k=1;k<n.size();k++){
        
        n[k]=x_0+(k*h);
    }
    
    for (int j=0;j<n.size();j++) { //simpson's rule application
        
        if (j %2 != 0) {
            
            sumForCoeff2+=2*myfuncAA(n[j],thetaZeroAA);
        }
        
        else if (j %2 ==0) {
            
            sumForCoeff4+=4*myfuncAA(n[j],thetaZeroAA);
        }
    }
    
    return (sumForCoeff4+sumForCoeff2+myfuncAA(x_0,thetaZeroAA)+myfuncAA(x_n,thetaZeroAA))*h/3.; //second
    

        
    }



//Reference: https://slidetodoc.com/numerical-integration-in-general-a-numerical-integration-is/

//************************************************************************

int main(int argc, const char * argv[]) {
    
    
    cout<<"PROBLEM-1"<<"\n"<<endl;
    
    double result;
    
    cout<<"Half life is for N0=10 :"<<Euler(0, 10., 10000, result)<<" year"<<endl;

    cout<<"At the half life,for N0=10 Carbon-14 has : "<<result<<" nuclei"<<"\n"<<endl;

    cout<<"Half life is for N0=100 :"<<Euler(0, 100., 10000, result)<<" year"<<endl;

    cout<<"At the half life,for N0=100 Carbon-14 has : "<<result<<" nuclei"<<"\n"<<endl;

    cout<<"Half life is for N0=1000 :"<<Euler(0, 1000., 10000, result)<<" year"<<endl;

    cout<<"At the half life,for N0=1000 Carbon-14 has : "<<result<<" nuclei"<<"\n"<<endl;

    cout<<"Half life is for N0=10000 :"<<Euler(0, 10000., 10000, result)<<" year"<<endl;

    cout<<"At the half life,for N0=10000 Carbon-14 has : "<<result<<" nuclei"<<"\n"<<endl;

    cout<<"************************************************************************"<<"\n"<<endl;
    
    cout<<"PROBLEM-2"<<"\n"<<endl;
    
    
    
    while (true) {

        double Texacttrapezoidal,Texactsimpson,Tapprox_;

        trapezoidalAA(0., pi/2., Texacttrapezoidal);

        Texactsimpson=simpsonAA(0.,pi/2.);

        Tapprox_=Tapprox();

        if (abs(Tapprox_-Texactsimpson) >0.01) {

            cout<<"ThetaZero : "<<thetaZeroAA<<" degree"<<endl;

            cout<<"Difference is :"<<abs(Tapprox_-Texactsimpson)<<" second"<<"\n"<<endl;

            cout<<"Period by Exact Trapeziodal Rule is : "<<Texacttrapezoidal<<" second"<<endl;

            cout<<"Period by Exact Simpson's Rule is : "<<Texactsimpson<<" second"<<endl;

            cout<<"Approx period value is : "<<Tapprox_<<" second"<<endl;


            break;


        }


        else {

            cout<<"ThetaZero : "<<thetaZeroAA<<" degree"<<endl;

            cout<<"Difference is :"<<abs(Tapprox_-Texactsimpson)<<" second"<<"\n"<<endl;

            thetaZeroAA += 0.05;

        }

    }
    
    return 0;
}
