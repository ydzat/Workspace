/*
A1. Rasterbilder 光栅图像
为了表示光栅图像数据，通常使用像素数据的二维阵列。 
考虑每个像素存储一个红色，绿色，蓝色和alpha的情况。
1每个通道通常使用8位，因此每个分量的强度可以编码为256级。

可以将计算机的主存储器理解为一系列存储单元的序列，
每个存储单元为1个字节，这些存储单元通过一维地址进行引用。 
为了存储光栅图像，将单个像素逐行存储在内存中。

（a）计算上述RGBA格式的4096×2160像素（“ 4K2K”）图像所需的存储空间！ （1分）
（b）我们考虑分辨率为w×h的图像。给出一个满足x∈{0，的给定二维像素位置（x，y）的公式a（x，y，c）。 ， ， ，w-1}，y∈{0 ,. ， ， ，h-1}和通道索引c∈{0，1，2，3}（0代表红色，1代表绿色，依此类推）确定内存地址！ （图片从地址0开始）。 （1分）
（c）指定公式或算法，利用该公式或算法可以从给定地址m（并取决于图像宽度w和图像高度h）重建二维像素位置（x，y）和通道索引c。您的函数/算法应使用参数w和h。然后确定像素位置以及存储在77x50像素图像的地址m = 4189处的通道索引。 （3分）
（d）如果图像总共为92160字节，并且像素（42，23）从14888开始，请计算w和h！ （2分）

A2.显示界面（3分）
分辨率为2560×1440像素的LCD监视器配有60Hz数字视频信号
（未压缩，RGB，每通道8位）
（a）至少必须提供显示接口的哪个数据速率（以MB / s为单位，
小数点后四舍五入到1位，Si表示1兆字节= 106字节）？ （1分）
（b）视频信号通过DVI-D接口传输。 
这导致像素时钟为241 7 MHz，而不是天真预期的221 2 MHz。 
解释什么是更高像素的时钟！ （2分）

A3数学基础
给出以下点：A=(0 0 2), B=(4 0 2), C=(-2 2 0), P=(2 3 3), Q=(2 5 5)
（A）以显式形式确定直线GQP和GAB的直线方程。 （1分）
（b）三个点A，B和C跨越一个平面。 确定隐式和显式形式的平面EABC的平面方程。 （2分）
（c）计算以下物体之间的欧几里得距离：
-直线GAB和GQP
-EABC级别和Q点
-飞机EABC和GQP线
-路线PQ和点C
（5分）
  （d）计算线GPQ和平面EABC之间的交点S。 （2分）
*/

#include<iostream>

#include"Rasterbilder.h"
#include"Displayschnittstellen.h"
#include"MathematischeGrundlagen.h"

using namespace std;
int main(){

    return 0;
}