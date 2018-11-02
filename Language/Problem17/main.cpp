#include <gsl/gsl>

#include <iostream>
#include <array>

template<typename T, size_t R, size_t C>
class cArray2D
{
public:
	std::array<std::array<T, C>, R> m_array;
public:
	cArray2D() = default;
	cArray2D(const cArray2D& other)
		:m_array(other.m_array)
	{
	}
	cArray2D(cArray2D&& other)
		:m_array(std::move(other.m_array))
	{
	}

	std::array<T, R>& operator[](size_t size)
	{
		return m_array[size];
	}

	T& at(size_t row, size_t col)
	{
		return m_array[row][col];
	}

	decltype(auto) data()
	{
		return m_array.data();
	}

	static constexpr size_t totalSize()
	{
		return R * C;
	}

	T* begin() { return &m_array[0][0]; }
	T* end() { return &m_array.back().data()[C]; }//이거 코드 더럽다;;

	void fill(const T& data)
	{
		for (auto& iter : m_array)
			iter.fill(data);
	}

	void swap(cArray2D& other)
	{
		std::swap(this->m_array, other.m_array);
	}
};

int main(int argc, char* argv[])
{
	cArray2D<int, 4, 5> hi;
	cArray2D<int, 4, 5> bye;

	int i = 0;
	for (auto& iter : hi)
		iter = ++i;

	for (auto iter : hi)
		std::cout << iter << '\t';
	std::cout << std::endl;

	bye.fill(5);
	for (auto iter : bye)
		std::cout << iter << '\t';
	std::cout << std::endl;

	hi.swap(bye);

	for (auto iter : hi)
		std::cout << iter << '\t';
	std::cout << std::endl;

	for (auto iter : bye)
		std::cout << iter << '\t';
	std::cout << std::endl;

	return 0;
}