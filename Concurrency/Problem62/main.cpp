#include <gsl/gsl>

#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <numeric>
#include <random>

template<class ForwardIt>
ForwardIt my_min_element(ForwardIt first, ForwardIt last)
{
	auto threadCount = std::thread::hardware_concurrency();
	std::vector<std::thread> threads(threadCount);
	std::vector<ForwardIt> results(threadCount);

	size_t targetSize = std::distance(first, last) / threadCount;

	for (size_t i = 0; i < threadCount; ++i)
	{
		auto iter = first;

		if (i == threadCount - 1)
			first = last;
		else
			std::advance(first, targetSize);

		threads[i] = std::thread([=, &results]() {
			results[i] = std::min_element(iter, first);
			}
		);
	}

	for (auto&& iter : threads)
		iter.join();

	return *std::min_element(results.begin(), results.end());
}

template<class ForwardIt, class Compare>
ForwardIt my_min_element(ForwardIt first, ForwardIt last, Compare comp)
{
	auto threadCount = std::thread::hardware_concurrency();
	std::vector<std::thread> threads(threadCount);
	std::vector<ForwardIt> results(threadCount);

	size_t targetSize = std::distance(first, last) / threadCount;

	for (size_t i = 0; i < threadCount; ++i)
	{
		auto iter = first;

		if (i == threadCount - 1)
			first = last;
		else
			std::advance(first, targetSize);

		threads[i] = std::thread([=, &results]() {
			results[i] = std::min_element(iter, first, comp);
			}
		);
	}

	for (auto&& iter : threads)
		iter.join();

	return *std::min_element(results.begin(), results.end(), comp);
}

int f()
{
	static int i = 0;
	return i++;
}

int main(int argc, char* argv[])
{
	std::string s("hello");
	std::cout << *my_min_element(s.begin(), s.end()) << std::endl;

	std::vector<int> test(1000);
	std::generate(test.begin(), test.end(), f);
	std::shuffle(test.begin(), test.end(), std::mt19937{ std::random_device{}() });

	std::cout << *my_min_element(test.begin(), test.end()) << std::endl;

	return 0;
}