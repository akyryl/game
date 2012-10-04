#include "sceneObject.h"


SceneObject::SceneObject()
{

}

SceneObject::~SceneObject()
{

}

RenderObject SceneObject::getDrawingObject() const
{
    return m_renderObject;
}
