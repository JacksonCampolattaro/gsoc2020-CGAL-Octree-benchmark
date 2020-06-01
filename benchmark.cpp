
#define CGAL_TRACE_STREAM std::cerr

// To be tested
#include "Octree.h"
#include <CGAL/Shape_detection/Efficient_RANSAC/Efficient_RANSAC_traits.h>
#include "Octree_3.h"

// Necessary for testing
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Point_set_3.h>

#include <boost/iterator/filter_iterator.hpp>
#include <CGAL/bounding_box.h>
#include <CGAL/Iterator_range.h>
#include <CGAL/Point_with_normal_3.h>

// Used to create and load data sets
#include <CGAL/point_generators_3.h>
#include <CGAL/Point_set_3/IO.h>
#include <istream>

// Used for benchmarking
#include <catch2/catch.hpp>

template <class K>
void bench() {

    typedef typename K::FT                                      FT;
    typedef CGAL::Point_with_normal_3<K>                        Pwn;
    typedef CGAL::Point_3<K>                                    Point;
    typedef CGAL::Vector_3<K>                                   Vector;
    typedef std::vector<Pwn>                                    Pwn_vector;
    typedef CGAL::Identity_property_map<Pwn>                    Point_map;
    typedef CGAL::Normal_of_point_with_normal_map<K>            Normal_map;

    typedef CGAL::Shape_detection::Efficient_RANSAC_traits<K, Pwn_vector, Point_map, Normal_map> Traits;

    typedef CGAL::Shape_detection::internal::Octree<Traits> OldOctree;
    typedef CGAL::OCTREE::Octree<K, Pwn_vector, Point_map, Normal_map> NewOctree;

    // TODO
}

TEST_CASE("Random cartesian float points in cubic volume") {

    // Set kernel type
    typedef CGAL::Simple_cartesian<float> Kernel;

    // Generate random point set
    CGAL::Random_points_in_cube_3<Kernel::Point_3> generator;
    // TODO

    bench<Kernel>();
}

TEST_CASE("Random points on spherical surface") {

    // Set kernel type
    typedef CGAL::Simple_cartesian<float> Kernel;

    // Generate random point set
    //Point_set points;
    //CGAL::Random_points_on_sphere_3<Point> generator;

    // TODO
}

TEST_CASE("Cleaned Statue surface") {

    // Set kernel type
    typedef CGAL::Simple_cartesian<float> Kernel;

    // Read example data from file
    /*std::ifstream stream("../data/archer_cleaned.ply");
    Point_set points;
    REQUIRE(CGAL::read_ply_point_set(stream, points));*/

    // TODO
}

TEST_CASE("Uncleaned Statue surface") {

    // Set kernel type
    typedef CGAL::Simple_cartesian<float> Kernel;

    // Read example data from file
    /*std::ifstream stream("../data/archer_original.ply");
    Point_set points;
    REQUIRE(CGAL::read_ply_point_set(stream, points));*/

    // TODO
}