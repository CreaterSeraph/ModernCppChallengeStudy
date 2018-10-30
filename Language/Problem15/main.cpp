#include <gsl/gsl>

#include <iostream>
#include <string_view>

class cIPv4
{
	friend std::istream& operator >>(std::istream& i, cIPv4& c)
	{
		char temp;
		return i >> c.ip[0] >> temp >> c.ip[1] >> temp >> c.ip[2] >> temp >> c.ip[3];
		//ip주소는 무조건 숫자값밖에 없기 때문에 temp(char)형을 입력받기 전까지
		//주소를 구분하는 .는 char형으로 추론되어 temp에 저장
		//분명 temp를 안쓰고 할수 있는 방법이 있을거같은데
		//분명 저 자료형도 int가 아니라 unsigned char형으로 할수 있을거같은데...
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
