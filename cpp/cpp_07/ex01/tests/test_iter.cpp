/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 15:34:45 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/26 16:10:21 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../catch.hpp"
#include "../includes/iter.hpp"

/**
 * @brief Use a template function to iterate through random type array values to apply modifications on them.
 * @param String - The address of an array
 * @param uint - The length of the array
 * @param f - Function that will be called on every element of the array
 */
SCENARIO("iter handles any type of array", "[templates][]") {
	GIVEN("an int array of length 3") {
		unsigned int const len = 3;
		int array[] = { 1, 2, 3 };
		std::string arr2[] = { "mama", "momo", "mumu" };
		// std::string const arr2[] = { "mama", "momo", "mumu" };

		WHEN("applying non-const addtwo template function") {
			::iter(array, len, &add_two<int>);
			::iter(arr2, len, &add_two<std::string>);

			THEN("array must add 2 at every int") {
				REQUIRE(array[0] == 3);
				REQUIRE(array[1] == 4);
				REQUIRE(array[2] == 5);
			}

			THEN("arr2 must concatenate 2 at every string") {
				CHECK(arr2[0] == "mama2");
				CHECK(arr2[1] == "momo2");
				CHECK(arr2[2] == "mumu2");
			}
		}

		WHEN("applying const print template function") {
			::iter(array, len, &print<int>);
			::iter(arr2, len, &print<std::string>);

			THEN("array must remain unchanged as it's values were displayed") {
				REQUIRE(array[0] == 1);
				REQUIRE(array[1] == 2);
				REQUIRE(array[2] == 3);
			}

			THEN("arr2 must remain unchanged string") {
				REQUIRE(arr2[0] == "mama");
				REQUIRE(arr2[1] == "momo");
				REQUIRE(arr2[2] == "mumu");
			}
		}
	}
}

// 