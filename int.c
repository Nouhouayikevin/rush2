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
    Object *calcul_int = NULL;
    
    if (temp2->x == 0)
        raise("Division per zero\n");
    calcul_int = new(Int, temp->x / temp2->x);
    return calcul_int;
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

bool *gt_int(const Object *this, const Object *other)
{
    IntClass *temp = (IntClass *)this;
    IntClass *temp2 = (IntClass *)other;
    return  (temp->x > temp2->x);

}

bool *lt_int(const Object *this, const Object *other)
{
    IntClass *temp = (IntClass *)this;
    IntClass *temp2 = (IntClass *)other;
    return  (temp->x < temp2->x);
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
        .__eq__ = &eq_Int,
        .__gt__ = &gt_int,
        .__lt__ = &lt_int
    },
    .x = 0
};

const Class   *Int = (const Class *)&_description;
