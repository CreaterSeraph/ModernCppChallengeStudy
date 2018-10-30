#include <gsl/gsl>

#include <iostream>
#include <list>

int main(int argc, char* argv[])
{
    std::list<size_t> result;
	for (size_t i = 100; i < 1000; ++i)
	{
		size_t a = i % 10;
		size_t b = i / 10 % 10;
		size_t c = i / 100;//%10은 생략해도됨(1000아래 니까)
		if (a * a * a + b * b * b + c * c * c == i)
			result.push_back(i);
	}

	for (auto iter : result)
	{
		std::cout << iter << std::endl;
	}

    return 0;
}
