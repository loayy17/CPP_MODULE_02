#include "Point.hpp"

float	stringToFloat(const char *str)
{
	float	result = 0.0f;
	float	fraction = 0.0f;
	int		sign = 1;
	bool	decimal = false;
	float	divisor = 1.0f;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			if (decimal)
			{
				divisor *= 10.0f;
				fraction = fraction * 10.0f + (*str - '0');
			}
			else
				result = result * 10.0f + (*str - '0');
		}
		else if (*str == '.' && !decimal)
			decimal = true;
		else
			break ;
		str++;
	}
	result += fraction / divisor;
	return (result * sign);
}

int	main(int ac, char **av)
{
	if (ac != 9)
	{
		std::cerr << "Usage: " << av[0] << " ax ay bx by cx cy pointX pointY" << std::endl;
		return (1);
	}
	Point a(stringToFloat(av[1]), stringToFloat(av[2]));
	Point b(stringToFloat(av[3]), stringToFloat(av[4]));
	Point c(stringToFloat(av[5]), stringToFloat(av[6]));
	Point point(stringToFloat(av[7]), stringToFloat(av[8]));
	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle" << std::endl;
	return (0);
}