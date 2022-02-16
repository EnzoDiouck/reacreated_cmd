#include "main.h"

static void handler()
{
  write(1, "\r&> exit", 8);
  exit(EXIT_SUCCESS);
}


int main(int argc, char **argv, char **env)
{
  int comp;
  char *str;
  char **pathname;
  
  if (argc > 1)
    return 0;
  str = malloc(sizeof(char) * 256);
  if (str == NULL)
    return 0;
  while (1)
    {
      signal(SIGINT, handler);
      comp = 0;
      write (1, "&> ", 3);
      comp = read(0, str, 256);
      if (comp == 0 || comp == -1)
        {
	  write(1, "exit\n", 5);
	  return 0;
        }
      str[comp - 1] = '\0';
      if (str[0] == '/')
	  //argv = std_split(str, ' '); probleme ici
	std_dopathcmd(str, argv, env);
      else if (std_strcmp(str,"\n") == 0)
	return main(argc,argv,env);
      else if (std_strcmp(str,"cd") == 0)
	  env = std_dochdir(std_split(str, ' '), env);
      else if (str[0] == '.')
	std_dopathcmd(clearcmd(str), std_split(str, ' '),env);
      else if (std_strcmp(str,"exit") == 0)
	return 0;
      else
	{
	  pathname = std_split(env[find_inenv(env, "PATH")], ':');
	  pathname[0] = std_remove(pathname[0]);
	  argv = std_split(str, ' ');
	  std_docmd(pathname, argv, env, str);
	}
    }
}

