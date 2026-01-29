/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ScalarConverter.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 23:24:19 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/29 10:01:56 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "ScalarConverter.hpp"

SCENARIO("Pseudo-literals handling", "[special]") {
    GIVEN("Special floating point strings") {
        WHEN("Input is 'nan' or 'nanf'") {
            THEN("Output should show 'char: impossible', 'int: impossible', 'float: nanf', 'double: nan'") {
                ScalarConverter::convert("nan");
                ScalarConverter::convert("nanf");
                std::cout << std::endl;
            }
        }
        WHEN("Input is '+inf' or '-inff'") {
            THEN("Output should show infinite values correctly") {
                ScalarConverter::convert("+inf");
                ScalarConverter::convert("-inff");
                std::cout << std::endl;
            }
        }
    }
}

SCENARIO("Standard types parsing", "[basic]") {
    GIVEN("A single character") {
        THEN("Should display the char and its conversions") {
            ScalarConverter::convert("a");
            std::cout << std::endl;
        }
    }
    GIVEN("An integer") {
        THEN("Should display int and conversions") {
            ScalarConverter::convert("42");
            std::cout << std::endl;
        }
    }
    GIVEN("A float literal") {
        THEN("Should detect the 'f' and display correctly") {
            ScalarConverter::convert("42.42f");
            ScalarConverter::convert("43.f");
            std::cout << std::endl;
        }
    }
    GIVEN("A double literal") {
        THEN("Should detect the '.' and display correctly") {
            ScalarConverter::convert("-42.42");
            std::cout << std::endl;
        }
    }
}

SCENARIO("Malicious and edge cases", "[edge]") {
    GIVEN("Overflowing values") {
        WHEN("Input is larger than int max") {
            THEN("Int should display 'impossible' but double should work") {
                ScalarConverter::convert("2147483648");
                std::cout << std::endl;
            }
        }
    }
    GIVEN("Non-displayable characters") {
        WHEN("Int value is 31") {
            THEN("Char should display 'Non displayable'") {
                ScalarConverter::convert("31");
                std::cout << std::endl;
            }
        }
    }
    GIVEN("Invalid inputs") {
        WHEN("Input is gibberish") {
            THEN("Everything should be impossible or default handled") {
                ScalarConverter::convert("043.8");
                ScalarConverter::convert("42.42ff");
                ScalarConverter::convert("-+42");
                ScalarConverter::convert("abc42");
            }
        }
    }
}