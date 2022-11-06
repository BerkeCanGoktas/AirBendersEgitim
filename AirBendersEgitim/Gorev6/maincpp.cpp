#include <iostream> //for std::cout

#include "regularpolygon.h"

int RegularPolygon::m_counter;
int main()
{
	RegularPolygon square(4);
	RegularPolygon square1(4);
	RegularPolygon square2(4);
	std::cout << "Total number of objects: " << square.getCounter() << '\n';
	RegularPolygon square3(4);
	std::cout << "Total number of objects: " << square.getCounter() << '\n';

	std::cout << "Area of a square with length 5: " << square.area(5) << '\n';
	std::cout << "Length of an edge of a square with area 25: "
		      << square.length(25) << '\n';
}