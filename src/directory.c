#include "directory.h"

#include <stdio.h>

void _direrror(const char* msg, unsigned char device, unsigned char s)
{
 printf("[%d] %s: %d\n",device,msg,s);  
}

unsigned char list_directory(unsigned char device)
{
  unsigned char s;
  
  struct cbm_dirent de;
  
  s=cbm_opendir(1,device);
  if (s) { _direrror("open", device, (int)s); return -1; }
 
  s=cbm_readdir(1,&de);
  if (s) { _direrror("readdir", device, (int)s); return -1; }
  
  while(!(s=cbm_readdir(1,&de)))
  {
    printf("%s\n", de.name);
  }
  
  cbm_k_close(1);
  
  return 0;
}