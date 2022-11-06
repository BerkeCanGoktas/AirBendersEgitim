#include "regularpolygon.h"

/*
* Constructor for objects
* @param edges -> (int) number of edges of polygon
*/
RegularPolygon::RegularPolygon(int edges) : m_edges{ edges }
{
	m_angle = M_PI / m_edges;
	m_counter++;
}

/*
* Calculates the area of polygon with given length
* @param length -> (double) length of an edge
* @return (double) calculated area of the polygon
*/
double RegularPolygon::area(double length)
{
	return (length * length * m_edges) / (4 * tan(M_PI / m_edges));
}

/*
* Calculates the length of polygon with given area
* @param area -> (double) area of polygon
* @return (double) calculated length of an edge
*/
double RegularPolygon::length(double area)
{
	return sqrt((4 * area * tan(M_PI / m_edges)) / m_edges);
}

/*
* Returns the total number of living objects of the class
* @return (int) number of living objects
*/
int RegularPolygon::getCounter() const
{
	return m_counter;
}


/* Destructor for objects
*/
RegularPolygon::~RegularPolygon()
{
	m_counter--;
}
