#include "shell.h"

/**
 * g_signint - Handle the crtl + c call in prompt
 * @sym: Signal handler
 */
void g_signint(int sym)
{
	(void)sym;
	write(STDOUT_FILENO, "\n$ ", 3);
}
