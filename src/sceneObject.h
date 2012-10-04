#ifndef __SCENE_OBJECT_H__
#define __SCENE_OBJECT_H__


#include "renderObject.h"


class SceneObject
{
public:
    SceneObject();
    virtual ~SceneObject();

    RenderObject getDrawingObject() const;

private:
    RenderObject m_renderObject;
};


#endif // __SCENE_OBJECT_H__
