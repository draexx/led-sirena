const int numLeds = 8;
int ledPins[numLeds] = {2, 3, 4, 5, 6, 7, 8, 9};  // Pines de los LEDs
byte patronActual = 0x01; // Patrón inicial (00000001 en binario)
int tiempoRetardo = 500;
bool direccion = true;
void setup()
{
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);  // Configura los pines como salidas
    digitalWrite(ledPins[i], LOW);
  }
}
void updateLeds(byte byteVal) {
  for (int i = 0; i < numLeds; i++) {
    // Verificar si el bit correspondiente está encendido
    bool estadoLed = (byteVal & (0x01 << i)) ? HIGH : LOW;
    digitalWrite(ledPins[i], estadoLed);
  }
}
void loop()
{
  	updateLeds(patronActual);  // Actualiza los LEDs
	delay(tiempoRetardo);
  
    // Actualizar el patrón para la siguiente iteración
    if (direccion) {
      // Mover el bit hacia la izquierda
      patronActual = patronActual << 1;

      // Si llegamos al último LED, cambiar dirección
      if (patronActual == 0x80) { // 10000000 en binario
        direccion = false;
      }
    } else {
      // Mover el bit hacia la derecha
      patronActual = patronActual >> 1;

      // Si llegamos al primer LED, cambiar dirección
      if (patronActual == 0x01) { // 00000001 en binario
        direccion = true;
      }
    }
}
