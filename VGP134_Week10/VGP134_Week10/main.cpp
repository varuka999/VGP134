#include <thread>
#include <iostream>
#include <chrono>

uint32_t gSumOdd = 0;
uint32_t gSumEven = 0;

void SumOdd(uint32_t start, uint32_t end)
{
	for (uint32_t i = start; i < end; ++i)
	{
		if (i % 2 == 1)
		{
			++gSumOdd;
		}
	}
}

void SumEven(uint32_t start, uint32_t end)
{
	for (uint32_t i = start; i < end; ++i)
	{
		if (i % 2 == 0)
		{
			++gSumEven;
		}
	}
}

int main()
{
	const auto startTime = std::chrono::high_resolution_clock::now();
	uint32_t start = 0;
	uint32_t end = 1000000;

	SumOdd(start, end);
	SumEven(start, end);

	//std::thread t1(SumOdd, start, end);
	//std::thread t2(SumEven, start, end);
	//t1.join();
	//t2.join();

	const auto endTime = std::chrono::high_resolution_clock::now();
	const auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

	std::cout << gSumOdd << "\n";
	std::cout << gSumEven << "\n";
	std::cout << "Time (ms): " << milliseconds << "\n";


	return 0;
}
