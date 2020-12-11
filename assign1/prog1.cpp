/**********************************************************************
 *
 * Program: CSCI 241 Assignment 1
 * Date:    2/11/19
 *
 * This program tests functions for manipulating C strings.
 **********************************************************************/

#include <iostream>
#include <cstring>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

// Add your prototype  function here
char* copy(char* destination, const char* source, size_t num);
char* reverseCopy(char* destination, const char* source, size_t num);
char* caseChangeCopy(char* destination, const char* source, size_t num);
char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num);
void read(char* destination, int num);

int main()
   {
   const int WORDSIZE = 15;
   char words[][WORDSIZE] = {"sprightful", "reason to row", "New York", "Bolton", "Frida", ""};
   char word[WORDSIZE];

   // Test the copy function
   cout << "Copy \"sprightful\", should see \"sprightful\".\n";
   copy(word, words[0], sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the copy function
   cout << "Copy \"Supercalifragilisticexpialidocious\", should see \"Super\".\n";
   copy(word, "Supercalifragilisticexpialidocious", 5);
   cout << word << endl << endl;

   // Test the replaceCopy function
   cout << "Replace 'r' in \"reason to row\" with 's', should see \"season to sow\".\n";
   replaceCopy(word, words[1], 'r', 's', sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the replaceCopy function
   cout << "Replace 's' in \"Supercalifragilistic\" with 'd', should see \"duper\".\n";
   replaceCopy(word, "Supercalifragilistic", 'S', 'd', 5);
   cout << word << endl << endl;

   // Test the caseChangeCopy function
   cout << "Case change \"New York\", should see \"nEW yORK\".\n";
   caseChangeCopy(word, words[2], sizeof(word) - 1);
   cout << word << endl << endl;

   // Test the limit on the caseChangeCopy function
   cout << "Case change \"Supercalifragilistic\", should see \"sUPER\".\n";
   caseChangeCopy(word, "Supercalifragilistic", 5);
   cout << word << endl << endl;

   // Test the reverseCopy function
   cout << "Reverse \"Bolton\", should see \"notloB\"\n";
   reverseCopy(word, words[3], sizeof(word) - 1);;
   cout << word << endl << endl;

   // Test the limit on the reverseCopy function
   cout << "Reverse \"cytogeneticists\", should see \"tsicitenegotyc\"\n";
   reverseCopy(word, "cytogeneticists", sizeof(word) - 1);;
   cout << word << endl << endl;

   cout << "Reverse \"Frida\", change case, and replace 'D' with 'Z', should see \"AZIRf\".\n";
   replaceCopy(caseChangeCopy(reverseCopy(word, words[4], sizeof(word) - 1), word, sizeof(word) - 1), word, 'D', 'Z', sizeof(word) - 1);
   cout << word << endl << endl;

   cout << "Enter your entire name: ";
   read(words[5], sizeof(words[5]));
   cout << words[5] << endl << endl;

   cout << "Reverse your name and change case.\n";
   cout << caseChangeCopy(reverseCopy(word, words[5], sizeof(word) - 1), word, sizeof(word) - 1) << endl;

   return 0;
   }

/****************************************************************

   FUNCTION: char* copy(char* destination, const char* source, size_t num);

   ARGUMENTS: Takes a character as destination(words to be copied into),a character as source
   (characters of a string from the address) and a size_t as num which is the limt of characters
   it's able to take.

   RETURNS: The function returns a character

   NOTES: Copy the first num characters of a string specified by source to destination array.
   Source and destination are both pointers. Return a pointer to the start of the copied string.
****************************************************************/
char* copy(char* destination, const char* source, size_t num)
{
 /*copies the first num chacacters of source to destination */
 strncpy(destination, source, num);

 destination[num]='\0';                         /* at num, make that character a null */

 return destination;                           /* Return a pointer to the start of the copied string */

}

/****************************************************************

   FUNCTION: char* reverseCopy(char*destination, const char* source, size_t nume);

   ARGUMENTS: It takes a character as destination(the copied characters from source, a character as
   source(the characters of a string from the address), and a size_t as num which is the limit of
   characters it's able to take.

   RETURNS: The function returns a character.

   NOTES:  Copy the first num characters of a string by source to that specified by destination,
   reversing the order of the characters. Return a pointer to the start of the copied string.
****************************************************************/
char* reverseCopy(char* destination, const char* source, size_t num)
{
  int d,i;                              /*int d represents subscript of source*/
                                       /*int i represents subscript of destination*/
  size_t e=strlen (source);            /*e equals the string length of source*/


  /* if the first num characters of a string is less than the string lentht, subtract one from the num
   array and save it as the subsrcript else subract one from the string length and save it as
   the current subscript */
 if(num < e)
  {
   d=num-1;
  }
 else
  {
   d=e-1;
  }

  /* Copy the first num characters of a string from the address specified by
  source to that  specified by destination */
  for(i=0; d >= 0;i++,d--)
   {
     destination[i]=source[d];
   }

 destination[i]='\0';

 return destination;
}

/****************************************************************

   FUNCTION: char caseChangeCopy(char* destination, const char* source, size_t num);

   ARGUMENTS: It takes a character as destination(copied characters from source), a character as
   source(a character of strings from the address) and size_t as num which is the limit of character
   destination is able to take.

   RETURNS: The function returns a character.

   NOTES: Copy the first num characters of a string in which the case of each lowercase character
   is shifted to uppercase (and uppercase to lowercase),from the address specified by source to
   that specified by destination. Return a pointer to the start of the copied string.
****************************************************************/
char* caseChangeCopy(char* destination, const char* source, size_t num)
{

 /* Copy the first num characters of a string from the address of source to that specified by destination */
 strncpy(destination, source, num);

 destination[num]='\0';

 /* a for loop that goes through the entire character array */
 for(int i = 0; i < num; i++)
  {

 /*if the character of each case is a lowercase, shift it to uppercase (and uppercase character
  to lowercase */
    if(isupper(destination[i]))
     {
      destination[i]=tolower(destination[i]);
     }
    else
     {
        destination[i]=toupper(destination[i]);
     }
  }
   return destination;
}

/****************************************************************

   FUNCTION: char* replaceCopy(char* detination, const char* source, char target, char replace, size_t num);

   ARGUMENTS: It takes a character as destination(characters to be copied into),a constant character
   as source(characters of a string), a charcter as target(a character to be removed), a character as
   replace(which replace the target with a new character, and size_t as num which copies
   the first num characters of a string

   RETURNS: The function returns a character.

   NOTES: Copy the first num characters of a string in which each instance of a "target" character
   is replaced by the "replace" character, from the address specified by source to that specified by
   destination. Return a pointer to the start of the copied string.
****************************************************************/
char* replaceCopy(char* destination, const char* source, char target, char replace, size_t num)
{
 /* Copy the first num characters of a string from source to destination */
        strncpy(destination, source, num);

        destination[num]='\0';

 /* This for loop goes throught the entire character array */
  for(int i = 0; i < num; i++)
    {

 /*if the character happens to be a "target" character it is then replaced by the "replace" character, and
  takes the place of the orginal character */
     if(destination[i] == target)
      {
       destination[i]=replace;
      }
    }

return destination;

}

/****************************************************************

   FUNCTION: void read(char* destination, int num);

   ARGUMENTS: It takes a character as destination(a string of characters entered by the user) and a
   integer as num which is the length of characters it cannot exceed.

   RETURNS: The function returns a nothing.

   NOTES: Read a string of characters entered by the user at the keyboard with a length no
   longer than num characters (including the null character at the end of the C string)
   into an address specified by destination. The user should be able to type a space or tab as
   part of the string.
****************************************************************/
void read(char* destination, int num)
{
 /*Read a string of characters entered by the user with a length no longer
   than num characters (including the null character) into an address specified by destination */
 cin.getline(destination,num);

}
