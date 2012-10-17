#include "game.h"

#include <GL/freeglut.h>
#include "textureFactory.h"


Game::Game()
{
    init();
}

Game::~Game()
{
    delete m_pMainCar;
    delete m_renderObjects;
    delete m_pTrack;
    TextureFactory::die();
}

void Game::init()
{
    m_renderObjects = new RenderObjectsArr();
    m_pMainCar = getNewCar();
    m_pTrack = getNewTrack();
}

Car *Game::getNewCar() const
{
    Car *pCar = new Car();
    m_renderObjects->push_back(pCar->getDrawingObject());
    return pCar;
}

Track *Game::getNewTrack() const
{
    Track *pTrack = new Track();
    m_renderObjects->push_back(pTrack->getDrawingObject());
    return pTrack;
}

const RenderObjectsArr *Game::getRenderObjects() const
{
    return m_renderObjects;
}

bool Game::onKeyboard(int Key)
{
    bool Ret = false;
    switch (Key) {
    case GLUT_KEY_LEFT:
        {
            // TODO: update main car pos
            Ret = true;
        }
        break;
    case GLUT_KEY_RIGHT:
        {
            // TODO: update main car pos
            Ret = true;
        }
        break;
    default:
        break;
    }
}
