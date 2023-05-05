#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Курсовая работа Луговцов КРБО-02-22, Куб", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 700, SDL_WINDOW_OPENGL);
    SDL_GLContext glcontext = SDL_GL_CreateContext(window);
    glEnable(GL_DEPTH_TEST);

    bool rabotaet = true; 
    float angleX = 0.0f;
    float angleY = 0.0f;
    float angleZ = 0.0f;

	float gtr = 1.0f;
    float speedX = 0.0f;
    float speedY = 0.0;
    float speedZ = 0.0f;

    //float color = 0.0f;

    while (rabotaet)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                rabotaet = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                    case SDLK_LEFT:
                        angleY -= gtr;
                        break;
                    case SDLK_RIGHT:
                        angleY += gtr;
                        break;
                    case SDLK_UP:
                        angleX += gtr;
                        break;
                    case SDLK_DOWN:
                        angleX -= gtr;
                        break;
					case SDLK_w:
                        angleZ += gtr;
                        break;
					case SDLK_s:
                        angleZ -= gtr;
                        break;
                    case SDLK_KP_2:
						if (gtr + 1.0f < 10.0f)
						{
							gtr += 1.0f;
						}
                        break;
                    case SDLK_KP_1:
						if (gtr - 1.0f > 0.0f)
						{
							gtr -= 1.0f;
						}
                        break; 
                    case SDLK_r:
                        if (speedX + 0.2f < 2.0f)
                        {
                            speedX += 0.2f;
                        } 
                        break;
                    case SDLK_f:
                        if (speedX - 0.2f >= 0.0f)
                        {
                            speedX -= 0.2f;
                        } 
                        break;
                    case SDLK_t:
                        if (speedY + 0.2f < 2.0f)
                        {
                            speedY += 0.2f;
                        } 
                        break;
                    case SDLK_g:
                        if (speedY - 0.2f >= 0.0f)
                        {
                            speedY -= 0.2f;
                        } 
                        break;
                    case SDLK_y:
                        if (speedZ + 0.2f < 2.0f)
                        {
                            speedZ += 0.2f;
                        } 
                        break;
                    case SDLK_h:
                        if (speedZ - 0.2f >= 0.0f)
                        {
                            speedZ -= 0.2f;
                        } 
                        break;
                    /*case SDLK_c:
                        if (color - 0.1f > 0.0f)
                        {
                            color -= 0.1f;
                        }
                        break;
                    case SDLK_v:
                        if (color + 0.1f <= 1.0f)
                        {
                            color += 0.1f;
                        }
                        break;*/
                }
            }
        }
        angleX += speedX;
        angleY += speedY;
        angleZ += speedZ;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        gluPerspective(45.0, 1.0, 1.0, 100.0); //последний аргумент не должен быть меньше последнего аргумента в glTranslateF
        glTranslatef(0.0, 0.0, -6.0);

        glRotatef(angleX, 1.0f, 0.0f, 0.0f);
        glRotatef(angleY, 0.0f, 1.0f, 0.0f);
        glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

        glBegin(GL_QUADS);

        glColor3f(1.0f, 0.5f, 0.5f); // передняя поверхность
        glVertex3f(  -1.0f,  -1.0f,  1.0f);
        glVertex3f(   1.0f,  -1.0f,  1.0f);
        glVertex3f(   1.0f,   1.0f,  1.0f);
        glVertex3f(  -1.0f,   1.0f,  1.0f);

        glColor3f(0.0f, 0.0f, 1.0f); // задняя поверхность
        glVertex3f(  -1.0f,  -1.0,  -1.0);
        glVertex3f(   1.0f,  -1.0,  -1.0);
        glVertex3f(   1.0f,   1.0,  -1.0);
        glVertex3f(  -1.0f,   1.0,  -1.0);

        glColor3f(0.0f, 1.0f, 0.0f); // левая поверхность
        glVertex3f(  -1.0f,  -1.0,   1.0);
        glVertex3f(  -1.0f,  -1.0,  -1.0);
        glVertex3f(  -1.0f,   1.0,  -1.0);
        glVertex3f(  -1.0f,   1.0,   1.0);

        glColor3f(1.0f, 0.0f, 0.0f); // правая поверхность
        glVertex3f(  1.0f,  -1.0,  -1.0);
        glVertex3f(  1.0f,  -1.0,   1.0);
        glVertex3f(  1.0f,   1.0,   1.0);
        glVertex3f(  1.0f,   1.0,  -1.0);

        glColor3f(0.0f, 0.5f, 0.0f); // верхняя поверхность
        glVertex3f(  -1.0,   1.0,   1.0);
        glVertex3f(   1.0,   1.0,   1.0);
        glVertex3f(   1.0,   1.0,  -1.0);
        glVertex3f(  -1.0,   1.0,  -1.0);

        glColor3f(0.5f, 0.0f, 0.0f); // нижняя поверхность
        glVertex3f(  -1.0,  -1.0,  -1.0);
        glVertex3f(   1.0,  -1.0,  -1.0);
        glVertex3f(   1.0,  -1.0,   1.0);
        glVertex3f(  -1.0,  -1.0,   1.0);

        glEnd();
        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(glcontext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}