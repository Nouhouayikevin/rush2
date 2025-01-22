/*
** EPITECH PROJECT, 2025
** B-PDG-300-COT-3-1-PDGRUSH2-kevin.nouhouayi [WSL: Ubuntu]
** File description:
** Int
*/

#include "object.h"
#include "float.h"
#include "new.h"

typedef struct
{
    Class   base;
    float     x;
}   FloatClass;

char *affich_float(Object *c)
{
    FloatClass *tmp = (FloatClass *)c;
    char *str = malloc(100 * sizeof(char));
    
    snprintf(str, 100, "<Float (%f)>", tmp->x);
    return str;
}

static void float_ctor(FloatClass *this, va_list *args)
{
    this->x = va_arg(*args, double);
}

static void float_dtor(FloatClass *this)
{
    (void)this;
}

Object *add_float(const Object *this, const Object *other)
{
    FloatClass *temp = (FloatClass *)this;
    FloatClass *temp2 = (FloatClass *)other;
    Object *calcul_float = new(Float, temp->x + temp2->x);
    return calcul_float;
}

Object *mul_float(const Object *this, const Object *other)
{
    FloatClass *temp = (FloatClass *)this;
    FloatClass *temp2 = (FloatClass *)other;
    Object *calcul_float = new(Float, temp->x * temp2->x);
    return calcul_float;
}

Object *div_float(const Object *this, const Object *other)
{
    FloatClass *temp = (FloatClass *)this;
    FloatClass *temp2 = (FloatClass *)other;
    Object *calcul_float = NULL;
    
    if (temp2->x == 0)
        raise("Division per zero\n");
    calcul_float = new(Float, temp->x / temp2->x);
    return calcul_float;
}

Object *sub_float(const Object *this, const Object *other)
{
    FloatClass *temp = (FloatClass *)this;
    FloatClass *temp2 = (FloatClass *)other;
    Object *calcul_float = new(Float, temp->x - temp2->x);
    return calcul_float;
}

bool eq_float(const Object *this, const Object *other)
{
    FloatClass *temp = (FloatClass *)this;
    FloatClass *temp2 = (FloatClass *)other;
    return  (temp->x == temp2->x);
}

bool gt_float(const Object *this, const Object *other)
{
    FloatClass *temp = (FloatClass *)this;
    FloatClass *temp2 = (FloatClass *)other;
    return  (temp->x > temp2->x);

}

bool lt_float(const Object *this, const Object *other)
{
    FloatClass *temp = (FloatClass *)this;
    FloatClass *temp2 = (FloatClass *)other;
    return  (temp->x < temp2->x);
}

// Create additional functions here

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&float_ctor,
        .__dtor__ = (dtor_t)&float_dtor,
        .__str__ = &affich_float,    /* Implement this method for exercice 02 */
        .__add__ = &add_float,    /* Implement this method for exercice 03 */
        .__sub__ = &sub_float,    /* Implement this method for exercice 03 */
        .__mul__ = &mul_float,
        .__div__ = &div_float,
        .__eq__ = &eq_float,
        .__gt__ = &gt_float,
        .__lt__ = &lt_float
    },
    .x = 0,
};

const Class   *Float = (const Class *)&_description;