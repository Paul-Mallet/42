/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:06:06 by pamallet          #+#    #+#             */
/*   Updated: 2024/12/20 18:41:20 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pxl;
	int	line_len;
	int	endian;
}		t_data;

# define W_WIDTH 194
# define W_HEIGHT 259

#endif
