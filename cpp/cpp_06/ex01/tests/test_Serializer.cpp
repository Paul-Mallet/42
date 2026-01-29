/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_Serializer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul_mallet <paul_mallet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:35:21 by paul_mallet       #+#    #+#             */
/*   Updated: 2026/01/29 09:48:56 by paul_mallet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CATCH_CONFIG_MAIN
#include "../../../catch.hpp"
#include "Serializer.hpp"

SCENARIO("Serialization round-trip validation", "[serializer]") {
    GIVEN("A Data object initialized on the heap") {
        Data* originalPtr = new Data;
        originalPtr->str = "Hello 42";
        originalPtr->i = 42;
        originalPtr->f = -42.0f;
		uintptr_t raw = Serializer::serialize(originalPtr);

        WHEN("The pointer is serialized then deserialized") {
            Data* deserializedPtr = Serializer::deserialize(raw);

            THEN("The resulting pointer must be identical to the original") {
                REQUIRE(deserializedPtr == originalPtr);
            }
            THEN("The data inside the object must remain intact") {
                REQUIRE(deserializedPtr->i == 42);
                REQUIRE(deserializedPtr->f == -42.0f);
                REQUIRE(deserializedPtr->str == "Hello 42");
            }
        }

		WHEN("Casting to Reference (Dangerous way)") {
            Data& ref = reinterpret_cast<Data&>(raw);

            THEN("Accessing members will cause Undefined Behavior") {
                std::cout << "Value at ref.i (garbage): " << ref.i << std::endl;
                REQUIRE(reinterpret_cast<uintptr_t>(&ref) == reinterpret_cast<uintptr_t>(&raw));
                REQUIRE(reinterpret_cast<uintptr_t>(&ref) != raw);
            }
        }
        delete originalPtr;
    }
}

SCENARIO("Handling NULL pointers", "[edge-cases]") {
    GIVEN("A NULL pointer") {
        Data* nullPtr = NULL;

        WHEN("It is serialized") {
            uintptr_t raw = Serializer::serialize(nullPtr);
            THEN("The raw value should be 0") {
                REQUIRE(raw == 0);
            }
            AND_WHEN("It is deserialized back") {
                Data* finalPtr = Serializer::deserialize(raw);
                THEN("The result should still be NULL") {
                    REQUIRE(finalPtr == NULL);
                }
            }
        }
    }
}

SCENARIO("Serialization on different memory segments", "[memory]") {
    GIVEN("A Data object on the Stack") {
        Data stackData;
        stackData.i = 100;

        uintptr_t raw = Serializer::serialize(&stackData);
        Data* result = Serializer::deserialize(raw);

        REQUIRE(result == &stackData);
        REQUIRE(result->i == 100);
    }
}