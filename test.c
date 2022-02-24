#include "header.h"
#include <string.h>

int ft_isnumber(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i = 1;
	int	count = 0;
	
	while (i < ac)
	{
		if (ft_isnumber(av[i]))
			count++;
		i++;
	}
	printf("%d\n", count);
	return (0);
}