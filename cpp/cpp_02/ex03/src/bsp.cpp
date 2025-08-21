/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:51:49 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/21 11:52:24 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Point.hpp"

/*
	Binary Space Partitioning:
	know if a point is in a triangle area in euclidian space
	A PAB/ABC >= 0 + PBC/ABC >= 0 + PAC/ABC >= 0 === 1
	Triangle area: (base * height) / 2;
	area Shoelase: |( p[0] * (va[1] - vb[1])) + a[0] * (vp[1] - vb[1]) + b[0] * (p[1] - a[1]) )| / 2;
*/
bool Fixed::BSP( Fixed p[2], Fixed va[2], Fixed vb[2], Fixed vc[2] ) {
	Fixed areaABC;
	Fixed areaPAB;
	Fixed areaPBC;
	Fixed areaPAC;

	areaABC = (va[0] * (vb[1] - vc[1]) + vb[0] * (vc[1] - va[1]) + vc[0] * (va[1] - vb[1]));
	if (areaABC < 0)
		areaABC = areaABC * Fixed(-1);
	areaPAB = (p[0] * (va[1] - vb[1]) + va[0] * (vb[1] - p[1]) + vb[0] * (p[1] - va[1]));
	if (areaPAB < 0)
		areaPAB = areaPAB * Fixed(-1);
	areaPBC = (p[0] * (vb[1] - vc[1]) + vb[0] * (vc[1] - p[1]) + vc[0] * (p[1] - vb[1]));
	if (areaPBC < 0)
		areaPBC = areaPBC * Fixed(-1);
	areaPAC = (p[0] * (va[1] - vc[1]) + va[0] * (vc[1] - p[1]) + vc[0] * (p[1] - va[1]));
	if (areaPAC < 0)
		areaPAC = areaPAC * Fixed(-1);

	return ((areaPAB >= 0 && areaPBC >= 0 && areaPAC >= 0) && (areaPAB + areaPBC + areaPAC == areaABC));
}