#ifndef REGULARPOLYGON
#define REGULARPOLYGON

#define _USE_MATH_DEFINES //for M_PI
#include <cmath>		 //for M_PI

/*
* Class for maintaining regular polygons
* @member_var m_edges (int) -> variable for number of sides of the polygon
* @member_var m_angle (double) -> variable for the angle AOB whenever A and
* B are the two subsequent corners of the polygon and O is the center of the polygon
* @member_var m_counter (static int) -> counter for total created objects
* @function RegularPolygon(int) -> constructor of the class
* @function ~RegularPolygon() -> destructor of the class
* @function area(double) -> gives the area of the polygon with given edge length
* @function length(double) -> gives the length of an edge of the polygon with the given area
*/
class RegularPolygon
{
public:
	RegularPolygon(int edges);
	double area(double length); 
	double length(double area); 
	int getCounter() const;
	~RegularPolygon();

	
private:
	int m_edges;
	double m_angle;
	static int m_counter;
};

#endif
