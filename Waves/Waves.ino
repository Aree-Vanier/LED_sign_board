#include "FastLED.h"

#define NUM_LEDS 100
#define DATA_PIN 6

// Define the array of leds
CRGB leds[NUM_LEDS];

// Function to reverse every second row of LEDs, as in the sign board:
int serpentine(int i) {
  int r=i/10;
  int c=i%10;
  if ((r%2)==1)
    c=9-c;
  return 10*r+c;
}

// Define single colour moving patterns:
int pacman1[10][20]={ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0},
                      {0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0},
                      {0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

int pacman2[10][20]={ {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                      {0,0,0,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,0},
                      {0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0},
                      {0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                      {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

void setup()
{
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.show();
}

void loop() {
  int r,c;
  for (int j=0; j<20; j++)
  {
    for (int i = 0; i < NUM_LEDS; i++)
    {
      r=i/10;
      c=(i%10+20-j)%20;
      if ((i%2)==0)
        leds[serpentine(i)] = CRGB((r>2)*r*25*pacman2[r][c],0,pacman1[r][c]*255);
      else
        leds[serpentine(i)] = CRGB((r>2)*r*25*pacman2[r][c],0,pacman2[r][c]*255);
    }
    FastLED.show();
    delay(200);

  }
}

