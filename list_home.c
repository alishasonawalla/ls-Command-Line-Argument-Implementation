/*
 * Author: Alisha Sonawalla
 * Date: April 25, 2018
 * 
 * Description: This program displays the contents of the home directory irrespective of the 
 *              actual working directory. 
 * Note: The upper case functions - Fork, Execve and Wait are from csapp.c. Those functions take care of 
 *       error handling and therefore, I haven't done it in my program
 */


//Include header file with declarations and libraries
#include "csapp.h"


int main(int argc, char ** argcv, char ** envp)
{
	
	//Get value of the HOME environment variable using getenv
	//so that we can print out the contents of the home directory 
	//regardless of what the user's current working directory is
	const char *name = "HOME";
	char *val;
	val = getenv(name);
	//If there is no home value in envp, output error message
	if (val == NULL)
	{
		fprintf(stderr, "Cannot find home directory");
		exit(0);
        }
	
	//Declare an array to pass parameters to execve
	char *args [4];
	args[0] = "/bin/ls";
	args[1] = "-l";
	args[2] = val;
	args[3] = NULL;
	
	//Create a child process and call execve on it
	if (Fork() == 0)
	{
	   //Pass the filename, args array and envp (taken in through main) to execve
	   Execve(args[0], args, envp);
        }
	
	//Call Wait to let child process finish
	//Wait takes null as there's only one child process and address is therefore not needed
	Wait(NULL);
	return 0;
}

