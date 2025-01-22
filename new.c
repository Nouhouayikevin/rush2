/*
** EPITECH PROJECT, 2025
** Rush 2
** File description:
** Rush 2
*/

# include "point.h"
# include "vertex.h"
#include "new.h"

Object  *va_new(const Class *class, va_list* ap)
{
    if (class == NULL)
        raise("Class is NULL");
    Object *new_bof = malloc(class->__size__);

    memcpy(new_bof, class, class->__size__);
    if (class->__ctor__ != NULL) {
        class->__ctor__(new_bof, ap);
    }
    return new_bof;
}

Object *new(const Class *class, ...)
{
    if (class == NULL)
        raise("Class is NULL");
    Object *new_bof = malloc(class->__size__);
    va_list list;
    va_start(list, class);

    memcpy(new_bof, class, class->__size__);
    if (class->__ctor__ != NULL) {
        class->__ctor__(new_bof, &list);
    }
    va_end(list);
    return new_bof;
}


void delete(Object *ptr)
{
    Class *c = (Class *) ptr;

    if (c->__dtor__ != NULL) {
        c->__dtor__(c);
    }
    free(c);
}
