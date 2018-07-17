#include <iostream>

#define MAX 100

class SqList
{
public:
	unsigned length = 0;
	double *arr;

public:
	SqList(double a[], unsigned len)
	{
		arr = new double[len];
		for (unsigned i = 0; i < len; i++)
		{
			arr[i] = a[i];
		}
		length = len;
	}

	SqList(unsigned len): length(len), arr(new double[len])
	{

	}
	~SqList()
	{
		delete []arr;
	}

	double& operator[](unsigned i)//假如这里不是double&, 那么就不可以赋值
	{
		return  arr[i];
	}

public:
	void print()
	{
		for (unsigned i = 0; i < length; i++)
		{
			std::cout << arr[i] << "  ";
		}
		std::cout << std::endl;
	}
};
