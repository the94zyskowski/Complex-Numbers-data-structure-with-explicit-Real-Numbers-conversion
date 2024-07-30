# Complex Numbers Data Structure with Explicit Real Numbers Conversion

This project implements a comprehensive data structure for complex numbers in C++. It includes the following features:

- Constructors for initializing complex numbers.
- Copy and move constructors.
- Explicit conversion from `RealNumber` to `ComplexNumber`.
- Operator overloading for arithmetic operations (`+`, `-`, `*`, `/`).
- Comparison operators (`==`, `!=`).
- Stream operators (`<<`, `>>`) for easy input and output.
- Conversion of `ComplexNumber` to `double`, representing the magnitude.
- This project is a Visual Studio 2022 project and can be opened with full support in this IDE.

## Compilation

To compile the code, use a C++ compiler like `g++`:

```sh
g++ -o complex_number main.cpp
```
## Running
To run the compiled program:

```sh
./complex_number
```
Example Usage
Here is a brief example of how to use the ComplexNumber class:

```cpp
#include <iostream>
#include "ComplexNumber.h"

int main() {
    ComplexNumber c1(1.0, 2.0);
    ComplexNumber c2(3.0, 4.0);

    ComplexNumber c3 = c1 + c2;
    std::cout << "c1 + c2 = " << c3 << std::endl;

    std::cout << "Enter a complex number (real and imaginary parts): ";
    ComplexNumber c4;
    std::cin >> c4;
    std::cout << "You entered: " << c4 << std::endl;

    return 0;
}
```
This project is licensed under the MIT License - see the [LICENSE](https://opensource.org/license/mit) file for details.
