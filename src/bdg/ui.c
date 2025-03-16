#include "ui.h"

void UpdateButton(Button button)
{
    Vector2 mousePoint = GetMousePosition();
    if (CheckCollisionPointRec(mousePoint, button.rect))
    {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) button.btnState = PRESSED;
            else button.btnState = MOUSE_HOVER;
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) button.btnAction();
    }
    else
    {
        button.btnState = NORMAL;
    }
}

void DrawButton(Button button)
{
    if (IsTextureReady(button.texture))
    {
        // TODO: Probar con textura
        // DrawTextureRec(btn.texture, btn.rect, (Vector2){ btn.rect.x, btn.rect.y }, WHITE);
    }
    else
    {
        DrawRectangle(button.rect.x, button.rect.y, button.rect.width, button.rect.height, WHITE);
        if (button.txt)
        {
            DrawText(button.txt, button.rect.x + 5, button.rect.y + 5, 10, BLACK);
        }
    }
}