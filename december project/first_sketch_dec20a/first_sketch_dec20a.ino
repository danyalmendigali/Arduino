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
  #define ORANGE 0xFFA5
  #define VIOLET 0x881F
  #define VERY_DARK_BLUE 0x0004
  #define DARK_VIOLET 0x1802

  #define MY_COLOR_1 0x1234
  #define MY_COLOR_2 0xABCD
  #define MY_COLOR_3 0x5678

  const int squareSize = 16;
  const int screenWidth = 320;
  const int screenHeight = 480;
  const int rows = screenWidth / squareSize;
  const int cols = screenHeight / squareSize;

  ILI9488 tft (LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
  int xy[8][8];
  int cvet[]={0x0000, 0x001F, 0xF800, 0x07E0, 0x07FF, 0xF81F};

  int temp[8][8] = {
  {10, 20, 30, 40, 50, 60, 70, 10},
  {40, 23, 2, 6, 59, 78, 0, 32},
  {30, 43, 35, 45, 3, 43, 3, 54},
  {50, 76, 2, 23, 57, 67, 0, 67},
  {10, 11, 23, 12, 35, 55, 45, 23},
  {20, 35, 2, 74, 24, 34, 0, 70},
  {50, 4, 45, 1, 79, 21, 43, 34},
  {60, 4, 34, 6, 70, 46, 21, 74},
};

  void loop()
  {
  //  displpaySquares();
    delay(1000);
    tft.fillScreen(WHITE);
    //ft.fillRect(100, 50, 100, 25, RED);
  
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        int x = 35 * i;
        int y = 35 * j;
        if(temp[i][j] >= 0 && temp[i][j] < 10){
          tft.fillRect(x, y, 35, 50, DARK_VIOLET); 
        }
        if(temp[i][j] >= 10 && temp[i][j] < 20){
          tft.fillRect(x, y, 35, 50, VERY_DARK_BLUE); 
        }
        if(temp[i][j] >= 20 && temp[i][j] < 30){
          tft.fillRect(x, y, 35, 50, BLUE); 
        }
        if(temp[i][j] >= 30 && temp[i][j] < 40){
          tft.fillRect(x, y, 35, 50, BLUE); 
        }
        if(temp[i][j] >= 40 && temp[i][j] < 50){
          tft.fillRect(x, y, 35, 50, GREEN); 
        }
        if(temp[i][j] >= 50 && temp[i][j] < 60){
          tft.fillRect(x, y, 35, 50, YELLOW); 
        }
        if(temp[i][j] >= 60 && temp[i][j] < 70){
          tft.fillRect(x, y, 35, 50, ORANGE); 
        }
        if(temp[i][j] >= 70 && temp[i][j] < 80){
          tft.fillRect(x, y, 35, 50, RED); 
        }

      }
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
    //tft.setRotation(2);
    tft.fillScreen(WHITE);
    delay(5000);
  }