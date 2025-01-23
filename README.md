# Arduino LED Sirena Project

## Simulación
[Ver projeto en Tinkercad](https://www.tinkercad.com/things/01oKUlHFc62-luces-de-sirena)

## Descripción
Código Arduino que crea un patrón de luces LED que se mueve de izquierda a derecha y viceversa utilizando operaciones de bits.

## Código Explicado

### Variables Principales
```cpp
const int numLeds = 8;  // Número total de LEDs
int ledPins[numLeds] = {2, 3, 4, 5, 6, 7, 8, 9};  // Pines de conexión
byte patronActual = 0x01;  // Patrón inicial binario
int tiempoRetardo = 500;  // Tiempo entre cambios (ms)
bool direccion = true;  // Dirección del movimiento
```

### Función `setup()`
- Configura todos los pines de LEDs como salidas
- Inicializa los LEDs apagados

### Función `updateLeds()`
- Actualiza el estado de los LEDs usando operaciones de bits
- Utiliza bitwise AND (`&`) para determinar el estado de cada LED

### Función `loop()`
- Mueve un bit encendido de izquierda a derecha
- Cambia dirección al llegar a los extremos
- Utiliza operadores de desplazamiento de bits (`<<`, `>>`)

## Técnicas Clave
- Manipulación de bits
- Control de dirección 
- Uso de operadores de desplazamiento

## Personalización
- Modificar `tiempoRetardo` para cambiar velocidad
- Ajustar pines en `ledPins`

## Licencia
Este proyecto está bajo la Licencia MIT - ver el archivo [LICENSE](LICENSE) para más detalles.

## Autor
[Pedro Carranza](https://github.com/draexx)
