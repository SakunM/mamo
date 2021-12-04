#pragma once

#define WORD 32
#define WORDS 64
#define LINE 128
#define LINES LINE * 10
#define FAILS LINE * 100


#define foreach(x, list) for(x = list; x - list < sizeof(list) / sizeof(list[0]); x = x + 1)