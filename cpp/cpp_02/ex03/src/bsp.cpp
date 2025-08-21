/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamallet <pamallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:51:49 by paul_mallet       #+#    #+#             */
/*   Updated: 2025/08/21 17:00:27 by pamallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include "../includes/Point.hpp"

/*
	Binary Space Partitioning:
	know if a point is in a triangle area in euclidian space
	A PAB/ABC >= 0 + PBC/ABC >= 0 + PAC/ABC >= 0 === 1
	Triangle area: (base * height) / 2;
	area Shoelase: |( p[0] * (va[1] - vb[1])) + a[0] * (vp[1] - vb[1]) + b[0] * (p[1] - a[1]) )| / 2;
*/
// bool Fixed::BSP( Fixed p[2], Fixed va[2], Fixed vb[2], Fixed vc[2] ) {
// 	Fixed areaABC;
// 	Fixed areaPAB;
// 	Fixed areaPBC;
// 	Fixed areaPAC;

// 	areaABC = (va[0] * (vb[1] - vc[1]) + vb[0] * (vc[1] - va[1]) + vc[0] * (va[1] - vb[1]));
// 	if (areaABC < 0)
// 		areaABC = areaABC * Fixed(-1);
// 	areaPAB = (p[0] * (va[1] - vb[1]) + va[0] * (vb[1] - p[1]) + vb[0] * (p[1] - va[1]));
// 	if (areaPAB < 0)
// 		areaPAB = areaPAB * Fixed(-1);
// 	areaPBC = (p[0] * (vb[1] - vc[1]) + vb[0] * (vc[1] - p[1]) + vc[0] * (p[1] - vb[1]));
// 	if (areaPBC < 0)
// 		areaPBC = areaPBC * Fixed(-1);
// 	areaPAC = (p[0] * (va[1] - vc[1]) + va[0] * (vc[1] - p[1]) + vc[0] * (p[1] - va[1]));
// 	if (areaPAC < 0)
// 		areaPAC = areaPAC * Fixed(-1);

// 	return ((areaPAB >= 0 && areaPBC >= 0 && areaPAC >= 0) && (areaPAB + areaPBC + areaPAC == areaABC));
// }
bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed areaABC;
	Fixed areaPAB;
	Fixed areaPBC;
	Fixed areaPAC;

	std::cout << "pX: " << point.getX() << std::endl;
	std::cout << "pY: " << point.getY() << std::endl;
	std::cout << "aX: " << a.getX() << std::endl;
	std::cout << "aY: " << a.getY() << std::endl;
	std::cout << "bX: " << b.getX() << std::endl;
	std::cout << "bY: " << b.getY() << std::endl;
	std::cout << "cX: " << c.getX() << std::endl;
	std::cout << "cY: " << c.getY() << std::endl;

	areaABC = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()));
	if (areaABC < 0)
		areaABC = areaABC * -1;
	areaPAB = (point.getX() * (a.getY() - b.getY()) + a.getX() * (b.getY() - point.getY()) + b.getX() * (point.getY() - a.getY()));
	if (areaPAB < 0)
		areaPAB = areaPAB * -1;
	areaPBC = ( (point.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - point.getY())) + (c.getX() * (point.getY() - b.getY())) );
	if (areaPBC < 0)
		areaPBC = areaPBC * -1;
	areaPAC = (point.getX() * (a.getY() - c.getY()) + a.getX() * (c.getY() - point.getY()) + c.getX() * (point.getY() - a.getY()));
	if (areaPAC < 0)
		areaPAC = areaPAC * -1;

	std::cout << "ABC: " << areaABC << std::endl;
	std::cout << "PAB: " << areaPAB << std::endl;
	std::cout << "PBC: " << areaPBC << std::endl;
	std::cout << "PAC: " << areaPAC << std::endl;
	return ((areaPAB > 0 && areaPBC > 0 && areaPAC > 0) && (areaPAB + areaPBC + areaPAC == areaABC));
}