#include <GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;
float xr=0,yr=0;
float angle=0;
void Menu(int value);

void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
   
glPushMatrix();
    glRotatef(angle,0,0,1);
    glutWireTeapot(0.5+xr);
  glEnd();
glPopMatrix();

  angle+=0.01;
  glFlush();
  glutPostRedisplay();
  glutSwapBuffers();
}

void resize(int w,int h){
    if(w>=h)
        glViewport(0,0,(GLsizei)h,(GLsizei)h);
    else
        glViewport(0,0,(GLsizei)w,(GLsizei)w);
}

void specialkey(int key, int x, int y)
{
    switch(key){
        case GLUT_KEY_UP:
            yr=yr+1;
            glutPostRedisplay();
            break;
        
        case GLUT_KEY_DOWN:
            yr--;
            glutPostRedisplay();
            break;
            
        case GLUT_KEY_LEFT:
            xr--;
            glutPostRedisplay();
            break;
            
        case GLUT_KEY_RIGHT:
            xr++;
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("CG Experiment");
    
    glutReshapeFunc(resize);
    glutSpecialFunc(specialkey);
    
    int sub1=glutCreateMenu(Menu);
    
    glutAddMenuEntry("Red",1);
    glutAddMenuEntry("Green",2);
    glutAddMenuEntry("Yellow",3);
    glutCreateMenu(Menu);
    glutAddSubMenu("Colors",sub1);
    
    glutAddMenuEntry("Exit",4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
  
    glutDisplayFunc(mydisplay);
    
    glutIdleFunc(mydisplay);
    
    glutMainLoop();
}

void Menu(int value)
{
    switch(value)
    {
      case 1:
          glColor4f(1.0,0.0,0.0,0.0);
          break;
          
      case 2:
          glColor4f(0.0,1.0,0.0,0.0);
          break;
          
      case 3:
          glColor4f(1.0,1.0,0.0,0.0);
          break;
          
      case 4:
          exit(0);
          break;
      }
      glutPostRedisplay();
}

