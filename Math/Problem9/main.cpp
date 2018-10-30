#include <gsl/gsl>

#include <../MyMath.h>
#include <list>
#include <iostream>


int main(int argc, char* argv[])
{
    std::list<size_t> result;
	size_t input;
	std::cin >> input;

	auto primeList = MyMath::PrimeNumberVec(input);

	for (auto iter : primeList)
	{
		while (input % iter == 0)
		{
			input /= iter;
			result.push_back(iter);
		}
	}

	for (auto iter : result)
	{
		std::cout << iter << " ";
	}
	std::cout << std::endl;

    return 0;
}
