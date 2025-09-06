#include "Point.hpp"
#include <cmath>

float	area_triangle(Point const a, Point const b, Point const c)
{
	return (std::abs(0.5f * (a.getX() * (b.getY() - c.getY()) + b.getX()
				* (c.getY() - a.getY()) + c.getX() * (a.getY()
					- b.getY())).toFloat()));
}
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	/*
	a
	| |
	| | |
	b | | c
	*/
	Fixed area_abc = area_triangle(a, b, c);
	Fixed area_abp = area_triangle(a, b, point);
	Fixed area_acp = area_triangle(a, c, point);
	Fixed area_bcp = area_triangle(b, c, point);
	if (area_abc == 0 || area_abp == 0 || area_acp == 0 || area_bcp == 0 || area_abc != area_abp + area_acp + area_bcp)
		return (false);
	return (true);
}