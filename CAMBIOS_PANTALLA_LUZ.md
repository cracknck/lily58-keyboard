# Perfil Bluetooth y luz independiente

Base: el usuario confirmó que ambos displays y ambas mitades funcionan con los UF2 KEEBD después de resetear ambos controladores. Se conservan el shield OLED Lily58 estándar y los ajustes KEEBD de display/Studio. Esta es una nueva compilación con ZMK fijado a 4dd95d7840eb3d5a3f59bb29fbf1ab054715ef85; no es una modificación binaria de los UF2 KEEBD.

## Keymap preservado

Archivo fuente: /Users/enriqueestrada/Desktop/MR_ROBOT_Studio.keymap. SHA256 original: 0eca7e5da1603a67e200cfe98a1e343e004b2f500abe3d558670c9af25686758.

Se conservan las 58 posiciones de Base y las 58 de Lower, incluidos los cinco perfiles BT. Solo se añade la inclusión de comportamientos necesaria para compilar y los nombres de capa. Capa es la última tecla de pulgar derecha. Capa + Z apaga la luz; capa + X la enciende. Esos accesos usan RGB_OFF/RGB_ON, no External Power.

## Pantalla izquierda

Muestra BT 1–5 usando directamente zmk_ble_active_profile_index() + 1 y el estado de conexión del perfil. Así conserva el número al pasar a un perfil desconectado o al alimentar el teclado por USB. Se actualiza con eventos de cambio de perfil y endpoint. Conserva batería y nombre de capa. La derecha conserva batería y estado del enlace entre mitades.

## Luz

Luz fija blanca, efecto sólido, brillo inicial 30 %. El controlador se llama RGB underglow, pero se configura sin animaciones. Se usa el mismo LED strip estándar del shield Lily58: no se inventan pines. RGB_UNDERGLOW_EXT_POWER=n evita que apagar la luz corte la alimentación del display. No hay enlaces ext_power en el keymap fuente.

## Instalar y conservar el mapa

Conserva como vuelta atrás los tres archivos KEEBD que funcionaron: reset y firmware izquierdo/derecho, de https://github.com/keebd/zmk-firmware/releases/tag/lily58-firmware . No se pide instalar reset de ajustes para esta actualización.

Instala mr_robot_profile_light_right.uf2 en la derecha y mr_robot_profile_light_left.uf2 en la izquierda (USB, doble RESET, copiar a NICENANO y esperar al reinicio).

Si has guardado cambios en ZMK Studio, estos pueden sustituir las asignaciones compiladas. Después de instalar, en Studio selecciona Restore Stock Settings para cargar el keymap incluido en ESTE firmware, que es tu mapa del Escritorio. Ese comando restablece las personalizaciones de Studio; no es el firmware settings_reset ni el borrado de emparejamientos Bluetooth. Evita copiar asignaciones External Power de mapas anteriores.

## Validación necesaria

Actions comprueba explícitamente que RGB está habilitado, que su control de alimentación está deshabilitado, y que display/Studio/cola dedicada están activos. Verifica además que el código de pantalla usa el perfil activo. La compilación no acredita la prueba física.

Prueba física: elegir perfiles 1–5 y verificar cada número en la izquierda; encender/apagar luz con capa+X/Z y comprobar que ambas pantallas mantienen alimentación; comprobar escritura USB/Bluetooth y ambas mitades. Los displays conservan su apagado normal por inactividad y deben despertar con las teclas, sin corte de alimentación por el control de luz.
