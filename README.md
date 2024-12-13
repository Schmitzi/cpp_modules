# C++ Modules

This repository contains a series of modules designed to guide learners through core concepts in C++ programming, with a focus on object-oriented programming principles, memory management, and advanced features such as operator overloading and polymorphism. Each module is comprised of multiple exercises, gradually introducing new concepts and complexities in C++.

## Modules Overview

### Module 00 - Basics of C++

- **Namespaces and Classes**: Understanding basic structures in C++.
- **Member Functions**: How functions interact within classes.
- **Initialization Lists**: Best practices for initializing class members.
- **Static and Const**: Efficient use of static and constant variables.

### Module 01 - Memory Management and Pointers

- **Memory Allocation**: Effective management of dynamic memory in C++.
- **Pointers to Members and References**: Manipulating member pointers and understanding references.
- **Switch Statements**: Control flow with switch-case.

### Module 02 - Polymorphism, Overloading, and Canonical Forms

- **Ad-hoc Polymorphism**: Implementing polymorphic behavior through method overloading.
- **Operator Overloading**: Enabling intuitive operator use for custom classes.
- **Orthodox Canonical Form**: Following best practices for C++ class design with constructors, destructors, and assignment operators.

### Module 03 - Inheritance

- **Base and Derived Classes**: Understanding the relationship between parent and child classes.
    Construction/Destruction Chaining: Properly managing constructor and destructor calls in inheritance.
- **Special Member Functions**: Enhancing functionality with additional member functions.
- **Deep Copy Implementation**: Ensuring memory safety by avoiding shallow copies.

### Module 04 - Subtype Polymorphism and Abstract Classes

- **Abstract Classes**: Designing non-instantiable base classes with pure virtual functions.
- **Subtype Polymorphism**: Leveraging polymorphism for dynamic class behavior.
- **Memory Management**: Proper handling of memory allocation and preventing leaks with virtual destructors.

### Module 05 - Repetition and Exceptions

- **Exception Classes**: Handling errors using custom exception classes such as `GradeTooHighException` and `GradeTooLowException`.
- **Bureaucratic Systems**: Simulating real-world systems like office workflows, with classes such as `Bureaucrat`, `Form`, and their derivatives.
- **Advanced Exception Handling**: Using `try-catch` blocks to manage exceptions effectively.
- **Concrete Forms**: Implementation of specific forms like `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm`.
- **Intern Class**: Automating repetitive tasks through a `makeForm` function that generates forms dynamically.

### Module 06 - C++ Casts

- **Scalar Type Conversion**: Implementing a `ScalarConverter` class to handle conversions between `char`, `int`, `float`, and `double`.
- **Serialization**: Converting objects into serializable formats using custom `serialize` and `deserialize` methods.
- **Dynamic Type Identification**: Identifying real object types using inheritance and polymorphism without the use of `typeid`.
- **Specific Cast Usage**: Employing `static_cast`, `dynamic_cast`, `const_cast`, and `reinterpret_cast` as appropriate for various conversion

### Module 07 - C++ Templates

- **Function Templates**: Implementing versatile function templates for generic operations like `swap`, `min`, and `max.
- **Array Operations**: Creating a template-based array class with proper memory management and bounds checking.
- **Iterator Implementation**: Developing a generic iterator function template to process array elements.
- **Template Specialization**: Understanding and implementing template specialization for different data types.
