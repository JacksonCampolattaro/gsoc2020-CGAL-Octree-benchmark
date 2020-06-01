
#define CGAL_TRACE_STREAM std::cerr

#include "Octree.h"
#include "Octree_3.h"

#include <CGAL/Cartesian.h>

#include <catch2/catch.hpp>


typedef CGAL::Cartesian<float>  Kernel;
typedef Kernel::Point_3 Point_3;

TEST_CASE("Benchmark") {

    Point_3 p{1.5, 2.0, 2.5};

    std::cout << p << std::endl;

}