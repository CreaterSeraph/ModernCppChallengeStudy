#include <gsl/gsl>

#include <string>
#include <iostream>

int main(int argc, char* argv[])
{
    size_t input;

	std::cin >> input;

	std::wstring result;

	size_t m = input / 1000;
	input -= m * 1000;
	size_t d = input / 500;
	input -= d * 500;
	size_t c = input / 100;
	input -= c * 100;
	size_t l = input / 50;
	input -= l * 50;
	size_t x = input / 10;
	input -= x * 10;
	
	result.insert(result.end(), m, L'M');
	result.insert(result.end(), d, L'D');
	result.insert(result.end(), c, L'C');
	result.insert(result.end(), l, L'L');
	result.insert(result.end(), x, L'X');
	if(input > 0)
		result.insert(result.end(), L'Ⅰ' + input - 1);

	std::wcout.imbue(std::locale("kor"));//ㅎㅎ;;
	std::wcout << result << std::endl;

	//constexpr int temp1 = L'Ⅰ';
	//constexpr int temp2 = L'Ⅱ';
	//constexpr int temp3 = L'Ⅲ';
	//constexpr int temp4 = L'Ⅳ';
	//constexpr int temp5 = L'Ⅴ';
	//constexpr int temp6 = L'Ⅵ';
	//constexpr int temp7 = L'Ⅶ';
	//constexpr int temp8 = L'Ⅷ';
	//constexpr int temp9 = L'Ⅸ';
	//constexpr int temp10 = L'Ⅹ';
	//유니코드로는 1~10순서가 제대로임을 검증해따

    return 0;
}
