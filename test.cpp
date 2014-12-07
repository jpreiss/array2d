#include "array2D.hpp"
#include <cassert>

int main()
{
	{
		StaticArray2D<int, 4, 3> arr;
		assert(arr.rows() == 4);
		assert(arr.columns() == 3);
		assert(arr.to1D(0, 0) == 0);
		assert(arr.to1D(2, 1) == 7);
		assert(arr.to2D(7).first == 2);
		assert(arr.to2D(7).second == 1);
		arr(1, 2) = 42;
		assert(arr(1, 2) == 42);
		arr[8] = 100;
		assert(arr[8] == 100);
		assert(&arr[0] == arr.data());
		assert(arr.data() == arr.begin());
		assert(arr.end() == arr.data() + 4 * 3);
	}

	{
		Array2D<int> arr(4, 3);
		assert(arr.rows() == 4);
		assert(arr.columns() == 3);
		assert(arr.to1D(0, 0) == 0);
		assert(arr.to1D(2, 1) == 7);
		assert(arr.to2D(7).first == 2);
		assert(arr.to2D(7).second == 1);
		arr(1, 2) = 42;
		assert(arr(1, 2) == 42);
		arr[8] = 100;
		assert(arr[8] == 100);
		assert(&arr[0] == arr.data());
		assert(arr.data() == arr.begin());
		assert(arr.end() == arr.data() + 4 * 3);
	}
}

