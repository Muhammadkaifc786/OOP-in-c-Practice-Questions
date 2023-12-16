#include <iostream>

using namespace std;

class lineType {
private:
    double a, b, c;

public:
    // Constructors
    lineType(double coeffA, double coeffB, double coeffC) : a(coeffA), b(coeffB), c(coeffC) {
        // Ensure that at least one of a and b is non-zero
        if (a == 0 && b == 0) {
            cerr << "Error: Invalid line coefficients. At least one of a and b should be non-zero." << endl;
            exit(1);
        }
    }

    // Member functions
    double slope() const {
        if (b != 0) {
            return -a / b;
        } else {
            cerr << "Error: The line is vertical, and slope is undefined." << endl;
            exit(1);
        }
    }

    bool isEqual(const lineType& other) const {
        return (a == other.a) && (b == other.b) && (c == other.c);
    }

    bool isParallel(const lineType& other) const {
        // Two lines are parallel if their slopes are equal
        return slope() == other.slope();
    }

    bool isPerpendicular(const lineType& other) const {
        // Two lines are perpendicular if the product of their slopes is -1
        return (b != 0 && other.b != 0) && (slope() * other.slope() == -1);
    }

    void intersectionPoint(const lineType& other) const {
        // Calculate the point of intersection for two non-parallel lines
        if (!isParallel(other)) {
            double x = (b * other.c - other.b * c) / (a * other.b - other.a * b);
            double y = (a * other.c - other.a * c) / (other.a * b - a * other.b);

            cout << "Intersection point: (" << x << ", " << y << ")" << endl;
        } else {
            cerr << "Error: Lines are parallel. Intersection point is undefined." << endl;
        }
    }
};

int main() {
    // Example usage
    lineType line1(2, 3, 6);  // 2x + 3y = 6
    lineType line2(4, 6, 12); // 4x + 6y = 12

    cout << "Slope of line1: " << line1.slope() << endl;

    if (line1.isEqual(line2)) {
        cout << "Lines are equal." << endl;
    } else {
        cout << "Lines are not equal." << endl;
    }

    if (line1.isParallel(line2)) {
        cout << "Lines are parallel." << endl;
    } else {
        cout << "Lines are not parallel." << endl;
        line1.intersectionPoint(line2);
    }

    if (line1.isPerpendicular(line2)) {
        cout << "Lines are perpendicular." << endl;
    } else {
        cout << "Lines are not perpendicular." << endl;
    }

    return 0;
}
