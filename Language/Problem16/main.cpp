#include <gsl/gsl>

#include <iostream>
#include <string_view>
#include <array>

class cIPv4
{
	friend std::istream& operator >>(std::istream& i, cIPv4& c)
	{
		char temp;
		return i >> c.m_ip[0] >> temp >> c.m_ip[1] >> temp >> c.m_ip[2] >> temp >> c.m_ip[3];
		//ip주소는 무조건 숫자값밖에 없기 때문에 temp(char)형을 입력받기 전까지
		//주소를 구분하는 .는 char형으로 추론되어 temp에 저장
		//분명 temp를 안쓰고 할수 있는 방법이 있을거같은데
	}
	//내 머리로는 생각나지 않는다 저기에 어떻게 정수형을 char로 받을수 있을까
	friend std::ostream& operator <<(std::ostream& o, cIPv4& c)
	{
		return o << c.m_ip[0] << '.' << c.m_ip[1] << '.' << c.m_ip[2] << '.' << c.m_ip[3];
	}

	using address = int;//unsigned하면 나중에 --하다가 -1이 되는걸 감지할수 없다 char형이면 255때려박을텐데
private:
	std::array<address, 4> m_ip;

public:
	cIPv4() = default;
	~cIPv4() = default;

	cIPv4& operator++()
	{
		for (int i = 3; i > 0; --i)
		{
			if (++m_ip[i] != 256) break;//아 char쓰고싶어
			m_ip[i] = 0;
		}

		return *this;
	}

	bool operator==(const cIPv4& other) const
	{
		for (size_t i = 0; i < 4; ++i)
		{
			if (m_ip[i] != other.m_ip[i]) return false;
		}
		return true;
	}

	bool operator!=(const cIPv4& other) const
	{
		return !(*this == other);
	}
};

int main(int argc, char* argv[])
{
	cIPv4 from, to;
	std::cin >> from >> to;

	do
	{
		std::cout << from << '\t';
	} while (++from != to);

	return 0;
}
