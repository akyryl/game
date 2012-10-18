#ifndef __COMMON_RENDER_DATA_H__
#define __COMMON_RENDER_DATA_H__


#include "camera.h"


class CommonRenderData
{
public:
    CommonRenderData();
    ~CommonRenderData();
    static CommonRenderData *getInstance();
    Camera *getCamera() const;
    int getWindowWidth() const;
    int getWindowHeight() const;
    void die();

private:
    static CommonRenderData *m_pInstance;
    Camera* m_pGameCamera;
    int m_windowWidth;
    int m_windowHeight;
};


#endif // __COMMON_RENDER_DATA_H__
