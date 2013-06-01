#ifndef __ARRAY2D_HPP__
#define __ARRAY2D_HPP__

#include <utility>
#include <vector>

template <typename T, size_t Rows, size_t Columns>
class StaticArray2D
{
public:
	// default-construct all data
	void initialize()
	{
		for (size_t i = 0; i < Rows * Columns; ++i)
		{
			data_[i] = T();
		}
	}

	size_t rows()
	{
		return Rows;
	}

	size_t columns()
	{
		return Columns;
	}

	size_t to1D(size_t row, size_t column)
	{
		return row * Columns + column;
	}

	std::pair<size_t, size_t> to2D(size_t index)
	{
		std::pair<size_t, size_t> result;
		result.first = index / Columns;
		result.second = index % Columns;
		return result;
	}

	T const &operator[](size_t index) const
	{
		return data_[index];
	}

	T &operator[](size_t index)
	{
		return data_[index];
	}

	T const &operator()(size_t row, size_t column) const
	{
		return data_[to1D(row, column)];
	}

	T &operator()(size_t row, size_t column)
	{
		return data_[to1D(row, column)];
	}

	T const *begin() const
	{
		return data_;
	}

	T *begin()
	{
		return data_;
	}

	T const *end() const
	{
		return data_ + Rows * Columns;
	}

	T *end()
	{
		return data_ + Rows * Columns;
	}

private:
	T data_[Rows * Columns];
};


template <typename T>
class Array2D
{
public:
	Array2D(size_t rows, size_t columns) :
		rows_(rows),
		columns_(columns),
		data_(rows * columns)
	{
	}

	size_t rows()
	{
		return rows_;
	}

	size_t columns()
	{
		return columns_;
	}

	size_t to1D(size_t row, size_t column)
	{
		return row * columns_ + column;
	}

	std::pair<size_t, size_t> to2D(size_t index)
	{
		std::pair<size_t, size_t> result;
		result.first = index / columns_;
		result.second = index % columns_;
		return result;
	}

	T const &operator[](size_t index) const
	{
		return data_[index];
	}

	T &operator[](size_t index)
	{
		return data_[index];
	}

	T const &operator()(size_t row, size_t column) const
	{
		return data_[to1D(row, column)];
	}

	T &operator()(size_t row, size_t column)
	{
		return data_[to1D(row, column)];
	}

	T const *begin() const
	{
		return data_.data();
	}

	T *begin()
	{
		return data_.data();
	}

	T const *end() const
	{
		return data_.data() + rows_ * columns_;
	}

	T *end()
	{
		return data_.data() + rows_ * columns_;
	}

private:
	size_t rows_;
	size_t columns_;
	std::vector<T> data_;
};
#endif // __ARRAY2D_HPP__
