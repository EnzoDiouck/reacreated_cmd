#include "dollar.h"

char *find_afterdollar(char *argv, char **env)
{
  char *str;
  int comp;
  int comp2;
  int found;

  comp = 0;
  comp2 = 0;
  found = 0;
  str = malloc(sizeof(char) * 256);
  while(argv[comp] != 0)
    {
      if (argv[comp] == '$')
        {
          comp++;
          while(argv[comp] != 0 && argv[comp] != '=')
            {
              str[comp2] = argv[comp];
              comp++;
              comp2++;
            }
        }
      if (argv[comp] != 0)
        comp++;
    }
  str[comp2] = '\0';
  comp = 0;
  while(env[comp] != NULL)
    {
      if (std_strcmp(str, env[comp]) == 0)
        found = comp;
      comp++;
    }
  if (found == 0)
    {
      write(1,"error\n", 7);
      return str;
    }
  comp2 = std_strlen(str) + 1;
  comp = 0;
  free(str);
  str = malloc(sizeof(char) * std_strlen(env[found]) + 1);
  while(env[found][comp2] != 0)
    {
      str[comp] = env[found][comp2];
      comp++;
      comp2++;
    }
  str[comp] = '\0';
  return str;
}
