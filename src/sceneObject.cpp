#include "sceneObject.h"


SceneObject::SceneObject()
{

}

SceneObject::~SceneObject()
{

}

DrawingObject SceneObject::getDrawingObject() const
{
    return m_drawingObject;
}
