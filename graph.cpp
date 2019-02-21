#include "graph.h"

Graph::Graph(Adafruit_ST7735 *tft)
{
    m_tft = tft;
}

Graph::~Graph()
{
    delete m_tft;
}

void Graph::draw(float *values, int count)
{
    int smallestIndex = smallest(values, count);
    int largestIndex = largest(values, count);
    
    int x0, y0, x, y;
    
    // difference between min and max values
    float range = values[largestIndex] - values[smallestIndex];
    
    // Left margin
    int M = SCREEN_WIDTH - GRAPH_WIDTH;
    // Graph width
    int G = SCREEN_WIDTH - M;
    
    for (int i = 0; i < count-1; i++)
    {
        x0 = M + (int)((float)G / (float)(count-1) * (float)i);
        x =  M + (int)((float)G / (float)(count-1) * (float)(i+1));
        
        y0 = (int)((float)((values[largestIndex] - values[i]) / range) * (float)GRAPH_HEIGHT);
        y =  (int)((float)((values[largestIndex] - values[i+1]) / range) * (float)GRAPH_HEIGHT);
        
        m_tft->drawLine(x0, y0, x, y, YELLOW);
    }
    // Graph borders
    m_tft->drawFastVLine(M, 0, GRAPH_HEIGHT, 0xFFFF);
    m_tft->drawFastHLine(M, GRAPH_HEIGHT, G, 0xFFFF);
}

int Graph::smallest(float *a, int size)
{
    // Index of smallest value
    int index = 0;
    float min = a[0];
    
    for (int i = 0; i < size; i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            index = i;
        }
    }
    return index;
}

int Graph::largest(float *a, int size)
{
    // Index of largest value)
    int index = 0;
    float max = a[0];
    
    for (int i = 0; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
            index = i;
        }
    }
    return index;
}