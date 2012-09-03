#ifndef __SCENE_OBJECT_H__
#define __SCENE_OBJECT_H__


#include "drawingObject.h"


class SceneObject
{
public:
    SceneObject();
    virtual ~SceneObject();

    DrawingObject getDrawingObject() const;

private:
    DrawingObject m_drawingObject;
};


#endif // __SCENE_OBJECT_H__
