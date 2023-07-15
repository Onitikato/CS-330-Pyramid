#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

// Define the 5 corner points of the pyramid:
struct Vertex {
	glm::vec3 v;
	glm::vec2 uv;
};

Vertex vertices[] = {
  {glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
  {glm::vec3(1.0f, -1.0f, 0.0f), glm::vec2(1.0f, 0.0f)},
  {glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.5f, 1.0f)},
  {glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec2(0.0f, 0.0f)},
  {glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.5f, 1.0f)},
};

// Compile and link the shaders:
GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
glCompileShader(vertexShader);

GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
glCompileShader(fragmentShader);

GLuint shaderProgram = glCreateProgram();
glAttachShader(shaderProgram, vertexShader);
glAttachShader(shaderProgram, fragmentShader);

// Set the vertex attribute pointers:
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
glEnableVertexAttribArray(0);
glEnableVertexAttribArray(1);

// Main loop:
while (!glfwWindowShouldClose(window)) {
	// Clear the screen:
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw the pyramid:
	glUseProgram(shaderProgram);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, indices);

	// Swap buffers and poll events:
	glfwSwapBuffers(window);
	glfwPollEvents();
}

// Cleanup:
glfwTerminate();


