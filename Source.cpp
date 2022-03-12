#include <GL/glut.h>

static int shoulder = 0, elbow = 0, fingerBase = 0, fingerUp = 0;
int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    //Mouse movements
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(-1.0, 0.0, 0.0);

    //Shoulder
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(1.0, 0.0, 0.0);

    //Elbow
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.6, 1.0);
    glutWireCube(1.0);
    glPopMatrix();


    //Draw fingerBase 1
    glPushMatrix();
    glTranslatef(1.0, 0.25, 0.0);
    glRotatef(-(GLfloat)fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, -0.25);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.15);
    glutWireCube(1);
    glPopMatrix();

    //Draw fingerphalange 1 
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef(-(GLfloat)fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.15);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix();

    //Draw fingerBase 2
    glPushMatrix();
    glTranslatef(1.0, 0.25, 0.0);
    glRotatef(-(GLfloat)fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.15);
    glutWireCube(1);
    glPopMatrix();

    //Draw fingerphalange 2
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef(-(GLfloat)fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.15);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix();

    //Draw fingerBase 3
    glPushMatrix();
    glTranslatef(1.0, 0.25, 0.0);
    glRotatef(-(GLfloat)fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.25);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.15);
    glutWireCube(1);
    glPopMatrix();

    //Draw fingerphalange 3
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef(-(GLfloat)fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.15);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix();

    //Draw fingerBase 4 (Thumb)
    glPushMatrix();
    glTranslatef(1.0, -0.25, 0.4);
    glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.15);
    glutWireCube(1);
    glPopMatrix();

    //Draw fingerphalange 4
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.1, 0.15);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        if (shoulder < 90)
            shoulder = (shoulder + 5) % 360;
        glutPostRedisplay();
        break;
    case 'S':
        if (shoulder > -90)
            shoulder = (shoulder - 5) % 360;
        glutPostRedisplay();
        break;
    case 'e':
        if (elbow < 150)
            elbow = (elbow + 5) % 360;
        glutPostRedisplay();
        break;
    case 'E':
        if (elbow > 0)
            elbow = (elbow - 5) % 360;
        glutPostRedisplay();
        break;
    case 'f':
        if (fingerBase < 90)
            fingerBase = (fingerBase + 5) % 360;
        glutPostRedisplay();
        break;
    case 'F':
        if (fingerBase > 0)
            fingerBase = (fingerBase - 5) % 360;
        glutPostRedisplay();
        break;
    case 'p':
        if (fingerUp < 130)
            fingerUp = (fingerUp + 5) % 360;
        glutPostRedisplay();
        break;
    case 'P':
        if (fingerUp > 0)
            fingerUp = (fingerUp - 5) % 360;
        glutPostRedisplay();
        break;

    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving = 0;
        }
    }
    if (button==GLUT_RIGHT_BUTTON)  exit(0);
}


static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Robotic arm 3D group 4");
    init();
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}