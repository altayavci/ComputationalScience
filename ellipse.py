#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Feb 21 13:32:02 2022

@author: altayavci
"""

import numpy as np 
import matplotlib.pyplot as plt 
from math import atanh,tanh,cosh,sinh

A=1

eps0=atanh(0.5)

B=A*tanh(eps0)

c=A/cosh(eps0)

#ellipse equations coeffs


vTheta=np.linspace(0,2*np.pi,1000,False)

vx=c*cosh(eps0)*np.cos(vTheta)

vy=c*sinh(eps0)*np.sin(vTheta)

vTx=-cosh(eps0)*np.cos(vTheta)

vTy=sinh(eps0)*np.cos(vTheta)

#these are the initial conditions from the ellipse equation


vNorm=np.sqrt(vTx*vTx+vTx*vTy)

vTx=vTx/vNorm

vTy=vTy/vNorm 

#for the clear results, normalize the vector 


vDs=np.zeros(vx.size,dtype=float)

vDs[:vx.size-1]=np.array(((vx[1:]-vx[:vx.size-1])**2+(vy[1:]-vy[:vy.size-1])**2)**0.5)

vDs[vx.size-1]=vDs[vx.size-2]

#array of distances between points in the x and y components


rVx=np.array(vx)

rVx[:vx.size-1]=vx[1:]

rVx[vx.size-1]=vx[0]

#distance from the point to th right of the x component


rVy=np.array(vy)

rVy[:vy.size-1]=vy[1:]

rVy[vy.size-1]=vy[0]

#distance from the point to the right of the y component


lVx=np.array(vx)

lVx[1:]=vx[:vx.size-1]

lVx[0]=vx[vx.size-1]

#distance from the point to the left of the x component


lVy=np.array(vy)

lVy[1:]=vy[:vy.size-1]

lVy[0]=vy[vy.size-1]

#distance from the point to the left of the y component


N=np.zeros((vx.size,2),dtype=float)

N[:,0]=(rVx-lVx)/(2*vDs)

N[:,1]=(rVy-lVy)/(2*vDs)

curvature=np.sqrt(N[:,0]**2+N[:,1]**2)

#calculated curvature


fig, ((ax1)) = plt.subplots(1,1)
ax1.plot(N[:,0],N[:,1],color="blue")
ax1.set_xlabel("x",fontsize=10,x=1,y=1)
ax1.set_ylabel("y",fontsize=10,x=0,y=0)
 

ax = plt.gca()
ax.spines['top'].set_color('none')
ax.spines['bottom'].set_position('zero')
ax.spines['left'].set_position('zero')
ax.spines['right'].set_color('none')

#To visualize the Cartesian coordinate system

















