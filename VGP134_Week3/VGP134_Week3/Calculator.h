#pragma once

static class Calculator
{
public:
	static void Add(int amount)
	{
		mResult += amount;
	}

	static void Subtract(int amount)
	{
		mResult -= amount;
	}

	static void Multiply(int amount)
	{
		mResult *= amount;
	}

	static void Divide(int amount)
	{
		mResult /= amount;
	}

	static int GetResult()
	{
		int returnValue = mResult;
		Clear();
		return returnValue;
	}

	static void Clear()
	{
		mResult = 0;
	}

private:
	static int mResult;
};

int Calculator::mResult = 0;