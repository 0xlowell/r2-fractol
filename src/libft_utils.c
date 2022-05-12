#include "../includes/fractol.h"


void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
    int	i;

    i = 0;
    if (!s)
        return ;
    while (s[i])
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
}

int ft_strcmp(const char *s1, const char *s2)

{
    while (*s1 != '\0' && *s2 != '\0' && (*s1 - *s2) == 0)
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && n > i)
	{
		if (s1[i] == s2[i])
			;
		if (!(s1[i] == s2[i]))
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
