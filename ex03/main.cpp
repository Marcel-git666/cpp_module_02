#include "Point.hpp"
#include <iostream>

// Forward declaration of your bsp function
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
    // Set cout to print "true" / "false" instead of "1" / "0"
    std::cout << std::boolalpha;

    /*
     * We create a simple right-angled triangle
     * A = (0, 0)
     * B = (10, 0)
     * C = (0, 10)
     */
    Point const a(0.0f, 0.0f);
    Point const b(10.0f, 0.0f);
    Point const c(0.0f, 10.0f);

    std::cout << "--- Testing triangle A(0,0), B(10,0), C(0,10) ---"
              << std::endl;

    // --- Test 1: A point clearly INSIDE ---
    // Expected: true
    Point const p_in(1.0f, 1.0f);
    std::cout << "Point (1, 1) [Inside]:     " << bsp(a, b, c, p_in)
              << std::endl;

    // --- Test 2: A point clearly OUTSIDE ---
    // Expected: false
    Point const p_out(10.0f, 10.0f);
    std::cout << "Point (10, 10) [Outside]:  " << bsp(a, b, c, p_out)
              << std::endl;

    // --- Test 3: A point ON A VERTEX ---
    // The subject requires this to be false
    // Expected: false
    Point const p_vertex(0.0f, 0.0f); // Same as point 'a'
    std::cout << "Point (0, 0) [Vertex]:     " << bsp(a, b, c, p_vertex)
              << std::endl;

    // --- Test 4: A point ON AN EDGE ---
    // The subject requires this to be false
    // Expected: false
    Point const p_edge(5.0f, 0.0f); // Lies on edge A-B
    std::cout << "Point (5, 0) [Edge A-B]:   " << bsp(a, b, c, p_edge)
              << std::endl;

    // --- Test 5: A point ON THE HYPOTENUSE ---
    // Expected: false
    Point const p_hypotenuse(5.0f, 5.0f); // Lies on edge B-C
    std::cout << "Point (5, 5) [Edge B-C]:   " << bsp(a, b, c, p_hypotenuse)
              << std::endl;

    return 0;
}
