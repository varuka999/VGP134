#include <iostream>

//int Add(int a, int b)
//{
//	return a + b;
//}

enum Enums
{
	Null = -1, // Makes the first 'valid' enum = 0
	First,
	Second,
	Third,
};

template<class T>
T Add(T a, T b)
{
	return a + b;
}

template<class T>
T Sub(T a, T b)
{
	return a - b;
}

template<class T>
T Mult(T a, T b)
{
	return a * b;
}

template<class T>
T Div(T a, T b)
{
	return a / b;
}

template<class T>
T Mod(T a, T b)
{
	return a % b;
}

template<class T>
class Value
{
public:
	T value;

	Value<T> operator+(const Value<T>& rhs)
	{
		Value<T> newValue;
		newValue.value = value + rhs.value;

		return newValue;
	}

	Value<T> operator-(const Value<T>& rhs)
	{
		Value<T> newValue;
		newValue.value = value - rhs.value;

		return newValue;
	}

	Value<T> operator*(const Value<T>& rhs)
	{
		Value<T> newValue;
		newValue.value = value * rhs.value;

		return newValue;
	}

	Value<T> operator/(const Value<T>& rhs)
	{
		Value<T> newValue;
		newValue.value = value / rhs.value;

		return newValue;
	}

	Value<T> operator%(const Value<T>& rhs)
	{
		Value<T> newValue;
		int aInt = value;
		int bInt = rhs.value;
		newValue.value = aInt % bInt;

		return newValue;
	}
};

int main()
{
	//AddValue a{ 10.0f }; // fancy
	Value<float> a, b;
	a.value = 3.5;
	b.value = 2.75;

	std::cout << Add(a, b).value << "\n";
	std::cout << Sub(a, b).value << "\n";
	std::cout << Mult(a, b).value << "\n";
	std::cout << Div(a, b).value << "\n";
	std::cout << Mod(a, b).value << "\n";

	int i = First;

	int value = 10;
	int* intPtr = &value;
	int* newInt = new int(5);

	std::unique_ptr<int> uniquePtr = std::make_unique<int>(8);
	std::unique_ptr<int[]> uniquePtrArray = std::make_unique<int[]>(9);

	delete newInt;

	return 0;
}