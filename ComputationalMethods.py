#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jan  4 00:08:02 2022

@author: altayavci
"""

import numpy as np
import matplotlib.pyplot as plt 

#Linear Interpolation 

def linearInterpolation(vx,vxdata,vydata):
    h=vxdata[1]-vxdata[0]
    vy=np.zeros(vx.size,dtype=float)
    vslopes=(vydata[1:]-vydata[:vydata.size-1])/h
    for k in range(vx.size):
        n=int((vx[k]-vxdata[0])/h)
        vy[k]=vydata[n]+vslopes[n]*(vx[k]-vxdata[n])
        
    return vy

xdata=np.linspace(0,np.pi,10000)
h=xdata[1]-xdata[0]
ydata=np.cos(xdata)
x=np.random.random(10000)
x=x*np.pi
y=linearInterpolation(x,xdata,ydata)
error=np.abs(y-np.cos(x))

#Bisection Method

def bisection(f,a,b,tol=1.0e-08):
    fa=f(a)
    fb=f(b)
    n=0
    while n<50 and abs(b-a)>tol :
        n+=1
        q=(a+b)*0.5
        fq=f(q)
        if (fq==0):
                return q
        if (fq*fa<0.):
            b=q
            fb=fq
        else:
            if(fq*fb>0.):
                  print("no root!")
                  break
            else:
                  a=q
                  fa=fq
    print("N from bisection:",n)
    return q

A=2
B=1
g=9.8
m=1
v_0=1.5
h =1e-5

#Taking the first and second derivatives of the ellipse equation with the limit definition of the derivative.


def ellipse_equation(x):

        return B*np.sqrt(1-((x/A)**2))


def d_ellipse(x): #first derivative 

        return (ellipse_equation(x+h)-ellipse_equation(x-h))/(2*h)

def d_ellipse2(x): #second derivative

        return (d_ellipse(x+h)-d_ellipse(x-h))/(2*h)
    
    
    
#Numerical integration for the changing slopes. (euler method)    
    
class Lineer_interpolation:
    
    def __init__(self,xdata_,ydata_):
        
        self.xdata_=xdata
        self.ydata_=ydata
        self.slopes=(self.ydata_[1:]-self.ydata_[:self.ydata_.size-1])
        self.slopes/=(self.xdata_[1:]-self.xdata_[:self.xdata_.size-1])
        
        
        
        def integration(self,a,b):
            
            for k in range(self.xdata_.size-1):
                if ((a-self.xdata_[k])*(a-self.xdata_[k+1])<0.):
                    index1=k
                elif ((b-self.xdata_[k])*(b-self.xdata_[k+1])<0.):
                    index2=k
                    
            sum_=0   
            operation1=.5*(self.xdata_[index1+1]-a)*(self.interpolated(a)+self.ydata_[index1+1])
            operation2=.5*(b-self.xdata_[index2])*(self.interpolated(b)+self.ydata_[index2])
                
            for j in range((index2-index1)-1):
               sum_+=.5*(self.xdata_[index1+2+j]-self.xdata_[index1+1+j])*(self.ydata_[index1+1+j]+self.ydata_[index1+2+j])
               
            return operation1+operation2+sum_