/* init.c file */

#include "init.h"

#include <GL/glut.h>

void init_opengl()
{
    glShadeModel(GL_SMOOTH);

    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);

    glClearDepth(1.0);

    glEnable(GL_TEXTURE_2D);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glEnable(GL_FOG); // Forrás: https://users.cs.jmu.edu/, James Madison University
    {
        double colorGray[]={0.0, 0.5, 0.5, 0.5};
        glFogi(GL_FOG_MODE, GL_EXP);
        glFogfv(GL_FOG_COLOR, colorGray);
        glFogf(GL_FOG_DENSITY, 0.5);
    }
    glClearColor(0.0, 1.0, 1.0, 1.0);
}