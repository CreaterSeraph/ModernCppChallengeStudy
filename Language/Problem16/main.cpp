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
		//ip�ּҴ� ������ ���ڰ��ۿ� ���� ������ temp(char)���� �Է¹ޱ� ������
		//�ּҸ� �����ϴ� .�� char������ �߷еǾ� temp�� ����
		//�и� temp�� �Ⱦ��� �Ҽ� �ִ� ����� �����Ű�����
	}
	//�� �Ӹ��δ� �������� �ʴ´� ���⿡ ��� �������� char�� ������ ������
	friend std::ostream& operator <<(std::ostream& o, cIPv4& c)
	{
		return o << c.m_ip[0] << '.' << c.m_ip[1] << '.' << c.m_ip[2] << '.' << c.m_ip[3];
	}

	using address = int;//unsigned�ϸ� ���߿� --�ϴٰ� -1�� �Ǵ°� �����Ҽ� ���� char���̸� 255���������ٵ�
private:
	std::array<address, 4> m_ip;

public:
	cIPv4() = default;
	~cIPv4() = default;

	cIPv4& operator++()
	{
		for (int i = 3; i > 0; --i)
		{
			if (++m_ip[i] != 256) break;//�� char����;�
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
