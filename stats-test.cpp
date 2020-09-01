#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"
using namespace std;
#include <cmath>

TEST_CASE("reports average, minimum and maximum") {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
    auto computedStats = Statistics::ComputeStatistics({});
    //All fields of computedStats (average, max, min) must be
    //Use http://www.cplusplus.com/reference/cmath/isnan/
    REQUIRE(std::isnan(computedStats.average));
    REQUIRE(std::isnan(computedStats.max));
    REQUIRE(std::isnan(computedStats.min));
    
}
