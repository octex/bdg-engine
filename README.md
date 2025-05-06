Este proyecto es un mini motor grafico 2D construido con Raylib.

Utiliza Sol: https://github.com/ThePhD/sol2 para el control y manejo de archivos .lua y Raylib: https://github.com/raysan5/raylib para las funcionalidades core.

A dia de la fecha 06/05/2025 el motor puede:
  - Cargar escenas en archivos .lua
  - Chequeo basico de colisiones
  - Armar y renderizar Tilemaps
  - Carga de assets

Quedan pendientes:
  - Animaciones
  - Configuraciones de aplicacion
  - Colisiones trigger
  - UI
  - Shaders/Iluminacion
  - Transicionn entre escenas

Es necesario para ponerlo en funcionamiento compilar raylib y tener instalada la biblioteca de Lua para C++ y agregar para el linker la carpeta `/lib` donde se guardan las bibliotecas static.
Para que el programa lea los recursos (assets) crear un subdirectorio dentro de `/build` llamado `/resources` no es necesario respetar ningun orden en particular y pueden organizarse a gusto.
