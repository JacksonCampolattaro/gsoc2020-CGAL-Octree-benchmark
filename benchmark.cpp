
#define CGAL_TRACE_STREAM std::cerr

// To be tested
#include "Octree.h"
#include "Octree_3.h"

// Necessary for testing
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Point_set_3.h>

#include <boost/iterator/filter_iterator.hpp>
#include <CGAL/bounding_box.h>
#include <CGAL/Iterator_range.h>

// Used to create and load data sets
#include <CGAL/point_generators_3.h>
#include <CGAL/Point_set_3/IO.h>
#include <istream>

// Used for benchmarking
#include <catch2/catch.hpp>

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::FT FT;
typedef Kernel::Point_3 Point;
typedef CGAL::Point_set_3<Point> Point_set;

typedef CGAL::Shape_detection::internal::Octree<CGAL::Shape_detection::internal::DirectPointAccessor<Kernel>> OldOctree;
typedef CGAL::OCTREE::Octree<Kernel, Point_set::Point_range, Point_set::Point_map, Point_set::Vector_map> NewOctree;


TEST_CASE("Random points in cubic volume") {

    // Generate random point set
    Point_set points;
    CGAL::Random_points_in_cube_3<Point> generator;

    // TODO
}

TEST_CASE("Random points on spherical surface") {

    // Generate random point set
    Point_set points;
    CGAL::Random_points_on_sphere_3<Point> generator;

    // TODO
}

TEST_CASE("Cleaned Statue surface") {

    // Read example data from file
    std::ifstream stream("../data/archer_cleaned.ply");
    Point_set points;
    REQUIRE(CGAL::read_ply_point_set(stream, points));

    std::cout << points.size() << std::endl;

    // TODO
}

TEST_CASE("Uncleaned Statue surface") {

    // Read example data from file
    std::ifstream stream("../data/archer_original.ply");
    Point_set points;
    REQUIRE(CGAL::read_ply_point_set(stream, points));

    std::cout << points.size() << std::endl;

    // TODO
}
