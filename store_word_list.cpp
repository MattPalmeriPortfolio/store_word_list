#include <iostream>
#include <cstring>

//define class
class StringVar {
public:
	StringVar(); //Creates a StringVar object of [100]
	StringVar(unsigned int size); //creates a StringVar object of [size]
	StringVar(const char a[]); //Creates a StringVar object ocntaining the contents of a[], and the size of a[]
	StringVar(const StringVar& stringObject); //Copy constructor
	~StringVar(); //DESTRUCTINATOR
	unsigned int length() const; //returns the length of the current string value
	void inputLine(std::istream& ins = std::cin); //Reads a line of text, up to the first newline character
	StringVar copyPiece(unsigned int start, unsigned int end); //returns substring starting at index start and ending at index end
	char oneChar(unsigned int index); //returns the character located at the specified index
	void setChar(char inserted, unsigned int index); //sets the character at the specified index to inserted
	friend std::ostream& operator <<(std::ostream& outs, const StringVar& theString); //Outputs a StringVar object to outs
	friend std::istream& operator >>(std::istream& ins, StringVar& theString); //reads one word from ins and stores in theString
	void operator =(const StringVar& rightSide); //deep copies rightSide
	friend bool operator ==(const StringVar& left, const StringVar& right);
	friend StringVar operator +(const StringVar& left, const StringVar& right); //returns a new StringVar that is a concatenation of left and right
private:
	char* value;
	unsigned int maxLength;
};
class Text {
public:
	Text(); //creates an object of size 1 with one empty StringVar element
	Text(unsigned int size); //creates an object of size [size] of empty StringVar elements
	Text(const char a[]); //precondition: a must be a c-string. postcondition: creates an object with an array equal to the # of words in a, with each element equal to one word in a.
	~Text(); //destructor
	unsigned int length() const; //returns the max # of elements in the object
private:
	StringVar* words;
	unsigned int size;
};


//main
int main()
{
	using namespace std;
	Text one, fifty(50);
	return 0;
}

//StringVar functions
//constructors
StringVar::StringVar() : maxLength(100)
{ value = new char[maxLength + 1]; value[0] = '\0'; }
StringVar::StringVar(unsigned int size) : maxLength(size)
{ value = new char[maxLength + 1]; value[0] = '\0'; }
StringVar::StringVar(const char a[]) : maxLength(strlen(a))
{ value = new char[maxLength + 1]; strcpy_s(value, maxLength + 1, a);}
//copy constructor
StringVar::StringVar(const StringVar& stringObject) : maxLength(stringObject.length())
{ value = new char[maxLength + 1]; strcpy_s(value, maxLength + 1, stringObject.value); }
//destructor
StringVar::~StringVar() { delete[] value; }
//operators
std::ostream& operator << (std::ostream& outs, const StringVar& theString)
{ outs << theString.value; return outs; }
std::istream& operator >>(std::istream& ins, StringVar& theString)
{
	char next;
	if (theString.maxLength > 0)
	{
		unsigned int index = 0;
		do {
			ins.get(next);
			theString.value[index] = next;
			++index;
		} while (isspace(next) == false && index < theString.maxLength);
		theString.value[index] = '\0';
	}
	do {
		ins.get(next);
	} while (next != '\n');
	return ins;
}
bool operator==(const StringVar & left, const StringVar & right)
{
	if (left.length() == right.length())
		return strncmp(left.value, right.value, left.length());
	return false;
}
StringVar operator +(const StringVar& left, const StringVar& right)
{
	StringVar concatenated(left.length() + right.length());
	strncat_s(concatenated.value, left.length() + right.length() + 1, left.value, left.length());
	strncat_s(concatenated.value, left.length() + right.length() + 1, right.value, right.length());
	return concatenated;
}
void StringVar::operator =(const StringVar& rightSide)
{
	unsigned int newLength = strlen(rightSide.value);
	if (newLength > maxLength)
	{
		delete[] value;
		maxLength = newLength;
		value = new char[maxLength + 1];
	}
	for (unsigned int i = 0; i < newLength; ++i)
		value[i] = rightSide.value[i];
	value[newLength] = '\0';
	return;
}
//functions
unsigned int StringVar::length() const { return strlen(value); }
void StringVar::inputLine(std::istream& ins)
{ ins.getline(value, maxLength + 1); return; }
StringVar StringVar::copyPiece(unsigned int start, unsigned int end)
{
		if (start < length() && end <= length() && start < end)
		{
			StringVar substring(end - start + 2);
			for (unsigned int valueIndex = start, substringIndex = 0; valueIndex <= end && substringIndex < (end - start + 1); ++valueIndex, ++substringIndex)
				substring.value[substringIndex] = value[valueIndex];
			substring.value[end - start + 1] = '\0';
			return substring;
		}
		else
			return StringVar();
}
char StringVar::oneChar(unsigned int index)
{
	if (index < length())
		return value[index];
	else
		return '\0';
}

void StringVar::setChar(char inserted, unsigned int index)
{
	if (index < length())
		value[index] = inserted;
	return;
}

//Text functions
//constructors
Text::Text() : size(1), words(new StringVar[size]) {/*empty*/ }
Text::Text(unsigned int size) : size(size), words(new StringVar[size]) {/*empty*/ }
Text::Text(const char a[])
{
	//TODO
}
//destructor
Text::~Text() { delete[] words; }

//functions
unsigned int Text::length() const { return size; }
