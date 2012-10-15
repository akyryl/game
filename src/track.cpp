#include "track.h"


Track::Track()
{
    m_pDrawingObject = new TrackRenderObject();
}

Track::~Track()
{

}

TrackRenderObject *Track::getDrawingObject() const
{
    return m_pDrawingObject;
}
