#!/bin/bash

echo "Running test cases..."

./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" > test1.out
echo -n "Test 1: "
if grep -q '42' test1.out; then
    echo "Passed"
else
    echo "Failed"
fi

./RPN "7 7 * 7 -" > test2.out
echo -n "Test 2: "
if grep -q '42' test2.out; then
    echo "Passed"
else
    echo "Failed"
fi

./RPN "1 2 * 2 / 2 * 2 4 - +" > test3.out
echo -n "Test 3: "
if grep -q '0' test3.out; then
    echo "Passed"
else
    echo "Failed"
fi

# ./RPN "(1 + 1)" > test4.out
# # echo -n "Test 4: "
# # if grep -q 'Error' test4.out; then
# #     echo "Passed"
# # else
# #     echo "Failed"
# # fi

# Cleanup
rm test1.out test2.out test3.out # test4.out
