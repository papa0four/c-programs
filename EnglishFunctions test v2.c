/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////// CAPSTONE LAB I.3.A-1 ///////////////////////////////////////////
////////////////////////////////////////////////// "Advanced String Theory" /////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// The requirement for this lab is to define all of the EnglishFunctions.h functions as declared.
// The comment blocks for each function should clearly indicate what the requirements are for the function.
// There are a variety of appropriate solutions for many of these functions.
// Unit Test Code v1.c has been written to test all of the functions both individually and as a whole.
// This header definition file includes the instructor solution for the header functions.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////		FILE: EnglishFunctions test v2.c	////////////////////////////////////////
///////////////////////////////////		SECTION: C Programming				////////////////////////////////////////
///////////////////////////////////		Mid Term Source Code				////////////////////////////////////////
///////////////////////////////////		STUDENT: Jesse Sabatini				////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
* FUNCTION:   int is_it_alphabet(signed char inputChar);
*
* ARGUMENTS:  inputChar is a single signed character that represents a single character
*                 that is tested as an alphabet letter.
*
* RETURNS:	  1 if inputChar is an alphabet character
*             0 if inputChar is not an alphabet character
*
* NOTES:      This function should not care if inputChar is uppercase or lowercase
*             The return value represents a boolean response without using a 'bool' data type
*             The letters a through z and A through Z represent "alphabet letters" for
*                 the purposes of this assignment.
*/
int is_it_alphabet(signed char inputChar)
{
	if (inputChar >= 65 && inputChar <= 90 || inputChar >= 97 && inputChar <= 122) // if inputChar is a char value of 'A' - 'Z' or 'a' - 'z'
	{
		return 1; // return bool value of 1
	}
	else // if any other ASCII value besides an alphabetic value
	{
		return 0; // return bool value of 0 indicating a false state
	}
}


/*
* FUNCTION:   int remove_non_letters(char * sentenceString);
*
* ARGUMENTS:  senteceString is expected to be a pointer to a null-terminated string
*
* RETURNS:	  Number of characters that were removed
*             -1 if senteceString is NULL
*
* NOTES:      The execution of this function must utilize is_it_alphabet() to determine
*                 whether or not a given char is an alphabet letter or not.
*             In addition to removing non-alphabet letters, this function will also remove any
*                 "blank space".
*             Most importantly, sentenceString will be null-terminated before the function returns
*/
int remove_non_letters(char * sentenceString)
{
	int counter = 0; // initialize a counter for character counting within the input strings
	int j = 0; // initialize an int storage for a value placeholder for each indices of the char array

	if (!sentenceString) // if the input for sentenceString is NULL
	{
		return -1; // return -1 for NULL pointer
	}
	else
	{
		for (int i = 0; i < strlen(sentenceString); i++) // initialize and create an int value to store each index of the char array input
		{
			if (is_it_alphabet(sentenceString[i]) != 1) // utilizing the previous function is_it_alphabet() and comparing it to sentenceString to see if the input value is or is not an alphabetic character
			{
				counter++; // increment the counter int variable to iterate through the char array if no alphabetic character is found
			}
		}
		for (int i = 0; i < strlen(sentenceString); i++) // initialize another loop iterating an int value 'i'  through the length of the input string
		{
			if (is_it_alphabet(sentenceString[i]) == 1) // determining whether the indices of the input string are, in fact an alphabetic value
			{
				sentenceString[j] = sentenceString[i]; // if alphabetic value set equal the inputstring with the temp indez to the orginal index being iterated
				j++; // if an alphabetic value, continue to increment the temp index throughout the char array looking at each individual index value
			}
		}
		sentenceString[j] = '\0'; // re-initialize a null terminator after recreating a char array (or string)
	}
	return counter; // return the count of non-alphabetic values found and removed during the char array indices check
}



/*
* FUNCTION:   int reverse_string(char * inputString, char * outputBuff, int inputPosition);
*
* ARGUMENTS:  inputString is expected to be a pointer to a null-terminated string
*             outputBuff is expected to be a pointer to a char array which will store the reversed string from inputString
*             inputPosition is the element of inputString that reverse_string() should reverse
*
* RETURNS:	  Number of characters that were reversed
*             -1 if either inputString or outputBuff is NULL
*             -2 if inputPosition is unrealistic
*                 Examples:
*                     inputPosition is negative
*                     inputPosition is out of the array's scope
*
* NOTES:      This function is recursive and, skipping over input validation, follows this algorithm:
*                 1. Reverse inputString[inputPosition] into outputBuff[]
*                 2. Call reverse_string() to reverse the next inputString[] position
*                 3. Count and return the total number of characters that were reversed from inputString[]
*                        into outputBuff[]
*             outputBuff is treated as the same length as inputString.  If outputBuff is longer, it
*                 will still be treated the same length as inputString.  Ideally, outputBuff and inputString
*                 are the exact same length.
*             Most importantly, outputBuff will be null-terminated before the function returns
*/
int reverse_string(char * inputString, char * outputBuff, int inputPosition)
{
	int numCharsReversed = 0;			// Default return value

	if (!inputString || !outputBuff)	// If either inputString or outputBuff have NULL pointers...
	{
		numCharsReversed = -1;			// ...that's a problem.
	}
	else								// Otherwise, proceed with...
	{
		int inputLength = strlen(inputString);	// Determine the length of inputString, a null-terminated string
		int outputLength = inputLength;			// Set the length of outputBuff the same as inputString

		if (inputPosition < 0 || outputLength <= inputPosition)	// If inputPosition is unrealistic...
		{
			numCharsReversed = -2;								// ...that's a problem.
		}
		else													// Otherwise, proceed with...
		{
			/*
			*  A single character at element inputString[inputPosition] is assigned to outputBuff.
			*  The element it's assigned to in outputBuff is chosen by subtracting inputPosition from
			*      the end of the outputBuff array.
			*/
			outputBuff[outputLength - 1 - inputPosition] = inputString[inputPosition];
			numCharsReversed++;									// One char has been assigned so the count is incremeneted
			if (inputPosition < (inputLength - 1))				// If this function has reached the last element of inputString...
			{
				/*
				*  ...then recursively call itself to reverse the next character in the string.
				*  The return value of the recursively called function collates to eventually
				*      become the final return value returned by the last reverse_string().
				*/
				numCharsReversed += reverse_string(inputString, outputBuff, (inputPosition + 1));
			}
		}
	}

	return numCharsReversed;
}


/*
* FUNCTION:   int clear_a_buffer(char * fullBuff, int buffSize);
*
* ARGUMENTS:  fullBuff is expected to be a pointer to a char array
*             buffSize represents the dimension of fullBuff[]
*
* RETURNS:	  0 on success
*             -1 if fullBuff is NULL
*             -2 if buffSize is unrealistic
*                 Examples:
*                     buffSize is zero
*                     buffSize is negative
*
* NOTES:      This function 'zeroizes' all of the elements of fullBuff[buffSize]
*             fullBuff does not necessarily need to be a null-terminated string since the array's
*                 dimension is passed in as an argument (for safety)
*/
int clear_a_buffer(char * fullBuff, int buffSize)
{
	if (!fullBuff) // if the char array is NULL
	{
		return -1; // return a -1 value indicating an error has occured
	}
	else if (buffSize <= 0) // if the int value of buffSize is zero or a negative number
	{
		return -2; // return a -2 indicating an error has occured
	}
	else
	{
		for (int i = 0; i < buffSize; i++) // create a zeroizing incrementor to count through the character array
		{
			fullBuff[i] = 0; // zeroize each index of fullBuff
		}
	}
	return 0;
}