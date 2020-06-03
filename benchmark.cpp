
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

// Simon: harmless fix in case CATCH is not well-configured like on my
// computer :)
#ifndef BENCHMARK
#define BENCHMARK(x)
#endif


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


    std::stringstream benchName;
    benchName << "Tree  Construction | " << points.number_of_points() << " points";

    // Benchmark
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Build the old octree
    auto point_map = points.point_map();
    auto normal_map = points.normal_map();
    auto input_iterator_first = points.begin();
    auto input_iterator_beyond = points.end();

    auto oldOctree = OldOctree((Traits()), input_iterator_first, input_iterator_beyond, point_map, normal_map);
    BENCHMARK(benchName.str() + " | Old") {
        oldOctree.createTree();
    };

    BENCHMARK(benchName.str() + " | New") {
        // TODO
        NewOctree newOctree(points, point_map, normal_map);
        5+5;
    };
}


TEST_CASE("Random EPICK points in cubic volume") {

    typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    for (std::size_t N = 10; N <= 10000; N *= 10) {

        // Generate random point set
        Point_set points;
        CGAL::Random_points_in_cube_3<Point> generator;
        points.reserve(N);
        for (std::size_t i = 0; i < N; ++i)
            points.insert(*(generator++));

        bench<Kernel, Point>(points);
    }

}


TEST_CASE("Random cartesian float points in cubic volume") {

    typedef CGAL::Simple_cartesian<float> Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    for (std::size_t N = 10; N <= 100000; N *= 10) {

        // Generate random point set
        Point_set points;
        CGAL::Random_points_in_cube_3<Point> generator;
        points.reserve(N);
        for (std::size_t i = 0; i < N; ++i)
            points.insert(*(generator++));

        bench<Kernel, Point>(points);
    }

}

TEST_CASE("Random cartesian double points in cubic volume") {

    typedef CGAL::Simple_cartesian<double> Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    for (std::size_t N = 10; N <= 100000; N *= 10) {

        // Generate random point set
        Point_set points;
        CGAL::Random_points_in_cube_3<Point> generator;
        points.reserve(N);
        for (std::size_t i = 0; i < N; ++i)
            points.insert(*(generator++));

        bench<Kernel, Point>(points);
    }
}

TEST_CASE("Random EPICK points on spherical surface") {

    typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    for (std::size_t N = 10; N <= 100000; N *= 10) {

        // Generate random point set
        Point_set points;
        CGAL::Random_points_on_sphere_3<Point> generator;
        points.reserve(N);
        for (std::size_t i = 0; i < N; ++i)
            points.insert(*(generator++));

        bench<Kernel, Point>(points);
    }

}

TEST_CASE("Random cartesian float points on spherical surface") {

    typedef CGAL::Simple_cartesian<float> Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    for (std::size_t N = 10; N <= 100000; N *= 10) {

        // Generate random point set
        Point_set points;
        CGAL::Random_points_on_sphere_3<Point> generator;
        points.reserve(N);
        for (std::size_t i = 0; i < N; ++i)
            points.insert(*(generator++));

        bench<Kernel, Point>(points);
    }

}

TEST_CASE("Random cartesian double points on spherical surface") {

    typedef CGAL::Simple_cartesian<double> Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    for (std::size_t N = 10; N <= 100000; N *= 10) {

        // Generate random point set
        Point_set points;
        CGAL::Random_points_on_sphere_3<Point> generator;
        points.reserve(N);
        for (std::size_t i = 0; i < N; ++i)
            points.insert(*(generator++));

        bench<Kernel, Point>(points);
    }

}

TEST_CASE("Cleaned Statue surface with EPICK points") {

    typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    // Read example data from file
    std::ifstream stream("../data/archer_cleaned.ply");
    Point_set points;
    stream >> points;

    bench<Kernel, Point>(points);

}

TEST_CASE("Cleaned Statue surface with cartesian float points") {

    typedef CGAL::Simple_cartesian<float> Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    // Read example data from file
    std::ifstream stream("../data/archer_cleaned.ply");
    Point_set points;
    stream >> points;

    bench<Kernel, Point>(points);

}

TEST_CASE("Cleaned Statue surface with cartesian double points") {

    typedef CGAL::Simple_cartesian<double> Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    // Read example data from file
    std::ifstream stream("../data/archer_cleaned.ply");
    Point_set points;
    stream >> points;

    bench<Kernel, Point>(points);

}

TEST_CASE("Uncleaned Statue surface with EPICK points") {

    typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    // Read example data from file
    std::ifstream stream("../data/archer_original.ply");
    Point_set points;
    stream >> points;

    bench<Kernel, Point>(points);
}

TEST_CASE("Uncleaned Statue surface with cartesian float points") {

    typedef CGAL::Simple_cartesian<float> Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    // Read example data from file
    std::ifstream stream("../data/archer_original.ply");
    Point_set points;
    stream >> points;

    bench<Kernel, Point>(points);
}

TEST_CASE("Uncleaned Statue surface with cartesian double points") {

    typedef CGAL::Simple_cartesian<double> Kernel;
    typedef Kernel::Point_3 Point;
    typedef CGAL::Point_set_3<Point> Point_set;

    // Read example data from file
    std::ifstream stream("../data/archer_original.ply");
    Point_set points;
    stream >> points;

    bench<Kernel, Point>(points);
}
