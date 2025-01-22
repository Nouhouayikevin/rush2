/*
** EPITECH PROJECT, 2025
** Rush 2
** File description:
** Rush 2
*/

#include "new.h"
Object *new(const Class *class, ...)
{
    va_list list;
    va_start(list, class);
    Object *new_bof = malloc(sizeof(class->__size__));

    memcpy(new_bof, class, class->__size__);
    if (class->__ctor__ != NULL) {
        class->__ctor__(new_bof, &list);
    }
    va_end(list);
    return new_bof;
}
