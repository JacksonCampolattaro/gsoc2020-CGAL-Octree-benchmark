
#define CGAL_TRACE_STREAM std::cerr

#include "Octree.h"
#include "Octree_3.h"

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Point_set_3.h>
#include <CGAL/Point_set_3/IO.h>

#include <CGAL/point_generators_3.h>

#include <catch2/catch.hpp>

#include <fstream>
#include <istream>

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::FT FT;
typedef Kernel::Point_3 Point;
typedef Kernel::Vector_3 Vector;
typedef CGAL::Point_set_3<Point> Point_set;

TEST_CASE("Random points in cubic volume") {

    // TODO
}

TEST_CASE("Random points on spherical surface") {

    // TODO
}

TEST_CASE("Cleaned Statue surface") {

    // Read example data from file
    std::ifstream f("../data/archer_cleaned.ply");
    Point_set point_set;
    REQUIRE(CGAL::read_ply_point_set(f, point_set));

    // TODO
}

TEST_CASE("Uncleaned Statue surface") {

    // Read example data from file
    std::ifstream f("../data/archer_original.ply");
    Point_set point_set;
    REQUIRE(CGAL::read_ply_point_set(f, point_set));

    // TODO
}
