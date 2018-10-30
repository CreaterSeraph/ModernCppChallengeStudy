#include <gsl/gsl>

#include <iostream>
#include "../MyMath.h"

int main(int argc, char* argv[])
{
    size_t input;

	std::cin >> input;

	auto list = MyMath::PrimeNumber(input);
	size_t i;

	for (i = list.size() - 1; i != 0; i--)
	{
		if (list[i]) break;
	}

	std::cout << i << std::endl;

    return 0;
}
