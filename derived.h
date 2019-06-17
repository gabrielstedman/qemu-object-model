#ifndef DERIVED_H_
#define DERIVED_H_

#include "./base.h"

#define TYPE_DERIVED "derived"

void Derived_register(void);

///////////////////////////////////////////////////////////////////////////////
//
//                            class and struct
//
///////////////////////////////////////////////////////////////////////////////

typedef struct Derived {
  Base parent;
  int anumber;
} Derived;

typedef struct {
  BaseClass parent_class;
  void (*say)(void*);
  void (*derived_specific)(void*);
} DerivedClass;

#define DERIVED_GET_CLASS(obj) OBJECT_GET_CLASS(DerivedClass, obj, TYPE_DERIVED)

#define DERIVED_CLASS(klass) \
  OBJECT_CLASS_CHECK(DerivedClass, klass, TYPE_DERIVED)

#define DERIVED(obj) OBJECT_CHECK(Derived, obj, TYPE_DERIVED)

Derived* Derived_new(void);

#endif  // DERIVED_H_
