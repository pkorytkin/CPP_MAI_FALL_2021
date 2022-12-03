#include <iostream>
using namespace std;

class Devider
{
public:
	int LengthNumbers=0;
	int* Numbers = nullptr;
	int* Dev1 = nullptr;
	int* Dev2 = nullptr;
	int* Dev3 = nullptr;
	int Dev1Length = 0;
	int Dev2Length = 0;
	int Dev3Length = 0;
	Devider(int length=0)
	{
		
		RequireEnterNumbers(length);
	}
	~Devider()
	{
		delete[]Numbers;
	}
	void RequireEnterNumbers(int length=0)
	{
		LengthNumbers = length;
		if (length == 0) {
			while (LengthNumbers < 3) {
				cout << "Enter length";
				cin >> LengthNumbers;
			}
		}
		cout << "\nEnter numbers:";
		Numbers = new int[LengthNumbers];
		for (int i = 0; i < LengthNumbers; i++)
		{
			cin >> Numbers[i];
		}
		
	}
	int CalculateDelta(int DevidePos1,int DevidePos2)
	{
		int Sum1 = CalculateSum(0, DevidePos1);
		int Sum2 = CalculateSum(DevidePos1, DevidePos2);
		int Sum3 = CalculateSum(DevidePos2, LengthNumbers);

		int Delta1 = (Sum1 - Sum2);
		if (Delta1 < 0)
		{
			Delta1 *= -1;
		}
		int Delta2 = (Sum3 - Sum2);
		if (Delta2 < 0)
		{
			Delta2 *= -1;
		}
		//cout << "\n " << DevidePos1 << " " << DevidePos2 << " " << Sum1 << " " << Sum2 << " " << Sum3<<"\n";
		if(Sum1==Sum2&&Sum1==Sum3)
		{
			return 0;
		}
		//cout << "\n " << Delta1 << " " << Delta2<<"\n";
		return Delta1 > Delta2 ? Delta1 : Delta2;
	}
	void DevideNumbers()
	{
		delete[]Dev1;
		delete[]Dev2;
		delete[]Dev3;
		if(LengthNumbers==0)
		{
			cout << "Not initialized numbers";
			return;
		}

		int DevidePos1 = LengthNumbers / 3;
		int DevidePos2 = 2*LengthNumbers/3;

		
		int PrevDevidePos1 = DevidePos1;
		int PrevDevidePos2 = DevidePos2;

		int DeltaPrev = CalculateDelta(DevidePos1, DevidePos2);


		bool doStop = false;
		for(int d1=1;d1<LengthNumbers-2; d1++)
		{
			for(int d2=d1+1;d2<LengthNumbers;d2++)
			{
				int Delta = CalculateDelta(d1,d2);

				//cout << "\n" << "Delta " << Delta << " D1=" << d1 << " D2=" << d2 << "\n";
				if(Delta==0)
				{
					doStop = true;
					break;
				}
				if(Delta<DeltaPrev)
				{
					PrevDevidePos1 = d1;
					PrevDevidePos2 = d2;
					DeltaPrev = Delta;
					
				}
			}
			if(doStop)
			{
				break;
			}
		}
		Dev1Length = PrevDevidePos1;
		Dev2Length = PrevDevidePos2 - PrevDevidePos1;
		Dev3Length = LengthNumbers - PrevDevidePos2;
		Dev1 = new int[Dev1Length];
		Dev2 = new int[Dev2Length];
		Dev3 = new int[Dev3Length];

		for(int i=0;i<PrevDevidePos1;i++)
		{
			Dev1[i] = Numbers[i];
		}
		for (int i = PrevDevidePos1; i < PrevDevidePos2; i++)
		{
			Dev2[i- PrevDevidePos1] = Numbers[i];
		}
		for (int i = PrevDevidePos2; i < LengthNumbers; i++)
		{
			Dev3[i- PrevDevidePos2] = Numbers[i];
		}
		cout << "\n" << "Delta " << DeltaPrev<<" D1="<<PrevDevidePos1<<" D2="<<PrevDevidePos2<<"\n";
	}

	int CalculateSum(int From,int To)
	{
		int Sum1 = 0;
		for (int i = From; i < To; i++)
		{
			Sum1 += Numbers[i];
		}
		return Sum1;
	}

	void Print()
	{
		if (LengthNumbers == 0)
		{
			cout << "Not initialized numbers";
			return;
		}
		for(int i=0;i<LengthNumbers;i++)
		{
			cout << " " << Numbers[i];
		}
		cout << "\n";
		for (int i = 0; i < Dev1Length; i++)
		{
			cout << " " << Dev1[i];
		}
		cout << "\n";
		for (int i = 0; i < Dev2Length; i++)
		{
			cout << " " << Dev2[i];
		}
		cout << "\n";
		for (int i = 0; i < Dev3Length; i++)
		{
			cout << " " << Dev3[i];
		}
	}
};

int main()
{
    std::cout << "Hello World!\n";

	Devider d = Devider(0);
	d.DevideNumbers();
	d.Print();

}
