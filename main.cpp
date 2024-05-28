#include <GLFW/glfw3.h>
#include <iostream>

int main(int, char) {

    GLFWwindow* window;

    if (!glfwInit()) {
        return -1;
    }

    window = glfwCreateWindow(500, 500, "Window!", NULL, NULL);

    glfwMakeContextCurrent(window);

    while(!glfwWindowShouldClose(window)) {

        glfwPollEvents();

        glfwSwapBuffers(window);
    }

    glfwTerminate;

}