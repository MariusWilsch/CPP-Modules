#include "../inc/Array.hpp"

// int main(void) {

// 	Array<int> arr1(5);

// 	// Testing the subscript operator
// 	std::cout << "The value of the element is: " << arr1[4] << std::endl;

// 	// Testing the size() member function;
// 	cout << "Size of array: " << arr1.size() << endl;


// 	return (0);
// }

#define SIZE 10

int main( void )
{
		cout << "-----------------------------------------------------" << endl;

		Array< float > test;

		Array< float> floatArr ( SIZE );
		cout << "Float Array 1: " << endl;
		cout << floatArr.size() << endl;
		

		Array< int > intArray( SIZE );
		Array< int > intArray2( SIZE - 5 );

		for ( unsigned int i = 0; i < intArray.size(); i++ )
				intArray[i] = i * 2;

		cout << "Int Array 1: " << endl;
		intArray.print();

		intArray2 = intArray;

		cout << "int Array 2: " << endl;
		intArray2.print();

		try {
				cout << "Accessing a valid index: " << intArray[5] << endl;
				cout << "Accessing an invalid index: " << intArray[SIZE] << endl;
		} catch (std::exception &e) {
				cout << "Error: " << e.what() << endl;
		}

		cout << "-----------------------------------------------------" << endl;

		return ( 0 );
}