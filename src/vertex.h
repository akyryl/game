#ifndef __VERTEX_H__
#define __VERTEX_H__


struct Vertex
{
    Vector3f m_pos;
    Vector2f m_tex;

    Vertex() {}

    Vertex(Vector3f pos, Vector2f tex)
    {
        m_pos = pos;
        m_tex = tex;
    }
};


#endif // __VERTEX_H__
