#ifndef __SCENE_OBJECT_H__
#define __SCENE_OBJECT_H__


#include "carRenderObject.h"


class SceneObject
{
public:
    SceneObject();
    virtual ~SceneObject();

    CarRenderObject getDrawingObject() const;

private:
    CarRenderObject m_renderObject;
};


#endif // __SCENE_OBJECT_H__
