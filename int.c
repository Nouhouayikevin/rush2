/*
** EPITECH PROJECT, 2025
** oiuy
** File description:
** ouy
*/

#include "new.h"
#include <stdio.h>
#include "int.h"

typedef struct
{
    Class   base;
    int     x;
}   IntClass;

char *affich_Int(Object *c)
{
    IntClass *tmp = (IntClass *)c;
    char *str = malloc(100 * sizeof(char));
    
    snprintf(str, 100, "<Int (%d)>", tmp->x);
    return str;
}

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
    (void)this;
}

Object *add_Int(const Object *this, const Object *other)
{
    IntClass *temp = (IntClass *)this;
    IntClass *temp2 = (IntClass *)other;
    Object *calcul_Int = new(Int, temp->x + temp2->x);
    return calcul_Int;
}

Object *sub_Int(const Object *this, const Object *other)
{
    IntClass *temp = (IntClass *)this;
    IntClass *temp2 = (IntClass *)other;
    Object *calcul_Int = new(Int, temp->x - temp2->x);
    return calcul_Int;
}

Object *mul_Int(const Object *this, const Object *other)
{
    IntClass *temp = (IntClass *)this;
    IntClass *temp2 = (IntClass *)other;
    Object *calcul_Int = new(Int, temp->x * temp2->x);
    return calcul_Int;
}

Object *div_Int(const Object *this, const Object *other)
{
    IntClass *temp = (IntClass *)this;
    IntClass *temp2 = (IntClass *)other;
    Object *calcul_Int = new(Int, temp->x / temp2->x);
    return calcul_Int;
}

Object *eq_Int(const Object *this, const Object *other)
{
    IntClass *temp = (IntClass *)this;
    IntClass *temp2 = (IntClass *)other;
    if (temp->x == temp2->x)
        return true;
    else
        return false;
}

// Create additional functions here

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = &affich_Int,    /* Implement this method for exercice 02 */
        .__add__ = &add_Int,    /* Implement this method for exercice 03 */
        .__sub__ = &sub_Int,    /* Implement this method for exercice 03 */
        .__mul__ = &mul_Int,
        .__div__ = &div_Int,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0
};

const Class   *Int = (const Class *)&_description;
