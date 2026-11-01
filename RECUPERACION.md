# Recuperación MR ROBOT — Lily58

Esta rama prepara una prueba de recuperación; no acredita todavía que las pantallas físicas funcionen.

## Referencia y cambios

- Referencia: [aaf942d99bf554f0458ccf6d9e21edf413e81512](https://github.com/cracknck/lily58-keyboard/tree/aaf942d99bf554f0458ccf6d9e21edf413e81512), 11 de agosto de 2025.
- Punto de partida conservado como ancestro: 6b4940db65ccadb177d6f47ec6cdcbac86d299bd. No se reescribe main ni se borra historial.
- Mapa de teclas restaurado exactamente a la referencia; elimina la desactivación de I2C y la selección forzada de nice_view del 1 de noviembre.
- Configuración restaurada desde la referencia, con adaptaciones para ZMK actual: pantalla integrada activada explícitamente, eliminación de WS2812_STRIP (opción retirada) y widgets de capa/salida elegidos por la pantalla integrada según el rol. WPM se activa solo en la izquierda/central; USB se desactiva explícitamente en la derecha/periférica. La referencia la desactivaba, pero no incluía implementación de pantalla personalizada; los widgets por sí solos no prueban que existiera una.
- RGB permanece desactivado como en la referencia. No se intenta resolver el RGB derecho en esta recuperación.
- Placa migrada de nice_nano_v2 a nice_nano//zmk, nombre actual para nice!nano v2. Solo se compilan lily58_left y lily58_right.
- ZMK y el flujo reutilizable se fijan al commit 4dd95d7840eb3d5a3f59bb29fbf1ab054715ef85, para evitar que main cambie el código entre compilaciones. La imagen de compilación stable y acciones transitivas todavía pueden cambiar.

## Qué sabemos de las pantallas

La referencia histórica NO configura nice_view ni nice_view_adapter; tampoco importa módulos adicionales: usa ZMK oficial. El shield Lily58 estándar selecciona OLED SSD1306 de 128×32 por I2C, dirección 0x3c. Por eso esta recuperación genera firmware para ese OLED.

El usuario confirma que ambas pantallas funcionaban antes de los cambios. No se ha confirmado que el firmware instalado entonces procediera de este commit. La foto de la conversación y su interpretación anterior no permiten confirmar modelo ni cableado; no se afirma que originalmente hubiera nice!view.

nice!view usa otra interfaz/controlador y requiere soporte SPI y conexiones compatibles. Si los módulos físicos resultan ser nice!view, este firmware OLED no los manejará; hará falta la configuración del fabricante o identificar el cableado antes de introducir otro adaptador o pin CS. Compilar correctamente no verifica compatibilidad física.

Fuentes:
- [Lily58: selección OLED y nodo SSD1306](https://github.com/zmkfirmware/zmk/blob/4dd95d7840eb3d5a3f59bb29fbf1ab054715ef85/app/boards/shields/lily58/lily58.dtsi)
- [Configuración de pantallas ZMK](https://zmk.dev/docs/config/displays)
- [Migración de nombres de placa](https://zmk.dev/blog/2025/12/09/zephyr-4-1)
- [Adaptador nice!view](https://github.com/zmkfirmware/zmk/tree/4dd95d7840eb3d5a3f59bb29fbf1ab054715ef85/app/boards/shields/nice_view_adapter)

## Instalar los dos archivos en macOS

1. En el PR de recuperación, abre una compilación correcta de Actions del último commit. Descarga el artefacto firmware y descomprime el ZIP. Usa ambos archivos de esa misma compilación:
   - mr_robot_recovery_left.uf2: mitad izquierda.
   - mr_robot_recovery_right.uf2: mitad derecha.
2. Conecta solo la mitad derecha al Mac con un cable USB de datos. Pulsa RESET dos veces rápidamente; debe aparecer una unidad como NICENANO. Arrastra mr_robot_recovery_right.uf2 a esa unidad. Espera a que se reinicie y desconecta.
3. Conecta la izquierda y repite el doble RESET. Arrastra mr_robot_recovery_left.uf2. Espera a que se reinicie.
4. Enciende ambas mitades. Comprueba escritura de ambos lados, conexión Bluetooth y las dos pantallas. Puedes probar primero por USB en la izquierda.

No hace falta fusionar el PR para usar sus artefactos. No uses settings_reset en la primera prueba: borra emparejamientos. Si no aparece la unidad, revisa el cable de datos y el doble RESET antes de cambiar firmware.

Si ambas pantallas siguen apagadas pero las teclas funcionan, la recuperación física sigue sin confirmarse. Conserva este resultado y busca el firmware original del fabricante/modelo de pantalla; no pruebes pines al azar.
