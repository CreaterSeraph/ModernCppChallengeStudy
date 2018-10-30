#include <gsl/gsl>
#include <iostream>

int main(int argc, char* argv[])
{
    size_t input;//정수
	std::cin >> input;

	//size_t result = 0;
	//for (size_t i = 0; i <= input; ++i)
	//{
	//	if (i % 3 == 0 || i % 5 == 0)
	//	{
	//		result += i;
	//	}
	//}

	auto func = [] (size_t number)->size_t
	{
		return number * (number + 1) / 2;
	};

	size_t result = func(input / 3) * 3 + func(input / 5) * 5 - func(input / 15) * 15;//오 이거 좀 대단했다(??)
	//3이 포함되는 개수 * 3 + 5가 포함되는 개수 * 5 - 15가 포함되는 개수 * 15
	//중복되는 수(15의 배수)는 3,5의 배수 둘다 계산되니 제거

	std::cout << result << std::endl;

    return 0;
}
