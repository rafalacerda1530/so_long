#include "../so_long.h"

static int	pos(int c)
{
	int	cont;

	cont = 0;
	if (c == 0)
		return (1);
	if (c < 0)
	{
		cont = 1;
		while (c < 0)
		{
			c /= 10;
			cont++;
		}
	}
	while (c > 0)
	{
		c /= 10;
		cont++;
	}
	return (cont);
}

char	*ft_itoa(int n)
{
	char			*newint;
	unsigned int	i;
	unsigned int	new_n;

	if (n < 0)
		new_n = -n;
	else
		new_n = n;
	i = pos(n);
	newint = (char *)malloc(sizeof(char) * i + 1);
	if (newint == NULL)
		return (NULL);
	newint[i] = '\0';
	while (i > 0)
	{
		i--;
		newint[i] = (new_n % 10) + '0';
		new_n /= 10;
	}
	if (n < 0)
		newint[0] = '-';
	return (newint);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*temp;

	if ((nmemb * size) > INT_MAX)
		return (NULL);
	temp = malloc(nmemb * size);
	if (temp == NULL)
		return (NULL);
	ft_mem_set(temp, 0, (nmemb * size));
	return ((void *)temp);
}

char	*ft_mem_set(void *str, int c, size_t n)
{
	size_t			cont;
	unsigned char	*n_str;

	cont = 0;
	n_str = (unsigned char *) str;
	while (cont < n)
	{
		n_str[cont] = (unsigned char) c;
		cont++;
	}
	return (str);
}

size_t	ft_strlcopy(char *dst, const char *src, size_t n)
{
	size_t	cont;

	if (n == 0)
		return (ft_strlen(src));
	cont = 0;
	while (cont < (n - 1) && src[cont])
	{
		dst[cont] = src[cont];
		cont++;
	}
	dst[cont] = '\0';
	return (ft_strlen(src));
}
