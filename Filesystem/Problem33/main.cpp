#include <gsl/gsl>

#include <iostream>
#include <string>
#include <vector>

struct Process
{
	std::wstring name;
	size_t uid;
	enum STAT {
		RUNNING, SYSPENDED
	} status;

	static std::wstring StatToWstring(const STAT& status)
	{
		switch (status)
		{
		case Process::RUNNING:
			return L"Running  ";
		case Process::SYSPENDED:
			return L"Syspended";
		default:
			return L"ERROR";
		}
	}

	std::wstring user;
	size_t memory;
	size_t bit;

	Process(const std::wstring& name, size_t uid, STAT status, const std::wstring& user, size_t memory, size_t bit)
		:name(name), uid(uid), status(status), user(user), memory(memory), bit(bit)
	{
	}

	friend std::wostream& operator<<(std::wostream& o, const Process& p)
	{
		return o << p.name << "\t" << p.uid << "\t" << StatToWstring(p.status) << "\t" << p.user << "\t" << p.memory << "\t" << p.bit << std::endl;
	}
};

int main(int argc, char* argv[])
{
	std::vector<Process> vecProcess;

	vecProcess.emplace_back(L"chrome.exe", 1044, Process::RUNNING, L"user", 25180, 32);
	vecProcess.emplace_back(L"chrome.exe", 10110, Process::RUNNING, L"user", 227756, 32);
	vecProcess.emplace_back(L"cmddd.exe", 512, Process::RUNNING, L"SYSTEM", 48, 64);
	vecProcess.emplace_back(L"skype.exe", 22456, Process::SYSPENDED, L"user", 656, 64);

	for (auto& iter : vecProcess)
		std::wcout << iter;

	return 0;
}