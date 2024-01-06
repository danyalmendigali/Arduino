#include <Melopero_AMG8833.h>

Melopero_AMG8833 sensor;

// Размер матрицы
const int MATRIX_SIZE = 8;

// Матрица для хранения температурных значений
float temperatureMatrix[MATRIX_SIZE][MATRIX_SIZE];

void setup() {
  Serial.begin(9600);

  // initializing I2C to use default address AMG8833_I2C_ADDRESS_B and Wire (I2C-0):
  Wire.begin();
  sensor.initI2C();

  Serial.print("Resetting sensor ... ");  
  int statusCode = sensor.resetFlagsAndSettings();
  Serial.println(sensor.getErrorDescription(statusCode));

  Serial.print("Setting FPS ... ");
  statusCode = sensor.setFPSMode(FPS_MODE::FPS_10);
  Serial.println(sensor.getErrorDescription(statusCode));

  // Добавляем задержку после инициализации датчика
  delay(1000);
}

void loop() {
  Serial.print("Updating thermistor temperature ... ");
  int statusCode = sensor.updateThermistorTemperature();
  Serial.println(sensor.getErrorDescription(statusCode));

  Serial.print("Updating pixel matrix ... ");
  statusCode = sensor.updatePixelMatrix();
  Serial.println(sensor.getErrorDescription(statusCode));

  Serial.print("Thermistor temp: ");
  Serial.print(sensor.thermistorTemperature);
  Serial.println("°C");

  // Копируем значения из sensor.pixelMatrix в temperatureMatrix
  for (int row = 0; row < MATRIX_SIZE; row++) {
    for (int col = 0; col < MATRIX_SIZE; col++) {
      temperatureMatrix[row][col] = sensor.pixelMatrix[row][col];
    }
  }

  Serial.println("Temperature Matrix: ");
  for (int x = 0; x < MATRIX_SIZE; x++){
    for (int y = 0; y < MATRIX_SIZE; y++){
      Serial.print(temperatureMatrix[y][x]);
      Serial.print(" ");
    }
    Serial.println();
  }

  delay(1000);
}
