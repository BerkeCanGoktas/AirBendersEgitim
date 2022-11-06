#include <iostream>
#include <vector>

/*
* Creates an m*n matrix whose all entries are the given value
* @param value -> (T) any type of value given
* @param rows -> (int) number of rows for matrix
* @param cols -> (int) number of cols for matrix
* @return (std::vector<std::vector<T>>) the resulting matrix
*/
template<class T>
std::vector<std::vector<T>> createMatrix(T value, int rows, int cols)
{
	std::vector<std::vector<T>> matrix{};
	std::vector<T> rowVector{};
	for (int i = 0; i < rows; i++)
	{
		for (int i = 0; i < cols; i++)
		{
			rowVector.push_back(value);
		}
		matrix.push_back(rowVector);
		rowVector = {};
	}
	return matrix;
}

int main()
{
	std::vector<std::vector<double>> matrix{ createMatrix(5.8, 7, 2) }; //type can be changed for tests,
	for (std::vector<double> row : matrix)							   //double was the final test while writing
	{																  //and left as the way it was
		for (double entry : row)
		{
			std::cout << entry << " ";
		}
		std::cout << '\n';
	}
}