
#include <include.h>

int main() {

  SYSCTL->RCGCGPIO |=(1<<5);
  GPIOF_AHB->DIR |= (1<<0);
  /*Super micros*/

  while (1U){

  }
}
