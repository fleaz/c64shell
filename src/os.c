#include <stdio.h>

#include "os.h"

int os_getcpu(void)
{
  unsigned char cpu=getcpu();
  
  printf("CPU: ");
  
  switch(cpu)
  {
    case CPU_6502:
      printf("6502\n");
      return 0;
    case CPU_65C02:
      printf("65C02\n");
      return 0;
    case CPU_65816:
      printf("65816\n");
      return 0;
    default:
      printf("unknown\n");
      return 0;
  }
}