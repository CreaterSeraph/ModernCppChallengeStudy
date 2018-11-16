#include <gsl/gsl>

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int main(int argc, char* argv[])
{
	std::wstring filePath;
	std::wcin >> filePath;

	std::wifstream input(filePath);
	std::wofstream output(L"temp.txt");//임시 파일을 생성한다

	if (!input.is_open()) return -1;//없는 filePath
	if (!output.is_open()) return -1;//파일생성이 실패

	constexpr size_t bufSize = 65536;
	wchar_t str[bufSize];
	while (!input.eof())
	{
		input.getline(str, bufSize);
		if (str[0] == NULL)
			continue;

		output << str << std::endl;//임시파일에 파일 내용을 작성한다
	}

	std::filesystem::remove(filePath);
	std::filesystem::rename("temp.txt", filePath);//이름을 통채로 갈아끼워버리면 되는게 아닐까? ㅎㅎ;;

	return 0;
}