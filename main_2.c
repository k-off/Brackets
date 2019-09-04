/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 13:02:19 by exam          #+#    #+#                 */
/*   Updated: 2019/09/03 13:02:19 by exam          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		get_type(char c)
{
	if (c == '[')
		return (1);
	else if (c == '{')
		return (2);
	else if (c == '(')
		return (3);
	else if (c == ']')
		return (-1);
	else if (c == '}')
		return (-2);
	else if (c == ')')
		return (-3);
	else
		return (0);
}

int		brackets(char *s)
{
	int	brk[100000];
	int	tmp;
	int	i;

	i = 0;
	while (i < 100000)
		brk[i++] = 0;
	while (s[0])
	{
		i = 0;
		tmp = 0;
		while (brk[i] != 0)
			i++;
		brk[i] = (get_type(s[0]) > 0) ? get_type(s[0]) : 0;
		tmp = (get_type(s[0]) < 0) ? -get_type(s[0]) : 0;
		if (tmp != 0)
			brk[i - 1] -= tmp;
		if (tmp != 0 && (i == 0 || brk[i - 1] != 0))
			return (0);
		s++;
	}
	i = 0;
	while (brk[i] != 0)
		i++;
	return ((i == 0) ? 1 : 0);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (i < argc)
	{
		if (brackets(argv[i]) == 1)
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		i++;
	}
	return (0);
}
