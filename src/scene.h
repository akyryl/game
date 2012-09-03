#ifndef __SCENE_H__
#define __SCENE_H__


class Scene
{
public:
    Scene();
    ~Scene();

    void renderScene() const;
    void onKeyboard() const;
    void onSpecialKeyboard() const;
    void onMouse(int x, int y) const;
};


#endif // __SCENE_H__
