#include "commonRenderData.h"


CommonRenderData *CommonRenderData::m_pInstance;

CommonRenderData::CommonRenderData()
    : m_pGameCamera(NULL)
    , m_windowWidth(1920)
    , m_windowHeight(1200)
{
    m_pGameCamera = new Camera(m_windowWidth, m_windowHeight);
}

CommonRenderData::~CommonRenderData()
{
    delete m_pGameCamera;
}

void CommonRenderData::die()
{
    delete m_pInstance;
}

CommonRenderData *CommonRenderData::getInstance()
{
    if (m_pInstance == 0) {
        m_pInstance = new CommonRenderData();
    }
    return m_pInstance;
}

Camera *CommonRenderData::getCamera() const
{
    return m_pGameCamera;
}

int CommonRenderData::getWindowWidth() const
{
    return m_windowWidth;
}

int CommonRenderData::getWindowHeight() const
{
    return m_windowHeight;
}
