#include <gsl/gsl>

#include <iostream>

//constexpr�� ���
constexpr int PascalNum(int line, int num)
{
	if (line < 1) return 0;
	if (num < 1) return 0;
	if (num > line) return 0;
	if (num == 1) return 1;
	if (num == line) return 1;
	return PascalNum(line - 1, num - 1) + PascalNum(line - 1, num);
}

constexpr void PrintPascalLine(int line)//Release��忡�� inlineȭ ��
{
	for (int i = 1; i <= line; ++i)//constexpr for���� ������ ���� ���� �����Ͽ� �Ҽ� �����ٵ�
	{
		std::cout << PascalNum(line, i) << " ";
	}
}

constexpr void PrintPascal(int line)//Release��忡�� inlineȭ ��
{
	for (int i = 1; i <= line; ++i)//constexpr for���� ������ ���� ���� �����Ͽ� �Ҽ� �����ٵ�
	{
		PrintPascalLine(i);
		std::cout << std::endl;
	}
}

//���ø��� ���
template<int line, int num = 1>
constexpr int PascalNum()
{
	if constexpr (line < 1) return 0;
	else if constexpr (num < 1) return 0;
	else if constexpr (num > line) return 0;
	else if constexpr (num == 1) return 1;
	else if constexpr (num == line) return 1;
	else
		return PascalNum<line - 1, num - 1>() + PascalNum<line - 1, num>();
}

template<int line, int num = 1>
constexpr void PrintPascalLine()
{
	if constexpr (num <= line)
	{
		std::cout << PascalNum<line, num>() << " ";
		PrintPascalLine<line, num + 1>();
	}
}

template<int endLine, int nowLine = 1>
constexpr void PrintPascal()
{
	if constexpr (nowLine <= endLine)
	{
		PrintPascalLine<nowLine>();
		std::cout << std::endl;
		PrintPascal<endLine, nowLine + 1>();
	}
}

#include <array>

//ĳ�ø� ���� ��� (template���ڸ� �޾� std::array��)
template<int line>
constexpr void PascalNumCache()
{
	std::array<int, line> arr = { 1, };//���� ���� ����
	int i = 0;
	while (++i)
	{
		for (int j = 0; j < i; ++j)
			std::cout << arr[j] << ' ';
		std::cout << std::endl;
		if (i == line) break;
		for (int j = i; j > 0; --j)//�������� ���ƾ���
			arr[j] = arr[j] + arr[j - 1];
	}
}

#include <vector>
//ĳ�ø� ���� ��� (���ڸ� �޾� std::vector��)
void PascalNumCache(int line)
{
	std::vector<int> arr(line, 0);//���� ���� ����
	arr[0] = 1;
	int i = 0;
	while (++i)
	{
		for (int j = 0; j < i; ++j)
			std::cout << arr[j] << ' ';
		std::cout << std::endl;
		if (i == line) break;//���� �̰� ȿ���� �� ������;;
		for (int j = i; j > 0; --j)//�������� ���ƾ���
			arr[j] = arr[j] + arr[j - 1];
	}
}

int main(int argc, char* argv[])
{
	PrintPascal(10);//constexpr for�� ������ ��͵� ������Ÿ�ӿ� �� ���ٵ� �Ѥ�
	PrintPascal<10>();
	PascalNumCache(10);
	PascalNumCache<10>();//constexpr cache�� ������ ���ڴ� ���� �𸣴°ɱ�

	return 0;
}