#include "cGUI.h"

cGUI::cGUI()
{

}

cGUI::~cGUI()
{
}

bool cGUI::ImGUI_init(GLFWwindow* window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    static ImGuiIO& io = ImGui::GetIO();

    //platform / render bindings
    if (!ImGui_ImplGlfw_InitForOpenGL(window, true) || !ImGui_ImplOpenGL3_Init("#version 460"))
    {
        return false;
    }

    //imgui style (dark mode for the win)
    ImGui::StyleColorsDark();
}

void cGUI::ImGUI_shutdown()
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

bool cGUI::ImGUICreateFrame()
{
    bool result = false;
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    result = ImGUI_render();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    return result;
}

bool cGUI::ImGUI_render()
{
    ImGui::Begin("Model Settings");
    ImGui::BeginGroup();
    //ImGui::BeginChild("##MainWindow", ImVec2(450, 65), true);
    
    for (int i = 0; i < pVecInstanceMeshObj->size();i++)
    {
        cMeshObj* pCurrentMeshObject = pVecInstanceMeshObj->at(i);
        //ImGui::Text(pCurrentMeshObject->instanceName.c_str());
        if (ImGui::TreeNode((void*)(intptr_t)i, pCurrentMeshObject->instanceName.c_str()))
        {
            ImGui::BeginGroup();
                ImGui::DragFloat("X pos##", &pCurrentMeshObject->position.x, 0.1f);
                ImGui::DragFloat("Y pos##", &pCurrentMeshObject->position.y, 0.1f);
                ImGui::DragFloat("Z pos##", &pCurrentMeshObject->position.z, 0.1f);
            ImGui::EndGroup();
            ImGui::NewLine();
            ImGui::BeginGroup();
                ImGui::DragFloat("X Rotate##", &pCurrentMeshObject->rotation.x, 0.1f);
                ImGui::DragFloat("Y Rotate##", &pCurrentMeshObject->rotation.y, 0.1f);
                ImGui::DragFloat("Z Rotate##", &pCurrentMeshObject->rotation.z, 0.1f);
            ImGui::EndGroup();
            ImGui::NewLine();
            ImGui::DragFloat("scale##", &pCurrentMeshObject->scale, 0.1f, 0.f,100.f);
            ImGui::Checkbox("wireframe##", &pCurrentMeshObject->isWireframe);
            ImGui::SameLine();
            ImGui::Checkbox("visible##", &pCurrentMeshObject->isVisible);
            //ImGui::Text(pCurrentMeshObject->instanceName.c_str());
            ImGui::TreePop();
        }
        
        //ImGui::SameLine();
        //pCurrentMeshObject->position;
        //ImGui::InputText("Pos.x",)
    }
    ImGui::Text("test");
    //ImGui::EndChild();
    ImGui::EndGroup();
    ImGui::End();
    return true;
}

bool cGUI::ImGUI_update()
{
    
    return true;
}
