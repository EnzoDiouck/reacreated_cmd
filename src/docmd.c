#include "docmd.h"
#include <stdlib.h>

int find_inenv(char **env, char *tofind)
{
  int comp;

  comp = 0;
  while (std_strcmp(tofind, env[comp]) != 0)
    comp++;
  return comp;
}

void std_docmd(char **pathname, char **argv, char **envp, char *str)
{
  int id;
  int wstatus;
  char *path;
  int comp;
  int comp2;
  bool executed;

  comp = 0;
  executed = false;
  path = malloc(sizeof(char) * 256);
    while (argv[comp] != NULL)
    {
      comp2 = 0;
      while (argv[comp][comp2] != '\0')
	{
	  if (argv[comp][comp2] == '$')
	    argv[1] = find_afterdollar(argv[comp], envp);
	  comp2++;
	}
      comp++;
    }
  comp = 0;
  id = fork();
  if (id == 0)
    {
      while(pathname[comp] != NULL)
	{
	  path = std_fusion(pathname[comp],str);
	  if (execve(path, argv, envp) != -1)
	    executed = true;
	  comp++;
	}
      if (executed == false)
	{
	  write(1, "command not found\n", 19);
	  exit(0);
	}
    }
  else
    {
      waitpid(id, &wstatus, 0);
      if (WIFEXITED(wstatus) == 0)
	write (1, "problem when executing commande\n", 33);
    }
  free(path);
}

void std_dopathcmd(char *pathname, char **argv, char **envp)
{
  int id;
  int wstatus;

  id = fork();
  if (id == 0)
    {
      if (execve(pathname, argv, envp) == -1)
	{
	  write(1, "command not found\n", 19);
	  exit(0);
	}      
    }
  else
    {
      waitpid(id, &wstatus, 0);
      if (WIFEXITED(wstatus) == 0)
	write (1, "problem when executing commande\n", 33);
    }
  free(argv);
}

static char *remove_pwd(char *str)
{
  int comp;
  int comp2;
  char *new_str;

  comp2 = 0;
  comp = std_strlen(str);
  new_str = malloc(sizeof(char) * std_strlen(str) + 1);
  while (str[comp] != '/')
    comp--;
  while (comp2 < comp)
    {
      new_str[comp2] = str[comp2];
      comp2++;
    }
  new_str[comp2] = '\0';
  //free(str);
  return new_str;
}

static char *add_pwd(char *str, char *str2)
{
  int comp;
  int comp2;
  char *new_str;

  comp = 0;
  comp2 = 0;
  new_str = malloc(sizeof(char) * (std_strlen(str) + std_strlen(str2) + 2));
  while (str[comp] != 0)
    {
      new_str[comp] = str[comp];
      comp++;
    }
  new_str[comp] = '/';
  comp++;
  while (str2[comp2] != 0)
    {
      new_str[comp] = str2[comp2];
      comp2++;
      comp++;
    }
  new_str[comp] = '\0';
  return new_str;
}

char **std_dochdir(char **argv, char **envp)
{
  char **new_env;
  int pwd;
  
  pwd = find_inenv(envp, "PWD");
  if (argv[1] == NULL)
    return envp;
  else if (argv[1][0] == '.' && argv[1][1] != '.')
    return envp;
  else if (std_strcmp(argv[1], "..") == 0)
    {
      new_env = envp;
      chdir(argv[1]);
      new_env[pwd] = remove_pwd(envp[pwd]);
    }
  else
    {
      if (open(argv[1], O_DIRECTORY) == -1)
	{
	  write (1,"cd: aucun fichier ou dossier de ce type\n",41);
	  return envp;
	}
      new_env = envp;
      chdir(argv[1]);
      new_env[pwd] = add_pwd(envp[pwd], argv[1]);
    }
  free(argv);
  return new_env;
}
