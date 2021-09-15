#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#define PI 3.1415926535

void FFT(float dataR[],float dataI[],float dataA[],int N,int M)
{

	int i,j,k,r;
	int p,L,B;
	unsigned int I,J,K,F0,F1,m,n;
	float Tr,Ti,temp;
	//�������е���
/*
J=N/2;
for(I = 1; I < N - 2; I++)
{
	//����Ԫ�ػ���
	if(I<J)
	{
		temp = dataR[I];
		dataR[I] = dataR[J];
		dataR[J] = temp;
	}
	//��ȡ��һ��������
	K=N/2;//K��N��Ȩֵ�����������λȨֵ��ʼ�жϡ�
	while(1)
	{
		//������ѭ���жϸ�λ�Ƿ�Ϊ1
 		if(J< K)	
		{
			J=J+K;//�жϽ��Ϊ��λΪ0�����ϸ�λȨֵ��0���1��
			break;//ѭ������
 		}
		else 
		{
			J=J-K;//�жϽ��Ϊ��λΪ1����ȥ��λȨֵ��1���0��
			K=K/2;//�õ���һλ��Ȩֵ��������һλ0��1���жϡ�
		 }
	}
}*/

//����
	for(I=0;I< N;I++)   //���ݹ����ģ���Ҫ������Ԫ��ִ����䵹��
	{  
		/*��ȡ�±�I�ķ���J����ֵ*/ 
		J=0;
		for(k=0;k<(M/2+0.5);k++)     //k��ʾ����
	     {
	         //*�������*/
	         m=1;//m�����λΪ1�Ķ�������
			 n=(unsigned int)pow(2,M-1);//n�ǵ�MλΪ1�Ķ�������
			 m <<= k; //��m����kλ
	         n >>= k; //��n����kλ
	         F0=I & n;//I��n��λ����ȡ��ǰ�벿�ֵ�kλ
			 F1=I & m;//I��m��λ����ȡ��F0��Ӧ�ĺ�벿�ֵĵ�λ
	         if(F0) J=J | m; //J��m��λ��ʹF0��Ӧ��λΪ1
	         if(F1) J=J | n; //J��n��λ��ʹF1��Ӧ��λΪ1 
	     }
	 		//printf("IΪ��");printBin(I,M);printf(" %d\n",I);
	 		//printf("JΪ��");printBin(J,M);printf(" %d\n\n",J);
	 		
	 	 if(I<J)
			{
				temp = dataR[I];
				dataR[I] = dataR[J];
				dataR[J] = temp;
				//�����������ֽ����� 
				temp = dataI[I];
				dataI[I] = dataI[J];
				dataI[J] = temp;
			}                                
	} 

//����FFT
	/*	Tr = Xr(J+B)cos(2.0*PI*p/N) + Xi(J+B)sin(2.0*PI*p/N)
	    Ti = Xi(J+B)cos(2.0*PI*p/N) - Xr(J+B)sin(2.0*PI*p/N)
		Ar[J] = Xr(J) + Tr
	    Ai[J] = Xi(J) + Ti
	    Ar[J+B] = Xr(J) - Tr
	    Ai[J+B] = Xi(J) - Ti
	   (���� XrΪ��һ����Ar, XiΪ��һ����Ai)*/
	for(L=1; L<=M;L++)	//FFT���μ���L��1--M
	{		
		/*��L��������:
		Ȼ����ڵ�L�������������������ᵽ�����������������Ŀ���ڼ��B:�ж����ֵ��������Ҫ��Ҫѭ�����ٴ�;
		����ѭ���Ĳ�ͬ����תָ��PҲ��ͬ��P������Ϊk=2^(M-L)*/	
		//�ȼ���һ�¼�� B = 2^(L-1);
		B = 1;
		B = (int)pow(2,L-1);	
		for(j=0;j<=B-1;j++)		
		//j = 0,1,2,...,2^(L-1) - 1
		{	/*ͬ�ֵ�������*/	
			//�ȼ�������k=2^(M-L)
			k=1;
			k = (int)pow(2,M-L);
			//������תָ��p������Ϊkʱ����P=j*k
			p=1;
			p=j*k;
			/*�������������������ǿ���֪��ͬ�ֵ�������Ĵ����պ�Ϊ����k=2^(M-L)��
			ͬ�ֵ��ε����������Ϊ��������Ĵ���*/
			for(i=0; i<=k-1;i++) 
				{
					//�����±궨Ϊr
					r=1;
					r=j+2*B*i;
					Tr=dataR[r+B]*cos(2.0*PI*p/N) + dataI[r+B]*sin(2.0*PI*p/N);
					Ti=dataI[r+B]*cos(2.0*PI*p/N) - dataR[r+B]*sin(2.0*PI*p/N);
					dataR[r+B]=dataR[r]-Tr;
					dataI[r+B]=dataI[r]-Ti;
					dataR[r]=dataR[r]+Tr;
					dataI[r]=dataI[r]+Ti;
				}	
			}
	}
	//�����ֵ 
	for ( i=0;i<N;i++ )
	{ 		
	 	dataA[i]=sqrt(dataR[i]*dataR[i]+dataI[i]*dataI[i]);
	}
}

//FFTʵ�����뺯�� 
void FFTR(float dataR[],float dataI[],float dataA[],int N,int M)
{
	int i,k;
	int j,r,p,B;
	float Tr,Ti;
	float yR[N/2],yI[N/2],yA[N/2]; 
	float x1R[N/2],x2R[N/2],x1I[N/2],x2I[N/2],xR[N],xI[N];
	for(i=0;i<N/2;i++)
	{
		yR[i]=dataR[2*i];
		yI[i]=dataR[2*i+1];
				
	}
	FFT(yR,yI,yA,N/2,M-1);
	//��X1(k)��X2(k) 
	for(k=0;k<N/2;k++)
	{
		if(k==0)
		{
			x1R[k]=yR[k];
			x1I[k]=yI[k];
			x2R[k]=yI[k];
			x2I[k]=-yR[k];	
		}
		else
		{
			x1R[k]=(yR[k]+yR[N/2-k])/2;
			x1I[k]=(yI[k]-yI[N/2-k])/2;
			x2R[k]=(yI[k]+yI[N/2-k])/2;
			x2I[k]=(yR[N/2-k]-yR[k])/2;
		}
	}
	
	//��M���ĵ�������		
	B = 1;
	B = (int)pow(2,M-1);	
	for(j=0;j<=N/2-1;j++)		
	//j = 0,1,2,...,2^(L-1) - 1
	{		
		p=1;
		p=j;
		//�����±궨Ϊr
		r=1;
		r=j;
		int k=j;
		Tr=x2R[r]*cos(2.0*PI*p/N) + x2I[r]*sin(2.0*PI*p/N);
		Ti=x2I[r]*cos(2.0*PI*p/N) - x2R[r]*sin(2.0*PI*p/N);
		xR[r]=x1R[r]+Tr;
		xI[r]=x1I[r]+Ti;

		if(r==0)
		{
			xR[N/2]=x1R[0]-x2R[0];
			xI[N/2]=x1I[0]-x2I[0];		
		}
		else
		{
			xR[N-r]=xR[r];
			xI[N-r]=-xI[r];	
		}
	}
	
	for(i=0;i<N;i++)
	{
		dataR[i]=xR[i];
		dataI[i]=xI[i];
	}
	for ( i=0;i<N;i++ )
	{ 		
		//dataA[i]=sqrt(xR[i]*xR[i]+xI[i]*xI[i]);
	 	dataA[i]=sqrt(dataR[i]*dataR[i]+dataI[i]*dataI[i]);
	}	
} 

int main(int argc, char *argv[])
{
	int N=128,M=7;
	int i;
	float A0=255.0;
	float SinInR[N],SinInI[N],SinInA[N];
	FILE* fp;
	//���������ź� 
	for(i = 0; i < N; i++)
	{
		SinInR[i] = A0 * (sin(2*PI*i/25)+sin(2*PI* i * 0.4 ));
		SinInI[i] = 0;
		SinInA[i] = 0;
	}
	//д������ 
	if((fp=fopen("input.txt","wb"))==NULL)
	{
 		printf("�޷����ļ�");
 		exit(0);//��ֹ���� 
	}
	for(i = 0; i < N ; i++)
		fprintf(fp,"%f\n",SinInR[i]);
	//fwrite(&dataR,sizeof(dataR),1,fp);
	fclose(fp);
	FFTR(SinInR,SinInI,SinInA,N,M);//����FFTR����DFT 
	//FFT(SinInR,SinInI,SinInA,N,M);//����FFT��������DFT 
	for(i=0;i<N;i++)
	printf("%f\n",SinInA[i]);
	//д������ 
	if((fp=fopen("output.txt","wb"))==NULL)
	{
 		printf("�޷����ļ�");
 		exit(0);//��ֹ���� 
	}
	for(i = 0; i < N ; i++)
		fprintf(fp,"%f\n",SinInA[i]);
	//fwrite(&dataR,sizeof(dataR),1,fp);
	fclose(fp);
	return 0;
}

