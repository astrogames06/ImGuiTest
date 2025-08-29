#include <raylib.h>
#include <imgui.h>
#include <rlImGui.h>

#include <TextEditor.h>

int main()
{
    const int WIDTH = 800;
    const int HEIGHT = 600;
    InitWindow(800, 600, "Raylib + rlImGui Example");
    SetTargetFPS(60);

    static char codeBuffer[65536] = "";

    rlImGuiSetup(true);

    TextEditor editor;
    editor.SetLanguageDefinition(TextEditor::LanguageDefinition::Lua());
    editor.SetText("-- Your code here\nprint('hello, world!')");
    editor.SetShowWhitespaces(true);
    editor.SetTabSize(4);
    editor.SetReadOnly(false);

    ImGuiIO& io = ImGui::GetIO();
    ImFont* codeFont = io.Fonts->AddFontFromFileTTF("Menlo-Regular.ttf", 18.0f);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        rlImGuiBegin();

        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2((float)GetScreenWidth(), (float)GetScreenHeight()));
        ImGui::Begin("Code Editor", nullptr,
            ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);

        ImGui::PushFont(codeFont);
        editor.Render("CodeEditor");
        ImGui::PopFont();
        
        ImGui::End();

        rlImGuiEnd();

        EndDrawing();
    }

    rlImGuiShutdown();
    CloseWindow();
    return 0;
}
