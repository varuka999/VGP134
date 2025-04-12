#include <iostream>

class Test
{
private:
	int a = 0;
	int b = 0;
public:
	Test()
		: a(10), b(5)
	{

	}

	Test(const Test& v)
	{
		a = v.a + 5;
		b = v.b + 5;
	}

	Test& operator=(const Test& v)
	{
		a = v.a + 5;
		b = v.b + 5;

		return *this;
	}
};

class Car
{
public:
	virtual void Move()
	{
		++pos;
		ToString();
	}

	void ToString()
	{
		std::cout << "Car has position " << pos << "\n";
	}

	void operator++() { ++pos; ToString(); }

protected:
	int pos = 0;
};

class Sedan : public Car
{
public:
	void Move() override
	{
		pos += 10;
		ToString();
	}
};

int main()
{
	Car myCar;
	myCar.ToString();
	//myCar.Move();
	++myCar;

	Sedan mySedan;
	mySedan.Move();
	Car* ptr = &mySedan;

	ptr->Move();

	Test test1; // 1
	Test test2(test1); // 2
	Test test3 = test1; // 2
	test3 = test2; // 3

	int a = 50;
	int b = std::min(50 + a, 75);
	int c = std::max(25 - a, 0);

	return 0;
}