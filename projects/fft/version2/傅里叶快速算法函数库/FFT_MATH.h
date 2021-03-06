#ifndef FFT_MATH_H
#define FFT_MATH_H
/*
dataR[]：要计算序列的实数部分序列数组 
dataI[]：要计算序列的虚数部分序列数组 
dataA[]:FFT/IFFT变换后的幅值数组
N；输入要计算序列的个数（N=2^M）
M: M=log2(N)
*/
void FFT(float dataR[],float dataI[],float dataA[],int N,int M);/*复数FFT快速计算*/ 
void IFFT(float dataR[],float dataI[],float dataA[],int N,int M);/*复数IFFT快速计算*/ 
void FFTR(float dataR[],float dataI[],float dataA[],int N,int M);/*实数FFT快速计算*/ 
void IFFTR(float dataR[],float dataI[],float dataA[],int N,int M);/*实数IFFT快速计算*/ 
#endif
