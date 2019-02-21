#ifndef GRAPH_H
#define GRAPH_H

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#define SCREEN_HEIGHT   128
#define SCREEN_WIDTH    160

#define GRAPH_HEIGHT    116
#define GRAPH_WIDTH     136

#define YELLOW  0xF7E0

class Graph
{
    public:
        Graph(Adafruit_ST7735 *tft);
        ~Graph();
        
        void draw(float *values, int count);
        
    private:
        Adafruit_ST7735 *m_tft;
        
        int smallest(float*, int);
        int largest(float*, int);
};

#endif // GRAPH_H