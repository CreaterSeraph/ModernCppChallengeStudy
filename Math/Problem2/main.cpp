#include <gsl/gsl>

#include <iostream>
#include <../MyMath.h>
#include <numeric>

int main(int argc, char* argv[])
{
    size_t input1, input2;

	std::cin >> input1 >> input2;

	std::cout << std::gcd(input1, input2) << std::endl;

	//auto table = MyMath::PrimeNumberVec(std::max(input1, input2));
	//
	//size_t result = 1;
	//for (auto iter : table)
	//{
	//	while (input1 % iter == 0 && input2 % iter == 0)
	//	{
	//		result *= iter;
	//		input1 /= iter;
	//		input2 /= iter;
	//	}
	//}
	//
	//std::cout << result << std::endl;

    return 0;
}
