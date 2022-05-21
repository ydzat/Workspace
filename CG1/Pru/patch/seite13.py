'''
Author: your name
Date: 2022-02-20 19:51:14
LastEditTime: 2022-02-21 02:45:06
LastEditors: Please set LastEditors
Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
FilePath: \Workspace\CG1\Pru\patch\seite13.py
'''
import sys
import numpy as np
import math
import fractions
import decimal
np.set_printoptions(formatter={'all':lambda x: str(fractions.Fraction(x).limit_denominator())})

class Ecke():
    def set(self, x,y):
        self.x = x
        self.y = y
    def set(self,x,y,z):
        self.x = x
        self.y = y
        self.z = z
    def setArray(self,x,y,z):
        return np.array([x,y,z,1])
        
    

class TransMatrix():
    # 2D旋转矩阵(逆时针旋转theta角度)
    def rotationM_negativ(self, theta):
        t = math.radians(theta)
        m = np.mat([
            [math.cos(t), -math.sin(t),0],
            [math.sin(t),math.cos(t),0],
            [0,0,1]
        ])
        return m
    
    # 2D旋转矩阵(顺时针旋转theta角度)
    def rotationM_positiv(self, theta):
        t = math.radians(theta)
        m = np.mat([
            [math.cos(t), math.sin(t),0],
            [-math.sin(t),math.cos(t),0],
            [0,0,1]
        ])
        return m

    # 3D旋转矩阵(右手螺旋，绕x)
    def rotationM_negativ_x(self, theta):
        t = math.radians(theta)
        m = np.mat([
            [1,0,0,0],
            [0,math.cos(t), -math.sin(t),0],
            [0,math.sin(t),math.cos(t),0],
            [0,0,0,1]
        ])
        return m
    
    # 3D旋转矩阵(右手螺旋，绕y)
    def rotationM_negativ_y(self, theta):
        t = math.radians(theta)
        m = np.mat([
            [math.cos(t),0, math.sin(t),0],
            [0,1,0,0],
            [-math.sin(t),0,math.cos(t),0],
            [0,0,0,1]
        ])
        return m

    # 3D旋转矩阵(右手螺旋，绕z)
    def rotationM_negativ_z(self, theta):
        t = math.radians(theta)
        m = np.mat([
            [np.cos(np.deg2rad(theta)), -math.sin(t),0,0],
            [math.sin(t),math.cos(t),0,0],
            [0,0,1,0],
            [0,0,0,1]
        ])
        return m

    # 3D, 沿s(x,y,z)放大
    def skaliertM_3D(self, s):
        m = np.mat([
            [s.x,0,0,0],
            [0,s.y,0,0],
            [0,0,s.z,0],
            [0,0,0,1]
        ])
        return m

    # 3D，移动至新原点o(x,y)
    def translationM_to_new_O(self, o):
        m = np.mat([
            [1,0,0,o.x],
            [0,1,0,o.y],
            [0,0,1,o.z],
            [0,0,0,1]
        ])
        return m
    #正交投影
    def ortho(self,l,r,b,t,n,f):
        m = np.mat([
            [2/(r-l),0,0,-((r+l)/(r-l))],
            [0,2/(r-b),0,-((t+b)/(t-b))],
            [0,0,-(2/(f-n)),-((f+n)/(f-n))],
            [0,0,0,1]
        ])
        return m
    
    #透视投影
    def persp(self,l,r,b,t,n,f):
        m = np.mat([
            [2*n/(r-l),0,(r+l)/(r-l),0],
            [0,2*n/(t-b),(t+b)/(t-b),0],
            [0,0,-((f+n)/(f-n)),-((2*f*n)/(f-n))],
            [0,0,-1,0]
        ])
        return m
    
    # A 矩阵（NDC --A--> Window Space）
    # v_w 为宽度，v_h为高度。
    # z_win为Tiefenbereich，即[a,b]。
    # 当z_win in [0,1]时，表示近平面a=0, 远平面b=1
    # (v_x,v_y)为串钩左下角点的坐标，可能是(0,0)
    def get_A_Matrix(self,v_w,v_h,v_x,v_y,a,b):
        m = np.mat([
            [v_w/2,0,0,v_w/2+v_x],
            [0,v_h/2,0,v_h/2+v_y],
            [0,0,(b-a)/2, (a+b)/2],
            [0,0,0,1]
        ])
        return m

# 对称视锥视图symmetrischen View Frustums的4个参数转换为6个参数
# （参数化：a,theta,n,f -> l,r,b,t,n,f）
# a = breite / hoehe
# theta = FOV
# n = 到近平面的距离
# f = 到远平面的距离
def sym_View_Frustums_4to6_para(a,theta,n,f):
    
    result = {}
    result['t'] = round(n * math.tan(math.radians(theta/2)),3)
    result['r'] = result['t'] * a
    result['l'] = -result['r']
    result['b'] = -result['t']  
    return result  


# 已知3点，获取平面三角形面积
def get3EFlaeche(a,b,c):
    return 1/2*((b.x - a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y))

# 已知3点a,b,c，和指定平面重心d，求 α,β,γ
def getBaryKoo(a,b,c,d):
    koo = []
    f = get3EFlaeche(a,b,c)
    f1 = get3EFlaeche(b,c,d)
    f2 = get3EFlaeche(a,c,d)
    f3 = get3EFlaeche(a,b,d)
    koo.append(f1/f)
    koo.append(f2/f)
    koo.append(f3/f)
    return koo

# 归一化方法：np.linalg.norm( 向量 )



# Gouraud Shading:
# I_d = kd * ld * max(<n,l>,0)
def gouraud_shading(a,b,c,na,nb,nc,pl,kd,id):
    i_a = np.dot(kd , np.dot(id, max(np.dot(na,(pl-a)/np.linalg.norm(pl-a)),0)))
    i_b = np.dot(kd , np.dot(id, max(np.dot(nb,(pl-b)/np.linalg.norm(pl-b)),0)))
    i_c = np.dot(kd , np.dot(id, max(np.dot(nc,(pl-c)/np.linalg.norm(pl-c)),0)))
    result = [i_a,i_b,i_c]
    return result

# Phong Shading:
# I_d = kd * ld * max(<n,l>,0)
# 顶点法向量插值计算：
#def phong_shading():


if(__name__ == '__main__'):

    #平面三角形a,b,c以及重心d
    a = Ecke()
    b = Ecke()
    c = Ecke()
    d = Ecke()
    e = Ecke()
    f = Ecke()

    #print(getBaryKoo(a,b,c,d))
    

    #矩阵
    # m = np.mat([
    #     [2,-2,0,1],
    #     [1,1,0,-5],
    #     [0,0,-1/4,0],
    #     [0,0,0,1]
    # ])
    # ex = np.array([1,0,0,1])
    # ey = np.array([0,1,0,1])
    # ez = np.array([0,0,1,1])
    # o = np.array([0,0,0,1])
    # print(np.dot(m,ex))
    # print(np.dot(m,ey))
    # print(np.dot(m,ez))
    # print(np.dot(m,o))

    #放大->旋转->平移
    mx = TransMatrix()
    # s = Ecke()
    # o = Ecke()
    # s.set(1,2,1)
    # o.set(3,-1,0)
    # ma = np.dot(np.dot(mx.skaliertM_3D(s), mx.rotationM_negativ_z(90)),mx.translationM_to_new_O(o))

    # print(ma)
    # # 求逆矩阵 A^{-1}
    # print(np.linalg.inv(ma))

    # mo = mx.ortho(-9/2,9/2,-9/4,9/4,1,9)
    # mp = mx.persp(-1,1,-1/2,1/2,1,9)

    # # print(mo)
    # # print(mp)
    
    # print(np.dot(mp,a.setArray(-9/5,-9/10,-9/5)) * (5/9))
    # print(np.dot(mp,b.setArray(9/5,-9/10,-9/5)) * (5/9))
    # print(np.dot(mp,c.setArray(9/5,9/10,-9/5)) * (5/9))
    # print(np.dot(mp,d.setArray(-9/5,9/10,-9/5)) * (5/9))
    # print(np.dot(mp,e.setArray(-9/5,-9/10,-9))/9)
    # print(np.dot(mp,f.setArray(9/5,-9/10,-9))/9)

    #print(sym_View_Frustums_4to6_para(720/480,90,2,32))

    
    # m = np.mat([
    #     [0,8,0,6],
    #     [0,0,1,-2],
    #     [4,0,0,0],
    #     [0,0,0,1]
    # ])
    # p = np.mat([
    #     [1,0,0,0],
    #     [0,2,0,0],
    #     [0,0,-2,-12],
    #     [0,0,-1,0]
    # ])
    # v = np.mat([
    #     [0,0,1,0],
    #     [0,1,0,0],
    #     [-1,0,0,2],
    #     [0,0,0,1]
    # ])
    
    # a_worlds = np.dot(m,a.setArray(-1,0,0)).reshape(4,1)
    
    # a_es = np.dot(v,a_worlds).reshape(4,1)
    # a_cs = np.dot(p,a_es).reshape(4,1)
    # a_ndc = a_cs / a_cs[3]
    
    # print(a_es)
    # print(a_cs)
    # print(a_ndc)





    # m = np.mat([
    #     [0,-1,0,0],
    #     [1,0,0,0],
    #     [0,0,-1,2],
    #     [0,0,0,1]
    # ])
    # v = np.mat([
    #     [0,0,1,0],
    #     [0,-1,0,0],
    #     [-1,0,0,2],
    #     [0,0,0,1]
    # ])
    # p = np.mat([
    #     [1,0,0,0],
    #     [0,2,0,0],
    #     [0,0,-3/2,5],
    #     [0,0,-1,0]
    # ])
    
    # m_n1 = np.linalg.inv(m)
    # v_n1 = np.linalg.inv(v)
    # p_n1 = np.linalg.inv(p)

    # a_win = np.array([5/2,9/2,0,1])
    # b_win = np.array([5/2,9/2,1,1])

    # a = mx.get_A_Matrix(6,6,0,0,0,1)

    # a_n1 = np.linalg.inv(a)
    # a_nds = np.dot(a_n1,a_win).reshape(4,1)
    # a_cs = a_nds * 2
    # a_es = np.dot(p_n1,a_cs).reshape(4,1)

    # a_ws = np.dot(v_n1,a_es).reshape(4,1)
    # a_os = np.dot(m_n1,a_ws).reshape(4,1)
    # print(a_os)
    



    print(gouraud_shading(
            np.array([-8,4,4]),
            np.array([4,4,-8]),
            np.array([4,10,4]),
            np.array([-1,0,0]),
            np.array([0,1,0]),
            np.array([0,0,-1]),
            np.array([0,12,0]),
            np.array([1/2,1,1]),
            np.array([1,0,1/2])
        ))