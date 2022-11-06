#include <iostream> //for std::cout and std::cin

#define G 9.80665 //gravity constant

/*
* take input from the user
* @return (float) user input in correct format
*/
float getInput()
{
    while (true) 
    {
        float t{};
        std::cin >> t;
        if (!std::cin)
        {
            std::cin.clear();
            std::cerr << "Please enter a valid time and try again!" << '\n';
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return t;
        }
    }
}

/*
* calculate and return the free fall distance for
* given time t
* @param t -> (float) time variable
* @return (float) calculated distance
*/
float calculateDistance(float t)
{
    float distance = G * t * t / 2;
    return distance;
}

int main()
{
	std::cout << "This program computes the distance of a free falling "
				 "object with respect to the given time t" << '\n'
			  << "Please enter the time: " << '\n';

    float t{ getInput() };

    std::cout << "The distance taken by a free falling object at your given time t = " 
              << t << " is: " << calculateDistance(t) << " (m/s^2)";
}