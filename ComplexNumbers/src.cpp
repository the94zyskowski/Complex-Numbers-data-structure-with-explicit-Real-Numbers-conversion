#include <utility>
#include <iostream>
#include <iomanip>
#include <cmath>

class RealNumber {
private:
    double r;
public:
    RealNumber(double val) : r(val) {}
    double get_r() const { return r; }
    void set_r(double x) { r = x; }
};

class ComplexNumber {
private:
    double a;
    double b;

public:
    ComplexNumber() : a(0), b(0) {}
    ComplexNumber(double x, double y) : a(x), b(y) {}

    ComplexNumber(const ComplexNumber& other) : a(other.a), b(other.b) {}
    ComplexNumber(ComplexNumber&& other) noexcept : a(std::move(other.a)), b(std::move(other.b)) {}
    explicit ComplexNumber(const RealNumber& rn) : a(rn.get_r()), b(0) {}

    void set_a(double z) { a = z; }
    double get_a() const { return a; }
    void set_b(double z) { b = z; }
    double get_b() const { return b; }

    void set_complex_number(double x, double y) { a = x; b = y; }
    void print_complex_number() const { std::cout << std::setprecision(9) << a << "+" << b << "i" << std::endl; }

    operator double() const {
        return std::sqrt(a * a + b * b);
    }
    
    friend ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs);
    friend ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs);
    friend ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs);
    friend ComplexNumber operator/(const ComplexNumber& lhs, const ComplexNumber& rhs);

    friend bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs);
    friend bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs);

    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn);
    friend std::istream& operator>>(std::istream& is, ComplexNumber& cn);

};

ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    return ComplexNumber(lhs.a + rhs.a, lhs.b + rhs.b);
}

ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    return ComplexNumber(lhs.a - rhs.a, lhs.b - rhs.b);
}

ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    return ComplexNumber(lhs.a * rhs.a - lhs.b * rhs.b, lhs.a * rhs.b + lhs.b * rhs.a);
}

ComplexNumber operator/(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    double denominator = rhs.a * rhs.a + rhs.b * rhs.b;
    return ComplexNumber((lhs.a * rhs.a + lhs.b * rhs.b) / denominator, (lhs.b * rhs.a - lhs.a * rhs.b) / denominator);
}

bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    return lhs.a == rhs.a && lhs.b == rhs.b;
}

bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    return !(lhs == rhs);
}


std::ostream& operator<<(std::ostream& os, const ComplexNumber& cn) {
    os << "(" << cn.get_a() << " + " << cn.get_b() << "i)";
    return os;
}

std::istream& operator>>(std::istream& is, ComplexNumber& cn) {
    double a, b;
    is >> a >> b;
    cn.set_a(a);
    cn.set_b(b);
    return is;
}
