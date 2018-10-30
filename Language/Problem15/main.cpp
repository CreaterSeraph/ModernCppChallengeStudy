#include <gsl/gsl>

#include <iostream>
#include <string_view>

class cIPv4
{
	friend std::istream& operator >>(std::istream& i, cIPv4& c)
	{
		char temp;
		return i >> c.ip[0] >> temp >> c.ip[1] >> temp >> c.ip[2] >> temp >> c.ip[3];
		//ip�ּҴ� ������ ���ڰ��ۿ� ���� ������ temp(char)���� �Է¹ޱ� ������
		//�ּҸ� �����ϴ� .�� char������ �߷еǾ� temp�� ����
		//�и� temp�� �Ⱦ��� �Ҽ� �ִ� ����� �����Ű�����
		//�и� �� �ڷ����� int�� �ƴ϶� unsigned char������ �Ҽ� �����Ű�����...
	}
	friend std::ostream& operator <<(std::ostream& o, cIPv4& c)
	{
		return o << c.ip[0] << '.' << c.ip[1] << '.' << c.ip[2] << '.' << c.ip[3];
	}

	using address = unsigned int;
private:
	address ip[4];

public:
	cIPv4() = default;
	~cIPv4() = default;
};

int main(int argc, char* argv[])
{
	cIPv4 ipv4;
	std::cin >> ipv4;

	std::cout << ipv4;

	return 0;
}
