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
		std::cout << PascalNum(line, i) << " ";
	}
}

constexpr void PrintPascal(int line)//Release모드에선 inline화 됨
{
	for (int i = 1; i <= line; ++i)//constexpr for명세가 나오면 여길 완전 컴파일에 할수 있을텐데
	{
		PrintPascalLine(i);
		std::cout << std::endl;
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

//캐시를 만들어서 출력 (template인자를 받아 std::array로)
template<int line>
constexpr void PascalNumCache()
{
	std::array<int, line> arr = { 1, };//현재 라인 정보
	int i = 0;
	while (++i)
	{
		for (int j = 0; j < i; ++j)
			std::cout << arr[j] << ' ';
		std::cout << std::endl;
		if (i == line) break;
		for (int j = i; j > 0; --j)//역순으로 돌아야함
			arr[j] = arr[j] + arr[j - 1];
	}
}

#include <vector>
//캐시를 만들어서 출력 (인자를 받아 std::vector로)
void PascalNumCache(int line)
{
	std::vector<int> arr(line, 0);//현재 라인 정보
	arr[0] = 1;
	int i = 0;
	while (++i)
	{
		for (int j = 0; j < i; ++j)
			std::cout << arr[j] << ' ';
		std::cout << std::endl;
		if (i == line) break;//과연 이게 효과가 더 좋을까;;
		for (int j = i; j > 0; --j)//역순으로 돌아야함
			arr[j] = arr[j] + arr[j - 1];
	}
}

int main(int argc, char* argv[])
{
	PrintPascal(10);//constexpr for이 나오면 요것도 컴파일타임에 다 될텐데 ㅡㅡ
	PrintPascal<10>();
	PascalNumCache(10);
	PascalNumCache<10>();//constexpr cache가 있으면 좋겠다 내가 모르는걸까

	return 0;
}