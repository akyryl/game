#include "sceneObject.h"


SceneObject::SceneObject()
{

}

SceneObject::~SceneObject()
{

}

CarRenderObject SceneObject::getDrawingObject() const
{
    return m_renderObject;
}
