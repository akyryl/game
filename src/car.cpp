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

void Car::stepLeft()
{
    m_pDrawingObject->stepLeft();
}

void Car::stepRight()
{
    m_pDrawingObject->stepRight();
}
