#include "game.h"


Game::Game()
{
    init();
}

Game::~Game()
{
    delete m_pMainCar;
    delete m_renderObjects;
}

void Game::init()
{
    m_renderObjects = new RenderObjectsArr();
    createCar();
}

void Game::createCar()
{
    m_pMainCar = new Car();
    m_renderObjects->push_back(m_pMainCar->getDrawingObject());
}

const RenderObjectsArr *Game::getRenderObjects() const
{
    return m_renderObjects;
}
