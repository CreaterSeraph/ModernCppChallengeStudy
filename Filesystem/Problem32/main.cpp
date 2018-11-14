#include <gsl/gsl>

#include <iostream>

//constexpr만 사용
constexpr int PascalNum(int line, int num)
{
	if (line < 1) return 0;
	if (num < 1) return 0;
	if (num > line) return 0;
	if (num == 1) return 1;
	if (num == line) return 1;
	return PascalNum(line - 1, num - 1) + PascalNum(line - 1, num);
}

constexpr void PrintPascalLine(int line)//Release모드에선 inline화 됨
{
	for (int i = 1; i <= line; ++i)//constexpr for명세가 나오면 여길 완전 컴파일에 할수 있을텐데
	{
		std::cout << PascalNum(line, i) << "\t";
	}
}

//템플릿을 사용
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
		std::cout << PascalNum<line, num>() << "\t";
		PrintPascalLine<line, num + 1>();
	}
}

int main(int argc, char* argv[])
{
	PrintPascalLine(10);//constexpr for이 나오면 요것도 컴파일타임에 다 될텐데 ㅡㅡ
	PrintPascalLine<10>();

	return 0;
}