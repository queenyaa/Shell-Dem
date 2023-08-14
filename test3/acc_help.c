#include "shell.h"

/**
 * acc_help_setenv - Help information for the builtin setenv
 * Return: no return
 */
void acc_help_setenv(void)
{

	char * boa = "setenv: setenv (const char *nick, const char *value,";

	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = "int replace)\n\t";
	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, boa, _strlen(boa));
}

/**
 * acc_help_env - Help information for the builtin env
 * Return: no return
 */
void acc_help_env(void)
{
	char *boa = "env: env [option] [nick=value] [command [argt]]\n\t";

	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, boa, _strlen(boa));

}

/**
 * ac_help_unsetenv - Help information for the builtin unsetenv
 * Return: no return
 */
void acc_help_unsetenv(void)
{
	char * boa = "unsetenv: unsetenv (const char *nick)\n\t";

	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, boa, _strlen(boa));
}


/**
 * acc_help_exit - Help information fot the builint exit
 * Return: no return
 */
void acc_help_exit(void)
{
	char * boa = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = "status is that of the last command executed\n";
	write(STDOUT_FILENO, boa, _strlen(boa));
}

/**
 * acc_help_general - Entry point for help information for the help builtin
 * Return: no return
 */
void acc_help_general(void)
{
	char * boa = "$ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = "These commands are defined internally. Type 'help' to see the list";
	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, boa, _strlen(boa));
	boa = "unsetenv [variable]\n";
	write(STDOUT_FILENO, boa, _strlen(boa));
}

