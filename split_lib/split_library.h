#ifndef SPLIT_H
#define SPLIT_H

#include <Arduino.h>
class Split
{
	public:
Split();
void split (String input_str);
int result(String input_str,bool msg_en);
int type_check(char input, int type) ;
void clear_elements();
//extern String elements[20];

};
#endif
