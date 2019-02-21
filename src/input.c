#include "input.h"

struct input_implement *impl;

void input_init()
{
  /* Currently support input is only plantuml */
  int ret = layer_plant_attach(impl);
  
  if (ret == RET_OK)
    impl->layer_init();
}
