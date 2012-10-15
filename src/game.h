#include <deque>

#include "car.h"
#include "carRenderObject.h"
#include "track.h"


using namespace std;

typedef deque <RenderObject *> RenderObjectsArr;
typedef deque <RenderObject *>::const_iterator RenderObjectsConstIter;

class Game
{
    Car *m_pMainCar;
    RenderObjectsArr *m_renderObjects;
    Track *m_pTrack;

    void init();
    Car *getNewCar() const;
    Track *getNewTrack() const;


public:
    Game();
    ~Game();

    const RenderObjectsArr *getRenderObjects() const;
    bool onKeyboard(int Key);
};
