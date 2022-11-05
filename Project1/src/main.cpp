#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/vec3.hpp> // glm::vec3        (x,y,z)
#include <glm/vec4.hpp> // glm::vec4        (x,y,z,w)
#include <glm/mat4x4.hpp> // glm::mat4
// glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Shader/cShaderManager.h"
#include "VAOManager/cVAOManager.h"

#define MODEL_LIST_XML          "asset/model.xml"
#define VERTEX_SHADER_FILE      "src/shader/vertexShader.glsl"
#define FRAGMENT_SHADER_FILE    "src/shader/fragmentShader.glsl"

static const struct
{
    float x, y, z; //hw add z coordiante
    float r, g, b;
} vertices[] =
{
    { -0.6f, -0.4f, 0.0f, 1.f, 0.f, 0.f },
    {  0.6f, -0.4f, 0.0f, 0.f, 1.f, 0.f },
    {   0.f,  0.6f, 0.0f, 0.f, 0.f, 1.f },
                    
    { -0.6f, -0.4f, 1.0f, 0.0f, 1.0f, 0.0f },
    {  0.6f, -0.4f, 1.0f, 0.0f, 0.0f, 1.0f },
    {  0.0f,  0.6f, 1.0f, 1.0f, 0.0f, 0.0f }
};

glm::vec3 g_cameraEye = glm::vec3(0.0, 0.0, -4.0f);
glm::vec3 g_cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);


static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);

    //move camera
    // AWSD AD-Left, Right
    //      WS-Forward, Back
    const float CAMERA_MOVE_SPEED = 0.1f;
    if (key == GLFW_KEY_A)
    {
        ::g_cameraEye.x -= CAMERA_MOVE_SPEED;
    }
    if (key == GLFW_KEY_D)
    {
        ::g_cameraEye.x += CAMERA_MOVE_SPEED;
    }
    if (key == GLFW_KEY_W)
    {
        ::g_cameraEye.z -= CAMERA_MOVE_SPEED;
    }
    if (key == GLFW_KEY_S)
    {
        ::g_cameraEye.z += CAMERA_MOVE_SPEED;
    }
    if (key == GLFW_KEY_Q)
    {
        ::g_cameraEye.y -= CAMERA_MOVE_SPEED;
    }
    if (key == GLFW_KEY_E)
    {
        ::g_cameraEye.y += CAMERA_MOVE_SPEED;
    }
    if (key == GLFW_KEY_SPACE)
    {
        ::g_cameraEye = glm::vec3(0.0f, 0.0f, -4.0f);
    }
}


int main(void)
{
    bool result;
    std::cout << "starting..\n";
    GLFWwindow* window;
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    GLint mvp_location, vpos_location, vcol_location;
    GLuint shaderID = 0;

    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        exit(EXIT_FAILURE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(640, 480, "Simple test example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    std::cout << "created window" << std::endl;

    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSwapInterval(1);

    
    //create shader program
    cShaderManager* pShaderManager = new cShaderManager();
    cShaderManager::cShader vertexShader;
    cShaderManager::cShader fragmentShader;

    vertexShader.fileName = VERTEX_SHADER_FILE;
    fragmentShader.fileName = FRAGMENT_SHADER_FILE;
    result = pShaderManager->createShaderProgram("Shader01", vertexShader, fragmentShader);
    if (!result)
    {
        std::cout << "error: Shader compilation fail" << std::endl;
        return -1;
    }
    else
    {
        std::cout << "shader compilation OK" << std::endl;
    }

    pShaderManager->useShaderPRogram("Shader01");
    shaderID = pShaderManager->getIDfromName("Shader01");
    glUseProgram(shaderID);

    //todo lighting
    
    //load model
    cVAOManager* pVAOManager = new cVAOManager();

    result = pVAOManager->loadModelList(MODEL_LIST_XML, shaderID);
    if (!result)
    {
        return -1;
    }

    ////define model
    //glGenBuffers(1, &vertex_buffer);
    //glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    ////vertex layout
    //mvp_location = glGetUniformLocation(shaderID, "MVP");
    //vpos_location = glGetAttribLocation(shaderID, "vPosition"); //vertex position
    //vcol_location = glGetAttribLocation(shaderID, "vColour");

    //glEnableVertexAttribArray(vpos_location);
    //glVertexAttribPointer(vpos_location,
    //    3,
    //    GL_FLOAT,
    //    GL_FALSE,
    //    sizeof(vertices[0]),
    //    (void*)0);
    //glEnableVertexAttribArray(vcol_location);
    //glVertexAttribPointer(vcol_location,
    //    3,
    //    GL_FLOAT,
    //    GL_FALSE,
    //    sizeof(vertices[0]),
    //    (void*)(sizeof(float) * 3));

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        //mat4x4 m, p, mvp;
        glm::mat4x4 m, p, mvp;

        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        //mat4x4_identity(m);
        m = glm::mat4x4(1.0f); // make an identity matrix
        //mat4x4_rotate_Z(m, m, (float)glfwGetTime());
        //mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        //mat4x4_mul(mvp, p, m);

        //glUseProgram(program);
        //glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*)mvp);
        //glDrawArrays(GL_TRIANGLES, 0, 3);

        //glfwSwapBuffers(window);
        //glfwPollEvents();
        p = glm::perspective(0.6f,
            ratio,
            0.1f,
            1000.0f);

        glm::mat4x4 v = glm::mat4(1.0f);

        //glm::vec3 cameraEye = glm::vec3(0.0, 0.0, -4.0f);
        //glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f);

        v = glm::lookAt(g_cameraEye,
            g_cameraTarget,
            upVector);

        //        mat4x4_mul(mvp, p, m);
        mvp = p * v * m;

       // glUseProgram(program);
        //glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(mvp));
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(window);
        glfwPollEvents();

        //set window title
        //std::stringstream 

    }

    glfwDestroyWindow(window);

    glfwTerminate();
    exit(EXIT_SUCCESS);
}