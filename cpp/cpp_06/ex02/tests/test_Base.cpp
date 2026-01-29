/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_Base.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:05:29 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/29 10:21:47 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include <sstream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

struct RedirectCout {
    std::stringstream buffer;
    std::streambuf* old;

    RedirectCout() : old(std::cout.rdbuf(buffer.rdbuf())) {}
    ~RedirectCout() { std::cout.rdbuf(old); }

    std::string str() { return buffer.str(); }
};

SCENARIO("Identify with pointers", "[identify-ptr]") {
    GIVEN("Specific derived classes") {
        Base* a = new A;
        Base* b = new B;
        Base* c = new C;

        THEN("Identify should print the correct class name") {
            {
                RedirectCout capture;
                Base::identify(a);
                REQUIRE(capture.str() == "A\n");
            }
            {
                RedirectCout capture;
                Base::identify(b);
                REQUIRE(capture.str() == "B\n");
            }
            {
                RedirectCout capture;
                Base::identify(c);
                REQUIRE(capture.str() == "C\n");
            }
        }
        delete a; delete b; delete c;
    }

    GIVEN("A NULL pointer") {
        Base* n = NULL;
        RedirectCout capture;
        Base::identify(n);
        THEN("It should print nothing (or handle it gracefully)") {
            REQUIRE(capture.str() == "");
        }
    }
}

SCENARIO("Identify with references", "[identify-ref]") {
    GIVEN("A B object referenced as Base") {
        B realB;
        Base& ref = realB;

        WHEN("Identifying via reference") {
            RedirectCout capture;
            Base::identify(ref);
            THEN("The output should contain 'B'") {
                REQUIRE(capture.str().find("B\n") != std::string::npos);
            }
        }
    }
}

SCENARIO("Random generation distribution", "[generate]") {
    GIVEN("100 random generations") {
        int counts[3] = {0, 0, 0};

        for (int i = 0; i < 100; ++i) {
            Base* p = Base::generate();
            if (dynamic_cast<A*>(p)) counts[0]++;
            else if (dynamic_cast<B*>(p)) counts[1]++;
            else if (dynamic_cast<C*>(p)) counts[2]++;
            delete p;
        }
        THEN("Each type should have been generated at least once") {
            REQUIRE(counts[0] > 0);
            REQUIRE(counts[1] > 0);
            REQUIRE(counts[2] > 0);
        }
    }
}