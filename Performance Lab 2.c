//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////// MQT (I.4.b) PERFORMANCE LAB 2 ///////////////////////////////////////////
////////////////////////////////////////////////////// Portability ///////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Redefine EOF as 66 (without compiler warnings)
// Use preprocessor directive(s) to:
//     Only compile in "release" and only compile if _INC_STDIO is defined
//     Prints the name of a macro and also print the integer value of that macro
//     Use a #else 'fall through; for ease of use and safety
// Use your preprocessor directives on on FOPEN_MAX, FILENAME_MAX, and EOF
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* 
 *  stdio.h uses the _INC_STDIO macro as it's header guard 
 *  FOPEN_MAX is an integer which represents the maximum number of streams that the system can simultaneously guarantee
 *  FILENAME_MAX is an integer which represents the longest possible filename
 *  EOF is, by default, a negative integer which indicates the end-of-file has been reached
 */
#include <stdio.h>

				// If EOF is defined...
				// ...then undefine it...
				// ...and then define it as (66)...
				// ...Otherwise, if EOF was not previously defined...
				// ...then define it as (66) anyway.
				// That is all

				// If _INC_STDIO is defined *AND* _DEBUG is not defined...
				// ...then define PRINT_MACRO like this...

				// ...Otherwise, if either _INC_STDIO was undefined or _DEBUG was defined then...
				// ..then define PRINT_MACRO like this...
				// That is all.

#ifdef EOF
#undef EOF
#define EOF (66)
#else
	#define EOF (66)
#endif
#if defined(_INC_STDIO) && !defined (_DEBUG)
	#define(PRINT_MACRO)
#elif !defined(_INC_STDIO) && defined(_DEBUG)
	#define(PRINT_MACRO)
#else
	#define PRINT_MACRO(x) printf(#x " has a max value of %d \n", x);
#endif

int main(void)
{
	PRINT_MACRO(FOPEN_MAX);
	PRINT_MACRO(FILENAME_MAX);
	PRINT_MACRO(EOF);			
/* 
 *  Performance Note:  EOF's value will not print in this implementation of PRINT_MACRO() even though
 *  it's been redefine regardless of the status of stdio.h's header guard macro, _INC_STDIO
 *  (defined or not)
 */

	getchar(); getchar();
	return 0;
}
