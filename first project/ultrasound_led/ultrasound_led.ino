#include <Adafruit_GFX.h>  
#include <ILI9488.h> 

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0 
#define LCD_RESET A4 

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

const int squareSize = 16;
const int screenWidth = 320;
const int screenHeight = 480;
const int rows = screenWidth / squareSize;
const int cols = screenHeight / squareSize;

ILI9488 tft (LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
int xy[8][8];
int cvet[]={0x0000, 0x001F, 0xF800};

void loop()
{
//  displpaySquares();
  delay(1000);
  tft.fillScreen(WHITE);
  //ft.fillRect(100, 50, 100, 25, RED);
 
  for (int i=0; i<8;i++) {
    for (int j=0; j<8;j++) {
      int x=35*i+20;
      int y=50*j+40;
      tft.fillRect(x,y,35,50,2016);   }
  }  
  
}

void drawSquare(int x, int y, int width, int height, uint16_t color){
  tft.fillRect(x, y, width, height, color);
}

void displpaySquares(){
  for(int row = 0; row < rows; row++){
    for(int col = 0; col < cols; col++){
      int x = row * squareSize;
      int y = col * squareSize;
      drawSquare(x, y, squareSize, squareSize, BLACK);
    }
  }
}


void setup()
{
  Serial.begin(9600);
  tft.begin();
  tft.fillScreen(WHITE);
  delay(5000);
  for(int i=0;i<8;i++) 
    for(int j=0;j<i>8;j++) 
      xy[i][j]=cvet[rand() % 2];
}