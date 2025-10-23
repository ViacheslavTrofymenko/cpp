# README.md

## Project Overview

This is a 42 School C++ curriculum repository containing progressive exercises (cpp00 through cpp04) that explore fundamental C++ concepts. Each module contains multiple exercises (ex00, ex01, etc.) that build upon each other.

## Build System

Each exercise has its own isolated directory structure with a dedicated Makefile:

```
cppXX/exYY/
├── Makefile
├── src/
├── include/
└── obj/        (created during build)
```

### Building and Running

Navigate to a specific exercise directory and use:

```bash
# Build the exercise
make

# Clean object files
make clean

# Remove all build artifacts including the binary
make fclean

# Full rebuild
make re
```

The compiled binary will be in the exercise directory with a name specific to that exercise (e.g., `megaphone`, `brain`, etc.).

### Compiler Flags

All exercises are compiled with strict C++98 standard compliance:
- `-Wall -Wextra -Werror` (all warnings as errors)
- `-std=c++98` (C++98 standard)
- `-g3` (debugging symbols)

## Code Architecture

### Module Progression

- **cpp00**: Basic C++ syntax, classes, and I/O (megaphone, PhoneBook with Contact management)
- **cpp01**: Memory management, references vs pointers (Zombie, Weapon, file replacement, Harl logger)
- **cpp02**: Operator overloading, fixed-point numbers (Fixed class with arithmetic/comparison operators)
- **cpp03**: Inheritance and virtual functions (ClapTrap→ScavTrap→FragTrap→DiamondTrap hierarchy demonstrating multiple inheritance)
- **cpp04**: Polymorphism and abstract classes (Animal hierarchy with Brain, abstract classes)

### Common Patterns

#### Orthodox Canonical Form
All classes follow the Orthodox Canonical Form (required by 42):
- Default constructor
- Copy constructor
- Copy assignment operator
- Destructor

Example from Fixed class:
```cpp
Fixed();                              // Default constructor
Fixed(const Fixed& copy);             // Copy constructor
Fixed& operator=(const Fixed& other); // Copy assignment operator
~Fixed();                             // Destructor
```

#### Header Guards
All header files use traditional include guards:
```cpp
#ifndef CLASSNAME_HPP
#define CLASSNAME_HPP
// class definition
#endif
```

#### File Structure
- Headers in `include/` directory
- Implementation in `src/` directory
- Relative includes from source files: `#include "../include/ClassName.hpp"`

#### Inheritance Patterns

**cpp03 demonstrates diamond inheritance problem:**
- `DiamondTrap` inherits from both `ScavTrap` and `FragTrap`
- Both inherit from `ClapTrap`
- Uses virtual inheritance to resolve diamond problem
- Demonstrates method disambiguation with `using ScavTrap::attack;`

**cpp04 demonstrates polymorphism:**
- Base `Animal` class with virtual methods
- Derived `Cat` and `Dog` classes
- `Brain` class for composition (deep copy management)
- Abstract classes (ex02) where Animal cannot be instantiated

#### Color Output
Some classes use color macros for console output:
```cpp
C_GRN "message" C_RESET  // Green colored output
```

### Key Concepts by Module

**cpp02 - Fixed Point Class:**
- Stores fixed-point numbers using integer representation
- `bitsPoint = 8` for fractional precision
- Conversion constructors for int and float
- Full operator overloading (arithmetic, comparison, increment/decrement)
- Static min/max functions

**cpp03 - Diamond Inheritance:**
- `DiamondTrap` maintains separate names for itself and its ClapTrap component
- Attributes initialized from different parents: `FragTrap::hit_pts`, `ScavTrap::energy_pts`
- `whoAmI()` method demonstrates access to both DiamondTrap and ClapTrap names

**cpp04 - Deep Copies:**
- `Cat` and `Dog` classes contain pointer to `Brain`
- Copy constructors and assignment operators must perform deep copies of Brain
- Proper memory management in destructors

## Testing

Each exercise includes a `main.cpp` that demonstrates the required functionality. Run the binary without arguments to see the test output. No external testing framework is used - verification is done through manual inspection of output.

## Development Notes

- Always maintain C++98 compatibility (no C++11 features like `nullptr`, `auto`, range-based for loops)
- Headers should be self-contained (include all dependencies)
- Source files follow 42 header format with creation/update timestamps
- No using namespace std in headers
- Follow 42 norm requirements (visible in file headers with 42 formatting)
