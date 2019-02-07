/*
 *  Julius L.
 *  07.02.2019
 *
 *      bitcoin-chart.ino
 *
 */

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

// TFT pins
#define TFT_LITE   3
#define TFT_RST    8
#define TFT_DC     9
#define TFT_CS     10
#define TFT_MOSI   11
#define TFT_SCLK   13

#define HEIGHT  128
#define WIDTH   160

#define YELLOW  0xF7E0

#define arrayCount(a)   sizeof(a) / sizeof(a[0])

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

const float btcPrice[] =
{
    5792.1484,
    5407.6296,
    5671.5193,
    5378.74,
    5457.6058,
    5544.1137,
    5481.9092,
    5457.8245,
    5526.1396,
    5551.0579,
    5749.307,
    5585.2212,
    5670.942,
    5444.9806,
    5597.5737,
    5483.1586,
    5653.0174,
    5755.6543,
    5789.9522,
    5770.5897,
    5914.5883,
    6052.0889,
    6008.8864,
    5984.5243,
    6040.4342,
    6194.0077,
    6290.4958,
    6252.0526,
    6353.8776,
    5748.1158,
    5591.1517,
    5532.1329,
    5348.0054,
    5400.7852,
    5437.6242,
    5415.9033,
    5442.2469,
    5548.9997,
    5582.6634,
    5602.8911,
    5588.1638,
    5349.6115,
    5427.2091,
    5473.5148,
    5511.9996,
    5743.5796,
    5708.6985,
    5705.1496,
    5601.4968,
    5469.0783,
    5500.266,
    5742.8652,
    5702.5779,
    5669.9438,
    5689.6889,
    5683.8278,
    5634.915,
    5635.7976,
    5693.784,
    5716.3078,
    5693.7712,
    5712.4843,
    5762.7739,
    5748.9392,
    5682.8118,
    5328.9761,
    5371.23,
    5384.9279,
    5386.2169,
    5623.7207,
    5643.9202,
    5664.865,
    5630.7999,
    5567.9694,
    5599.7459,
    5604.962,
    5624.1027,
    5608.7133,
    5659.4891,
    5651.0836,
    5640.718,
    5635.5631,
    5635.2168,
    5526.3044,
    5539.5882,
    5585.4147,
    5575.2995,
    5593.1285,
    5573.7653,
    5653.051,
    5628.1771,
    5662.5498,
    5703.8825,
    5653.6988,
    5604.3032,
    5617.8082,
    5637.7691,
    5664.5202,
    5581.8866,
    5022.0817,
    4963.707,
    4858.1167,
    4848.4912,
    4889.8088,
    4178.0613,
    3882.9412,
    4017.5633,
    3761.3064,
    3809.6945,
    3365.1656,
    3507.7932,
    3319.7138,
    3364.7318,
    3731.1057,
    3744.1342,
    3527.1089,
    3680.3548,
    3632.7305,
    3395.9548,
    3464.8712,
    3280.3018,
    3046.4963,
    2990.4237,
    3015.8148,
    3128.7516,
    3036.9282,
    2984.3619,
    3047.2334,
    2898.6607,
    2850.7449,
    2842.4517,
    2856.1735,
    3119.8196,
    3257.5595,
    3273.2261,
    3587.7686,
    3417.8848,
    3545.6485,
    3507.8923,
    3567.5926,
    3350.1957,
    3354.327,
    3178.0247,
    3441.1746,
    3303.6546,
    3392.4092,
    3259.8458,
    3375.0601,
    3475.4516,
    3363.3866,
    3390.4831,
    3365.8718,
    3580.0374,
    3521.6176,
    3522.3739,
    3487.9205,
    3191.4506,
    3192.74,
    3189.9051,
    3087.8181,
    3231.7379,
    3159.7797,
    3185.7644,
    3218.5745,
    3194.0016,
    3262.775,
    3125.903,
    3121.0729,
    3166.7919,
    3142.1863,
    3183.6896,
    3141.593,
    3139.2404,
    3114.1167,
    3022.7909,
    2991.7181,
    3032.7037,
    3007.0764,
    3027.0589,
    3025.2834,
    3005.4438,
    3017.8379,
    3044.2838,
    2985.4605
};

int smallest(float *a, int size)
{
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

int largest(float *a, int size)
{
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

void drawGraph(float *values)
{
    int smallestIndex = smallest(btcPrice, arrayCount(btcPrice));
    int largestIndex = largest(btcPrice, arrayCount(btcPrice));
    
    for (int i = 0; i < arrayCount(btcPrice); i++)
    {
        Serial.println(btcPrice[i]);
    }
    Serial.print("Smallest: ");
    Serial.println(btcPrice[smallestIndex]);
    
    Serial.print("Largest: ");
    Serial.println(btcPrice[largestIndex]);
    
    
    
    
    
    int size = arrayCount(btcPrice);
    int x0, y0, x, y;
    
    // difference between min and max values
    float range = btcPrice[largestIndex] - btcPrice[smallestIndex];
    for (int i = 0; i < size-1; i++)
    {
        x0 = (int)((float)WIDTH / (float)(size-1) * (float)i);
        x =  (int)((float)WIDTH / (float)(size-1) * (float)(i+1));
        
        y0 = (int)((float)((btcPrice[largestIndex] - btcPrice[i]) / range) * (float)HEIGHT);
        y =  (int)((float)((btcPrice[largestIndex] - btcPrice[i+1]) / range) * (float)HEIGHT);
        
        tft.drawLine(x0, y0, x, y, YELLOW);
    }
}

void setup() 
{
    // Set backlight
    analogWrite(TFT_LITE, 0xFF);
    // Interrupt every second
    timerInit();
    
    Serial.begin(9600);
    
    tft.initR(INITR_BLACKTAB);
    tft.fillScreen(ST7735_BLACK);
    tft.setRotation(1);      
    
    drawGraph(btcPrice);
}

void timerInit()
{
    TCCR1A = 0x00;// set entire TCCR1A register to 0
    TCCR1B = 0x00;// same for TCCR1B
    TCNT1  = 0;//initialize counter value to 0
    // set compare match register for 1hz increments
    OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
    
    TCCR1B |= (1 << WGM12); // turn on CTC mode
    TCCR1B |= (1 << CS12) | (1 << CS10); // 1024 prescaler
    TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt   
}

ISR(TIMER1_COMPA_vect)
{
    
}

void loop() 
{
    
}





