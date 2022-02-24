/***************************/
/* Austin Preston          */
/* CS 241                  */
/* 23 FEB 2022             */
/* Finds secret messages   */
/* using spaces after a    */ 
/* dot or defined char     */ 
/***************************/

#include <stdio.h>
#define DOT 0x2E /* This is the key character */
#define SPACE 0x20

int main () 
{
  int charManager;
  int spaceCounter = 0;
  int movingBits = 8;
  int bitCounter = 0;
  int byte = 0;

  while ((charManager = getchar()) != EOF) 
    {
      if (charManager == DOT)
	{
          
	  while (charManager == SPACE)
	    spaceCounter++;
	}

      if (charManager != SPACE && charManager != DOT)
        {
	 
         /* Will "add" a zero to the byte */
	  if (spaceCounter == 1) 
	    {
	      bitCounter++;
	      movingBits--;
	    }
          /* Adds a one to the byte */
	  if (spaceCounter == 2)
	    { 
	      bitCounter++;
	      movingBits--;
	      byte = byte + (1 << movingBits);
	    }

          /* This marks the end of the message */
	  if (spaceCounter == 3)
	    {      
      	      byte = 0;
	      return 0;
	    }
	  spaceCounter = 0;
	}  

      /* Forms the letter using the bits in the message */
      if (movingBits == 0)
        {
          printf("%d ", byte);
          movingBits = 8;
          byte = 0;
        }
  
      /* Error Case 1: Wrong Number of Bits */
      if (spaceCounter == 3 && (bitCounter % 8 != 0))
        return 1;

    }

  /* Error Case 2: No Message Closing Identifier */
  if (charManager == EOF && spaceCounter != 3)
    return 2;

  return 0;
}
