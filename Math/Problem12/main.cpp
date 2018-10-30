#include <gsl/gsl>

#include <array>

constexpr size_t MAX_NUM = 1000000;
std::array<size_t, MAX_NUM> table;

constexpr size_t SequenceLength(size_t num)
{
	if (num == 1) return 1;
	return SequenceLength(num % 2 == 0 ? num / 2 : num * 3 + 1) + 1;
}

template<size_t N>
struct CompiledResult
{
	enum { value = SequenceLength(N + 1) };
};

//template<size_t I = MAX_NUM - 1>//템플릿메타프로그래밍으로의 재귀는 2000번까지 허용된다 아니면 C1202를 뱉음
//void MakeTable()
//{
//	MakeTable<I - 1>();
//
//	if(i > 0 && i < MAX_NUM)
//		table[I] = CompiledResult<I>::value;
//}

template<size_t I>//템플릿메타프로그래밍으로의 재귀는 2000번까지 허용된다 아니면 C1202를 뱉음
void MakeTable()
{
	static_assert(I < MAX_NUM * 2, "What?");
	if constexpr (I > 0 && I < MAX_NUM)
	{
		table[I] = CompiledResult<I>::value;
		MakeTable<I * 2>();
		MakeTable<I * 2 + 1>();
	}
}

template<>
void MakeTable<0>()
{
	table[0] = CompiledResult<0>::value;
}

void MakeTable()
{
	MakeTable<0>();
	MakeTable<1>();
}

//template<size_t N = MAX_NUM>
//class Table
//{
//	template <size_t I = N>
//	constexpr void makeTable(std::array<size_t, N> table) noexcept
//	{
//		//static_assert(I, "NOoooooooooo");
//		table[I] = SequenceLength(I + 1);
//		makeTable<I - 1>(table);
//	}
//	template<>
//	constexpr void makeTable<0>(std::array<size_t, N> table) noexcept
//	{
//		table[0] = SequenceLength(1);
//	}
//public:
//	std::array<size_t, N> table;
//	constexpr Table() noexcept
//	{
//		makeTable(table);
//	}
//};
//
//constexpr Table table;

int main(int argc, char* argv[])
{
    //아 결국 어쩌지;;
    return 0;
}
