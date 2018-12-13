#include <gsl/gsl>

#include <iostream>
#include <thread>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <iterator>

//https://en.cppreference.com/w/cpp/iterator/iterator_tags
//
//template<bool cant_random_access, class InputIt, class OutputIt, class UnaryOperation>
//OutputIt mytransform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op) //���� ������ �Ұ����Ѱ��
//{
//	auto threadCount = std::thread::hardware_concurrency();
//	std::vector<std::thread> threads(threadCount);
//
//	size_t size = std::distance(first1, last1) / threadCount;
//
//	for (size_t i = 0; i < threadCount; ++i)
//	{
//
//	}
//
//	return d_first;
//}
//
//template<class InputIt, class OutputIt, class UnaryOperation>
//OutputIt mytransform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op, std::random_access_iterator_tag, std::random_access_iterator_tag) //�Ѵ� ���� ����(�ε����� ���� ����)
//{
//	auto threadCount = std::thread::hardware_concurrency();
//	std::vector<std::thread> threads(threadCount);
//
//	for (size_t i = 0; i < threadCount; ++i)
//	{
//		auto inIter = first1;
//	}
//
//	return d_first;
//}
//
//template<class InputIt, class OutputIt, class UnaryOperation>
//OutputIt mytransform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op, std::forward_iterator_tag, std::output_iterator_tag)
//{
//	return mytransform<false>(first1, last1, d_first, unary_op);
//}
//
//template<class InputIt, class OutputIt, class UnaryOperation>
//OutputIt mytransform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op, std::forward_iterator_tag, std::forward_iterator_tag)
//{
//	return mytransform<false>(first1, last1, d_first, unary_op);
//}
//���� �� ���� ����� �����Ű����� �Ӹ��� ������
//���� �ܼ�Ʈ�� ������Ɲ�
//advance�� �׳� �ݺ��� ���� �� �ٸ��� ���ǵǾ��־���
//�ð��ȳ�

template<class InputIt, class OutputIt, class UnaryOperation>
OutputIt mytransform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op)
{
	auto threadCount = std::thread::hardware_concurrency();
	std::vector<std::thread> threads(threadCount);

	size_t targetSize = std::distance(first1, last1) / threadCount;

	for (size_t i = 0; i < threadCount; ++i)
	{
		auto inIter = first1;
		auto outIter = d_first;

		if (i == threadCount - 1)
			first1 = last1;
		else
		{
			std::advance(first1, targetSize);
			std::advance(d_first, targetSize);
		}

		threads[i] = std::thread([=]() {
			std::transform(inIter, first1, outIter, unary_op);
			}
		);
	}

	for (auto&& iter : threads)
		iter.join();

	return d_first;
}

template<class InputIt1, class InputIt2, class OutputIt, class BinaryOperation>
OutputIt transform(InputIt1 first1, InputIt1 last1, InputIt2 first2, OutputIt d_first, BinaryOperation binary_op)
{
	while (first1 != last1) {
		*d_first++ = binary_op(*first1++, *first2++);
	}
	return d_first;

	//???? �ƴ� �̰� ��ü ��� �϶�°ž�
}

//https://en.cppreference.com/w/cpp/algorithm/transform
int main(int argc, char* argv[])
{
	std::string s("hello");
	mytransform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) -> unsigned char { return std::toupper(c); });

	std::vector<std::size_t> ordinals1;
	mytransform(s.begin(), s.end(), std::back_inserter(ordinals1),
		[](unsigned char c) -> std::size_t { return c; });

	std::cout << s << ':';
	for (auto ord : ordinals1)
		std::cout << ' ' << ord;

	std::cout << std::endl;

	std::list<char> r = { 'w', 'o', 'r', 'l', 'd', '!' };
	mytransform(r.begin(), r.end(), r.begin(),
		[](unsigned char c) -> unsigned char { return std::toupper(c); });

	std::vector<std::size_t> ordinals2;
	mytransform(r.begin(), r.end(), std::back_inserter(ordinals2),
		[](unsigned char c) -> std::size_t { return c; });

	for (auto i : r)
		std::cout << i;
	std::cout << ':';
	for (auto ord : ordinals2)
		std::cout << ' ' << ord;
}