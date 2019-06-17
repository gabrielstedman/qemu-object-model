#include <stdio.h>
#include "derived.h"

// used in error.c
Error *error_fatal;
Error *error_abort;
int errno;

int main() {
  object_type_register();
  Base_register();
  Derived_register();

  Derived *obj = Derived_new();
  DERIVED_GET_CLASS(obj)->say(obj);
  DERIVED_GET_CLASS(obj)->derived_specific(obj);
  return 0;
}
