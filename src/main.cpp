/*

	Copyright 2011 Etay Meiri

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Tutorial 16 - Basic Texture Mapping
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include "pipeline.h"
#include "camera.h"
#include "texture.h"

#include "scene.h"

#define WINDOW_WIDTH  1920
#define WINDOW_HEIGHT 1200


Scene *p_scene;

static void RenderSceneCB()
{
    p_scene->renderScene();
}

static void SpecialKeyboardCB(int Key, int x, int y)
{
    p_scene->onSpecialKeyboard(Key, x, y);
}

static void KeyboardCB(unsigned char Key, int x, int y)
{
    p_scene->onKeyboard();

    switch (Key) {
        case 'q':
            glutLeaveMainLoop();
    }
}

static void PassiveMouseCB(int x, int y)
{
    p_scene->onMouse(x, y);
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB);
    glutIdleFunc(RenderSceneCB);
    glutSpecialFunc(SpecialKeyboardCB);
    glutPassiveMotionFunc(PassiveMouseCB);
    glutKeyboardFunc(KeyboardCB);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Game");
    glutGameModeString("1920x1200@32");
    glutEnterGameMode();

    InitializeGlutCallbacks();
    // Must be done after glut is initialized!
    GLenum res = glewInit();
    if (res != GLEW_OK) {
      fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
      exit(1);
    }

    Scene scene;
    p_scene = &scene;

    glutMainLoop();
    return 0;
}
