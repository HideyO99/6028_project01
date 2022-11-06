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
#include "MeshObj/cMeshObj.h"

#define MODEL_LIST_XML          "asset/model.xml"
#define VERTEX_SHADER_FILE      "src/shader/vertexShader.glsl"
#define FRAGMENT_SHADER_FILE    "src/shader/fragmentShader.glsl"

//glm::vec3 g_cameraEye = glm::vec3(0.0, 100.0, -300.0f);
glm::vec3 g_cameraEye = glm::vec3(0.0, 100.0, 300.0f);
glm::vec3 g_cameraTarget = glm::vec3(5.0f, 0.0f, 0.0f);


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
    const float CAMERA_MOVE_SPEED = 1.f;
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
        //::g_cameraEye = glm::vec3(-5.5f, -3.4f, 15.0f);
        ::g_cameraEye = glm::vec3(0.0, 100.0, 300.0f);
        //::g_cameraTarget = glm::vec3(5.0f, 0.0f, 0.0f);
    }
}


int main(void)
{
    bool result;
    std::cout << "starting..\n";
    GLFWwindow* window;
    GLuint vertex_buffer, vertex_shader, fragment_shader, program;
    //GLint mvp_location, vpos_location, vcol_location;
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

        glfwDestroyWindow(window);

        delete pShaderManager;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    else
    {
        std::cout << "shader compilation OK" << std::endl;
    }

    pShaderManager->useShaderPRogram("Shader01");
    shaderID = pShaderManager->getIDfromName("Shader01");
    //glUseProgram(shaderID);

    //todo lighting
    
    //load model
    cVAOManager* pVAOManager = new cVAOManager();

    result = pVAOManager->loadModelList(MODEL_LIST_XML, shaderID);
    if (!result)
    {
        std::cout << "cannot load model list" << std::endl;

        glfwDestroyWindow(window);

        delete pVAOManager;
        delete pShaderManager;

        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    cMeshObj* pTerrain = new cMeshObj();
    pTerrain->meshName = "terrain";
    pTerrain->position = glm::vec3(0.0f, 0.0f, 0.0f);
    pTerrain->isWireframe = false;
    pTerrain->isVisible = true;
    pTerrain->scale = 0.5f;
    pTerrain->color_RGBA = glm::vec4(187.0f, 195.0f, 41.0f, 255);

    std::vector< cMeshObj* > vec_pMeshObjects;

    vec_pMeshObjects.push_back(pTerrain);



    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glm::mat4x4 matModel;
        glm::mat4x4 matProjection;
        glm::mat4x4 matView;

        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float)height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::vec3 upVector = glm::vec3(0.0f, 1.0f, 0.0f);

        matView = glm::lookAt(::g_cameraEye, ::g_cameraTarget, upVector);

        matProjection = glm::perspective( 0.6f, ratio, 0.1f, 10000.0f);

        for (std::vector< cMeshObj* >::iterator itCurrentMesh = vec_pMeshObjects.begin();
            itCurrentMesh != vec_pMeshObjects.end();
            itCurrentMesh++)
        {
            cMeshObj* pCurrentMeshObject = *itCurrentMesh;        // * is the iterator access thing

            if (!pCurrentMeshObject->isVisible)
            {
                // Skip the rest of the loop
                continue;
            }

            // 
                    // Don't draw any "back facing" triangles
            glCullFace(GL_BACK);

            // Turn on depth buffer test at draw time
            glEnable(GL_DEPTH_TEST);

            matModel = glm::mat4x4(1.0f);  // identity matrix

            // Move the object 
            glm::mat4 matTranslation = glm::translate(glm::mat4(1.0f),
                pCurrentMeshObject->position);


            // Scale the object
            float uniformScale = pCurrentMeshObject->scale;
            glm::mat4 matScale = glm::scale(glm::mat4(1.0f),
                glm::vec3(uniformScale, uniformScale, uniformScale));

            matModel = matModel * matTranslation;


            matModel = matModel * matScale;

            pShaderManager->setShaderUniformM4fv("mModel", matModel);
            pShaderManager->setShaderUniformM4fv("mView", matView);
            pShaderManager->setShaderUniformM4fv("mProjection", matProjection);

            // Wireframe
            if (pCurrentMeshObject->isWireframe)
            {
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);      // GL_POINT, GL_LINE, GL_FILL
            }
            else
            {
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            }

            pShaderManager->setShaderUniform4f("RGBA_Colour",
                                               pCurrentMeshObject->color_RGBA.r,
                                               pCurrentMeshObject->color_RGBA.g,
                                               pCurrentMeshObject->color_RGBA.b,
                                               pCurrentMeshObject->color_RGBA.w);

            cModelDrawInfo drawingInformation;
            if (pVAOManager->FindDrawInfo(pCurrentMeshObject->meshName, drawingInformation))
            {
                glBindVertexArray(drawingInformation.VAO_ID);

                glDrawElements(GL_TRIANGLES,
                    drawingInformation.numberOfIndices,
                    GL_UNSIGNED_INT,
                    (void*)0);

                glBindVertexArray(0);

            }
            else
            {
                // Didn't find that model
                std::cout << "Error: didn't find model to draw." << std::endl;

            }//if ( pVAOManager..
        }
        //glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(window);
        glfwPollEvents();

        //set window title
        //std::stringstream 

    }

    glfwDestroyWindow(window);

    delete pVAOManager;
    delete pShaderManager;

    glfwTerminate();
    exit(EXIT_SUCCESS);
}