#include "Point.hpp"

Fixed	area_triangle(Point const a, Point const b, Point const c)
{
	Fixed	result;

	result = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY()
				- a.getY()) + c.getX() * (a.getY() - b.getY())) / Fixed(2);
	if (result < Fixed(0))
		result = result * Fixed(-1);
	return (result);
}
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed area_abc = area_triangle(a, b, c);
	Fixed area_abp = area_triangle(a, b, point);
	Fixed area_acp = area_triangle(a, c, point);
	Fixed area_bcp = area_triangle(b, c, point);

	if (area_abc == Fixed(0) || area_abp == Fixed(0) || area_acp == Fixed(0)
		|| area_bcp == Fixed(0))
		return (false);

	return (area_abc == area_abp + area_acp + area_bcp);
}