#include "carRenderObject.h"


class Car
{
    CarRenderObject *m_pDrawingObject;
public:
    Car();
    ~Car();

    CarRenderObject *getDrawingObject() const;
};
