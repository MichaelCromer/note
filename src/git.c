#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int not_git_repo() 
{
  return system("git rev-parse --is-inside-work-tree > /dev/null 2>&1");
}

char * git_repo_name()
{
  return read_command_stdout("basename $(git rev-parse --show-toplevel 2>/dev/null)");
}

char * git_branch_name()
{
  return read_command_stdout("git branch --show-current 2>/dev/null");
}

char * get_git_repo_name()
{
  if (not_git_repo()) {
    return NULL;
  }

  return git_repo_name();
}

char * get_git_branch_name()
{
  if (not_git_repo()) {
    return NULL;
  }

  return git_branch_name();
}
