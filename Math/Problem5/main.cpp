#include <gsl/gsl>

#include <iostream>
#include <set>

int main(int argc, char* argv[])
{
    size_t input;

	std::cin >> input;

	auto list = MyMath::PrimeNumberVec(input);
	std::set<size_t> result;

	for (size_t i = 1; i < list.size() - 3; ++i)//2는 무조건 첫번째 인덱스니까 제거
	{
		for (size_t j = 1; j <= 3; ++j)
		{
			if (list[i] + 6 == list[i + j])
			{
				result.insert(list[i]);
				result.insert(list[i + j]);
			}
		}
	}

	for (auto iter : result)
		std::cout << iter << " ";
	std::cout << std::endl;

    return 0;
}
