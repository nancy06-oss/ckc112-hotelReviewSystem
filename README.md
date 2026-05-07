# Hotel Review System - CKC112 OOP Assignment

## Project Overview
A comprehensive console-based Hotel Review System demonstrating Object-Oriented Programming principles in C++. The system manages traveler profiles, hotel reviews, and provides analytics on hotel ratings and reviewer statistics.

## Course Details
- **Course**: CKC112 - Object-Oriented Programming
- **Assignment**: Programming Assignment 1 - Hotel Review System
- **Submission Due**: 10th May 2026
- **Team**: Maximum 3 students

## Key Features

### Core Functionality
1. **Property Deep-Dive**: Find and summarize all reviews for a specific hotel
2. **Traveler Profile**: Manage traveler information including loyalty points and authored reviews
3. **Top-Pick Matcher**: Identify highest-rated hotels and provide hotel ranking
4. **Top Reviewers**: Display top travelers by loyalty points

## OOP Implementation Highlights

### ✅ INHERITANCE
- `Traveler` class inherits from `User` class
- Child class extends parent with specialized attributes (loyaltyPoints, membershipLevel)
- Demonstrates method overriding (displayUser())

### ✅ COMPOSITION (Has-A)
- `HotelSystem` contains arrays of `Hotel` and `Traveler` objects
- `Hotel` class contains array of `Review` objects
- `Traveler` class contains array of `Review` objects
- Demonstrates object containment without circular dependencies

### ✅ OPERATOR OVERLOADING
- **Comparison Operators**: `>`, `<`, `==` for comparing hotels by rating and travelers by loyalty points
- **Stream Insertion Operator**: `<<` for easy hotel printing (Friend Function)

### ✅ FRIEND FUNCTION
- `operator<<` implemented as a friend function in `Hotel` class
- Allows external access to private members for stream output
- Demonstrates encapsulation while providing controlled access

## File Structure

```
├── Review.h / Review.cpp           # Individual review data
├── User.h / User.cpp               # Base user class
├── Traveler.h / Traveler.cpp       # Derived traveler class (INHERITANCE)
├── Hotel.h / Hotel.cpp             # Hotel with reviews (COMPOSITION)
├── HotelSystem.h / HotelSystem.cpp # Main system class (COMPOSITION)
├── main.cpp                        # Entry point (Entity-Centric Design)
├── Users.txt                       # Sample traveler data
├── Reviews.txt                     # Sample review data
└── README.md                       # This file
```

## Technical Specifications

### Architecture
- **Entity-Centric Design**: Single `HotelSystem` object in main() encapsulates all operations
- **One-Time I/O Rule**: Files read exactly once at startup, written once at termination
- **Memory Management**: Fixed-size arrays (no STL containers)
- **No Circular Dependencies**: Clean inheritance and composition hierarchy

### Constraints Met
- ✅ No STL containers (std::vector)
- ✅ No virtual functions (method overriding used instead)
- ✅ No abstraction or polymorphism
- ✅ Fixed-size arrays for all objects
- ✅ All processing logic in class member functions

## Compilation & Execution

### For Local Environment
```bash
g++ Review.h Review.cpp User.h User.cpp Traveler.h Traveler.cpp Hotel.h Hotel.cpp HotelSystem.h HotelSystem.cpp main.cpp -o HotelReviewSystem.elf
./HotelReviewSystem.elf
```

### For Google Colab
```python
%%shell
g++ Review.h Review.cpp User.h User.cpp Traveler.h Traveler.cpp Hotel.h Hotel.cpp HotelSystem.h HotelSystem.cpp main.cpp -o HotelReviewSystem.elf
./HotelReviewSystem.elf
```

## Menu Operations

1. **Property Deep-Dive**: Enter hotel ID to view all reviews
2. **Traveler Profile**: Enter traveler ID to view profile and reviews
3. **Top-Pick Matcher**: Find highest-rated hotel or rank all hotels
4. **Top Reviewers**: View top 5 travelers by loyalty points
5. **Display All Hotels**: View summary of all hotels
6. **Display All Travelers**: View all traveler information
7. **Add Manual Review**: Manually add a new review
8. **Save Reports & Exit**: Generate report and terminate

## Sample Data Files

### Users.txt Format
```
<UserID> <Name> <Email> <City> <LoyaltyPoints> <MembershipLevel>
```

### Reviews.txt Format
```
<ReviewID> <HotelID> <UserID> <Rating> <Comment>
```

## Class Responsibilities

| Class | Responsibility |
|-------|----------------|
| `Review` | Encapsulate individual review data (ID, rating, comment) |
| `User` | Base class for system users with common attributes |
| `Traveler` | Extend User with loyalty points and review authoring |
| `Hotel` | Manage hotel data and aggregate reviews |
| `HotelSystem` | Orchestrate entire system, manage data I/O and operations |

## OOP Design Principles Applied

1. **Encapsulation**: Private data members with public accessors
2. **Inheritance**: Single inheritance hierarchy (User → Traveler)
3. **Composition**: Strong relationships between classes
4. **Abstraction**: Complex operations hidden in class methods
5. **Modularity**: Separated header and implementation files

## Report Output

The system generates a detailed report (`HotelReview_Report.txt`) containing:
- Hotel rankings by average rating
- Top reviewers by loyalty points
- Complete analytics summary

## Notes

- No login system or password encryption required
- Program operates as an administrative tool
- All data processing occurs in memory during execution
- Final state saved to report file before termination

## Author Notes

This implementation strictly adheres to all mandatory OOP specifications while maintaining clean, readable, and well-commented code. The design emphasizes separation of concerns, modularity, and proper use of object-oriented principles.
