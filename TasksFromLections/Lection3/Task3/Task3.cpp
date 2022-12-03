
#include <iostream>
using namespace std;
class Drob
{
	bool Negative;
	int _Numerator;//Числитель
	int _Denominator = 1;//Знаменатель
	int _Mixed;//Целое
public:
	Drob(int Mixed,int Numerator, int Denominator)
	{
		SetValue(Mixed,Numerator,Denominator);
	}
	int Numerator()
	{
		return _Numerator;
	}
	int Denominator()
	{
		return _Denominator;
	}
	int Mixed()
	{
		return _Mixed;
	}
	void PrintValue()
	{
		if(_Numerator ==0)
		{
			if (_Mixed == 0)
			{
				cout << "0";
			}
			else
			{
				cout << (Negative ? "-" : "");
				cout << _Mixed;
			}
		}else
		{
			if (_Mixed == 0)
			{
				cout << (Negative ? "-" : "");
				cout << _Numerator << "/" << _Denominator;
			}
			else
			{
				cout <<( Negative ? "-" : "");
				cout << Mixed() << "(" << Numerator() << "/" << Denominator() << ")";
			}
		}
		cout << endl;
		
	}
	void ReadValue()
	{
		try 
		{
			cout << "Enter Celoe:";
			cin >> _Mixed;
		}catch(exception e)
		{
			cout << "\nWrong type";
		}
		try
		{
			cout << "Enter Numerator:";
			cin >> _Numerator;
		}
		catch (exception e)
		{
			cout << "\nWrong type";
		}
		try
		{
			cout << "Enter Denominator:";
			cin >> _Denominator;
		}
		catch (exception e)
		{
			cout << "\nWrong type";
		}
		SetValue(_Mixed, _Numerator, _Denominator);
	}
	void SetValue(int Mixed,int Numerator,int Denominator)
	{
		bool negative = false;
		if(Numerator<0)
		{
			negative = !negative;
		}
		if (Denominator == 0) 
		{
			cout << "Error Denominator is 0 setting denominator to 1 for "<<Mixed<<"("<<Numerator<<"/"<<Denominator<<") \n";
			Denominator = 1;
		}
		if (Denominator < 0)
		{
			negative = !negative;
		}
		if (Mixed < 0)
		{
			negative = !negative;
		}
		if(Denominator==0)
		{
			Denominator = 1;
		}
		Numerator = abs(Numerator);
		Denominator = abs(Denominator);
		Mixed = abs(Mixed);

		if(Numerator>= Denominator)
		{
			int mix = Numerator / Denominator;
			Numerator -= mix * Denominator;
			Mixed += mix;
		}

		_Numerator = Numerator;
		_Denominator = Denominator;
		_Mixed = Mixed;
		Negative = negative;
	}


};
int main()
{
	Drob d1 = Drob(5,6,2);
	d1 = Drob(-1, -6, 3);
	d1.PrintValue();
	
	d1.ReadValue();
	d1.PrintValue();
}