#include "split_library.h"

//--------------------------------------------------VARIABLE DEFINITIONS-------------------------------------------------------
extern String elements[]; // array of strings used to store the split elements                                                                                               

String element_string; // a string varialbe used to accumulate a temporary section of string, which could become an element   
int index = 1;         // integer variable to tell program where to save the current element in the elements[] array          
// below are some parameters used for establishing the type a char is, this is simply  to make the code more readable.        
const int LETTER = 1;                                                                                                         
const int SPACE =  2;                                                                                                         
const int NUMBER = 3;                                                                                                         
const int SYMBOL = 4;                                                                                                         
Split::Split(){
	
}

int Split::type_check(char input, int type) {

  if (isAlpha(input)) {                     // check if the current char is a letter
    type = LETTER;
  } else if (input == ' ') {                // check if the current char is a space
    type = SPACE;
  } else if (isdigit(input)) {              //check if the current char is a number
    type = NUMBER;
  } else {                                 // if the current char was not a letter,space, or number, assume it was a symbol
    type = SYMBOL;
  }
  return type;                             // return the result
}

/*The function below iterates through all the characters in the length of the input string an uses some logic to determine where/whether
 * to save them as an element or discard them. Spaces and symbols are the character of interest, or split chars.
 */

void Split::split (String input_str) {                                                 //define the function used to split a string into elements
  for (int i = 0; i <= input_str.length(); i ++) {              // index through the length of the string

    int current_type = type_check(input_str[i], current_type);                  // determine type for current char
    int prev_type = type_check(input_str[i - 1], prev_type);    // determine type for previous char
    switch (current_type) {                                             // switch cases according to the type of the current char
      case LETTER:
        element_string += input_str[i];                         // in the case it is a letter, simply accumulate it to the element_string
        break;
      case SPACE: // space
        if (prev_type != SPACE and prev_type != SYMBOL) {       // if the current type is a space, the previous type wasnt a space and wasnt a symbol:
          elements[index] = element_string;                     //   -save what's already in the element string, increment the index, and clear the element string
          index++;
          element_string = "";
        } else if (prev_type == SPACE or prev_type == SYMBOL) { // if the current type is a space and the previous type was a space or a symbol:
          element_string = "";                                  //  - just clear the element string and move on
        }
        break;
      case NUMBER:
        element_string += input_str[i];                        
        break;
      case SYMBOL: // symbol
        if (prev_type != SPACE and prev_type != SYMBOL) {
          elements[index] = element_string;  // make the current index of the element list equal to the current new_string
          index++;                            // increment the index
          elements[index] = input_str[i];   // add the symbol to the element list at the current index
          index++;                            // incremement the index again
          element_string = "";
        } else if (prev_type == SPACE or prev_type == SYMBOL) {
          elements[index] = input_str[i];  // make the current index of the element list equal to the current new_string
          index++;
          element_string = "";
        }
        break;
    }
  }
  elements[0] = index - 1;             // save the quantity of elements found in the first spot of the elements[] array
}

int Split::result(String input_str, bool msg_en)		   // define a function to print the elemenents the string was split into 
 
 {     
 if (msg_en){ 
  Serial.print("\noriginal string: '");
  Serial.print(input_str);
  Serial.print("'");
  Serial.print("\nelements found:");
  Serial.print(index - 1);
  Serial.print(": [");
  Serial.print("'");
  for (int i = 1; i < index; i++) {
    Serial.print(elements[i]);
    i < index - 2 ? Serial.print("','") : Serial.print("");
  }
  Serial.print("']");
 }
  String len_str = elements[0];
  int len = len_str.toInt();
  return len;
}

void Split::clear_elements(){
	int len = elements[0].toInt();
	for (int i = 0; i <=len; i++) {
	elements[i] = "";
	}
}
