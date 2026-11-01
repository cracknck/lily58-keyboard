# Reconstrucción correspondiente a agosto de 2025

El primer intento de recuperación restauró parte de los archivos de agosto pero usó ZMK de 2026. Esta rama cambia también la base ZMK para aproximar el entorno de aquella fecha.

- Configuración y keymap: copias exactas de aaf942d99bf554f0458ccf6d9e21edf413e81512 (11 agosto 2025). El keymap tiene blob Git e78abb2cce724fed1e1d3eebe8ab66521dad5696 y coincide con el respaldado.
- ZMK: ccf20a1f5c1534a197d32279abbe0eaf651099d8, último commit que devuelve el historial oficial con fecha anterior al commit de configuración (10 agosto 2025).
- Manifest original: apuntaba a main; no guardaba el SHA que se compiló ni la fecha exacta del firmware instalado. Esta selección por fecha es una reconstrucción, no una prueba de identidad con el firmware instalado.
- Zephyr: rama v3.5.0+zmk-fixes que importaba ese ZMK. La rama importada aún puede haber cambiado respecto al día original.
- Entorno de compilación: zmkfirmware/zmk-build-arm:3.5-branch; flujo oficial de aquella revisión copiado localmente, con imagen de Zephyr 3.5 y sin caché para no reutilizar dependencias de 2026. La etiqueta de imagen no acredita el mismo compilador exacto del día original.
- Placa: nice_nano_v2. Este es el nombre correcto para ZMK de 2025; nice_nano//zmk pertenece al toolchain posterior y no se aplica a esta rama histórica.
- Pantallas: soporte OLED estándar; no nice!view. No se cambian pines físicos ni se puede confirmar el modelo de pantalla solo con el repositorio.
- RGB: desactivado, como en aaf942d99.

La restauración exacta de la configuración recupera también su elección de pantalla integrada desactivada; el repositorio no aporta código de pantalla personalizada. La compilación y su configuración efectiva deben revisarse. No se considera reparación física confirmada hasta probar ambos lados.

## Instalar

Descarga el artefacto firmware de una compilación correcta de esta rama y descomprime. Instala mr_robot_2025_right.uf2 en la derecha (USB, doble RESET, arrastrar a NICENANO). Espera al reinicio. Repite en la izquierda con mr_robot_2025_left.uf2. Usa ambos de la misma compilación.

No uses los mr_robot_diagnostic: esos desactivan las pantallas deliberadamente. No se incluye settings_reset ni se borran emparejamientos en esta prueba.
