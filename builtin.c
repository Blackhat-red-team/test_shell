#include "shell.h"



/**
 * exitt - out from shell
 * @info: struct contain an argument
 * Return: ecit from programme with status 
*/

int exitt(info_t *info)
{

int checke;
if (info->argv[1])
{

checke = error_atoi(info->argv[1]);
if (checke == -1)
{
info->status = 2;

print_error(info, "umlegal number: ");

_eputs(info->argv[1]);
_eputchar('\n');
return (1);

}
info->err_num = error_atoi(info->argv[1]);
return (-2);
}

info->err_num = -1;
return (-2);
}

/**
 * cdd - chage curren directory
 * @info: struct contain an argument
 *  Return: 0
 */

int _mycd(info_t *info)
{

char *s, *dir, buffer[1024];
int chdir_ret;

s = getcwd(buffer, 1024);
if (!s)
_puts("TODO: >>getcwd failure emsg here<<\n");

if (!info->argv[1])

{

dir = _getenv(info, "HOME =");
if (!dir)
chdir_ret =
chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
else
chdir_ret = chdir(dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}

_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_ret = /* what should this be */
chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
chdir_ret = chdir(info->argv[1]);
	
if (chdir_ret == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}


return (0);

}


/**
 * _myhelp - changes the current directory of the process
 * @info: struct contain an argument
 *  Return: 0
 */

int _myhelp(info_t *info)
{

char **arg_arr;

arg_arr = info->argv;
_puts("help call works. Function not yet implemented \n");

if (0)
	
_puts(*arg_arr);

	return (0);
}
