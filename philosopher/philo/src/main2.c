/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:24:01 by pamallet          #+#    #+#             */
/*   Updated: 2025/05/16 15:47:32 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>

int	main(void)
{
	/* gettimeofday() */
	struct timeval tv;

	gettimeofday(&tv, NULL);
	printf("time of day(sec): %ld.%ld\n", tv.tv_sec, tv.tv_usec);
	return (0);

	/*  */
}