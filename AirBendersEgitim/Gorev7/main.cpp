#include <iostream> //for std::cout
#include <stdlib.h> //for atof()
#include <vector> //for std::vector

int main(int argc, char* argv[])
{
	std::vector<std::vector<float>> matrix{};
	std::vector<float> row{};
	for (int i = 0; i < atof(argv[2]); i++)
	{
		for (int j = 3; j < argc; j++)
		{
			if (i == 0)
			{
				row.push_back(atof(argv[j]) * atof(argv[2]));
			}
			else
			{
				row.push_back(atof(argv[j]));
			}
		}
		matrix.push_back(row);
		row.clear();
	}

	std::cout << "The matrix given by the command line arguments: " << '\n';
	for (std::vector<float> row : matrix)
	{
		for (float entry : row)
		{
			std::cout << entry << " ";
		}
		std::cout << '\n';
	}
}