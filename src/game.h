#include <deque>

#include "car.h"
#include "carRenderObject.h"


using namespace std;

typedef deque <RenderObject *> RenderObjectsArr;
typedef deque <RenderObject *>::const_iterator RenderObjectsConstIter;

class Game
{
    Car *m_pMainCar;
    RenderObjectsArr *m_renderObjects;

    void init();
    Car *getNewCar() const;

public:
    Game();
    ~Game();

    const RenderObjectsArr *getRenderObjects() const;
    bool onKeyboard(int Key);
};
