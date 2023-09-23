#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include<iostream>

extern "C" {
    _declspec(dllexport) unsigned long NvOptimusEnablement = 0x00000001;   //   Intel
    //__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;  //   AMD
}

int g_windowSizeX = 640;
int g_windowSizeY = 480;

void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height)
{
    g_windowSizeX = width;
    g_windowSizeY = height;
    glViewport(0, 0, g_windowSizeX, g_windowSizeY);
}

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}


//void character_callback(GLFWwindow* window, unsigned int codepoint)
//{
//    std::cout << (char)codepoint<<std::endl;
//}

int main(void)
{

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow*  pwindow = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "test", nullptr, nullptr);
    if (!pwindow)
    {
        std::cout << "glfwCreateWindow failed"<< std::endl;
        glfwTerminate();
        return -1;
    }

    /*  callbacks   */
    glfwSetWindowSizeCallback(pwindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pwindow, glfwKeyCallback);
    //glfwSetCharCallback(pwindow, character_callback);

    /* Make the window's context current */
    glfwMakeContextCurrent(pwindow);
    

    if (!gladLoadGL())
    {
    	std::cout<<"Can't load GLAD!"<<std::endl;
	return -1;
    }
    
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

    glClearColor(1, 1, 0, 1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pwindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pwindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}