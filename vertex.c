/*
** EPITECH PROJECT, 2025
** oiuy
** File description:
** ouy
*/

#include "vertex.h"
#include <stdio.h>

typedef struct
{
    Class   base;
    int     x, y ,z;
}   VertexClass;

char *affich_Vertex(Object *c)
{
    VertexClass *tmp = (VertexClass *)c;
    char *str = malloc(100 * sizeof(char));
    
    snprintf(str, 100, "<Vertex (%d, %d, %d)>", tmp->x, tmp->y, tmp->z);
    return str;
}

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    (void)this;
}

// Create additional functions here

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = &affich_Vertex,    /* Implement this method for exercice 02 */
        .__add__ = NULL,    /* Implement this method for exercice 03 */
        .__sub__ = NULL,    /* Implement this method for exercice 03 */
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class   *Vertex = (const Class *)&_description;