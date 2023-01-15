# Fractol

This project is about creating a small fractal exploration program. The program displays the Julia set, Mandelbrot set, and the Burning Ship fractal and allows the user to zoom in and out using the mouse wheel. The program also allows the user to create different Julia sets by passing different parameters to the program.

## Project specifications

For the project we had to use the miniLibX.

<b>Allowed functions:</b>
``` open, close, read, write, malloc, free, perror, strerror, exit, All functions of the math library (-lm compiler option, man man 3 math)```

## How to use

The current version of Fractol is developed and tested on macOS.

<b>Requirements:</b>
- GCC / CLANG Compiler
- GNU Make

```
git clone https://github.com/srein91/fractol.git fractol
```
```
cd webserv && make
```
```
./fractol <Mandelbrot> or <Julia> or <BurningShip>
```
For Julia you can start the programm with 2 additional arguments, for example:
```
./fractol julia 0.28 0.008
```

| Key / Input  | What it does |
| :---         | :---         |
| ```ARROWS RIGHT LEFT```  | change color scheme |
| ```ARROWS UP DOWN```  | change into different fractals |
| ```MOUSE WHEEL```  | zoom in and out |
| ```ESC```  | exit the Programm |

![alt text](https://github.com/SRein91/Fractol/blob/main/Mandelbrot.png?raw=true)
<br>
![alt text](https://github.com/SRein91/Fractol/blob/main/Julia.png?raw=true)
<br>
![alt text](https://github.com/SRein91/Fractol/blob/main/BurningShip.png?raw=true)

<br>
<hr>
<b>This is a 42 project which has to be written in C.<br></b>
<br>

> #### Sample restrictions:
> - All variables have to be declared and aligned at the top of each function
> - Each function can not have more then 25 lines
> - Projects should be created with allowed std functions otherwise it is cheating
