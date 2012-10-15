#ifndef __CAR_H__
#define __CAR_H__

#include "carRenderObject.h"


class Car
{
    CarRenderObject *m_pDrawingObject;
public:
    Car();
    ~Car();

    CarRenderObject *getDrawingObject() const;
};


#endif // __CAR_H__
