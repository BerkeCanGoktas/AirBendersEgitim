#include <fstream>    //for std::ifstream
#include <iostream>  //for std::cout
#include <sstream>  //for std::istringstream
#include <string>  //for std::string and std::getline
#include <vector> //for std::vector

//A namespace for doing the matrice reading operations over files
namespace matrix_reader
{
	typedef std::vector<std::vector<std::string>>  Matrix;
	typedef std::vector<std::string> Vector;

	/*
	* Reads matrices with nxm dimensions from files
	* @param fileName -> (std::string) name of given file
	* @return (Matrix) matrix read from the file
	*/
	Matrix nByMReader(std::string fileName)
	{
		std::ifstream file(fileName);
		std::string fileVal;
		Matrix matrice;
		Vector vector;
		while (std::getline(file, fileVal)) {
			std::istringstream iss(fileVal);
			std::string entry;
			while (std::getline(iss, entry, ' '))
			{
				vector.push_back(entry);
			}
			matrice.push_back(vector);
			vector.clear();
		}
		file.close();
		return matrice;
	}

	/*
	* Reads vectors files
	* @param fileName -> (std::string) name of given file
	* @return (Vector) vector read from the file
	*/
	Vector nBy1Reader(std::string fileName)
	{
		std::ifstream file(fileName);
		std::string entry;
		Vector vector;
		while (std::getline(file, entry))
		{
			vector.push_back(entry);
		}
		file.close();
		return vector;
	}
}

int main()
{
	std::cout << "Matrix A, read from A.txt: " << '\n';
	std::vector<std::vector<std::string>> matrix = matrix_reader::nByMReader("A.txt");
	for (std::vector<std::string> row : matrix)
	{
		for (std::string entry : row)
		{
			std::cout << entry << " ";
		}
		std::cout << '\n';
	}
	
	std::cout << '\n';

	std::cout << "Vector b, read from b.txt: " << '\n';
	std::vector<std::string> vect = matrix_reader::nBy1Reader("b.txt");
	for (std::string entry : vect)
	{
		std::cout << entry << '\n';
	}
}

/*
* Note: File operations can be improved by adding things
* such as entry control, filename control, etc.
*/