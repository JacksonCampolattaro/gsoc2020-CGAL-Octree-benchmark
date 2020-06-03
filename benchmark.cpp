
#define CGAL_TRACE_STREAM std::cerr

// To be tested
#include "Octree.h"
#include <CGAL/Shape_detection/Efficient_RANSAC/Efficient_RANSAC_traits.h>
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
#define CATCH_CONFIG_ENABLE_BENCHMARKING

#include <catch2/catch.hpp>

template<class Kernel, class Point>
void bench(CGAL::Point_set_3<Point> points) {

    // Defining shared types
    typedef CGAL::Point_set_3<Point> Point_set;

    // Defining the Old Octree
    typedef CGAL::Shape_detection::Efficient_RANSAC_traits
            <Kernel, Point_set, typename Point_set::Point_map, typename Point_set::Vector_map>
            Traits;
    typedef CGAL::Shape_detection::internal::Octree
            <CGAL::Shape_detection::internal::DirectPointAccessor<Traits>>
            OldOctree;

    // Defining the New Octree
    typedef CGAL::OCTREE::Octree
            <Kernel, Point_set, typename Point_set::Point_map, typename Point_set::Vector_map>
            NewOctree;


    // Benchmark
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Build the old octree
    auto point_map = points.point_map();
    auto normal_map = points.normal_map();
    auto input_iterator_first = points.begin();
    auto input_iterator_beyond = points.end();

    OldOctree oldOctree((Traits()), input_iterator_first, input_iterator_beyond, point_map, normal_map);

    // Build the new octree
    // FIXME: I'm having trouble constructing the new octree
    //NewOctree newOctree(points, point_map, normal_map);

    // TODO
}


TEST_CASE("Random exact points in a cubic volume") {

    typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    std::size_t N = 1000;

    // Generate random point set
    Point_set points;
    CGAL::Random_points_in_cube_3<Point> generator;
    points.reserve(N);
    for (std::size_t i = 0; i < N; ++i)
        points.insert(*(generator++));

    BENCHMARK("Random exact points in a cubic volume") {return bench<Kernel, Point>(points);};
}

TEST_CASE("Random exact points on spherical surface") {

    typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    std::size_t N = 1000;

    // Generate random point set
    Point_set points;
    CGAL::Random_points_on_sphere_3<Point> generator;
    points.reserve(N);
    for (std::size_t i = 0; i < N; ++i)
        points.insert(*(generator++));

    BENCHMARK("Random exact points on spherical surface") {return bench<Kernel, Point>(points);};
}

TEST_CASE("Cleaned Statue surface with exact points") {

    typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    // Read example data from file
    std::ifstream stream("../data/archer_cleaned.ply");
    Point_set points;
    stream >> points;

    BENCHMARK("Cleaned Statue surface with exact points") {return bench<Kernel, Point>(points);};
}

TEST_CASE("Uncleaned Statue surface with exact points") {

    typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    // Read example data from file
    std::ifstream stream("../data/archer_original.ply");
    Point_set points;
    stream >> points;

    BENCHMARK("Uncleaned Statue surface with exact points") {return bench<Kernel, Point>(points);};
}
