#include "MyMath.h"

namespace MyMath
{
	std::vector<bool> PrimeNumber(size_t size)
	{
		std::vector<bool> result;
		result.resize(size + 1, true);
		result[0] = false;
		result[1] = false;
		if (size > 1)
		{
			for (size_t i = 2; i <= sqrt(size); ++i)
			{
				if (result[i] == false)
					continue;
				for (size_t j = i * 2; j <= size; j += i)
					result[j] = false;
			}
		}

		return result;
	}
	std::vector<size_t> PrimeNumberVec(size_t max)
	{
		std::vector<size_t> result;
		auto temp = PrimeNumber(max);
		for (size_t i = 0; i < max + 1; ++i)
		{
			if (temp[i])
				result.push_back(i);
		}

		return result;
	}
}