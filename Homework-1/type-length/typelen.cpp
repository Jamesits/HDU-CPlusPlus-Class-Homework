// typelen.cpp
// tell how long is int and long
// by James Swineson, 2015-03-23

#include <iostream>
#include <limits>
#include <cmath>
#include <string>

template <typename T>
class VariableLengthFinder {
private:
    std::string displayedtypename;
public:
    VariableLengthFinder(std::string displayTypename){
        displayedtypename = displayTypename;
    }
    size_t getSizeFromSizeOf() {
        return sizeof(T);
    }
    size_t getSizeFromHeader()
    {
        return (size_t)(ceil(
                                std::log2(
                                    (unsigned long long)std::numeric_limits<T>::max()
                                    - (unsigned long long)std::numeric_limits<T>::min()
                                    // there should add 1 but since used with long will overflow so use ceil() instead
                                )
                            ) / 8
                        );
    }
    void printSize() {
        std::cout << "Type: " << displayedtypename << " / " << typeid(this).name() << std::endl <<
        "\tLength from sizeof(): " << getSizeFromSizeOf() << "byte(s)" << std::endl <<
        "\tLength from <limits>: " << getSizeFromHeader() << "byte(s)" << std::endl <<
        "\tMax value: " << std::numeric_limits<T>::max() << std::endl <<
        "\tMin value: " << std::numeric_limits<T>::min() << std::endl;
    }
};

int main() {
    VariableLengthFinder<int> i("int");
    i.printSize();
    VariableLengthFinder<unsigned int> u("unsigned int");
    u.printSize();
    VariableLengthFinder<long> l("long");
    l.printSize();

    return 0;
}
