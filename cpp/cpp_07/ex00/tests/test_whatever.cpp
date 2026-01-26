/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_whatever.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:58:31 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/26 16:11:02 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "../../catch.hpp"
#include "../includes/whatever.hpp"

/**
 * @brief WHY + HOW?
 * @warning Unit testing must be :
 * * quality > quantity
 * * white(know its implementation)
 * * black(don't know, only input / output)
 * * grey box(have idea on how it works)
 * * TDD / BDD user story based, 1 red test, 1 green pass, refactor(for integration, system, perf tests)
 * * TAD - Black box
 * * Not trivial, too much time consuming
 */
TEST_CASE("Swap handles complex objects", "[templates][swap]") {
	GIVEN("Two custom objects") {
		std::string s1 = "Alpha";
		std::string s2 = "Omega";

		WHEN("swapped") {
			::swap(s1, s2);
			THEN("their values are interchanged") {
				CHECK(s1 == "Omega");
				CHECK(s2 == "Alpha");
			}
		}
	}
}

TEST_CASE("Min handles edge cases", "[templates][min]") {
    SECTION("Equality: should return the second argument") {
        int a = 42;
        int b = 42;
        REQUIRE(&::min(a, b) == &b);
    }
}

TEST_CASE("Max handles edge cases", "[templates][max]") {
    SECTION("Equality: should return the second argument") {
        std::string s1 = "Same";
        std::string s2 = "Same";
        REQUIRE(&::max(s1, s2) == &s2);
    }
}
