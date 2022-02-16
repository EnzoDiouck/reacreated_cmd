#ifndef __DOCMD_H__
#define __DOCMD_H__

#include <wait.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include "fusion.h"
#include "strcmp.h"
#include "dollar.h"

int find_inenv(char **env, char *tofind);

void std_docmd(char **pathname, char **argv, char **envp, char *str);

void std_dopathcmd(char *pathname, char **argv, char **envp);

char **std_dochdir(char **argv, char **envp);

#endif /*  __DOCMD_H__ */
