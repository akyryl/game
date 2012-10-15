#ifndef __TRACK_H__
#define __TRACK_H__


#include "trackRenderObject.h"


class Track
{
    TrackRenderObject *m_pDrawingObject;
public:
    Track();
    ~Track();

    TrackRenderObject *getDrawingObject() const;
};


#endif // __TRACK_H__
