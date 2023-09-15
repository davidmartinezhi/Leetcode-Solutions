Claro, aquí tienes una "cheat sheet" más detallada con comentarios para entender mejor cada operación de bits en C++:

### Operadores de Bits

- **AND Bit a Bit (`&`)**: Útil para enmascarar bits, es decir, seleccionar ciertos bits mientras se ocultan otros.
  ```cpp
  int a = 5;  // 0101
  int b = 3;  // 0011
  int c = a & b;  // 0001 (1)
  ```

- **OR Bit a Bit (`|`)**: Útil para establecer bits en 1, especialmente cuando se combinan diferentes banderas o estados.
  ```cpp
  int c = a | b;  // 0111 (7)
  ```

- **XOR Bit a Bit (`^`)**: Útil para alternar bits, es decir, cambiar un 1 a 0 y un 0 a 1.
  ```cpp
  int c = a ^ b;  // 0110 (6)
  ```

- **NOT Bit a Bit (`~`)**: Útil para invertir todos los bits de un número.
  ```cpp
  int c = ~a;  // 1010 (-6 en complemento a dos)
  ```

- **Desplazamiento a la Izquierda (`<<`)**: Útil para multiplicar un número por 2.
  ```cpp
  int c = a << 1;  // 1010 (10)
  ```

- **Desplazamiento a la Derecha (`>>`)**: Útil para dividir un número por 2.
  ```cpp
  int c = a >> 1;  // 0010 (2)
  ```

### Manipulación de Bits

- **Establecer el i-ésimo bit**: Útil para marcar un bit específico como 1.
  ```cpp
  int setBit(int num, int i) {
    return num | (1 << i);
  }
  ```

- **Limpiar el i-ésimo bit**: Útil para marcar un bit específico como 0.
  ```cpp
  int clearBit(int num, int i) {
    return num & ~(1 << i);
  }
  ```

- **Cambiar el i-ésimo bit**: Útil para alternar un bit específico.
  ```cpp
  int toggleBit(int num, int i) {
    return num ^ (1 << i);
  }
  ```

- **Verificar si el i-ésimo bit está encendido**: Útil para comprobar el estado de un bit específico.
  ```cpp
  bool isBitSet(int num, int i) {
    return (num & (1 << i)) != 0;
  }
  ```

### Trucos y Técnicas

- **Contar bits encendidos**: Útil para saber cuántos bits en un número son 1.
  ```cpp
  int countBits(int num) {
    int count = 0;
    while (num) {
      num &= (num - 1);
      count++;
    }
    return count;
  }
  ```

- **Invertir bits**: Útil para obtener el número con los bits invertidos.
  ```cpp
  int reverseBits(int num) {
    int rev = 0;
    while (num) {
      rev <<= 1;
      rev |= (num & 1);
      num >>= 1;
    }
    return rev;
  }
  ```

Espero que esta versión más detallada te sea de ayuda para entender cómo y cuándo usar cada operación de bits en C++.