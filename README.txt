Puzzle Solver
This is a C++ program to solve a "find the word" puzzle with a slight twist. The program takes 2d character array and a word as the input. The goal is to find specific words within these arrays, where the words can appear horizontally or vertically but not diagonally.

The words to find can appear horizontally or vertically BUT NOT diagonally. The horizontal word will appear in order from left to right. The vertical word will appear in order from top to bottom. 
 
The characters in each puzzle input have also been rotated by 1 character several times. So in order to find the word, you will need to :
- rotate all the characters in the array once, search the arrays for the word. 
- if not found, repeat the rotation and search until the word is found. 

Rotation occurs as follows: 'a' -> 'b', 'b' -> 'c', 'c' -> 'd', ... 'y' -> 'z', 'z' -> 'a'.
 
The expected output to return is the number of rotations needed as well as the x and y coordinate of the first letter of the word. 

For example, if you need to find the word 'abc' from the following character array
[[ 'z', 'e', 'z'],
[ 'w', 'n', 'a'],
[ 'n', 'q', 'b']]

then, your output would be  'x=2, y=0, count=1’. 

This is because if you rotate the characters in the array once (count=1), then you will arrive with an array 
[[ 'a', 'f', 'a'],
 [ 'x', 'o', 'b'],
 [ 'o', 'r', 'c']]

In this array, you can find the first letter of the word 'abc' at (2,0). Hence your output will be 'x=2, y=0, count=1’. 
 
The output should appear like the format used in this example: 'x=2, y=0, count=1’

For solving the problem, i.e., finding the pattern in the given 2D character array, 
I first traversed the entire matrix row-wise and then column-wise. While traversing row-wise, 
I considered each row and applied the Knuth-Morris-Pratt (KMP) Algorithm to check if the current 
row contains the given pattern. If the pattern doesn't exist, I checked column-wise, i.e., while 
traversing each column, to check if that column contains the pattern or not. I have written tests 
in the Main.cpp file in order to check the correctness of the code, including a variety of test cases, 
both cases that contain the result and cases that don't contain the result.

For Reference (KMP Algorithm): https://cp-algorithms.com/string/prefix-function.html


------------------------------------------------------------------------------------------------


Instructions:
Clone the repository in your local system.
Run the following commands to run the program in your terminal:
- cd Find-the-word-master/src
- g++ -o find-the-word Main.cpp
- ./find-the-word

Time Complexity Analysis:
The Knuth-Morris-Pratt (KMP) Algorithm, has a time complexity of O(a + b), where a and b are the sizes of the strings being searched and the pattern being searched for, respectively.

Since we are applying KMP Algorithm to each row and each column of the 2D array, the overall time complexity becomes O(n * m), where n is the number of rows and m is the number of columns in the array.
