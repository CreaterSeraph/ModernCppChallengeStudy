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
		return -1;//어떤 이유로든 recursive_directory_iterator의 생성이 실패하면 catch될거임
				  //관리자 권한이 필요한 디렉터리라던가 하는 이유에서 에러를 뱉음
	}

	for (auto& iter : fsIter)
		size += iter.file_size();

	std::cout << size << std::endl;

	return 0;
}