///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////// DEMONSTRATION LAB I.3.A-3 ///////////////////////////////
//////////////////////////////////////// Header Files /////////////////////////////////////
////////////////////////////////////// "String Theory" ////////////////////////////////////
////////////////////////////////////// Instructor Solution ////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
// The objective of this lab is to declare and define a header "MyStringHeader.h"
// MyStringHeader should include a function of prototype:
// int print_the_count(char * inputString, int strLen);
// The requirements for the prototype are included below in the function documentation box
// The students definition of the prototype will be tested by instructor-written
//     test code (see: Unit Test Code 1.c)
// When students are done declaring and defining the header, they are to add
//     "Unit Test Code 1.c" to their project and debug.
// Unit Test Code 1.c utilizes macros to run some, all, or none of the available
//     unit tests.  Comment out the Unit Test Code 1.c macros to manage which tests
//     are run. 
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef ERR_NULL_POINTER
#define ERR_NULL_POINTER -1
#else 
#undef ERR_NULL_POINTER
#define ERR_NULL_POINTER -1
#endif

#ifndef ERR_INVALID_LENGTH
#define ERR_INVALID_LENGTH -2
#else 
#undef ERR_INVALID_LENGTH
#define ERR_INVALID_LENGTH -2
#endif

/*
* FUNCTION:   int print_the_count(char * inputString, int strLen)
*
* ARGUMENTS:  inputString is a pointer to a character array (see: string) and is *NOT*
*                 guaranteed to be NULL terminated.  This is why the length of the
*                 string is also passed as an argument.
*             strLen is the length of the inputString.  strLen is required as a safety
*                 measure since inputString is not guaranteed to be null-terminated.
*                 strLen does not need to be long enough to include any null character,
*                 even if there was one.
*
* RETURNS:    # of alphabet letters found in inputString
*             ERR_NULL_POINTER is inputString is NULL
*             ERR_INVALID_LENGTH is strLen is unreasonable (zero or less)
*
* NOTES:      Not only does this function return the total number of alphabet letters
*                 that were counted, it should also print a table of letters from the
*                 string with their count.  Do not print any letters that were not
*                 found in inputString.
*             The "case" of the letter (upper or lower) should not matter for the count.
*                 There are different ways to ignore the case of a char.  It is up
*                 to the student to determine the method.
*/
int print_the_count(char * inputString, int strLen)
{
	int theCount = 0; // Running count of upper case letters
	int i = 0; // Incrementing variable
	char oneCharacter = 0; // Temp storage to change each string character to an upper case character one by one
						   /*
						   *  An array to store the by-letter-count of upper case letters
						   *  Each element represents the count of an upper case letter
						   *  Index 0 represents the letter A
						   *  Index 25 represents the letter Z
						   */
	int countTheLetters[26] = { 0 };

	if (!inputString) // Checks for NULL pointer
	{
		return ERR_NULL_POINTER;
	}
	else if (strLen <= 0) // Checks for unrealistic input
	{
		return ERR_INVALID_LENGTH;
	}
	else
	{
		/*
		*  COUNT THE STRING'S ALPHABET LETTERS
		*/
		for (i = 0; i < strLen; i++)
		{
			oneCharacter = toupper(inputString[i]); // Changes the string to upper case characters
			if (oneCharacter >= 65 && oneCharacter <= 90) // If the character matches A-Z...
			{
				countTheLetters[oneCharacter - 65]++;	// ...Add one to the count of this particular upper case letter...
				theCount++;								// ...and increment the running count of upper case letters
			}
		}

		/*
		*  PRINT THE ALPHABET CHART
		*/
		// Table title
		printf("************\n");
		printf("LETTER COUNT\n");
		printf("************\n");
		for (i = 0; i <= 25; i++) // Check the decimal value of each upper case letter
		{
			if (countTheLetters[i] > 0) // If the value is greater than zero...
			{
				printf("%c\t%d\n", i + 65, countTheLetters[i]); // ...print a table entry for this letter
			}
		}
	}

	return theCount; // Return the running count of upper case letters
}

int reverse_it(char * forwardString, int strLen)
{

	if (!forwardString)
	{
		return ERR_NULL_POINTER;
	}
	else if (forwardString <= 0)
	{
		return ERR_INVALID_LENGTH;
	}
	else
	{
		for (int i = strLen - 1; i >= 0; --i)
		{
			printf("%c", forwardString[i]);
		}
		return 0;
	}
}

/*
*  NOTE:
*  This code was incomplete at the time it was transferred from the development laptop
*  to it's storage location on the NIPRNET.  Some code was added without the aid of an IDE.
*  The conditional preprocessor wrappers for the two error condition macro constants
*  (see: ERR_NULL_POINTER and ERR_INVALID_LENGTH) were added after the fact.  The docmentation
*  box was also missing.  The final edits were made in Noteapd.
*/
