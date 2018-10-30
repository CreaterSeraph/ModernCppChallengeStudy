#include <gsl/gsl>

#include <iostream>
#include <../MyMath.h>
#include <numeric>

int main(int argc, char* argv[])
{
    size_t input1, input2;

	std::cin >> input1 >> input2;

	std::cout << std::lcm(input1, input2) << std::endl;

	//auto table = MyMath::PrimeNumberVec(std::max(input1, input2));
	//
	//size_t result = 1;
	//for (auto iter : table)
	//{
	//	size_t count1 = 0, count2 = 0;
	//	while(input1 % iter == 0)
	//	{
	//		input1 /= iter;
	//		++count1;
	//	}
	//	while(input2 % iter == 0)
	//	{
	//		input2 /= iter;
	//		++count2;
	//	}
	//	result *= pow(iter, std::max(count1, count2));
	//}
	//
	//std::cout << result << std::endl;

    return 0;
}
