template <typename T>
class Holder {
private:
    T data;
public:
    Holder(T d) : data(d) {}
    void display() {
        std::cout << data << std::endl;
    }
};

Certainly! Here's a step-by-step breakdown to tackle the exercise you provided on implementing a class template for an array:

### Steps to Implement the Array Class Template:

1. **Class Declaration**:
    - Start by declaring a class template named `Array` with a single template parameter (e.g., `T`).

2. **Private Data Members**:
    - Declare a pointer (e.g., `data`) of type `T` that will be used to dynamically allocate memory for the array.
    - Declare an unsigned integer (e.g., `size_`) to store the size of the array.

3. **Default Constructor**:
    - Implement a default constructor that initializes the pointer to `nullptr` and the size to 0.

4. **Parameterized Constructor**:
    - Implement a constructor that takes an unsigned integer `n` as its parameter.
    - Allocate memory for `n` elements of type `T` using the `new[]` operator.
    - Initialize each element to its default value.

5. **Copy Constructor**:
    - Implement a copy constructor that performs a deep copy of the source array.
    - Allocate memory for the new array and copy each element from the source array.

6. **Destructor**:
    - Implement a destructor that deallocates the dynamically allocated memory using the `delete[]` operator.

7. **Overload Subscript Operator (`operator[]`)**:
    - Implement the `operator[]` to return a reference to the element at the specified index.
    - Check if the given index is out of bounds. If it is, throw an `std::exception`.

8. **Assignment Operator (`operator=`)**:
    - Implement the assignment operator that performs a deep copy, similar to the copy constructor.
    - Before copying, ensure that any previously allocated memory is deallocated.
    - Return a reference to the current object.

9. **Size Member Function**:
    - Implement a member function named `size()` that returns the current size of the array.

10. **Test Your Implementation**:
    - In the `main.cpp` file, create various test cases to ensure your class template works correctly.
    - Test the default and parameterized constructors.
    - Test the copy constructor by copying an array and modifying the original and the copy.
    - Test out-of-bounds access to ensure the exception is thrown.
    - Test the `size()` function.

11. **Makefile**:
    - Write a Makefile that compiles and links your C++ files. Make sure it generates the executable and also has a clean rule to remove any generated files.

Remember, while implementing, always follow the principle of encapsulation by keeping data members private (or protected) and exposing necessary functionalities via public member functions. Good luck with your implementation!