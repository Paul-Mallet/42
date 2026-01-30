/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_whatever.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:58:31 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/30 09:00:40 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include <string>
#include "whatever.hpp"

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
        REQUIRE(&::min(a, b) != &a);
    }
}

TEST_CASE("Max handles edge cases", "[templates][max]") {
    SECTION("Equality: should return the second argument") {
        std::string s1 = "Same";
        std::string s2 = "Same";
        REQUIRE(&::max(s1, s2) == &s2);
        REQUIRE(&::max(s1, s2) != &s1);
    }
}
