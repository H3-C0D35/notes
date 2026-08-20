
/*Objective: Practice the Rule of Three on a class that owns a dynamically allocated char array.
Implement a class DynamicString with:
● A private member char* data.
● A constructor DynamicString(const char* text) that allocates exactly enough memory (data = new
char[strlen(text) + 1]) and copies the characters in.
● A destructor that frees data.
● A copy constructor that performs a deep copy (allocates new memory and copies the characters, never
just copies the pointer).
● A copy assignment operator that: (a) checks for self-assignment, (b) frees the old memory, (c) allocates
new memory and deep-copies the characters, and (d) returns *this.
● A member function int length() const and a member function void print() const.
In main(), demonstrate all three special functions: construct a DynamicString, copy-construct a second one from
it, default-construct a third and copy-assign into it, then modify one object&#39;s contents (you may add a simple
setChar(int index, char c) helper) and show the others are unaffected.*/