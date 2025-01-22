/*
** EPITECH PROJECT, 2025
** oiuy
** File description:
** ouy
*/

#include "char.h"
#include <stdio.h>
#include "new.h"

typedef struct
{
    Class base;
    char x;
}   CharClass;

char *affich_Char(Object *c)
{
    CharClass *tmp = (CharClass *)c;
    char *str = malloc(100 * sizeof(char));
    
    snprintf(str, 100, "<Char (%d)>", tmp->x);
    return str;
}

static void Char_ctor(CharClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    (void)this;
}

Object *add_Char(const Object *this, const Object *other)
{
    CharClass *temp = (CharClass *)this;
    CharClass *temp2 = (CharClass *)other;
    Object *calcul_Char = new(Char, temp->x + temp2->x);
    return calcul_Char;
}

Object *sub_Char(const Object *this, const Object *other)
{
    CharClass *temp = (CharClass *)this;
    CharClass *temp2 = (CharClass *)other;
    Object *calcul_Char = new(Char, temp->x - temp2->x);
    return calcul_Char;
}

Object *div_Char(const Object *this, const Object *other)
{
    CharClass *temp = (CharClass *)this;
    CharClass *temp2 = (CharClass *)other;
    Object *calcul_char = NULL;
    
    if (temp2->x == 0)
        raise("Division per zero\n");
    calcul_char = new(Char, temp->x / temp2->x);
    return calcul_char;
}

Object *mul_Char(const Object *this, const Object *other)
{
    CharClass *temp = (CharClass *)this;
    CharClass *temp2 = (CharClass *)other;
    Object *calcul_Char = new(Char, temp->x * temp2->x);
    return calcul_Char;
}

bool eq_Char(const Object *this, const Object *other)
{
    CharClass *temp = (CharClass *)this;
    CharClass *temp2 = (CharClass *)other;
    if (temp->x == temp2->x)
        return true;
    return false;
}

bool lt_Char(const Object *this, const Object *other)
{
    CharClass *temp = (CharClass *)this;
    CharClass *temp2 = (CharClass *)other;
    return  (temp->x < temp2->x);
}

bool gt_Char(const Object *this, const Object *other)
{
    CharClass *temp = (CharClass *)this;
    CharClass *temp2 = (CharClass *)other;
    return  (temp->x > temp2->x);
}

// Create additional functions here

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = &affich_Char,    /* Implement this method for exercice 02 */
        .__add__ = &add_Char,    /* Implement this method for exercice 03 */
        .__sub__ = &sub_Char,    /* Implement this method for exercice 03 */
        .__mul__ = &mul_Char,
        .__div__ = &div_Char,
        .__eq__ = &eq_Char,
        .__gt__ = &gt_Char,
        .__lt__ = &lt_Char
    },
    .x = 0
};

const Class   *Char = (const Class *)&_description;