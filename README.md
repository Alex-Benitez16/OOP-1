# OOP-1

## Battle Card Game

Este es un juego de cartas sencillo para dos jugadores, donde cada jugador toma el rol de un **Atacante** o **Defensor**. Cada jugador utiliza un mazo compuesto por cartas básicas y cartas especiales que determinan sus acciones durante el turno. El objetivo es reducir los puntos de vida del oponente a 0 utilizando estrategias basadas en las habilidades únicas de cada rol.

Este proyecto fue desarrollado como parte de una práctica de programación orientada a objetos, haciendo uso de **herencia**, **composición** y **agregación**.

## Funcionalidad

- **Roles Únicos**:
    - **Atacante**: Enfocado en infligir daño con cartas de ataque y movimientos especiales.
    - **Defensor**: Capaz de absorber daño y recuperar puntos de vida.
- **Cartas y Mazos**: 
    - Cada jugador tiene un mazo básico (cartas compartidas) y un mazo especial (cartas únicas según su rol).
- **Dinámica del Juego**: 
    - Los jugadores se turnan para jugar una carta y decidir cómo usar sus habilidades.
    - Las reglas del juego permiten acciones como atacar, defender, o curarse según el rol del jugador y las cartas disponibles.
- **Condición de Victoria**:
    - El primer jugador en reducir los puntos de vida de su oponente a 0 gana.

## Instrucciones para ejecutar el programa

1. **Requisitos previos**: 
    - Un compilador de C++ (como g++).
2. **Clonar el repositoria**:
    ```bash
    git clone <URL-del-repositorio>
    cd <nombre-del-repositorio>
    ```
3. **Compilar el Programa**:
    Ejecuta el siguiente comando en la terminal:
    ```bash
    g++ -o juego main.cpp
    ```
4. **Ejecutar el Programa**:
    Una vez compilado, ejecuta el archivo generado:
    ```bash
    ./juego
    ```