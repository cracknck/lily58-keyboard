/* SPDX-License-Identifier: MIT
 * Reuses the standard ZMK OLED battery/layer/peripheral widgets.
 * The left status reads the active BLE profile, never a fallback endpoint index.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <zephyr/kernel.h>
#include <lvgl.h>
#include <zmk/display.h>
#include <zmk/display/status_screen.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/display/widgets/layer_status.h>
#include <zmk/display/widgets/peripheral_status.h>

#if IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
#include <zmk/ble.h>
#include <zmk/event_manager.h>
#include <zmk/events/ble_active_profile_changed.h>
#include <zmk/events/endpoint_changed.h>

struct mr_robot_profile_state {
    uint8_t index;
    bool connected;
};

static lv_obj_t *profile_label;

static struct mr_robot_profile_state profile_get_state(const zmk_event_t *event) {
    return (struct mr_robot_profile_state){
        .index = zmk_ble_active_profile_index(),
        .connected = zmk_ble_active_profile_is_connected(),
    };
}

static void profile_update(struct mr_robot_profile_state state) {
    if (!profile_label) {
        return;
    }
    char text[24];
    snprintf(text, sizeof(text), "BT %u %s", (unsigned int)state.index + 1,
             state.connected ? LV_SYMBOL_OK : LV_SYMBOL_CLOSE);
    lv_label_set_text(profile_label, text);
}

ZMK_DISPLAY_WIDGET_LISTENER(mr_robot_profile, struct mr_robot_profile_state,
                           profile_update, profile_get_state)
ZMK_SUBSCRIPTION(mr_robot_profile, zmk_ble_active_profile_changed);
ZMK_SUBSCRIPTION(mr_robot_profile, zmk_endpoint_changed);
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_BATTERY_STATUS)
static struct zmk_widget_battery_status battery_widget;
#endif
#if IS_ENABLED(CONFIG_ZMK_WIDGET_LAYER_STATUS)
static struct zmk_widget_layer_status layer_widget;
#endif
#if IS_ENABLED(CONFIG_ZMK_WIDGET_PERIPHERAL_STATUS)
static struct zmk_widget_peripheral_status peripheral_widget;
#endif

lv_obj_t *zmk_display_status_screen(void) {
    lv_obj_t *screen = lv_obj_create(NULL);

#if IS_ENABLED(CONFIG_ZMK_WIDGET_BATTERY_STATUS)
    zmk_widget_battery_status_init(&battery_widget, screen);
    lv_obj_align(zmk_widget_battery_status_obj(&battery_widget), LV_ALIGN_TOP_RIGHT, 0, 0);
#endif

#if IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
    profile_label = lv_label_create(screen);
    lv_obj_align(profile_label, LV_ALIGN_TOP_LEFT, 0, 0);
    mr_robot_profile_init();
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_PERIPHERAL_STATUS)
    zmk_widget_peripheral_status_init(&peripheral_widget, screen);
    lv_obj_align(zmk_widget_peripheral_status_obj(&peripheral_widget), LV_ALIGN_TOP_LEFT, 0, 0);
#endif

#if IS_ENABLED(CONFIG_ZMK_WIDGET_LAYER_STATUS)
    zmk_widget_layer_status_init(&layer_widget, screen);
    lv_obj_set_style_text_font(zmk_widget_layer_status_obj(&layer_widget),
                              lv_theme_get_font_small(screen), LV_PART_MAIN);
    lv_obj_align(zmk_widget_layer_status_obj(&layer_widget), LV_ALIGN_BOTTOM_LEFT, 0, 0);
#endif

    return screen;
}
