#include <gsl/gsl>

#include <iostream>
#include <vector>
#include <list>
#include "../MyMath.h"

int main(int argc, char* argv[])
{
    //와 이건 개망했다 소수가지고 구해야하는데 코드 어캐짜지
	constexpr size_t size = 1000000;
	std::vector<size_t> table;
	table.resize(size);
	std::list<std::pair<size_t, size_t>> result;
	for (size_t i = 0; i < size; ++i)
	{
		size_t sumResult = 0;
		for (size_t j = 1; j < i / 2 + 1; j++)//무린데 이거
		{
			if (i % j == 0)
				sumResult += j;
		}

		table[i] = sumResult;
	}

	for (size_t i = 0; i < size; ++i)
	{
		if (table[i] >= size) continue;//인덱스 out으로터지는거 방지
		if (i != table[table[i]]) continue;//친화수가 아닌거 거름

		result.push_back(std::make_pair(i, table[i]));
		table[i] = 0;
		table[table[i]] = 0;//중복 방지
	}

	for (auto iter : result)
	{
		std::cout << iter.first << "\t" << iter.second << std::endl;
	}

    return 0;
}
