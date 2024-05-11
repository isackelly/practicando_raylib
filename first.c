#include "raylib.h"
const int screenWidth = 800;
const int screenHeight = 450;

Vector2 perspective(Vector3 V3)
{
  //transformation desde 3 dimensiones hasta 2 dimensiones.
  float mid_distance_x = V3.x - (screenWidth/2.0f);
  float mid_distance_y = V3.y - (screenHeight/2.0f);

  float scaled_distance_x = mid_distance_x / (V3.z / 100.0f);
  float scaled_distance_y = mid_distance_y / (V3.z / 100.0f);

  Vector2 V = {
    scaled_distance_x + (screenWidth/2.0f),
    scaled_distance_y + (screenHeight/2.0f)};

  return V;
}

int main(void)
{
    InitWindow(screenWidth, screenHeight,
               "raylib [core] example - basic window");
    float rotation = 0.0f;
    float rotation_speed = 0.2f;
    SetTargetFPS(60);  // Set our game to run at 60 frames-per-second

    float distance = 100.0f;
    
    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_RIGHT)) rotation_speed += 0.05f;
        if (IsKeyDown(KEY_LEFT)) rotation_speed -= 0.05f;
        if (IsKeyDown(KEY_UP)) distance += 1.0f;
        if (IsKeyDown(KEY_DOWN)) distance -= 1.0f;

        rotation += rotation_speed;
        BeginDrawing();
            ClearBackground(RAYWHITE);
                        DrawText("Usa las llaves derecho, izquierda, arriba, y bajo", 190, 200, 20, LIGHTGRAY);

                        Vector3 V3 = {
              screenWidth/2.0f + 100.0f,
              screenHeight/2.0f,
              100.0f};
                        //mueven en perspectiva con foco en el medio pantalla.
            DrawTriangle(perspective((Vector3){ screenWidth/4.0f, 80.0f, distance}),
                         perspective((Vector3){ screenWidth/4.0f - 50.0f, 150.0f, distance}),
                         perspective((Vector3){ screenWidth/4.0f + 50.0f, 150.0f, distance}),
                         RED);
            DrawTriangle(perspective((Vector3){ screenWidth/2.0f, 80.0f, distance}),
                         perspective((Vector3){ screenWidth/2.0f - 50.0f, 150.0f, distance}),
                         perspective((Vector3){ screenWidth/2.0f + 50.0f, 150.0f, distance}),
                         GREEN);
            //Notas que eso triangle azul no esta dibujada. eso es porque los puntas no son en orden de reloj. son contra-reloj. Eso es buena, porque significa que si tenemos una objecto con tres dimensiones, no va a dibujar la lado del objecto que no podemos ver.
            DrawTriangle(perspective((Vector3){ screenWidth/4.0f, 200.0f, distance}),
                         perspective((Vector3){ screenWidth/4.0f - 50.0f, 150.0f, distance}),
                         perspective((Vector3){ screenWidth/4.0f + 50.0f, 150.0f, distance}),
                         BLUE);
            DrawPoly((Vector2){ screenWidth/4.0f*3, 330 }, 6, 80, rotation, BROWN);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

