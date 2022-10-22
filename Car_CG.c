#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#define SENS_ROT	5.0
#define SENS_OBS	10.0
#define SENS_TRANSL	10.0

GLfloat fAspect, angle, obsX, obsY, obsZ, rotX, rotY, obsX_ini, obsY_ini, obsZ_ini;
GLfloat rotX_ini, rotY_ini;
double valor = 0;
GLfloat x_boneco = 0;
GLfloat z_boneco = 0;
GLfloat distance = 4;
GLfloat azimuth = 0;
GLfloat incidence = 0;
GLfloat twist = 0;
int x_ini, y_ini, bot;

//iluminação
void DefineIluminacao (void){
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};	   
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
	GLint especMaterial = 60;
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );
}

void init(){
    glClearColor(0.22, 0.69, 0.87, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
    glMatrixMode( GL_MODELVIEW );
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    angle=60;
    rotX=0;
    rotY=0;
    obsX=10;
    obsY=25;
    obsZ=150;
}

void car(float x, float y, float z){
    glPushMatrix();
    glTranslatef(x/2, 0, 0);
    glScalef(x, y, z);
    glutSolidCube(1);
    glPopMatrix();
}

void keySpecial(int key, int x, int y) {
    switch(key){
        case GLUT_KEY_LEFT:
            valor = valor - 2.0;
            break;
        case GLUT_KEY_RIGHT:
            valor = valor + 2.0;
            break;
    }
     glutPostRedisplay();
}

void myKeyboard(unsigned char c, int x, int y){
    switch(c){
        case 'd': x_boneco += 1; break;
        case 'a': x_boneco -= 1; break;
        case 'w': z_boneco -= 1; break;
        case 's': z_boneco += 1; break;
    }
    glutPostRedisplay();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    DefineIluminacao();

    glPushMatrix(); // inicio chao
	    glTranslatef(0, -500.0, 0);
	    glColor3d(0.13, 0.55, 0.13);
	    glutSolidCube(1000);
	glPopMatrix(); // fim chao

    glPushMatrix();
        glClearColor(0.54, 0.84, 0.84, 1.0);
        glTranslatef(0.0, 0.0, -8.0);
        
        glPushMatrix(); //inicio nuvens 1
            glTranslatef(-37.0,43.0, -300.0);
            glColor3f(0.75,0.75,0.75);
            glutSolidSphere(8,30,30);
            glTranslatef(8.4,5.3,0.0);
            glutSolidSphere(8, 30, 30);
            glTranslatef(-8,0.0,0.0);
            glutSolidSphere(8, 30, 30);
            glTranslatef(-8,0.0,0.0);
            glutSolidSphere(8, 30, 30);
            glTranslatef(-4,-8.0,0.0);
            glutSolidSphere(8, 30, 30);
            glTranslatef(22.5,-0.75,0.0);
            glutSolidSphere(8, 30, 30);
        glPopMatrix(); //fim nuvens 1

        glPushMatrix(); //inicio nuvens 2
            glTranslatef(-85.0, 65.0, -300.0);
            glColor3f(0.75,0.75,0.75);
            glutSolidSphere(8,30,30);
            glTranslatef(8.4,5.3,0.0);
            glutSolidSphere(8, 30, 30);
            glTranslatef(-8,0.0,0.0);
            glutSolidSphere(8, 30, 30);
            glTranslatef(-8,0.0,0.0);
            glutSolidSphere(8, 30, 30);
            glTranslatef(-4,-8.0,0.0);
            glutSolidSphere(8, 30, 30);
            glTranslatef(22.5,-0.75,0.0);
            glutSolidSphere(8, 30, 30);
        glPopMatrix(); //fim nuvens 2

        glPushMatrix(); //inicio nuvens 3
            glTranslatef(-25.0, 80.0, -300.0);
            glColor3f(0.75,0.75,0.75);
            glutSolidSphere(8,30,30);
            glTranslatef(8.4,5.3,0.0);
            glutSolidSphere(8, 30, 30);
            glTranslatef(-8,0.0,0.0);
            glutSolidSphere(8, 30, 30);
            glTranslatef(-8,0.0,0.0);
            glutSolidSphere(8, 30, 30);
            glTranslatef(-4,-8.0,0.0);
            glutSolidSphere(8, 30, 30);
            glTranslatef(22.5,-0.75,0.0);
            glutSolidSphere(8, 30, 30);
        glPopMatrix(); //fim nuvens 3

        
        glPushMatrix(); //inicio personagem com propulsor a jato
            glTranslatef(x_boneco, 10.0, z_boneco);
            glPushMatrix();
                glColor3f(0.13,0.41,0.55);
                glTranslatef(0.0,0.0,0.0);
                glRotatef(90,-1,0,0);
                glutSolidCylinder(3.4, 5.85, 20, 40);
                glColor3f(0.72,0.45,0.20);
                glTranslatef(0.0, 0.0, 8.0);
                glutSolidSphere(3.5, 30, 30);
                glColor3f(0.55,0.47,0.14);
                glTranslatef(0.0, 0.0, 2.0);
                glutSolidCone(2.5, 5, 15, 0);
                
                glColor3f(0.85,0.85,0.10);
                //propulsor 1
                glTranslatef(-2.0, 3.0, -4.0);
                glutSolidTorus(2.3,1.5,10,20);
                //propulsor 2
                glTranslatef(5.0,0.0,0.0);
                glutSolidTorus(2.3,1.5,10,20);
            glPopMatrix();
        glPopMatrix(); //fim personagem com propulsor a jato
        
        glPushMatrix(); // inicio da Arvore
            glTranslatef(50, -0.5, -100); //inicio tronco
            glRotatef(90, -1, 0, 0);
            glColor3d(0.39, 0.26, 0.13);
            glutSolidCylinder(5, 35, 20, 5);// inicio tronco

            glTranslatef(1.0, 1.0, 18.0); //inicio folhas
            glRotatef(0, 1, 0, 0); 
            glColor3d(0, 1, 0);
            glutSolidCone(20, 50, 100, 0); //fim folhas
        glPopMatrix(); // fim da Arvore


        //movimentacao carro
        glTranslatef((GLfloat) valor, 0.0, 0.0);

        glPushMatrix();//inicio carro
            glColor3f(0.81,0.71,0.23);
            glTranslatef(20.0,6.0,16.0);
            car(38.0, 8.0, 18.0); 
            glColor3f(0.85,0.85,0.95);
            glTranslatef(5.5,6.0,0.0);
            car(12.0,12.0,15.0); 
            
            glPushMatrix(); //inicio rodas
                glRotatef((GLfloat) valor,0.0,0.0,0.0);
                glColor3f(0,0,0);
                //Primeira roda
                glTranslatef(-2.0,-9.5, 10.0);
                glutSolidTorus(2.3,0.5,10,20);
                //Segunda roda
                glTranslatef(10.0,0.0,0.0);
                glutSolidTorus(2.3,0.5,10,20);
                //Terceira roda
                glTranslatef(0.0,0.0,-20.0);
                glutSolidTorus(2.3,0.5,10,20);
                //Quarta roda
                glTranslatef(-10.0,0.0,0.0);
                glutSolidTorus(2.3,0.5,10,20);
                //Quinta roda
                glTranslatef(23.0, 0.0, 20.0);
                glutSolidTorus(2.3,0.5,10,20);
                //Sexta roda
                glTranslatef(5.0,0.0,0.0);
                glutSolidTorus(2.3,0.5,10,20);
                //Sétima roda
                glTranslatef(0.0,0.0,-20.0);
                glutSolidTorus(2.3,0.5,10,20);
                //Oitava roda
                glTranslatef(-5.0,0.0,0.0);
                glutSolidTorus(2.3,0.5,10,20);
            glPopMatrix(); //fim rodas

            glPushMatrix(); //inicio sol
                glColor3f(0.9,0.8,0);
                glTranslatef(100.0,60.0,-350.0);
                glutSolidSphere(30,30,30);
            glPopMatrix(); //fim sol

        glPopMatrix(); //fim carro
    glPopMatrix();
    glutSwapBuffers();
}

void PosicionaObservador(void){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	DefineIluminacao();
	glTranslatef(-obsX,-obsY,-obsZ);
	glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
}

void ParametrosVi(void){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(angle,fAspect,0.5,500);
	PosicionaObservador();
}

void myReshape(GLsizei w, GLsizei h){
    if(h==0) h = 1;
    glViewport(0, 0, w, h);
    fAspect = (GLfloat)w/(GLfloat)h;
    ParametrosVi();
}

void mouse(int button, int state, int x, int y){
	if(state==GLUT_DOWN){
		x_ini = x;
		y_ini = y;
		obsX_ini = obsX;
		obsY_ini = obsY;
		obsZ_ini = obsZ;
		rotX_ini = rotX;
		rotY_ini = rotY;
		bot = button;
	}
	else bot = -1;
}

void movimentacao(int x, int y){
	if(bot==GLUT_LEFT_BUTTON){
		int deltax = x_ini - x;
		int deltay = y_ini - y;		
		rotY = rotY_ini - deltax/SENS_ROT;
		rotX = rotX_ini - deltay/SENS_ROT;
	}
	else if(bot==GLUT_RIGHT_BUTTON){
		int deltaz = y_ini - y;
		obsZ = obsZ_ini + deltaz/SENS_OBS;
	}
	else if(bot==GLUT_MIDDLE_BUTTON){
		int deltax = x_ini - x;
		int deltay = y_ini - y;
		obsX = obsX_ini + deltax/SENS_TRANSL;
		obsY = obsY_ini - deltay/SENS_TRANSL;
	}
	PosicionaObservador();
	glutPostRedisplay();
}

int main(int argc, char** argv){
    glutInit(&argc, argv); //inicializa
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //mostra o display como
    glutInitWindowSize(500, 500); //tamanho da janela
    glutInitWindowPosition(100, 100);
    glutCreateWindow("TrabCG");
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    glutSpecialFunc(keySpecial);
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(movimentacao);
    init();
    glutMainLoop();
    return 0;
}