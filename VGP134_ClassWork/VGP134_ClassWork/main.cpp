#include <iostream>

void Print(int& value) { std::cout << "lvalue reference :" << value << "\n"; }
void Print(int&& value) { std::cout << "rvalue reference :" << value << "\n"; }
void Print(float& value) { std::cout << "lvalue reference :" << value << "\n"; }
void Print(float&& value) { std::cout << "rvalue reference :" << value << "\n"; }
void Print(double& value) { std::cout << "lvalue reference :" << value << "\n"; }
void Print(double&& value) { std::cout << "rvalue reference :" << value << "\n"; }
void Print(const int& value) { std::cout << "lvalue reference :" << value << "\n"; }
void Print(const int&& value) { std::cout << "rvalue reference :" << value << "\n"; }

class MyString
{
public:
	MyString() = default;

	MyString(size_t size, const char* str)
		: mSize(size), mString(new char[size + 1])
	{
		std::memcpy(mString, str, size + 1);

		Print("Default Constructor");
	}

	~MyString()
	{
		Print("Destructor");

		if (mString != nullptr)
		{
			delete[] mString;
			mString = nullptr;
			mSize = 0;
		}
	}

	// Copy Constructor
	MyString(const MyString& copy)
	{
		mSize = copy.mSize;
		mString = new char[mSize + 1];
		std::memcpy(mString, copy.mString, mSize + 1);

		Print("Copy Constructor");
	}
	//MyString(const MyString&& copy) noexcept
	//{
	//	mSize = copy.mSize;
	//	mString = new char[mSize + 1];
	//	std::memcpy(mString, copy.mString, mSize + 1);
	//	Print("Copy2");
	//}

	// Copy Assignment Operator
	MyString& operator=(const MyString& copy)
	{
		/*mSize = copy.mSize;
		mString = copy.mString;*/

		delete[] mString;
		mString = nullptr;
		mSize = 0;

		if (copy.mString != nullptr)
		{
			mSize = copy.mSize;
			mString = new char[mSize + 1];
			std::memcpy(mString, copy.mString, mSize + 1);
		}

		Print("Copy Assignment Operator");

		return *this;
	}

	// Move constructor, take rvalue, transfer data ownership to me
	MyString(MyString&& rvalue) noexcept
	{
		mString = rvalue.mString;
		mSize = rvalue.mSize;

		rvalue.mString = nullptr;
		rvalue.mSize = 0;

		Print("Move Constructor");
	}

	// Move Assignment Operator
	MyString& operator=(MyString&& rvalue) noexcept
	{
		delete[] mString;
		mString = nullptr;
		mSize = 0;

		mString = rvalue.mString;
		mSize = rvalue.mSize;
		rvalue.mString = nullptr;
		rvalue.mSize = 0;

		Print("Move Assignment Operator");

		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const MyString& size)
	{
		out << ((size.mString != nullptr) ? size.mString : "null");
		return out;
	}

	void Print(std::string constructorType)
	{
		std::cout << constructorType << " (" << ((mString != nullptr) ? mString : "null") << ") This Address: " << this << " String Address: " << (void*)mString << " String Value: " << *this << "\n";
	}

	char*& ReturnStringPtr()
	{
		return mString;
	}

private:
	std::size_t mSize = 0;
	char* mString = nullptr;
};

void Swap(MyString& a, MyString& b)
{
	MyString temp = a;
	a = b;
	b = temp;
}
void MoveSwap(MyString& a, MyString& b)
{
	MyString temp = std::move(a);
	a = std::move(b);
	b = std::move(temp);
}

int main()
{
	//int val = 7;
	//Print(val);
	//Print(5);
	//const int val2 = val;
	//Print(val2);
	//Print(val2 + val2);
	//float currentTime = 0;
	//float endTime = currentTime + 5.0f;
	//int endTimeInt = endTime;
	//double endTimeD = endTime;
	//Print(endTime);
	//Print(endTimeInt);
	//Print(endTimeD);
	//Print(currentTime);
	//Print(currentTime + 5.0f);
	//Print(val);
	//Print(currentTime);

	MyString hello(5, "Hello");
	MyString world(5, "World");

	MyString helloCopy = hello;
	MyString moveWorld = std::move(world);

	std::cout << hello << std::endl;
	std::cout << world << std::endl;
	std::cout << helloCopy << std::endl;
	std::cout << moveWorld << std::endl;

	std::cout << "Start Swap\n";
	Swap(helloCopy, moveWorld);
	std::cout << "Start Move Swap\n";
	MoveSwap(helloCopy, moveWorld);

	//char* helloPtr = hello2.ReturnStringPtr();
	//char* worldPtr = world2.ReturnStringPtr();
	//std::cout << helloPtr << " " << world2 << "\n";

	hello.~MyString();
	world.~MyString();
	helloCopy.~MyString();
	moveWorld.~MyString();

	return 0;
}

