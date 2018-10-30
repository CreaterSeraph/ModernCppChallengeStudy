#include <gsl/gsl>

#include <iosream>
#include <list>

int main(int argc, char* argv[])
{
    size_t input;
	std::cin >> input;

	std::list<size_t> result;

	for (size_t i = 2; i < input; ++i)
	{
		//if (result.find(i) != result.end()) continue;

		size_t sumResult = 0;
		for (size_t j = 1; j < i / 2 + 1; j++)//진약수의 합을 구하는중(소수 쓰는게 더 빠를거같은데)
		{
			if (i % j == 0)
				sumResult += j;
		}
		if (sumResult > i)
		{
			//for (size_t j = i; j < input; j += i)//과잉수의 배수는 무조건 과잉수이다 모든 약수 * 배수를 다 더하면 넘어가니까 ㅎㅎ;
			//근데 이거 최적화해도 거의 쓸데가 없는데 이거;;
				result.push_back(i);
		}
	}

	for (auto iter : result)
		std::cout << iter << " ";
	std::cout << std::endl;

    return 0;
}
