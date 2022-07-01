/*Name: Marshall Garrett
 * Project: split function on MCU
 * description: The purpose of this library is to implement something close to the split() function in python. 
 * The split() function will take a string as input, and output an array of elements. Any letter, number, or symbol is considered to be an element. 
 * White spaces are removed. Numbers and letters that don’t have a space between them will be put into one element, but symbols are always put into their own elements.
 */

#include <split_library.h>  // include the library
String elements[20];        // define the array to hold elements, choose appropriate size (NOTE: MUST BE NAMED 'elements')

String input_str = "if(counter1 < 10){";  // Create the string that is going to be split
Split str1;                               // Create an object of the Split class
//--------------------------------------------------RUN TEST CODE IN SETUP----------------------------------------------------|
void setup() {
  Serial.begin(9600);                                             // setup communication to serial monitor
  Serial.print("\n original string: ");Serial.print(input_str);  // print the original string
  str1.split(input_str);                                         // call the function to split string into elements
  int len = str1.result(input_str,0);                            // call the function to print result of split operation to serial monitor, return length (how many elements found)(NOTE: if the second argument is 1, it prints elements to console)
  Serial.print("\nelements returned:");         
  print_arr(len);                                                // print the array after it was filled with elements by the split function
  str1.clear_elements();                                        // clear all the elements in the array
  Serial.print("\nerased array:");
  print_arr(len);                                               // print the array again to show it is erased
}



//-----------------------------------------------------------------------------------------------------------------------------
void loop() {} // void loop does nothing in this case

void print_arr(int len) {                                      // define a function to print what is in the array with some commas and brackets for formatting
   Serial.print("["); Serial.print("'");         
  for (int i = 1; i <= len; i++)                               // iterate through all the elements stored in the array
  {
    Serial.print(elements[i]);                                 // print the current element
    i < len - 1 ? Serial.print("','") : Serial.print("");
  }
  Serial.print("']");
}
