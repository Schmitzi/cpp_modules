# Notes

## Orthodox Canonical Form

The Orthodox Canonical Form is a set of essential member functions for managing the lifecycle
of objects, particularly when dealing with dynamic memory allocation or resource management.

The goal od OCF is to provide consistent and reliable handling of resources within a class.

### Why OCF is Important

The Orthodox Canonical Form ensures that classes behave correctly when copied, assigned, or destroyed. This is especially critical in C++ when managing resources manually, as these functions prevent memory leaks, dangling pointers, and other resource management issues. By implementing OCF, you make your class safer and predictable when used with other features of C++, like collections or smart pointers.

The four keywords are:

1. Default Constructor
2. Copy Constructor
3. Copy Assignment Operator
4. Destructor

In more detail:

### Default Constructor

- Purpose:  Initialises an object with default values when no arguments are provided.
- Syntax:   `ClassName()`
- Usage:    Allows the creation of objects without requiring initialisation parameters.

```cpp
ClassName() {
    // Initialise members of default values here
}
```

### Copy Constructor

- Purpose:  Creates new object as a copy of existing object.
- Syntax:   `ClassName( const ClassName& other )`
- Usage:    Used when an object is initialized with another object of the same type
  (e.g., `ClassName obj2 = obj1;`). It allows for creating a deep copy if the class
  manages pointers or dynamic resources.

```cpp
ClassName( const ClassName& other ) {
    // Copy all members from "other" to create a deep copy
}
```

### Copy Assignment Operator

- Purpose:  Copies the constant of one object to another existing object of the same type.
- Syntax:   `ClassName& operator=( const ClassName& other )`
- Usage:    Used when one object is assigned to another object (e.g., `obj1 = obj2;`).
  Handles self-assignment checks and allows a deep copy to manage dynamic resources.

```cpp
ClassName& operator=( const ClassName& other ) {
    if (this != &other) {
        // Copy all members from "other" to create a deep copy
    }
    return *this;
}
```

### Destructor

- Purpose:  Frees resources when an object goes out of scope.
- Syntax:   `~ClassName();`
- Usage:    Essential if the class allocates dynamic memory or acquires resources (e.g., file
  handles) to ensure these resources are released when the object is destroyed.

```cpp
~ClassName() {
    // Clean up allocated memory
}
```


## Inheriatance


Inheritance is a mechanism where one class (called the child or derived class) inherits the properties and behavours (methods and attributes of another class (called the parent or base class).

### Key Charactaristics:

1. Code Reusablitlity: 
	Inheritance allows a derived class to reuse code from the base class, avoiding duplication
2. Hierarchy:
	Inheritance establishes a "is-a" relationship (e.g., a ``Dog``is an ``Animal).``
3. Implementation Focus:
	Inheritance is primarily about creating a new class based on an existing class, often extending or overriding its behaviour.

Example:

```cpp
class Animal {
public:
    void eat() { std::cout << "Eating...\n"; }
};

class Dog : public Animal {
public:
    void bark() { std::cout << "Barking...\n"; }
};
```

Usage:

```cpp
Dog dog;
dog.eat();  // Inherited from Animal
dog.bark(); // Specific to Dog
```

## Polymorphism

Polymorphism means "many forms" and refers to the ability of different classes to be treated as instances of the same base class. It allows a single interface to represent different underlying types.

### Key Characteristics:

1. Behavioral Flexibility:
	Polymorphism enables the program to decide at runtime which method to invoke, depending on the object's actual type.
2. Dynamic Dispatch:
	Achieved using virtual functions, it allows derived classes to override methods of the base class.
3. Interface Focus:
	Polymorphism emphasizes working with objects through a common interface (e.g., using a base class pointer or reference).
	
Example: 
```cpp
class Animal {
public:
    virtual void speak() const { std::cout << "Animal sound\n"; }
};

class Dog : public Animal {
public:
    void speak() const override { std::cout << "Woof\n"; }
};

class Cat : public Animal {
public:
    void speak() const override { std::cout << "Meow\n"; }
};
```

Usage:

```cpp
Animal* animals[] = {new Dog(), new Cat()};

for (Animal* animal : animals) {
    animal->speak(); // Calls Dog's or Cat's version of speak
}
```
