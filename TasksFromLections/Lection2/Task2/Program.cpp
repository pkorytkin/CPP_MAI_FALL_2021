#include <iostream>
#include <string.h>
using namespace std;
void Fill();
void Work();
//int* mass1;
int mass1[10];
int mass2[20];
int main()
{
	Fill();
	Work();
}
void Fill()
{
	cout << "VVedite 10 elementov";
	for (int i = 0; i < 10; i++)
	{
		cin >> mass1[i];
	}
	//mass1 = new int[10]{-156,891,598,156,749,1495,14567,12366,458,369};
}
void Work()
{
	for(int i=0;i<10;i++)
	{
		int src_value = mass1[i];
		if(src_value<0)
		{
			src_value *= (-1);
		}
		int size = 0;
		int copyValue = src_value;
		while(copyValue!=0)
		{
			copyValue /= 10;
			size++;
		}
		copyValue = src_value;
		int PoT = 0;
		int NpoT = 0;
		int work_value = src_value;
		for(int v=0;v<size;v++)
		{
			copyValue /= 10;
			copyValue *= 10;
			int thisValue = NAN;
			for(int t=0;t<10;t++)
			{
				if((copyValue+t)== work_value)
				{
					thisValue = t;
				}
			}
			if(thisValue%2==0)
			{
				PoT += thisValue;
			}else
			{
				NpoT += thisValue;
			}
			copyValue /= 10;
			work_value /= 10;
		}
		mass2[i * 2] = NpoT;
		mass2[i * 2 + 1] = PoT;

		cout << endl << src_value << " " << size<<" "<<PoT<<" "<<NpoT;
	}
	cout << endl;
	for(int i=0;i<20;i++)
	{
		cout << mass2[i]<<" ";
	}
}
