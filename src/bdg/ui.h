#ifndef TBOX_UI
#define TBOX_UI

#include "raylib.h"

typedef enum ButtonState { NORMAL, MOUSE_HOVER, PRESSED } ButtonState;

typedef struct UIElement {
    unsigned int elementId;
    const char *elementName;
    void *uiElement;
} UIElement;

typedef struct UIElementTexture {
    Texture2D texture;
    Image *dest;
} UIElementTexture;

typedef struct Button {
    Texture2D texture;
    Rectangle rect;
    char* txt;
                                // src:https://www.raylib.com/examples/textures/loader.html?name=textures_sprite_button
    ButtonState btnState;       // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    void (*btnAction)();
} Button;

void UpdateButton(Button);
void DrawButton(Button);

// UIElementButton *btn = (UIElementButton*) malloc(sizeof(UIElementButton));
// Rectangle btnRect;
// btnRect.height = 200;
// btnRect.width = 200;
// btnRect.x = 200;
// btnRect.y = 200;
// btn->element.elementId = 0;
// btn->element.elementName = "Play Button";
// btn->button.txt = "Play";
// btn->button.rect = btnRect;

#endif