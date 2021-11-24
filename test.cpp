#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
    "4 11\n"
    "cAda\n"
    "AbrAcadAbRa"
            ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();

    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    REQUIRE(buffer.str() ==
    "2"
    );
}

TEST_CASE("Same len", ""){
    std::stringstream input(
            "3 3\n"
            "abc cba"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
    "1"
    );
}

TEST_CASE("Last elements", ""){
    std::stringstream input(
            "3 10\n"
            "abc 1234567bac"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
    "1"
    );
}

TEST_CASE("First elements", ""){
    std::stringstream input(
            "3 10\n"
            "abc abc1234567"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
    "1"
    );
}

TEST_CASE("Single len", ""){
    std::stringstream input(
            "1 10\n"
            "a a123a4567a"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
    "3"
    );
}