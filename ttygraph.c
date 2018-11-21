/*
 * ttygraph.c: a simple utility for graphing on the commandline
 * 
 * - Everything here is a bit messy, but it works for the most part
 */

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tinyexpr.h"

void init_ncurses(){
  initscr();
  start_color();

  init_pair(1,COLOR_RED,COLOR_BLACK);
  init_pair(2,COLOR_WHITE,COLOR_BLACK);    
}
void shutdown_ncurses(){
  getch();
  endwin();
}

void draw_axes(int row, int col){
  for(int x=0;x<col;x++){
    mvprintw((row/2),x,"-");
  }
  for(int y=0;y<row;y++){
    mvprintw(y,(col/2),"|");
  }
}
void draw_point(int x, int y){
  mvprintw(y,x,"*");
  refresh();
}

void print_info(char *func){
  mvprintw(0,0,"Graph of y=%s\nPress any key to exit",func);
}

te_expr *parse_func(char *arg, double *x){
  te_variable vars[] = {{"x",x}};

  int err;

  char *flip = malloc(strlen(arg)+3);
  sprintf(flip,"-(%s)",arg);

  te_expr *expr = te_compile(flip,vars,1,&err);

  if(!err){
    return expr;
  } else {
    return NULL;
  }
}

int main(int argc, char *argv[]){
  if(argc < 2){
    printf("Usage: ttygraph [righthand of func]\n");
    return 1;
  }

  int row, col;
  double x;
  te_expr *expr = parse_func(argv[1],&x);

  if(expr){
    init_ncurses();

    getmaxyx(stdscr,row,col);

    attron(COLOR_PAIR(2));
    draw_axes(row,col);

    attron(COLOR_PAIR(1));
    for(x=-(col/2);x<(col/2);x+=1.0){
      draw_point(x+(col/2),te_eval(expr)+(row/2));
    }

    attron(COLOR_PAIR(2));
    print_info(argv[1]);

    shutdown_ncurses();
  } else {
    printf("Invalid expression\n");
    return 2;
  }

  return 0;
}
