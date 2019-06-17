#include "derived.h"
#include "stdio.h"

///////////////////////////////////////////////////////////////////////////////
//
//                   Specific functions
//
///////////////////////////////////////////////////////////////////////////////


// derived class specific function
static void derived_specific(void *obj) { 
    printf("This is a derived specific func. anumber=%d\n", DERIVED(obj)->anumber); 
}

///////////////////////////////////////////////////////////////////////////////
//
//                   object constructor and destructor
//
///////////////////////////////////////////////////////////////////////////////

static void instance_init(Object *obj) {
    BASE(obj)->greeting = "I am derived";
    DERIVED(obj)->anumber = 10;
}

Derived *Derived_new(void) {
    Object *obj = object_new(TYPE_DERIVED);
    return (Derived *)obj;
}

///////////////////////////////////////////////////////////////////////////////
//
//                   binding and type registration
//
///////////////////////////////////////////////////////////////////////////////

static void class_init(ObjectClass *oc, void *data) {
    DerivedClass *dc = DERIVED_CLASS(oc);
    dc->say = BASE_CLASS(oc)->say;
    dc->derived_specific = derived_specific;
}

static const TypeInfo type_info = {
    .name = TYPE_DERIVED,
    .parent = TYPE_BASE,
    .instance_size = sizeof(Derived),
    .abstract = false,
    .class_size = sizeof(DerivedClass),
    .instance_init = instance_init,
    .class_init = class_init,
};

void Derived_register(void) { type_register_static(&type_info); }
