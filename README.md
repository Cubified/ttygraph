# ttygraph

A simple utility for graphing on the commandline

## Usage

     ttygraph [righthand of func]

### Examples:

     ttygraph "x"
     ttygraph "x*x"
     ttygraph "2*sin(x)"

### Screenshots:

![linear](https://github.com/Cubified/ttygraph/blob/master/screenshots/linear.png)

![parabola](https://github.com/Cubified/ttygraph/blob/master/screenshots/parabola.png)

![sine](https://github.com/Cubified/ttygraph/blob/master/screenshots/sine.png)

## Compilation

     git clone "https://github.com/Cubified/ttygraph"
     cd ttygraph
     make

`ttygraph` requires `ncurses`

## See Also

[tinyexpr](https://github.com/codeplea/tinyexpr) - does the brunt of the work
