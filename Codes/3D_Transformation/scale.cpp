#include <cstdlib>
#include <cstdio>
#include <GL/glut.h>
#include <stdlib.h>

int n=3;

float *x = NULL;
float *y = NULL;
float *z = NULL;

float sx=0,sy=0,sz=0;

void fill(float xt,float yt,float zt, int i){
	x[i] = xt;
	y[i] = yt;
	z[i] = zt;
}

void displayTranslated(void){
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
		for(int i=0;i<n;i++){
			glColor3f(rand()%10, rand()%10, rand()%10);
			float tsX = x[i]*sx;
			float tsY = y[i]*sy;
			float tsZ = z[i]*sz;
			glVertex3f(tsX, tsY,tsZ);
		}
		glEnd();
		glFlush ();
		glutSwapBuffers(); 
}

void display(void){
		glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
		for(int i=0;i<n;i++){
			glColor3f(rand()%10, rand()%10, rand()%10);
			glVertex3f(x[i], y[i],z[i]);
		}
		glEnd();
		glFlush ();
		glutSwapBuffers();
}

void init (void){
    glClearColor (0.0, 0.0, 0.0, 0.0);
}

void reshape(int x, int w){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 30.0, 0.0, 35.0, -1.0, 1.0);
}

void mouse(int button, int state, int x, int y){
    x=0; y=0;
    state =0;

    if(button==GLUT_LEFT_BUTTON)
    {	
         displayTranslated();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv); 
    glutInitDisplayMode ( GLUT_DOUBLE|GLUT_DEPTH | GLUT_RGBA); 

    glutInitWindowSize (500, 400); 
    glutInitWindowPosition (100, 100);
    
    x = (float *)calloc(n, sizeof(float));
    y = (float *)calloc(n, sizeof(float));
    z = (float *)calloc(n, sizeof(float));
    
    for (int i=0;i<n;i++){
		printf("Enter the co-ordinate values(x,y) of the %dth vertex: ",i);
		float tempx,tempy,tempz;
		scanf("%f%f%f",&tempx,&tempy,&tempz);
		fill(tempx,tempy,tempz,i);
	}
	
	printf("\n\nCLICK THE LEFT BUTTON TO TRANSLATE\n\n");
	
	printf("Enter the scale factor values(sx,sy,sz): ");
	scanf("%f%f%f",&sx,&sy,&sz);
     
    glutCreateWindow ("Scaling"); 
    init(); 
    glutDisplayFunc(display); 
    glutReshapeFunc(reshape); 
    glutMouseFunc(mouse);
    glutMainLoop();
    free(x);
    free(y);
    free(z);
    return 0;
}
