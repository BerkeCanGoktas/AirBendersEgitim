#include <iostream> //for std::cout
#include <vector> //for std::vector

/*
* Calculates the mean of a given set
* @param data -> (std::vector<double> the set given
* @return (double) the mean of the given set
*/
double mean(std::vector<double> data)
{
	double sum{ 0.0 };
	for(double element : data)
	{
		sum += element;
	}
	return sum / data.size();
}

/*
* Calculates the standard deviation of a given set
* @param data -> (std::vector<double> the set given
* @return (double) the standard deviation of the given set
*/
double stddev(std::vector<double> data)
{
	double dataMean{ mean(data) };
	double sum{ 0.0 };
	for(double element : data)
	{
		sum += (element - dataMean) * (element - dataMean);
	}
	return sqrt(sum / (data.size() - 1));
}

int main()
{
	std::vector<double> trivialVector{ 7.2, 89.0, 45.4, 75.4, 35.9, 46.92, 13.666 }; //test vector1
	//std::vector<double> trivialVector{ 3, 3, 6, 8, 12, 5 }; //test vector2
	std::cout << "The trivial data set is: ";
	for (double element : trivialVector)
	{
		std::cout << element << " ";
	}
	std::cout << '\n';
	std::cout << "Mean of the data set: " << mean(trivialVector) << '\n';
	std::cout << "Standard deviation of the data set: " << stddev(trivialVector) << '\n';
} 
