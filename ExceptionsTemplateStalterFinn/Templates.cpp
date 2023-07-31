//Finn Stalter
//CIS 1202 5T1
// 7/30/23

#include <iostream>
#include <type_traits>

// Function template for floating-point types
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
half(T value) {
    return value / 2.0;
}

// Function template for integer types
template <typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
half(T value) {
    // If the value is odd, we want to round up
    if (value % 2 != 0) {
        return (value + 1) / 2;
    }
    else {
        return value / 2;
    }
}

int main() {
    // Test with floating-point types
    float f_value = 7.8;
    double d_value = 15.6;

    std::cout << "Half of " << f_value << " is: " << half(f_value) << std::endl;
    std::cout << "Half of " << d_value << " is: " << half(d_value) << std::endl;

    // Test with integer types
    int i_value = 10;
    long long ll_value = 27;

    std::cout << "Half of " << i_value << " is: " << half(i_value) << std::endl;
    std::cout << "Half of " << ll_value << " is: " << half(ll_value) << std::endl;

    return 0;
}

