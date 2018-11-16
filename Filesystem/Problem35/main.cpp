#include <gsl/gsl>

#include <iostream>
#include <string>
#include <filesystem>

int main(int argc, char* argv[])
{
	std::wstring path;
	std::wcin >> path;

	size_t size = 0;

	std::filesystem::recursive_directory_iterator fsIter;
	try
	{
		fsIter = std::filesystem::recursive_directory_iterator(path);
	}
	catch (...)
	{
		return -1;//� �����ε� recursive_directory_iterator�� ������ �����ϸ� catch�ɰ���
				  //������ ������ �ʿ��� ���͸������ �ϴ� �������� ������ ����
	}

	for (auto& iter : fsIter)
		size += iter.file_size();

	std::cout << size << std::endl;

	return 0;
}