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
	std::wofstream output(L"temp.txt");//�ӽ� ������ �����Ѵ�

	if (!input.is_open()) return -1;//���� filePath
	if (!output.is_open()) return -1;//���ϻ����� ����

	constexpr size_t bufSize = 65536;
	wchar_t str[bufSize];
	while (!input.eof())
	{
		input.getline(str, bufSize);
		if (str[0] == NULL)
			continue;

		output << str << std::endl;//�ӽ����Ͽ� ���� ������ �ۼ��Ѵ�
	}

	std::filesystem::remove(filePath);
	std::filesystem::rename("temp.txt", filePath);//�̸��� ��ä�� ���Ƴ��������� �Ǵ°� �ƴұ�? ����;;

	return 0;
}