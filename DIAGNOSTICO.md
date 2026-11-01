# Prueba de retraso al escribir

La recuperación OLED ee281bd0 compiló, pero el usuario reporta que ambas pantallas siguen apagadas y hay retraso al escribir. Indicó inicialmente Bluetooth y ambas mitades; no hay mediciones ni logs del teclado en ejecución.

Esta variante desactiva únicamente la función de pantalla y sus widgets respecto a la recuperación; mantiene mapa de teclas, versión ZMK, radio Bluetooth, suspensión y RGB desactivado. Elimina del build izquierdo el widget WPM, dependiente de pantalla. No cambia emparejamientos ni usa settings_reset.

Propósito: comprobar si el trabajo de pantalla contribuye al retraso. No se afirma que sea la causa. ZMK usa por defecto la cola del sistema para pantalla; en la recuperación anterior no se seleccionó una cola dedicada. Fuente: https://github.com/zmkfirmware/zmk/blob/4dd95d7840eb3d5a3f59bb29fbf1ab054715ef85/app/src/display/main.c

Las dos pantallas permanecerán apagadas en esta prueba por diseño. No es una reparación de pantallas. Modelo y conexiones siguen sin confirmar; no se cambian pines ni se añade nice!view.

## Instalar y comparar

1. Descarga firmware de una compilación correcta de esta rama y descomprime.
2. Instala mr_robot_diagnostic_right.uf2 en la derecha: conecta USB al Mac, doble RESET y arrastra el archivo a NICENANO. Espera al reinicio y desconecta.
3. Repite en la izquierda con mr_robot_diagnostic_left.uf2.
4. Enciende ambas. Con la izquierda por USB, escribe una frase usando ambos lados. Después desconecta USB y repite por Bluetooth al mismo Mac, con las mismas aplicaciones y ubicación.
5. Indica si el retraso desaparece, sigue igual o empeora, y si ocurre por USB, Bluetooth o ambos.

Si desaparece con esta variante, la pantalla es un posible contribuyente; habrá que identificar el módulo y probar una cola dedicada antes de reactivarla. Si persiste solo por Bluetooth, el siguiente foco es el enlace al Mac (interferencia/negociación); no atribuirlo al enlace entre mitades sin más evidencia.

Para volver a la recuperación anterior, reinstala los dos mr_robot_recovery_*.uf2 de la ejecución https://github.com/cracknck/lily58-keyboard/actions/runs/41286500235 . No mezcles las variantes en la comparación.
