# -*- coding: utf-8 -*-


import numpy as np
from math import pi,cos,sin,tan
import matplotlib.pyplot as plt



at=np.linspace(0.,3.,1001)
g=9.8
v0=10.0# initial speed
theta=pi/3.# initial launch angle (with x axis)
beta=pi/4.
slope=tan(beta)
v_in=v0*np.array([cos(theta),sin(theta)])

#np.array([cos(theta),sin(theta)]) is the unit vector in the direction of 
#initial velocity
vx_in=v_in[0]
vy_in=v_in[1]

cos_=cos(beta)
sin_=sin(beta)
tangent=np.array([cos_,sin_])
normal=np.array([-sin_,cos_])

#accelaration for the x and y axis 

ax=np.zeros(at.size,dtype=float)
ay=np.zeros(at.size,dtype=float)
avx=np.zeros(at.size,dtype=float)
avy=np.zeros(at.size,dtype=float)


x_in=0.0
y_in=0.0
ax[0]=x_in
ay[0]=y_in
avx[0]=vx_in
avy[0]=vy_in
t_in=0.0

for k in range(1,at.size):
    ax[k]=x_in+vx_in*(at[k]-t_in)
    ay[k]=y_in+vy_in*(at[k]-t_in)-0.5*g *(at[k]-t_in)**2
    avx[k]=vx_in
    avy[k]=vy_in-g*(at[k]-t_in)
    if( ay[k]<slope*ax[k]):
        t_in=at[k]
        x_in=ax[k]
        y_in=slope*ax[k]
        v_b=np.array([avx[k],avy[k]])# velocity just before the collision
        v_a=v_b-2.*np.dot(v_b,normal)*normal# velocity just after the collision   
        vx_in=v_a[0]
        vy_in=v_a[1]
plt.plot(at,ax,at,ay)
plt.show()


        

