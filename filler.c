/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:46:53 by rasingh           #+#    #+#             */
/*   Updated: 2018/07/17 10:35:06 by rasingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>

int	ft_size(char **arr)
{
	int	i;
	int	j;
	int	x[6];
	char **tmp;

	i = 0;
	while (arr[i])
	{
		if (ft_strnequ(arr[i], "Plateau", 7))
		{
			j = 0;
			while (arr[i][j] < 48 || arr[i][j] > 57)
				j++;
			x[0] = ft_atoi(ft_strsub(arr[i], j, 2));
			x[2] = ft_atoi(ft_strsub(arr[i], j + 3, 2));
		}
		if ((tmp = ft_strsplit(ft_strstr(arr[i], "Piece"), ' ')))
		{
			x[1] = ft_atoi(tmp[1]);
			x[3] = ft_atoi(tmp[2]);
		}
		i++;
	}
	i = ((x[1] <= x[0]) && (x[3] <= x[2])) ? 1 : 0;
	return (i);
}

char	**ft_getpiece(char **arr)
{
	int		i;
	int		j;
	char	**piece;

	i = 0;
	j = 0;
	piece = (char**)ft_strnew(50);
	if (ft_size(arr))  // checks that piece can fit into array
	{
		while (arr[i])
		{
			if (ft_strnequ(arr[i], "Piece", 5))
			{
				i++;
				while (arr[i][0] == '.' || arr[i][0] == '*')
				{
					piece[j] = arr[i];
					i++;
					j++;
				}
				return (piece);
			}
			i++;
		}
	}
	return (NULL);
}

void	ft_place()  //////////////////
{
	write(1, "8 2", 3);

//	ft_putchar('\n');
}												///////////////////////

/*int	main(int ac, char **av)
{
// *Read in Grid from stdin (needs to be edited)* && Determines Char*

	(void)ac;   //////////////////////////////////
	int     i = 0 ;
	char    *line =  NULL;
	int     ret = 1;
	int     fd = open(av[1], O_RDONLY); //
	char    *arr[120];
	char    letter; ///Determine Char
	//	int     start; ///Determine Char
	while (ret && (ft_strnequ(line, "got", 3) == 0))
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			write(1, "Insert File", 11);
			exit(4) ;
		}
		if (ft_strcmp(line, "$$$ exec p1 : [players/rasingh.filler]") == 0)  //////////////
			letter = 'O';                                                 //   For    //
		if (ft_strcmp(line, "$$$ exec p2 : [players/rasingh.filler]") == 0)//    Char  //
			letter = 'X';                                              //////////////
		if (ret)
		{
			arr[i] = line;
			i++;
		}
	//		ft_putarr(arr); //////////////////////////////
	}
	// *Get Piece && Locate Chars*
	char **piece;
	if ((piece = ft_getpiece(arr)) != NULL)
	{
		/////////////////////
		int j;
		i = 0;
		while (arr[i])
		{
			j = 0;
			while (arr[i][j])
			{
				if (arr[i][j] == letter)
					break;
				j++;
			}
			if (arr[i][j] == letter)
				break;
			i++;
		}
		////////////////////
		ft_place(arr, piece, i, j); /////////////////remove///////////
	}
	return (0);
}*/

int	main(/*int ac, char **av*/)
{
// *Read in Grid from stdin (needs to be edited)* && Determines Char*

	//(void)ac;   //////////////////////////////////
	int     i = 0 ;
	char    *line =  NULL;
	int     ret = 1;
	//int     fd = open(av[1], O_RDONLY); //
	char    *arr[120];
	char    letter = '\0'; ///Determine Char
	//	int     start; ///Determine Char
	while (ret)
	{
		ret = get_next_line(0, &line);
		if (ret == -1)
		{
			write(1, "Insert File", 11);
			exit(4) ;
		}
		if (ft_strcmp(line, "$$$ exec p1 : [../rasingh.filler]") == 0)  //////////////
			letter = 'O';                                                 //   For    //
		if (ft_strcmp(line, "$$$ exec p2 : [../rasingh.filler]") == 0)//    Char  //
			letter = 'X';                                              //////////////
		if (ret)
		{
			arr[i] = line;
			i++;
		}
	//		ft_putarr(arr); //////////////////////////////
	}
	// *Get Piece && Locate Chars*
/*	char **piece;
	if ((piece = ft_getpiece(arr)) != NULL)*/
	{
		/////////////////////	
		//int j;
		i = 0;
		while (arr[i])
		{
			j = 0;
			while (arr[i][j])
			{
				if (arr[i][j] == letter)
					break;
				j++;
			}
			if (arr[i][j] == letter)
				break;
			i++;
		}
		////////////////////
		ft_place(); /////////////////remove///////////
	}
	return (0);
}
