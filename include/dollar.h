#ifndef __DOLLAR_H__
#define __DOLLAR_H__

#include <unistd.h>
#include <stdlib.h>
#include "strlen.h"
#include "strcmp.h"

char *find_afterdollar(char *argv, char **env);

#endif /* __DOLLAR_H__ */
