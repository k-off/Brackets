/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/16 13:03:40 by exam          #+#    #+#                 */
/*   Updated: 2019/04/16 13:03:40 by exam          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			brackets(char *s, int *i, char c)
{
	int		res;

	res = 1;
	while (1)
	{
		if (s[*i] == '[' || s[*i] == '{' || s[*i] == '(')
		{
			(*i)++;
			res = brackets(s, i, s[*i - 1]);
		}
		else if ((s[*i] == ']' && c != '[') || (s[*i] == '}' && c != '{')
				|| (s[*i] == ')' && c != '(') || (s[*i] == 0 && c != 0))
			return (0);
		else if ((s[*i] == ']' && c == '[') || (s[*i] == '}' && c == '{')
				|| (s[*i] == ')' && c == '(') || s[*i] == 0)
			break ;
		(*i)++;
	}
	return (1 * res);
}

int			main(int argc, char **argv)
{
	int		i;
	int		j;
	char	c;

	i = 1;
	while (i < argc)
	{
		j = 0;
		c = 0;
		if (i > 1)
			write(1, "\n", 1);
		if (brackets(argv[i], &j, c) == 1)
			write(1, "OK", 2);
		else
			write(1, "Error", 5);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
