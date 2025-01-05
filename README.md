# K-dron OpenGL

A project demonstrating the K-dron shape rendered using OpenGL. Includes functionality for animation, projection toggles, and interactive controls.

---

## Table of Contents

1. [How to Run](#how-to-run)
2. [How to Use](#how-to-use)
3. [Video Showcase](#video-showcase)
4. [License](#license)

---

## How to Run

To build and run the project, follow these steps:

1. Build and execute the project:
    ```bash
    make run
    ```
    
    <details>
      <summary>Example output:</summary>
        
        g++ -c -Wall -DDEBUG -g3 -fpermissive -MMD baseprogram.cpp -o baseprogram.o -lX11 -lglfw -lGL -lGLU -lGLEW -lm
        g++ -c -Wall -DDEBUG -g3 -fpermissive -MMD cameraprogram.cpp -o cameraprogram.o -lX11 -lglfw -lGL -lGLU -lGLEW -lm
        g++ -c -Wall -DDEBUG -g3 -fpermissive -MMD cube.cpp -o cube.o -lX11 -lglfw -lGL -lGLU -lGLEW -lm
        g++ -c -Wall -DDEBUG -g3 -fpermissive -MMD glerror.cpp -o glerror.o -lX11 -lglfw -lGL -lGLU -lGLEW -lm
        g++ -c -Wall -DDEBUG -g3 -fpermissive -MMD indexmodel.cpp -o indexmodel.o -lX11 -lglfw -lGL -lGLU -lGLEW -lm
        g++ -c -Wall -DDEBUG -g3 -fpermissive -MMD kdron.cpp -o kdron.o -lX11 -lglfw -lGL -lGLU -lGLEW -lm
        g++ -c -Wall -DDEBUG -g3 -fpermissive -MMD main.cpp -o main.o -lX11 -lglfw -lGL -lGLU -lGLEW -lm
        g++ -c -Wall -DDEBUG -g3 -fpermissive -MMD matma.cpp -o matma.o -lX11 -lglfw -lGL -lGLU -lGLEW -lm
        g++ -c -Wall -DDEBUG -g3 -fpermissive -MMD modelprogram.cpp -o modelprogram.o -lX11 -lglfw -lGL -lGLU -lGLEW -lm
        g++ -c -Wall -DDEBUG -g3 -fpermissive -MMD window.cpp -o window.o -lX11 -lglfw -lGL -lGLU -lGLEW -lm
        g++ baseprogram.o cameraprogram.o cube.o glerror.o indexmodel.o kdron.o main.o matma.o modelprogram.o window.o -o cube  -lX11 -lglfw -lGL -lGLU -lGLEW -lm
        ./cube -sync -gldebug
    </details>

2. Clean up build files:
    ```bash
    make clean
    ```
    
    <details>
      <summary>Example output:</summary>
        
        rm -f cube baseprogram.o cameraprogram.o cube.o glerror.o indexmodel.o kdron.o main.o matma.o modelprogram.o window.o
        rm -f baseprogram.d cameraprogram.d cube.d glerror.d indexmodel.d kdron.d main.d matma.d modelprogram.d window.d
    </details>

---

## How to Use

- **Toggle Animation:** Press the `Space` key.
- **Speed Up Animation:** Hold the `Right Arrow` key.
- **Slow Down Animation:** Hold the `Left Arrow` key.
- **Switch to Orthographic Projection:** Press the `Home` key.
- **Switch to Perspective Projection:** Press the `End` key.
- **Close the Window:** Press the `Esc` key.
- **Zoom In:** Hold the `Page Up` key.
- **Zoom Out:** Hold the `Page Down` key.
- **Rotate K-dron:** After toggling off animation, hold the `Up`, `Down`, `Left`, or `Right` arrow keys.

---

## Video Showcase
https://github.com/user-attachments/assets/55bdd2ee-8629-49a9-bfaa-8617e21f44c4

