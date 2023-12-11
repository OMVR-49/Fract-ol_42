# fract-ol
Fract’ol is a computer graphics project aimed at generating visually appealing fractals. In this project, I will use the 1337 school graphical library, MiniLibX, to create a basic computer graphics project. I will get to explore the mathematical concept of complex numbers, learn about optimization in computer graphics, and practice event handling.

This project provides an excellent opportunity to learn about computer graphics, explore the mathematical concept of fractals, and develop your programming skills.

# fract'ol - Computer Graphics Fractals

## Summary

The **fract'ol** project revolves around creating visually appealing fractals using computer graphics. This project explores mathematical concepts, complex numbers, optimization in computer graphics, and event handling. It involves utilizing the MiniLibX, a graphical library developed internally at the school.

## Version

Version: 3

## Table of Contents

I. [Foreword](#foreword)  
II. [Introduction](#introduction)  
III. [Objectives](#objectives)  
IV. [Common Instructions](#common-instructions)  
V. [Mandatory Part](#mandatory-part)  
   V.1 [Rendering](#v1-rendering)  
   V.2 [Graphic Management](#v2-graphic-management)  
VI. [Bonus Part](#bonus-part)   

### I. Foreword
The project title "fract'ol" is not related to hydraulic fracturing; instead, it focuses on the creation of graphically beautiful fractals.

### II. Introduction
The term "fractal" was coined by mathematician Benoit Mandelbrot in 1974, based on the Latin word "fractus," meaning "broken" or "fractured." Fractals are abstract mathematical objects with patterns that remain the same at every scale.

### III. Objectives
Create a basic computer graphics project using the MiniLibX library. Get familiar with MiniLibX, explore complex numbers, understand optimization in computer graphics, and practice event handling.

### IV. Common Instructions
- Project must be written in C.
- Adhere to the Norm for coding standards.
- Functions should not quit unexpectedly (segmentation fault, bus error, double free, etc.).
- Properly free heap-allocated memory.
- Bonus part evaluation only if the mandatory part is perfect.

### V. Mandatory Part
**Program Name:** fractol  
**Turn in Files:** Makefile, *.h, *.c  
**Makefile Rules:** NAME, all, clean, fclean, re  
**Arguments:** Type of fractal to display and any other available options  
**External Functions:** open, close, read, write, malloc, free, perror, strerror, exit, math library functions, MiniLibX functions, ft_printf or equivalent  
**Libft Authorized:** Yes

#### V.1 Rendering
- Offer Julia set and Mandelbrot set.
- Mouse wheel zooms in and out.
- Create different Julia sets by passing parameters.
- Handle rendering options as parameters.
- Use colors to show fractal depth.
  
#### V.2 Graphic Management
- Display the image in a window.
- Smooth window management.
- Pressing ESC or clicking on the window's cross closes the window and exits the program cleanly.

### VI. Bonus Part
Extra points for additional features:
- Implement one more different fractal. ( I choose tricorn )
- Zoom follows the actual mouse position.
- Move the view with arrow keys.
- Make the color range shift.
