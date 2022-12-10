/**
 * @file main.cpp
 * @author Brooke Kindleman (brooke.kindleman@gmail.com) @brooke-k
 * @date 19/Jul/2022
 *
 */

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include "./classes/include/equines/equid.hpp"
#ifndef PRINTFORM
#define PRINTFORM
#include "./classes/include/utilities/printForm.hpp"
#endif // PRINTFORM

using namespace std;

void startUpMessages();

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void checkInputs(GLFWwindow *window);

void checkInputs(GLFWwindow *window)
{
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
  {
    glfwSetWindowShouldClose(window, true);
  }
}

int main(void)
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
  if (window == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glViewport(0, 0, 800, 600);

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  startUpMessages();
  // bitset<32> manusetA(0);
  // bitset<32> manusetB(0);
  // manusetA[1] = 1;
  // manusetB[1] = 1;
  // manusetB[0] = 1;
  // // manusetB[14] = 1;
  // // manusetB[18] = 1;
  // srand(time(NULL));
  // // unsigned long int randVal = rand();

  // Coat cA(manusetA.to_ulong());
  // Coat cB(manusetB.to_ulong());
  // // testBase.minPrint();
  // cA.fullPrint();
  // cB.fullPrint();

  Equid EEE("Cabbage", "Garden Friend", chestnut ^ sabino, 'G', 15.3, 9);

  while (!glfwWindowShouldClose(window))
  {

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    checkInputs(window);
    glfwPollEvents();
    glfwSwapBuffers(window);
    // EEE.createCustomEquid();
  }
  glfwTerminate();
  return 0;
}

void startUpMessages()
{
  printTopBorder();
  printFormLine("UNNAMED HORSE GAME", "", 1);
  printFormLine("Welcome!", "", 2);
  printBottomBorder();
  return;
}