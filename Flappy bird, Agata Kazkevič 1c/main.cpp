#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h>
#include <gl/glut.h>

#define pi (2*acos(0.0))//radianai
#define GLUT_DISABLE_ATEXIT_HACK;//kad isvengti problemø
#define PI 3.1416


GLvoid *font_style = GLUT_BITMAP_HELVETICA_18;
double cameraHeight;
double cameraAngle;
static float clx1 = 280;
static float cly1 = 70;
int drawgrid;
int drawaxes;
int a=0;
double angle;
double incx, incy;
int state,state1,state2,state3;
int tx,ty,tx1=-60,ty1=150,tx2=-60,ty2=-20,tx3,ty3,tx4=-14,ty4=15;
float tx5=150,ty5,tx6=300,ty6,tx7=-90,ty7=0,tx8=-10,ty8=16;
char text[100]="START";
char text2[100]="Enter space to start";
char text1[100]="LET's PLAY THE FLAPPY BIRD";
char text3[100]="Thanks for play!";
char text4[100]="Score: ";
double inc_ang=0.05;
int stop=0;
double score;
char msg[30];
char sc[30]="Score= ";


struct point
{
    double x,y,z;
};

void continuous()
{
    tx+=1;
    tx1-=1;
    tx2+=1;

    if(state ==0 && ty4>10)
    {
        state =1;
    }
    if(state ==1 && ty4<15)
    {
        state =0;
    }
    if(state==1)
        ty4-=3;
    if(state==0)
        ty4+=3;
    if(state1 ==0 && tx5 <-690)
    {
        state1 =1;
    }
    if(state1 ==1 && tx5==155 )
    {
        state1 =0;
    }

    if(state1==0)
        tx5-=0.2;
    if(state1==1)
    {
        tx5=155;
    }

    if(state2 ==0 && tx6 <-250)
    {
        state2 =1;
    }
    if(state2 ==1 && tx6==100 )
    {
        state2 =0;
    }

    if(state2==0)
        tx6-=0.2;
    if(state2==1)
    {
        tx6=100;
    }

    if(state3==0)
    {
        state3=1;
    }

    if(state3==1)
    {
        ty7-=0.05;
    }
    clx1 -= 0.08;
    if(clx1 <= -240)
        clx1 = clx1 + 450;
    glutPostRedisplay();

}
void drawAxes()
{
    if(drawaxes==1)
    {
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
        {
            glVertex3f( 100,0,0);
            glVertex3f(-100,0,0);

            glVertex3f(0,-100,0);
            glVertex3f(0, 100,0);

            glVertex3f(0,0, 100);
            glVertex3f(0,0,-100);
        }
        glEnd();
    }
}

void drawGrid()
{
    int i;
    if(drawgrid==1)
    {
        glColor3f(0.0, 0.0, 1.0);	//pilka
        glBegin(GL_LINES);
        {
            for(i=-8; i<=8; i++)
            {

                if(i==0)
                    continue;

                glVertex3f(i*10, -90, 0);
                glVertex3f(i*10,  90, 0);
                glVertex3f(-90, i*10, 0);
                glVertex3f( 90, i*10, 0);
            }
        }
        glEnd();
    }
}

void drawSquare(double a)
{
    glBegin(GL_QUADS);
    {
        glColor3f(1.0,0.0,0.0);
        glVertex3f( a, a,2);
        glVertex3f( a,-a,2);
        glVertex3f(-a,-a,2);
        glVertex3f(-a, a,2);
    }
    glEnd();
}

void circle(float radius_x, float radius_y)
{
    int i = 0;
    float angle = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++)
    {
        angle = 2 * PI * i / 20;
        glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);//speciali formul
    }

    glEnd();
}

void draw_tail()//uodega
{
    glColor3f(1,1,1);
    int i;
    struct point points[100];
    glColor3f(1.0, 0.5 ,0.0);//oranzine


    for(i=10; i<=25; i++)
    {
        points[i].x=8*cos(((double)i/(double)15)*2*pi);
        points[i].y=5*sin(((double)i/(double)15)*2*pi);
    }

    for(i=10; i<25; i++)
    {
        glBegin(GL_POLYGON);
        {
            glVertex3f(points[i].x,points[i].y,0);
            glVertex3f(points[i+1].x,points[i+1].y,0);
            glVertex3f(points[i+2].x,points[i+2].y,0);
            glVertex3f(points[i+3].x,points[i+3].y,0);
            glVertex3f(points[i+4].x,points[i+4].y,0);
            glVertex3f(points[i+5].x,points[i+5].y,0);
            glVertex3f(points[i+6].x,points[i+6].y,0);
            glVertex3f(points[i+7].x,points[i+7].y,0);
            glVertex3f(points[i+8].x,points[i+8].y,0);
            glVertex3f(points[i+9].x,points[i+9].y,0);
            glVertex3f(points[i+10].x,points[i+10].y,0);
            glVertex3f(points[i+11].x,points[i+11].y,0);
        }
        glEnd();


    }

}

void circle1()//akys
{
    int i;
    struct point points[100];
    glColor3f(1.0, 1.0, 1.0);//balta
    //generate points
    for(i=10; i<=25; i++)
    {
        points[i].x=4*cos(((double)i/(double)15)*2*pi);
        points[i].y=6*sin(((double)i/(double)15)*2*pi);
    }
    for(i=10; i<25; i++)
    {
        glBegin(GL_POLYGON);
        {
            glVertex3f(points[i].x,points[i].y,0);
            glVertex3f(points[i+1].x,points[i+1].y,0);
            glVertex3f(points[i+2].x,points[i+2].y,0);
            glVertex3f(points[i+3].x,points[i+3].y,0);
            glVertex3f(points[i+4].x,points[i+4].y,0);
            glVertex3f(points[i+5].x,points[i+5].y,0);
            glVertex3f(points[i+6].x,points[i+6].y,0);
            glVertex3f(points[i+7].x,points[i+7].y,0);
            glVertex3f(points[i+8].x,points[i+8].y,0);
            glVertex3f(points[i+9].x,points[i+9].y,0);
            glVertex3f(points[i+10].x,points[i+10].y,0);
            glVertex3f(points[i+11].x,points[i+11].y,0);
        }
        glEnd();
    }
}

void circle2()
{
    int i;
    struct point points[100];
    glColor3f(0.0, 0.0, 1.0);//melyna
    for(i=10; i<=25; i++)
    {
        points[i].x=2*cos(((double)i/(double)15)*2*pi);
        points[i].y=3*sin(((double)i/(double)15)*2*pi);
    }

    for(i=10; i<25; i++)
    {
        glBegin(GL_POLYGON);
        {
            glVertex3f(points[i].x,points[i].y,0);
            glVertex3f(points[i+1].x,points[i+1].y,0);
            glVertex3f(points[i+2].x,points[i+2].y,0);
            glVertex3f(points[i+3].x,points[i+3].y,0);
            glVertex3f(points[i+4].x,points[i+4].y,0);
            glVertex3f(points[i+5].x,points[i+5].y,0);
            glVertex3f(points[i+6].x,points[i+6].y,0);
            glVertex3f(points[i+7].x,points[i+7].y,0);
            glVertex3f(points[i+8].x,points[i+8].y,0);
            glVertex3f(points[i+9].x,points[i+9].y,0);
            glVertex3f(points[i+10].x,points[i+10].y,0);
            glVertex3f(points[i+11].x,points[i+11].y,0);
        }
        glEnd();
    }
}

void drawCircle(double radius,int segments)//kunas
{
    int i;
    struct point points[100];
    glColor3f(1.0, 1.0, 0.0);//geltona

    for(i=0; i<=segments; i++)
    {
        points[i].x=11*cos(((double)i/(double)segments)*2*pi);
        points[i].y=radius*sin(((double)i/(double)segments)*2*pi);
    }
    for(i=0; i<segments; i++)
    {
        glBegin(GL_POLYGON);
        {

            glVertex3f(points[i].x,points[i].y,0);
            glVertex3f(points[i+1].x,points[i+1].y,0);
            glVertex3f(points[i+2].x,points[i+2].y,0);
            glVertex3f(points[i+3].x,points[i+3].y,0);
            glVertex3f(points[i+4].x,points[i+4].y,0);
            glVertex3f(points[i+5].x,points[i+5].y,0);
            glVertex3f(points[i+6].x,points[i+6].y,0);
            glVertex3f(points[i+7].x,points[i+7].y,0);
            glVertex3f(points[i+8].x,points[i+8].y,0);
            glVertex3f(points[i+9].x,points[i+9].y,0);
            glVertex3f(points[i+10].x,points[i+10].y,0);
            glVertex3f(points[i+11].x,points[i+11].y,0);
        }
        glEnd();
    }
}

void draw_rec()
{
    glColor3f(0,1,0);
    drawSquare(10);
}

void obstacle1()
{

    glPushMatrix();
    glColor3f(0.0 ,1.0 ,1.0);
    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,155);
        glVertex2f(115,155);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,20);
        glVertex2f(120,20);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(-20,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-20);
        glVertex2f(120,-20);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(60,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-60);
        glVertex2f(120,-60);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(80,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,150);
        glVertex2f(115,150);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,50);
        glVertex2f(120,50);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

    glPopMatrix();
}

void obstacle2()
{

    glPushMatrix();
    glTranslatef(360,3,0);
  glColor3f(0.0 ,1.0, 1.0);
    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,155);
        glVertex2f(115,155);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,20);
        glVertex2f(120,20);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(170,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-20);
        glVertex2f(120,-20);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(300,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-60);
        glVertex2f(120,-60);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(280,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,150);
        glVertex2f(115,150);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,50);
        glVertex2f(120,50);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();


    glPopMatrix();



}
void obstacle3()
{

    glPushMatrix();
    glTranslatef(440,3,0);
   glColor3f(0.0 ,1.0, 1.0);
    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,155);
        glVertex2f(115,155);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,20);
        glVertex2f(120,20);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(340,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-20);
        glVertex2f(120,-20);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();
    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(490,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-60);
        glVertex2f(120,-60);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(210,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,150);
        glVertex2f(115,150);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,50);
        glVertex2f(120,50);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();
    glPopMatrix();

}
void obstacle4()
{
    glPushMatrix();
    glColor3f(0.0 ,1.0, 1.0);
    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,155);
        glVertex2f(115,155);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,20);
        glVertex2f(120,20);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();



    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-20);
        glVertex2f(120,-20);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();
    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(60,-2,0);

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,-60);
        glVertex2f(120,-60);
        glVertex2f(120,-165);
        glVertex2f(100,-165);

    }
    glEnd();
    glPopMatrix();
    glPushMatrix();

    glBegin(GL_QUADS);
    {
        glVertex2f(85,-155);
        glVertex2f(115,-155);
        glVertex2f(115,-165);
        glVertex2f(85,-165);

    }
    glEnd();

    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(80,3,0);

    glPushMatrix();
    glTranslatef(0,3,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(85,150);
        glVertex2f(115,150);
        glVertex2f(115,165);
        glVertex2f(85,165);

    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,2,0);
    glBegin(GL_QUADS);
    {
        glVertex2f(100,50);
        glVertex2f(120,50);
        glVertex2f(120,165);
        glVertex2f(100,165);

    }
    glEnd();
    glPopMatrix();


    glPopMatrix();


}
void drawSS()//???
{
    glColor3f(1,0,0);
    drawSquare(20);
    glPushMatrix();

    glTranslatef(110,0,0);

    glColor3f(0,1,0);
    drawSquare(15);

    glPushMatrix();
    {

        glTranslatef(60,0,0);
        glColor3f(0,0,1);
        drawSquare(10);
    }
    glPopMatrix();

}
void lip()
{
    glBegin(GL_TRIANGLES);
    {
        glColor3f(1,0,0);
        glVertex3f(-1,16,0);
        glVertex3f(6,16,0);
        glVertex3f(-1,9,0);

    }
    glEnd();

    glBegin(GL_TRIANGLES);
    {
        glColor3f(1,0,0);
        glVertex3f(0,28,0);
        glVertex3f(8,17,0);
        glVertex3f(0,17,0);

    }
    glEnd();

}


void draw_bird_body()
{

    glPushMatrix();
    glTranslatef(tx3,ty3,0);

    glPushMatrix();
    glPushMatrix();
    glTranslatef(tx4,ty4,0);
    glRotatef(-290,10,30,0);
    draw_tail();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,0);
    glTranslatef(-4,25,0);
    circle2();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1,1);
    glTranslatef(-4,25,0);
    circle1();
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,0,0);
    glTranslatef(-10,20,0);
    drawCircle(15,20);
    glPopMatrix();
    glPushMatrix();
    lip();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-24,22,0);

    glRotatef(180,10,30,0);
    draw_tail();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-22,15,0);
    glRotatef(2*190,10,30,0);
    draw_tail();
    glPopMatrix();

    glPopMatrix();

}

void keyboardListener(unsigned char key, int x,int y)
{
    switch(key)
    {

    case 32:

        glutIdleFunc(continuous);

        break;

    default:
        break;
    }
}


void specialKeyListener(int key, int x,int y)
{
    switch(key)
    {
    case GLUT_KEY_DOWN:

        ty7-=5;

        cameraHeight -= 3.0;
        break;
    case GLUT_KEY_UP:
        ty7+=5;
        cameraHeight += 3.0;

        break;

    case GLUT_KEY_RIGHT:
        tx3+=5;
        break;

    case GLUT_KEY_LEFT:
        tx3-=5;
        cameraAngle -= 0.03;
        break;

    case GLUT_KEY_PAGE_UP:
        break;
    case GLUT_KEY_PAGE_DOWN:
        break;

    case GLUT_KEY_INSERT:
        break;

    case GLUT_KEY_HOME:
        break;
    case GLUT_KEY_END:
        break;
    case 32:
        glutIdleFunc(continuous);
        break;

    default:
        break;
    }
}


void mouseListener(int button, int state, int x, int y)
{
    switch(button)
    {
    case GLUT_LEFT_BUTTON:
        if(state == GLUT_DOWN)
        {
            drawaxes=1-drawaxes;
        }
        break;

    case GLUT_RIGHT_BUTTON:
        break;

    case GLUT_MIDDLE_BUTTON:

        break;

    default:
        break;
    }
}

void draw_text1(const char *text,int length,int x,int y)
{
    glMatrixMode(GL_PROJECTION);
    double *matrix=new double[16];
    glGetDoublev(GL_PROJECTION_MATRIX,matrix);
    glLoadIdentity();
    glOrtho(-400,500,-200,300,-5,5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x,y);
    for(int i=0; text[i]!='\0'; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,(int)text[i]);

    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(matrix);
    glMatrixMode(GL_MODELVIEW);

}

void coliision()//teksto spalva
{

    glPushMatrix();

    glColor3f(1.0 ,0.0, 1.0);
    draw_text1(text3,100,-20,80);
    glPopMatrix();
    glPushMatrix();
     glColor3f(1.0 ,0.0, 1.0);
    draw_text1(sc,100,-20,60);
    draw_text1(msg,100,35,60);
    glPopMatrix();


    glPushMatrix();//lapo spalva
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-175,180);
    glVertex2f(-175,-180);
    glVertex2f(175,-180);
    glVertex2f(175,180);
    glEnd();
    glPopMatrix();

}


void firstpage()

{
    int num = 10;
    itoa(score,msg,10);

    if(stop==1)
    {

        return coliision();
    }


    if(ty7>=-10&&(tx5<=-173&&tx5>=-200))
    {
        stop=1;
    }
    if(ty7<=-25&&(tx5<=-151&&tx5>=-176))
    {
        stop=1;
    }
    if(ty7<=-63&&(tx5<=-230&&tx5>=-254))
    {
        stop=1;
    }
    if(ty7>=10&&(tx5<=-250&&tx5>=-274))
    {
        stop=1;
    }
    if(ty7<=-25&&(tx5<=-338&&tx5>=-374))
    {
        stop=1;
    }
    if(ty7>=20&&(tx5<=-382&&tx5>=-400))
    {
        stop=1;
    }
    if(ty7<=-65&&(tx5<=-472&&tx5>=-488))
    {
        stop=1;
    }
    if(ty7<=-20&&(tx5<=-512&&tx5>=-532))
    {
        stop=1;
    }
    if(ty7<=-65&&(tx5<=-660&&tx5>=-680))
    {
        stop=1;
    }
    if(ty7>=-6&&(tx5<=-529&&tx5>=-540))
    {
        stop=1;
    }
    if(ty7>=-13&&(tx5<=-611&&tx5>=-628))
    {
        stop=1;
    }
    if(ty7>=-20&&(tx5<=-380&&tx5>=-400))
    {
        //stop=1;
    }
    if(ty7>=-10&&(tx5<=-450&&tx5>=-470))
    {
        stop=1;
    }


    glPushMatrix();

    glPushMatrix();
    glTranslatef(tx7,ty7,0);
    draw_bird_body();
    glPopMatrix();

    glColor3f(1,1,0);
    draw_text1(msg,100,-320,250);
    draw_text1(sc,100,-380,250);

    glPushMatrix();
    glColor3f(1,1,0);
    draw_text1(text2,100,tx2,ty2);
    glPopMatrix();
    glPushMatrix();

    glColor3f(1,1,0);
    draw_text1(text1,100,tx1,ty1);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1,1,0);
    draw_text1(text,100,tx,ty);
    glPopMatrix();


    glPopMatrix();
    glPushMatrix();
    score=score+.1;
    glTranslatef(tx5,ty5,0);
    obstacle1();
    obstacle2();
    obstacle3();
    glPopMatrix();
    glPushMatrix(); //clouds
    glTranslated(clx1,cly1,0);
    glColor3d(0.0, 0.0, 1.0);
    glTranslated(0,70,0);
    circle(5,10);
    glTranslated(5,4,0);
    circle(5,10);
    glTranslated(5,-4,0);
    circle(5,10);
    glTranslated(-5,-4,0);
    circle(5,10);

    glTranslated(30,0,0);
    circle(10,10);
    glTranslated(5,4,0);
    circle(5,10);
    glTranslated(5,-4,0);
    circle(10,10);
    glTranslated(-5,-4,0);
    circle(5,10);

    glTranslated(-100,10,0);
    circle(8,10);
    glTranslated(-5,4,0);
    circle(5,10);
    glTranslated(0,-8,0);
    circle(5,10);
    glTranslated(-5,4,0);
    circle(8,10);
    glPopMatrix();

    glEnd();
}
void display()
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.52940,0.80780,0.9800,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0,0,200,	0,0,0,	0,1,0);
    glMatrixMode(GL_MODELVIEW);
    firstpage();
    glutSwapBuffers();
}



void init()
{
    drawgrid=0;
    drawaxes=1;
    cameraHeight=150.0;
    cameraAngle=1.0;
    angle=45;
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80,	1,	1,	1000.0);

}


int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(-500, 0);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Flappy bird");
    init();
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardListener);
    glutSpecialFunc(specialKeyListener);
    glutMouseFunc(mouseListener);



    glutMainLoop();

    return 0;
}
