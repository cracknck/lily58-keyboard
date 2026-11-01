# Archivos del 3 de junio de 2025

Referencia: 685666cf037481176df828855a39ff399ccf21c7, 3 de junio de 2025, 22:41:05 en Ciudad de México (4 junio 04:41:05 UTC).

config/lily58.conf y config/lily58.keymap permanecen exactamente como en ese commit. El keymap coincide con el respaldo: blob e78abb2cce724fed1e1d3eebe8ab66521dad5696.

ZMK se fija a 239baa487509ace108d36f0e5c627d61a3d95f53 y Zephyr a 489d3b00c49d1d3a0d4ec1f693fa0719db38bbf9, últimas revisiones devueltas por los historiales correspondientes anteriores a la fecha solicitada. El manifest antiguo seguía main y no conservaba el SHA compilado originalmente. La selección por fecha reconstruye una base histórica; no prueba identidad con el firmware instalado entonces.

El workflow de esa revisión usa una imagen Zephyr 3.5 (etiqueta 3.5-branch) y omite caché para evitar dependencias posteriores. Esa etiqueta de imagen no fija el compilador original exacto.

Esta configuración histórica tiene RGB habilitado, inicio RGB apagado y control de alimentación externa por defecto. No se han corregido ni alterado esos valores. Se está reproduciendo la versión solicitada; no se promete que resuelva el problema actual de pantallas.

## Descarga e instalación

En Actions de esta rama abre una ejecución correcta, baja a Artifacts y descarga firmware. Descomprime el ZIP. Contiene mr_robot_jun03_2025_left.uf2 y mr_robot_jun03_2025_right.uf2. No hace falta fusionar el PR.

Instala el archivo right en la mitad derecha y left en la izquierda: conecta USB, pulsa RESET dos veces y copia el UF2 a NICENANO. Espera a que reinicie. Usa ambos archivos de la misma compilación. No se incluye settings_reset.
