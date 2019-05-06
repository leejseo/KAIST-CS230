#include <stdio.h>
#include "file.h"

// Do not modify this file

int main()
{  
  	char command[100];  // maximum input char length = 100

	while (1) {
		fgets(command, sizeof(command), stdin); // get command line
		file(command);
	}

  return 0;
}
