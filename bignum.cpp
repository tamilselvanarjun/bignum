#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class bignum {

	string value;
	bool isPositive;

public:
	bignum() 
	{
		value = "";
		isPositive = true;
	}

	bignum(int n) 
	{
		if(n<0)
			isPositive = false;
		else
			isPositive = true;					//sign of the number
		value = "";
		n = abs(n);
		while(n!=0)
		{
			value = (char)((n%10)+'0') + value;
			n/=10;
		}
	}

	bignum(string s)
	{
		if(s[0]=='-')			//negative number
		{
			isPositive = false;
			for(int i=1;i<s.length();i++)
			{
				if(s[i]<'0' or s[i]>'9')
				{
					value = "";
					break;
				}
				value += s[i];
			}
		}
		else
		{
			isPositive = true;
			for(int i=0;i<s.length();i++)
			{
				if(s[i]<'0' or s[i]>'9')
				{
					value = "";
					break;
				}
				value += s[i];
			}
		}						//positive
	}

	void print()
	{
		if(value=="")
			return;
		if(!isPositive)
			cout<<"-";
		cout<<value<<endl;
	}
};

int main()
{
	bignum a(0),b(-10),c("-234");
	a.print();
	b.print();
	c.print();
}