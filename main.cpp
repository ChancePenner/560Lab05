#include <iostream>
#include "executive.h"

int main() //takes input of file to be opened
{
	Executive exec; //passes in the run mode flag ("-i" for interactive mode or "-t" for test mode)
	exec.run(); //calls the executive run functions

  return(0);
}
