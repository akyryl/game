#include "car.h"


Car::Car()
{
    m_pDrawingObject = new CarRenderObject();
}

Car::~Car()
{

}

CarRenderObject *Car::getDrawingObject() const
{
    return m_pDrawingObject;
}
