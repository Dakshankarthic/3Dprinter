#include <string.h>

#include "actions.h"
#include "fonts.h"
#include "images.h"
#include "screens.h"
#include "styles.h"
#include "ui.h"
#include "vars.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_homescreen_neue_spule_button(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 2, 0, e);
  }
}

static void event_handler_cb_homescreen_trocknen_button(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 4, 0, e);
  }
}

static void event_handler_cb_homescreen_einstellungen_button_1(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 8, 0, e);
  }
}

static void
event_handler_cb_neue_spule_material_screen_trocknen_button_2(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 4, 0, e);
  }
}

static void
event_handler_cb_neue_spule_material_screen_home_button_1(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 8, 0, e);
  }
}

static void
event_handler_cb_neue_spule_material_screen_material_1(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 10, 0, e);
  }
}

static void
event_handler_cb_neue_spule_material_screen_material_4(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 12, 0, e);
  }
}

static void
event_handler_cb_neue_spule_material_screen_material_2(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 14, 0, e);
  }
}

static void
event_handler_cb_neue_spule_material_screen_material_3(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 16, 0, e);
  }
}

static void
event_handler_cb_neue_spule_material_screen_material_5(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 18, 0, e);
  }
}

static void
event_handler_cb_neue_spule_material_screen_material_6(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 20, 0, e);
  }
}

static void
event_handler_cb_neue_spule_material_screen_material_7(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 22, 0, e);
  }
}

static void
event_handler_cb_neue_spule_material_screen_material_8(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 24, 0, e);
  }
}

static void
event_handler_cb_neue_spule_material_screen_material_9(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 26, 0, e);
  }
}

static void
event_handler_cb_neue_spule_material_screen_material_10(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 28, 0, e);
  }
}

static void
event_handler_cb_neue_spule_material_screen_material_11(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 30, 0, e);
  }
}

static void
event_handler_cb_neue_spule_material_screen_material_12(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 32, 0, e);
  }
}

static void
event_handler_cb_neue_spule_hersteller_screen_neue_spule_button_hersteller(
    lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 2, 0, e);
  }
}

static void
event_handler_cb_neue_spule_hersteller_screen_trocknen_button_1(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 4, 0, e);
  }
}

static void
event_handler_cb_neue_spule_hersteller_screen_home_button(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 8, 0, e);
  }
}

static void
event_handler_cb_neue_spule_hersteller_screen_hersteller_1(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 10, 0, e);
  }
}

static void
event_handler_cb_neue_spule_hersteller_screen_hersteller_4(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 12, 0, e);
  }
}

static void
event_handler_cb_neue_spule_hersteller_screen_hersteller_2(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 14, 0, e);
  }
}

static void
event_handler_cb_neue_spule_hersteller_screen_hersteller_3(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 16, 0, e);
  }
}

static void
event_handler_cb_neue_spule_hersteller_screen_hersteller_5(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 18, 0, e);
  }
}

static void
event_handler_cb_neue_spule_hersteller_screen_hersteller_6(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 20, 0, e);
  }
}

static void
event_handler_cb_neue_spule_hersteller_screen_hersteller_7(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 22, 0, e);
  }
}

static void
event_handler_cb_neue_spule_hersteller_screen_hersteller_8(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 24, 0, e);
  }
}

static void
event_handler_cb_neue_spule_farbe_screen_neue_spule_button_hersteller_10(
    lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 2, 0, e);
  }
}

static void
event_handler_cb_neue_spule_farbe_screen_trocknen_button_12(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 4, 0, e);
  }
}

static void
event_handler_cb_neue_spule_farbe_screen_home_button_11(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 8, 0, e);
  }
}

static void event_handler_cb_neue_spule_farbe_screen_farbe_1(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 10, 0, e);
  }
}

static void event_handler_cb_neue_spule_farbe_screen_farbe_4(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 12, 0, e);
  }
}

static void event_handler_cb_neue_spule_farbe_screen_farbe_2(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 14, 0, e);
  }
}

static void event_handler_cb_neue_spule_farbe_screen_farbe_3(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 16, 0, e);
  }
}

static void event_handler_cb_neue_spule_farbe_screen_farbe_5(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 18, 0, e);
  }
}

static void event_handler_cb_neue_spule_farbe_screen_farbe_6(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 20, 0, e);
  }
}

static void event_handler_cb_neue_spule_farbe_screen_farbe_7(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 22, 0, e);
  }
}

static void event_handler_cb_neue_spule_farbe_screen_farbe_8(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 24, 0, e);
  }
}

static void event_handler_cb_neue_spule_farbe_screen_farbe_9(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 26, 0, e);
  }
}

static void event_handler_cb_neue_spule_farbe_screen_farbe_10(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 28, 0, e);
  }
}

static void event_handler_cb_neue_spule_farbe_screen_farbe_11(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 30, 0, e);
  }
}

static void event_handler_cb_neue_spule_farbe_screen_farbe_12(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 32, 0, e);
  }
}

static void event_handler_cb_trocknenscreen_neue_spule_button_1(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 2, 0, e);
  }
}

static void event_handler_cb_trocknenscreen_home_button_2(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 8, 0, e);
  }
}

static void
event_handler_cb_einstellungen_screen_neue_spule_button_hersteller_5(
    lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 2, 0, e);
  }
}

static void
event_handler_cb_einstellungen_screen_trocknen_button_7(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 4, 0, e);
  }
}

static void event_handler_cb_einstellungen_screen_home_button_6(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 6, 0, e);
  }
}

static void event_handler_cb_einstellungen_screen_wlan_button_1(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 8, 0, e);
  }
}

static void
event_handler_cb_einstellungen_screen_spulen_daten_button_1(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 10, 0, e);
  }
}

static void
event_handler_cb_einstellungen_screen_systemdaten_button_1(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 12, 0, e);
  }
}

static void
event_handler_cb_einstellungen_screen_zurueck_button_9(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 14, 0, e);
  }
}

static void
event_handler_cb_einstellungen_screen_systemdaten_button_2(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 22, 0, e);
  }
}

static void
event_handler_cb_einstellungen_screen_systemdaten_button_3(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 24, 0, e);
  }
}

static void
event_handler_cb_netzwerksuche_screen_neue_spule_button_hersteller_6(
    lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 2, 0, e);
  }
}

static void
event_handler_cb_netzwerksuche_screen_trocknen_button_8(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 4, 0, e);
  }
}

static void event_handler_cb_netzwerksuche_screen_home_button_7(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 6, 0, e);
  }
}

static void event_handler_cb_netzwerksuche_screen_zurueck_netzwerksuche_button(
    lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 10, 0, e);
  }
}

static void event_handler_cb_netzwerksuche_screen_obj0(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 12, 0, e);
  }
}

static void
event_handler_cb_netzwerksuche_screen_manuele_netzwerksuche_button_1(
    lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 15, 0, e);
  }
}

static void event_handler_cb_ssid_screen_abbruch_button_1(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 2, 0, e);
  }
}

static void
event_handler_cb_passworteingabe_screen_abbruch_button(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 2, 0, e);
  }
}

static void
event_handler_cb_system_screen_neue_spule_button_hersteller_7(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 2, 0, e);
  }
}

static void event_handler_cb_system_screen_trocknen_button_9(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 4, 0, e);
  }
}

static void event_handler_cb_system_screen_home_button_8(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 6, 0, e);
  }
}

static void event_handler_cb_system_screen_zurueck_button_7(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 12, 0, e);
  }
}

static void event_handler_cb_spulen_daten_screen_neue_spule_button_hersteller_8(
    lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 2, 0, e);
  }
}

static void
event_handler_cb_spulen_daten_screen_trocknen_button_10(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 4, 0, e);
  }
}

static void event_handler_cb_spulen_daten_screen_home_button_9(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 6, 0, e);
  }
}

static void
event_handler_cb_spulen_daten_screen_zurueck_button_3(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 14, 0, e);
  }
}

static void
event_handler_cb_system_farben_preset_neue_spule_button_hersteller_9(
    lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 2, 0, e);
  }
}

static void
event_handler_cb_system_farben_preset_trocknen_button_11(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 4, 0, e);
  }
}

static void
event_handler_cb_system_farben_preset_home_button_10(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 6, 0, e);
  }
}

static void
event_handler_cb_system_farben_preset_zurueck_button_8(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 8, 0, e);
  }
}

static void event_handler_cb_system_farben_preset_farbe_13(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 14, 0, e);
  }
}

static void event_handler_cb_system_farben_preset_farbe_15(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 16, 0, e);
  }
}

static void event_handler_cb_system_farben_preset_farbe_17(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 18, 0, e);
  }
}

static void event_handler_cb_system_farben_preset_farbe_19(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 20, 0, e);
  }
}

static void event_handler_cb_system_farben_preset_farbe_21(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 22, 0, e);
  }
}

static void event_handler_cb_system_farben_preset_farbe_23(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 24, 0, e);
  }
}

static void event_handler_cb_system_farben_preset_farbe_25(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 26, 0, e);
  }
}

static void event_handler_cb_system_farben_preset_farbe_27(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 28, 0, e);
  }
}

static void event_handler_cb_system_farben_preset_farbe_29(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 30, 0, e);
  }
}

static void event_handler_cb_system_farben_preset_farbe_31(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 32, 0, e);
  }
}

static void event_handler_cb_system_farben_preset_farbe_33(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 34, 0, e);
  }
}

static void event_handler_cb_system_farben_preset_farbe_35(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 36, 0, e);
  }
}

static void
event_handler_cb_system_hersteller_preset_neue_spule_button_hersteller_11(
    lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 2, 0, e);
  }
}

static void
event_handler_cb_system_hersteller_preset_trocknen_button_13(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 4, 0, e);
  }
}

static void
event_handler_cb_system_hersteller_preset_home_button_12(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 6, 0, e);
  }
}

static void
event_handler_cb_system_hersteller_preset_zurueck_button_10(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 8, 0, e);
  }
}

static void
event_handler_cb_system_hersteller_preset_hersteller_9(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 14, 0, e);
  }
}

static void
event_handler_cb_system_hersteller_preset_hersteller_11(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 16, 0, e);
  }
}

static void
event_handler_cb_system_hersteller_preset_hersteller_13(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 18, 0, e);
  }
}

static void
event_handler_cb_system_hersteller_preset_hersteller_17(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 20, 0, e);
  }
}

static void
event_handler_cb_system_hersteller_preset_hersteller_20(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 22, 0, e);
  }
}

static void
event_handler_cb_system_hersteller_preset_hersteller_22(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 24, 0, e);
  }
}

static void
event_handler_cb_system_hersteller_preset_hersteller_24(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 26, 0, e);
  }
}

static void
event_handler_cb_system_hersteller_preset_hersteller_26(lv_event_t *e) {
  lv_event_code_t event = lv_event_get_code(e);
  void *flowState = lv_event_get_user_data(e);
  (void)flowState;

  if (event == LV_EVENT_PRESSED) {
    e->user_data = (void *)0;
    flowPropagateValueLVGLEvent(flowState, 28, 0, e);
  }
}

void create_screen_homescreen() {
  void *flowState = getFlowState(0, 0);
  (void)flowState;
  lv_obj_t *obj = lv_obj_create(0);
  objects.homescreen = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 480, 320);
  {
    lv_obj_t *parent_obj = obj;
    {
      // FilaTrack
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.fila_track = obj;
      lv_obj_set_pos(obj, 119, 7);
      lv_obj_set_size(obj, 354, 68);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3dbcfd),
                                LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_32,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "FilaTrack");
    }
    {
      // Neue_SpuleButton
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.neue_spule_button = obj;
      lv_obj_set_pos(obj, 5, 80);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(obj, event_handler_cb_homescreen_neue_spule_button,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // NeueSpule
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.neue_spule = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Neue Spule");
        }
      }
    }
    {
      // Trocknen_Button
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.trocknen_button = obj;
      lv_obj_set_pos(obj, 6, 173);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(obj, event_handler_cb_homescreen_trocknen_button,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Trocknen_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.trocknen_text = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Trocknen");
        }
      }
    }
    {
      // ON/OFF_Button
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.on_off_button = obj;
      lv_obj_set_pos(obj, 6, 261);
      lv_obj_set_size(obj, 50, 50);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // ON/OFF_Bild
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.on_off_bild = obj;
      lv_obj_set_pos(obj, 9, 262);
      lv_obj_set_size(obj, 46, 49);
      lv_img_set_src(obj, &img_anoff);
      lv_img_set_zoom(obj, 190);
    }
    {
      // Einstellungen_Button_1
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.einstellungen_button_1 = obj;
      lv_obj_set_pos(obj, 62, 261);
      lv_obj_set_size(obj, 50, 50);
      lv_obj_add_event_cb(obj,
                          event_handler_cb_homescreen_einstellungen_button_1,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // Einstellungen_Bild
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.einstellungen_bild = obj;
      lv_obj_set_pos(obj, 63, 262);
      lv_obj_set_size(obj, 49, 50);
      lv_img_set_src(obj, &img_einstellungen);
      lv_img_set_zoom(obj, 190);
    }
    {
      // Filamentanzeige
      lv_obj_t *obj = lv_bar_create(parent_obj);
      objects.filamentanzeige = obj;
      lv_obj_set_pos(obj, 119, 261);
      lv_obj_set_size(obj, 300, 51);
      lv_bar_set_value(obj, 75, LV_ANIM_OFF);
      lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe7e2e2),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 3,
                                    LV_PART_INDICATOR | LV_STATE_DEFAULT);
    }
    {
      // Rest_Filament
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.rest_filament = obj;
      lv_obj_set_pos(obj, 119, 210);
      lv_obj_set_size(obj, 177, 29);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_22,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Rest Filament");
    }
    {
      // Gewicht
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.gewicht = obj;
      lv_obj_set_pos(obj, 291, 206);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_28,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_RIGHT,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "750g / 1000g");
    }
    {
      // Trocknungszeitanzeige_Bild
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknungszeitanzeige_bild = obj;
      lv_obj_set_pos(obj, 420, 255);
      lv_obj_set_size(obj, 60, 60);
      lv_img_set_src(obj, &img_zeit);
      lv_img_set_zoom(obj, 180);
    }
    {
      // Trocknungszeit_Zeit
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.trocknungszeit_zeit = obj;
      lv_obj_set_pos(obj, 441, 283);
      lv_obj_set_size(obj, 39, 19);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_14,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "0,25h");
    }
    {
      // Hersteller+Material
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.hersteller_material = obj;
      lv_obj_set_pos(obj, 119, 120);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_28,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Prusament PC-Blend");
    }
    {
      // Farbe
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.farbe = obj;
      lv_obj_set_pos(obj, 119, 155);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_24,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_LEFT,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Galaxy Black");
    }
    {
      // Verbindung
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.verbindung = obj;
      lv_obj_set_pos(obj, 250, 80);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Verbunden");
    }
    {
      // Datum
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.datum = obj;
      lv_obj_set_pos(obj, 393, 80);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "17.03.2025");
    }
    {
      // Trocknen_Bild_13
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknen_bild_13 = obj;
      lv_obj_set_pos(obj, 26, 180);
      lv_obj_set_size(obj, 47, 33);
      lv_img_set_src(obj, &img_trocknen_);
      lv_img_set_zoom(obj, 250);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj1 = obj;
      lv_obj_set_pos(obj, 47, 107);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj2 = obj;
      lv_obj_set_pos(obj, 55, 99);
      lv_obj_set_size(obj, 6, 22);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_img_create(parent_obj);
      lv_obj_set_pos(obj, 11, 7);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_img_set_src(obj, &img_logo);
    }
  }

  tick_screen_homescreen();
}

void tick_screen_homescreen() {
  void *flowState = getFlowState(0, 0);
  (void)flowState;
}

void create_screen_neue_spule_material_screen() {
  void *flowState = getFlowState(0, 1);
  (void)flowState;
  lv_obj_t *obj = lv_obj_create(0);
  objects.neue_spule_material_screen = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 480, 320);
  {
    lv_obj_t *parent_obj = obj;
    {
      // Material_Überschrift
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.material__berschrift = obj;
      lv_obj_set_pos(obj, 119, 7);
      lv_obj_set_size(obj, 354, 68);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3dbcfd),
                                LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_32,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Material");
    }
    {
      // Neue_SpuleButton_Hersteller_1
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.neue_spule_button_hersteller_1 = obj;
      lv_obj_set_pos(obj, 5, 80);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // NeueSpule_2
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.neue_spule_2 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Neue Spule");
        }
      }
    }
    {
      // Trocknen_Button_2
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.trocknen_button_2 = obj;
      lv_obj_set_pos(obj, 6, 173);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_material_screen_trocknen_button_2,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Trocknen_Text_2
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.trocknen_text_2 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Trocknen");
        }
      }
    }
    {
      // Filamentanzeige_2
      lv_obj_t *obj = lv_bar_create(parent_obj);
      objects.filamentanzeige_2 = obj;
      lv_obj_set_pos(obj, 119, 261);
      lv_obj_set_size(obj, 300, 51);
      lv_bar_set_value(obj, 75, LV_ANIM_OFF);
      lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe7e2e2),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 3,
                                    LV_PART_INDICATOR | LV_STATE_DEFAULT);
    }
    {
      // Trocknungszeitanzeige_Bild_2
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknungszeitanzeige_bild_2 = obj;
      lv_obj_set_pos(obj, 420, 255);
      lv_obj_set_size(obj, 60, 60);
      lv_img_set_src(obj, &img_zeit);
      lv_img_set_zoom(obj, 180);
    }
    {
      // Home_Button_1
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.home_button_1 = obj;
      lv_obj_set_pos(obj, 6, 262);
      lv_obj_set_size(obj, 106, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_material_screen_home_button_1,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Home_Text_1
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.home_text_1 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Home");
        }
      }
    }
    {
      // Material_1
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.material_1 = obj;
      lv_obj_set_pos(obj, 119, 84);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_material_screen_material_1,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Material_1_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.material_1_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "PLA");
        }
      }
    }
    {
      // Material_4
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.material_4 = obj;
      lv_obj_set_pos(obj, 390, 84);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_material_screen_material_4,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Material_4_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.material_4_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "ABS");
        }
      }
    }
    {
      // Material_2
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.material_2 = obj;
      lv_obj_set_pos(obj, 209, 85);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_material_screen_material_2,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Material_2_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.material_2_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "PLA-CF");
        }
      }
    }
    {
      // Material_3
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.material_3 = obj;
      lv_obj_set_pos(obj, 300, 85);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_material_screen_material_3,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Material_3_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.material_3_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "PLA+");
        }
      }
    }
    {
      // Material_5
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.material_5 = obj;
      lv_obj_set_pos(obj, 119, 144);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_material_screen_material_5,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Material_5_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.material_5_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "PETG");
        }
      }
    }
    {
      // Material_6
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.material_6 = obj;
      lv_obj_set_pos(obj, 209, 144);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_material_screen_material_6,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Material_6_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.material_6_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "PETG-CF");
        }
      }
    }
    {
      // Material_7
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.material_7 = obj;
      lv_obj_set_pos(obj, 300, 144);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_material_screen_material_7,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Material_7_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.material_7_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "PC-Blend");
        }
      }
    }
    {
      // Material_8
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.material_8 = obj;
      lv_obj_set_pos(obj, 390, 144);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_material_screen_material_8,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Material_8_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.material_8_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "ASA");
        }
      }
    }
    {
      // Material_9
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.material_9 = obj;
      lv_obj_set_pos(obj, 119, 203);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_material_screen_material_9,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Material_9_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.material_9_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "TPU");
        }
      }
    }
    {
      // Material_10
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.material_10 = obj;
      lv_obj_set_pos(obj, 209, 203);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_material_screen_material_10,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Material_10_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.material_10_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "PA6");
        }
      }
    }
    {
      // Material_11
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.material_11 = obj;
      lv_obj_set_pos(obj, 300, 203);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_material_screen_material_11,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Material_11_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.material_11_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "PA12");
        }
      }
    }
    {
      // Material_12
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.material_12 = obj;
      lv_obj_set_pos(obj, 390, 203);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_material_screen_material_12,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Material_12_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.material_12_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Andere");
        }
      }
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj3 = obj;
      lv_obj_set_pos(obj, 47, 107);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj4 = obj;
      lv_obj_set_pos(obj, 55, 99);
      lv_obj_set_size(obj, 6, 22);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_img_create(parent_obj);
      lv_obj_set_pos(obj, 11, 7);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_img_set_src(obj, &img_logo);
    }
    {
      // Trocknen_Bild_14
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknen_bild_14 = obj;
      lv_obj_set_pos(obj, 26, 180);
      lv_obj_set_size(obj, 47, 33);
      lv_img_set_src(obj, &img_trocknen_);
      lv_img_set_zoom(obj, 250);
    }
    {
      // Trocknungszeit_Zeit_2
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.trocknungszeit_zeit_2 = obj;
      lv_obj_set_pos(obj, 441, 283);
      lv_obj_set_size(obj, 39, 19);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_14,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "0,25h");
    }
  }

  tick_screen_neue_spule_material_screen();
}

void tick_screen_neue_spule_material_screen() {
  void *flowState = getFlowState(0, 1);
  (void)flowState;
}

void create_screen_neue_spule_hersteller_screen() {
  void *flowState = getFlowState(0, 2);
  (void)flowState;
  lv_obj_t *obj = lv_obj_create(0);
  objects.neue_spule_hersteller_screen = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 480, 320);
  {
    lv_obj_t *parent_obj = obj;
    {
      // Hersteller_Überschrift
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.hersteller__berschrift = obj;
      lv_obj_set_pos(obj, 119, 7);
      lv_obj_set_size(obj, 354, 68);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3dbcfd),
                                LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_32,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Hersteller");
    }
    {
      // Neue_SpuleButton_Hersteller
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.neue_spule_button_hersteller = obj;
      lv_obj_set_pos(obj, 5, 80);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj,
          event_handler_cb_neue_spule_hersteller_screen_neue_spule_button_hersteller,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // NeueSpule_1
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.neue_spule_1 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Neue Spule");
        }
      }
    }
    {
      // Trocknen_Button_1
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.trocknen_button_1 = obj;
      lv_obj_set_pos(obj, 6, 173);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_hersteller_screen_trocknen_button_1,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Trocknen_Text_1
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.trocknen_text_1 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Trocknen");
        }
      }
    }
    {
      // Filamentanzeige_1
      lv_obj_t *obj = lv_bar_create(parent_obj);
      objects.filamentanzeige_1 = obj;
      lv_obj_set_pos(obj, 119, 261);
      lv_obj_set_size(obj, 300, 51);
      lv_bar_set_value(obj, 75, LV_ANIM_OFF);
      lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe7e2e2),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 3,
                                    LV_PART_INDICATOR | LV_STATE_DEFAULT);
    }
    {
      // Trocknungszeitanzeige_Bild_1
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknungszeitanzeige_bild_1 = obj;
      lv_obj_set_pos(obj, 420, 255);
      lv_obj_set_size(obj, 60, 60);
      lv_img_set_src(obj, &img_zeit);
      lv_img_set_zoom(obj, 180);
    }
    {
      // Home_Button
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.home_button = obj;
      lv_obj_set_pos(obj, 6, 262);
      lv_obj_set_size(obj, 106, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_hersteller_screen_home_button,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Home_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.home_text = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Home");
        }
      }
    }
    {
      // Hersteller_1
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_1 = obj;
      lv_obj_set_pos(obj, 119, 80);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_hersteller_screen_hersteller_1,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_1_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_1_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Prusa");
        }
      }
    }
    {
      // Hersteller_4
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_4 = obj;
      lv_obj_set_pos(obj, 390, 80);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_hersteller_screen_hersteller_4,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_4_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_4_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Polymaker");
        }
      }
    }
    {
      // Hersteller_2
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_2 = obj;
      lv_obj_set_pos(obj, 209, 80);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_hersteller_screen_hersteller_2,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_2_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_2_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Bambulab");
        }
      }
    }
    {
      // Hersteller_3
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_3 = obj;
      lv_obj_set_pos(obj, 299, 80);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_hersteller_screen_hersteller_3,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_3_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_3_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "eSun");
        }
      }
    }
    {
      // Hersteller_5
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_5 = obj;
      lv_obj_set_pos(obj, 119, 136);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_hersteller_screen_hersteller_5,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_5_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_5_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Extrudr");
        }
      }
    }
    {
      // Hersteller_6
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_6 = obj;
      lv_obj_set_pos(obj, 209, 136);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_hersteller_screen_hersteller_6,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_6_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_6_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Nobofil");
        }
      }
    }
    {
      // Hersteller_7
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_7 = obj;
      lv_obj_set_pos(obj, 299, 136);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_hersteller_screen_hersteller_7,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_7_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_7_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Sunlu");
        }
      }
    }
    {
      // Hersteller_8
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_8 = obj;
      lv_obj_set_pos(obj, 390, 136);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_hersteller_screen_hersteller_8,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_8_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_8_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Andere");
        }
      }
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj5 = obj;
      lv_obj_set_pos(obj, 47, 107);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj6 = obj;
      lv_obj_set_pos(obj, 55, 99);
      lv_obj_set_size(obj, 6, 22);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_img_create(parent_obj);
      lv_obj_set_pos(obj, 11, 7);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_img_set_src(obj, &img_logo);
    }
    {
      // Trocknung_Temperaturannzeige_3
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.trocknung_temperaturannzeige_3 = obj;
      lv_obj_set_pos(obj, 263, 208);
      lv_obj_set_size(obj, 67, 33);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_20,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "1000g");
    }
    {
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.obj7 = obj;
      lv_obj_set_pos(obj, 212, 206);
      lv_obj_set_size(obj, 41, 35);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xfff5f5f5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.obj8 = obj;
      lv_obj_set_pos(obj, 339, 206);
      lv_obj_set_size(obj, 41, 35);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xfff5f5f5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj9 = obj;
      lv_obj_set_pos(obj, 357, 213);
      lv_obj_set_size(obj, 6, 22);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj10 = obj;
      lv_obj_set_pos(obj, 349, 221);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj11 = obj;
      lv_obj_set_pos(obj, 222, 221);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // Kalibrirung_Preeset_8
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.kalibrirung_preeset_8 = obj;
      lv_obj_set_pos(obj, 390, 192);
      lv_obj_set_size(obj, 80, 28);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Kalibrirung_Preeset_4
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.kalibrirung_preeset_4 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "1000g");
        }
      }
    }
    {
      // Kalibrirung_Preeset_9
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.kalibrirung_preeset_9 = obj;
      lv_obj_set_pos(obj, 390, 227);
      lv_obj_set_size(obj, 80, 28);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2196f3),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Kalibrirung_Preeset_6
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.kalibrirung_preeset_6 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "500g");
        }
      }
    }
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      lv_obj_set_pos(obj, 119, 212);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_20,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Gewicht");
    }
    {
      // Trocknen_Bild_15
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknen_bild_15 = obj;
      lv_obj_set_pos(obj, 26, 180);
      lv_obj_set_size(obj, 47, 33);
      lv_img_set_src(obj, &img_trocknen_);
      lv_img_set_zoom(obj, 250);
    }
    {
      // Trocknungszeit_Zeit_1
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.trocknungszeit_zeit_1 = obj;
      lv_obj_set_pos(obj, 441, 283);
      lv_obj_set_size(obj, 39, 19);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_14,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "0,25h");
    }
  }

  tick_screen_neue_spule_hersteller_screen();
}

void tick_screen_neue_spule_hersteller_screen() {
  void *flowState = getFlowState(0, 2);
  (void)flowState;
}

void create_screen_neue_spule_farbe_screen() {
  void *flowState = getFlowState(0, 3);
  (void)flowState;
  lv_obj_t *obj = lv_obj_create(0);
  objects.neue_spule_farbe_screen = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 480, 320);
  {
    lv_obj_t *parent_obj = obj;
    {
      // Farbe_Überschrift
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.farbe__berschrift = obj;
      lv_obj_set_pos(obj, 119, 7);
      lv_obj_set_size(obj, 354, 68);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3dbcfd),
                                LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_32,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Farbe");
    }
    {
      // Neue_SpuleButton_Hersteller_10
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.neue_spule_button_hersteller_10 = obj;
      lv_obj_set_pos(obj, 5, 80);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj,
          event_handler_cb_neue_spule_farbe_screen_neue_spule_button_hersteller_10,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // NeueSpule_12
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.neue_spule_12 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Neue Spule");
        }
      }
    }
    {
      // Trocknen_Button_12
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.trocknen_button_12 = obj;
      lv_obj_set_pos(obj, 6, 173);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_farbe_screen_trocknen_button_12,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Trocknen_Text_12
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.trocknen_text_12 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Trocknen");
        }
      }
    }
    {
      // Filamentanzeige_4
      lv_obj_t *obj = lv_bar_create(parent_obj);
      objects.filamentanzeige_4 = obj;
      lv_obj_set_pos(obj, 119, 261);
      lv_obj_set_size(obj, 300, 51);
      lv_bar_set_value(obj, 75, LV_ANIM_OFF);
      lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe7e2e2),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 3,
                                    LV_PART_INDICATOR | LV_STATE_DEFAULT);
    }
    {
      // Trocknungszeitanzeige_Bild_4
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknungszeitanzeige_bild_4 = obj;
      lv_obj_set_pos(obj, 420, 255);
      lv_obj_set_size(obj, 60, 60);
      lv_img_set_src(obj, &img_zeit);
      lv_img_set_zoom(obj, 180);
    }
    {
      // Home_Button_11
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.home_button_11 = obj;
      lv_obj_set_pos(obj, 6, 262);
      lv_obj_set_size(obj, 106, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_neue_spule_farbe_screen_home_button_11,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Home_Text_11
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.home_text_11 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Home");
        }
      }
    }
    {
      // Farbe_1
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_1 = obj;
      lv_obj_set_pos(obj, 119, 84);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_neue_spule_farbe_screen_farbe_1,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_1_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_1_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Schwarz");
        }
      }
    }
    {
      // Farbe_4
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_4 = obj;
      lv_obj_set_pos(obj, 390, 84);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_neue_spule_farbe_screen_farbe_4,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_4_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_4_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Blau");
        }
      }
    }
    {
      // Farbe_2
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_2 = obj;
      lv_obj_set_pos(obj, 209, 85);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_neue_spule_farbe_screen_farbe_2,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_2_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_2_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Weiss");
        }
      }
    }
    {
      // Farbe_3
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_3 = obj;
      lv_obj_set_pos(obj, 300, 85);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_neue_spule_farbe_screen_farbe_3,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_3_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_3_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Rot");
        }
      }
    }
    {
      // Farbe_5
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_5 = obj;
      lv_obj_set_pos(obj, 119, 144);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_neue_spule_farbe_screen_farbe_5,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_5_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_5_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Gruen");
        }
      }
    }
    {
      // Farbe_6
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_6 = obj;
      lv_obj_set_pos(obj, 209, 144);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_neue_spule_farbe_screen_farbe_6,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_6_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_6_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Gelb");
        }
      }
    }
    {
      // Farbe_7
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_7 = obj;
      lv_obj_set_pos(obj, 300, 144);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_neue_spule_farbe_screen_farbe_7,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_7_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_7_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Orange");
        }
      }
    }
    {
      // Farbe_8
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_8 = obj;
      lv_obj_set_pos(obj, 390, 144);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_neue_spule_farbe_screen_farbe_8,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_8_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_8_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Grau");
        }
      }
    }
    {
      // Farbe_9
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_9 = obj;
      lv_obj_set_pos(obj, 119, 203);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_neue_spule_farbe_screen_farbe_9,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_9_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_9_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Tuerkis");
        }
      }
    }
    {
      // Farbe_10
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_10 = obj;
      lv_obj_set_pos(obj, 209, 203);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj,
                          event_handler_cb_neue_spule_farbe_screen_farbe_10,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_10_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_10_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Gold");
        }
      }
    }
    {
      // Farbe_11
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_11 = obj;
      lv_obj_set_pos(obj, 300, 203);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj,
                          event_handler_cb_neue_spule_farbe_screen_farbe_11,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_11_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_11_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Silber");
        }
      }
    }
    {
      // Farbe_12
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_12 = obj;
      lv_obj_set_pos(obj, 390, 203);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj,
                          event_handler_cb_neue_spule_farbe_screen_farbe_12,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_12_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_12_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Andere");
        }
      }
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj12 = obj;
      lv_obj_set_pos(obj, 47, 107);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj13 = obj;
      lv_obj_set_pos(obj, 55, 99);
      lv_obj_set_size(obj, 6, 22);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_img_create(parent_obj);
      lv_obj_set_pos(obj, 11, 7);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_img_set_src(obj, &img_logo);
    }
    {
      // Trocknen_Bild_16
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknen_bild_16 = obj;
      lv_obj_set_pos(obj, 26, 180);
      lv_obj_set_size(obj, 47, 33);
      lv_img_set_src(obj, &img_trocknen_);
      lv_img_set_zoom(obj, 250);
    }
    {
      // Trocknungszeit_Zeit_4
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.trocknungszeit_zeit_4 = obj;
      lv_obj_set_pos(obj, 441, 283);
      lv_obj_set_size(obj, 39, 19);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_14,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "0,25h");
    }
  }

  tick_screen_neue_spule_farbe_screen();
}

void tick_screen_neue_spule_farbe_screen() {
  void *flowState = getFlowState(0, 3);
  (void)flowState;
}

void create_screen_trocknenscreen() {
  void *flowState = getFlowState(0, 4);
  (void)flowState;
  lv_obj_t *obj = lv_obj_create(0);
  objects.trocknenscreen = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 480, 320);
  {
    lv_obj_t *parent_obj = obj;
    {
      // FilaTrack_1
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.fila_track_1 = obj;
      lv_obj_set_pos(obj, 119, 7);
      lv_obj_set_size(obj, 354, 68);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3dbcfd),
                                LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_32,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "FilaTrack");
    }
    {
      // Neue_SpuleButton_1
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.neue_spule_button_1 = obj;
      lv_obj_set_pos(obj, 5, 80);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(obj,
                          event_handler_cb_trocknenscreen_neue_spule_button_1,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // NeueSpule_3
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.neue_spule_3 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Neue Spule");
        }
      }
    }
    {
      // Trocknen_Button_3
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.trocknen_button_3 = obj;
      lv_obj_set_pos(obj, 6, 173);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Trocknen_Text_3
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.trocknen_text_3 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Trocknen");
        }
      }
    }
    {
      // Filamentanzeige_3
      lv_obj_t *obj = lv_bar_create(parent_obj);
      objects.filamentanzeige_3 = obj;
      lv_obj_set_pos(obj, 119, 261);
      lv_obj_set_size(obj, 300, 51);
      lv_bar_set_value(obj, 75, LV_ANIM_OFF);
      lv_obj_set_style_border_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe7e2e2),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 3,
                                    LV_PART_INDICATOR | LV_STATE_DEFAULT);
    }
    {
      // Trocknungszeitanzeige_Bild_3
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknungszeitanzeige_bild_3 = obj;
      lv_obj_set_pos(obj, 420, 255);
      lv_obj_set_size(obj, 60, 60);
      lv_img_set_src(obj, &img_zeit);
      lv_img_set_zoom(obj, 180);
    }
    {
      // Home_Button_2
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.home_button_2 = obj;
      lv_obj_set_pos(obj, 6, 262);
      lv_obj_set_size(obj, 106, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_trocknenscreen_home_button_2,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Home_Text_2
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.home_text_2 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Home");
        }
      }
    }
    {
      // Trocknung_Preeset_1
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.trocknung_preeset_1 = obj;
      lv_obj_set_pos(obj, 119, 84);
      lv_obj_set_size(obj, 83, 36);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Trocknung_Preeset_1_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.trocknung_preeset_1_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "PLA");
        }
      }
    }
    {
      // Trocknung_Preeset_2
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.trocknung_preeset_2 = obj;
      lv_obj_set_pos(obj, 209, 85);
      lv_obj_set_size(obj, 83, 35);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_14
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_14 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "PETG");
        }
      }
    }
    {
      // Trocknung_Preeset_3
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.trocknung_preeset_3 = obj;
      lv_obj_set_pos(obj, 300, 85);
      lv_obj_set_size(obj, 83, 35);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_16
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_16 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "ABS/ASA");
        }
      }
    }
    {
      // Trocknung_Preeset_4
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.trocknung_preeset_4 = obj;
      lv_obj_set_pos(obj, 390, 84);
      lv_obj_set_size(obj, 83, 36);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_18
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_18 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "TPU");
        }
      }
    }
    {
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.obj14 = obj;
      lv_obj_set_pos(obj, 133, 178);
      lv_obj_set_size(obj, 45, 35);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xfff5f5f5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // Trocknung_Temperaturannzeige
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.trocknung_temperaturannzeige = obj;
      lv_obj_set_pos(obj, 213, 126);
      lv_obj_set_size(obj, 65, 33);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_26,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "65C°");
    }
    {
      // Trocknung_Stundenanzeige
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.trocknung_stundenanzeige = obj;
      lv_obj_set_pos(obj, 184, 178);
      lv_obj_set_size(obj, 38, 33);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_26,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "5h");
    }
    {
      // Trocknung_Minutenanzeige
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.trocknung_minutenanzeige = obj;
      lv_obj_set_pos(obj, 224, 178);
      lv_obj_set_size(obj, 90, 33);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_26,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "45min");
    }
    {
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.obj15 = obj;
      lv_obj_set_pos(obj, 319, 178);
      lv_obj_set_size(obj, 45, 35);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xfff5f5f5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.obj16 = obj;
      lv_obj_set_pos(obj, 319, 125);
      lv_obj_set_size(obj, 45, 35);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xfff5f5f5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_switch_create(parent_obj);
      objects.obj17 = obj;
      lv_obj_set_pos(obj, 400, 181);
      lv_obj_set_size(obj, 55, 28);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffdf1e21),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff489e45),
                                LV_PART_INDICATOR | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff489e45),
                                LV_PART_INDICATOR | LV_STATE_PRESSED);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff489e45),
                                LV_PART_INDICATOR | LV_STATE_CHECKED |
                                    LV_STATE_PRESSED);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff489e45),
                                LV_PART_INDICATOR | LV_STATE_CHECKED);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_KNOB | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    }
    {
      // Temperaturannzeige_1
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.temperaturannzeige_1 = obj;
      lv_obj_set_pos(obj, 390, 142);
      lv_obj_set_size(obj, 75, 33);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_22,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Auto");
    }
    {
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.obj18 = obj;
      lv_obj_set_pos(obj, 133, 126);
      lv_obj_set_size(obj, 45, 35);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xfff5f5f5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // Start_button_9
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.start_button_9 = obj;
      lv_obj_set_pos(obj, 121, 224);
      lv_obj_set_size(obj, 171, 31);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_24,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Start_button_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.start_button_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_22,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Start");
        }
      }
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj19 = obj;
      lv_obj_set_pos(obj, 143, 140);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj20 = obj;
      lv_obj_set_pos(obj, 47, 106);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj21 = obj;
      lv_obj_set_pos(obj, 55, 98);
      lv_obj_set_size(obj, 6, 22);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj22 = obj;
      lv_obj_set_pos(obj, 339, 133);
      lv_obj_set_size(obj, 6, 22);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj23 = obj;
      lv_obj_set_pos(obj, 331, 141);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj24 = obj;
      lv_obj_set_pos(obj, 339, 185);
      lv_obj_set_size(obj, 6, 22);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj25 = obj;
      lv_obj_set_pos(obj, 331, 193);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj26 = obj;
      lv_obj_set_pos(obj, 143, 193);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_img_create(parent_obj);
      lv_obj_set_pos(obj, 11, 7);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_img_set_src(obj, &img_logo);
    }
    {
      // Trocknen_Bild_17
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknen_bild_17 = obj;
      lv_obj_set_pos(obj, 26, 180);
      lv_obj_set_size(obj, 47, 33);
      lv_img_set_src(obj, &img_trocknen_);
      lv_img_set_zoom(obj, 250);
    }
    {
      // Trocknungszeit_Zeit_3
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.trocknungszeit_zeit_3 = obj;
      lv_obj_set_pos(obj, 441, 283);
      lv_obj_set_size(obj, 39, 19);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_14,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "0,25h");
    }
    {
      // Start_button_10
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.start_button_10 = obj;
      lv_obj_set_pos(obj, 300, 224);
      lv_obj_set_size(obj, 173, 31);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_24,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Start_button_Text_1
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.start_button_text_1 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_22,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Stopp");
        }
      }
    }
  }

  tick_screen_trocknenscreen();
}

void tick_screen_trocknenscreen() {
  void *flowState = getFlowState(0, 4);
  (void)flowState;
}

void create_screen_einstellungen_screen() {
  void *flowState = getFlowState(0, 5);
  (void)flowState;
  lv_obj_t *obj = lv_obj_create(0);
  objects.einstellungen_screen = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 480, 320);
  {
    lv_obj_t *parent_obj = obj;
    {
      // Einstellungen_Überschrift_1
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.einstellungen__berschrift_1 = obj;
      lv_obj_set_pos(obj, 119, 7);
      lv_obj_set_size(obj, 354, 68);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3dbcfd),
                                LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_32,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Einnstellungen");
    }
    {
      // Neue_SpuleButton_Hersteller_5
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.neue_spule_button_hersteller_5 = obj;
      lv_obj_set_pos(obj, 5, 80);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj,
          event_handler_cb_einstellungen_screen_neue_spule_button_hersteller_5,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // NeueSpule_7
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.neue_spule_7 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Neue Spule");
        }
      }
    }
    {
      // Trocknen_Button_7
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.trocknen_button_7 = obj;
      lv_obj_set_pos(obj, 6, 173);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj, event_handler_cb_einstellungen_screen_trocknen_button_7,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Trocknen_Text_7
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.trocknen_text_7 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Trocknen");
        }
      }
    }
    {
      // Home_Button_6
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.home_button_6 = obj;
      lv_obj_set_pos(obj, 6, 262);
      lv_obj_set_size(obj, 106, 50);
      lv_obj_add_event_cb(obj,
                          event_handler_cb_einstellungen_screen_home_button_6,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Home_Text_6
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.home_text_6 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Home");
        }
      }
    }
    {
      // Wlan_Button_1
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.wlan_button_1 = obj;
      lv_obj_set_pos(obj, 119, 84);
      lv_obj_set_size(obj, 354, 32);
      lv_obj_add_event_cb(obj,
                          event_handler_cb_einstellungen_screen_wlan_button_1,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Wlan_Button_Text_1
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.wlan_button_text_1 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Wifi");
        }
      }
    }
    {
      // SpulenDaten_Button_1
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.spulen_daten_button_1 = obj;
      lv_obj_set_pos(obj, 119, 120);
      lv_obj_set_size(obj, 354, 32);
      lv_obj_add_event_cb(
          obj, event_handler_cb_einstellungen_screen_spulen_daten_button_1,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Kalibrirung_Button_Text_1
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.kalibrirung_button_text_1 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Spulendaten");
        }
      }
    }
    {
      // Systemdaten_Button_1
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.systemdaten_button_1 = obj;
      lv_obj_set_pos(obj, 119, 156);
      lv_obj_set_size(obj, 354, 32);
      lv_obj_add_event_cb(
          obj, event_handler_cb_einstellungen_screen_systemdaten_button_1,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Systemdaten_Button_Text_1
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.systemdaten_button_text_1 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Systemdaten");
        }
      }
    }
    {
      // Zurueck_button_9
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.zurueck_button_9 = obj;
      lv_obj_set_pos(obj, 152, 270);
      lv_obj_set_size(obj, 144, 34);
      lv_obj_add_event_cb(
          obj, event_handler_cb_einstellungen_screen_zurueck_button_9,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_20,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Zurueck_button_Text_9
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.zurueck_button_text_9 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Zurueck");
        }
      }
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj27 = obj;
      lv_obj_set_pos(obj, 47, 107);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj28 = obj;
      lv_obj_set_pos(obj, 55, 99);
      lv_obj_set_size(obj, 6, 22);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // Softwareversion_Text
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.softwareversion_text = obj;
      lv_obj_set_pos(obj, 423, 276);
      lv_obj_set_size(obj, 57, 29);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_20,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "V1.0");
    }
    {
      // Controler_Text
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.controler_text = obj;
      lv_obj_set_pos(obj, 324, 276);
      lv_obj_set_size(obj, 99, 29);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_20,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "ESP32 S3");
    }
    {
      lv_obj_t *obj = lv_img_create(parent_obj);
      lv_obj_set_pos(obj, 11, 7);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_img_set_src(obj, &img_logo);
    }
    {
      // Trocknen_Bild_18
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknen_bild_18 = obj;
      lv_obj_set_pos(obj, 26, 180);
      lv_obj_set_size(obj, 47, 33);
      lv_img_set_src(obj, &img_trocknen_);
      lv_img_set_zoom(obj, 250);
    }
    {
      // Systemdaten_Button_2
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.systemdaten_button_2 = obj;
      lv_obj_set_pos(obj, 119, 192);
      lv_obj_set_size(obj, 354, 32);
      lv_obj_add_event_cb(
          obj, event_handler_cb_einstellungen_screen_systemdaten_button_2,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbauswahl_Button_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbauswahl_button_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Farbauswahl");
        }
      }
    }
    {
      // Systemdaten_Button_3
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.systemdaten_button_3 = obj;
      lv_obj_set_pos(obj, 119, 229);
      lv_obj_set_size(obj, 354, 32);
      lv_obj_add_event_cb(
          obj, event_handler_cb_einstellungen_screen_systemdaten_button_3,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Systemdaten_Button_Text_3
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.systemdaten_button_text_3 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Herstellerauswahl");
        }
      }
    }
  }

  tick_screen_einstellungen_screen();
}

void tick_screen_einstellungen_screen() {
  void *flowState = getFlowState(0, 5);
  (void)flowState;
}

void create_screen_netzwerksuche_screen() {
  void *flowState = getFlowState(0, 6);
  (void)flowState;
  lv_obj_t *obj = lv_obj_create(0);
  objects.netzwerksuche_screen = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 480, 320);
  {
    lv_obj_t *parent_obj = obj;
    {
      // Einstellungen_Überschrift_2
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.einstellungen__berschrift_2 = obj;
      lv_obj_set_pos(obj, 119, 7);
      lv_obj_set_size(obj, 354, 68);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3dbcfd),
                                LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_32,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Einnstellungen");
    }
    {
      // Neue_SpuleButton_Hersteller_6
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.neue_spule_button_hersteller_6 = obj;
      lv_obj_set_pos(obj, 5, 80);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj,
          event_handler_cb_netzwerksuche_screen_neue_spule_button_hersteller_6,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // NeueSpule_8
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.neue_spule_8 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Neue Spule");
        }
      }
    }
    {
      // Trocknen_Button_8
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.trocknen_button_8 = obj;
      lv_obj_set_pos(obj, 6, 173);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj, event_handler_cb_netzwerksuche_screen_trocknen_button_8,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Trocknen_Text_8
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.trocknen_text_8 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Trocknen");
        }
      }
    }
    {
      // Home_Button_7
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.home_button_7 = obj;
      lv_obj_set_pos(obj, 6, 262);
      lv_obj_set_size(obj, 106, 50);
      lv_obj_add_event_cb(obj,
                          event_handler_cb_netzwerksuche_screen_home_button_7,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Home_Text_7
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.home_text_7 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Home");
        }
      }
    }
    {
      // Erneute_Netzwerksuche_button
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.erneute_netzwerksuche_button = obj;
      lv_obj_set_pos(obj, 362, 80);
      lv_obj_set_size(obj, 115, 28);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Erneute_Netzwerksuche_button_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.erneute_netzwerksuche_button_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Erneut Suchen");
        }
      }
    }
    {
      // Zurueck_Netzwerksuche_button
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.zurueck_netzwerksuche_button = obj;
      lv_obj_set_pos(obj, 120, 80);
      lv_obj_set_size(obj, 115, 28);
      lv_obj_add_event_cb(
          obj,
          event_handler_cb_netzwerksuche_screen_zurueck_netzwerksuche_button,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Zurueck_Netzwerksuche_button_Text
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.zurueck_netzwerksuche_button_text = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Zurueck");
        }
      }
    }
    {
      lv_obj_t *obj = lv_list_create(parent_obj);
      objects.obj0 = obj;
      lv_obj_set_pos(obj, 120, 113);
      lv_obj_set_size(obj, 353, 199);
      lv_obj_add_event_cb(obj, event_handler_cb_netzwerksuche_screen_obj0,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_ON);
      lv_obj_set_scroll_dir(obj, LV_DIR_VER);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj29 = obj;
      lv_obj_set_pos(obj, 47, 107);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj30 = obj;
      lv_obj_set_pos(obj, 55, 99);
      lv_obj_set_size(obj, 6, 22);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // Manuele_Netzwerksuche_button_1
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.manuele_netzwerksuche_button_1 = obj;
      lv_obj_set_pos(obj, 240, 80);
      lv_obj_set_size(obj, 115, 28);
      lv_obj_add_event_cb(
          obj,
          event_handler_cb_netzwerksuche_screen_manuele_netzwerksuche_button_1,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Zurueck_Netzwerksuche_button_Text_1
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.zurueck_netzwerksuche_button_text_1 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Manuel");
        }
      }
    }
    {
      lv_obj_t *obj = lv_img_create(parent_obj);
      lv_obj_set_pos(obj, 11, 7);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_img_set_src(obj, &img_logo);
    }
    {
      // Trocknen_Bild_19
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknen_bild_19 = obj;
      lv_obj_set_pos(obj, 26, 180);
      lv_obj_set_size(obj, 47, 33);
      lv_img_set_src(obj, &img_trocknen_);
      lv_img_set_zoom(obj, 250);
    }
  }

  tick_screen_netzwerksuche_screen();
}

void tick_screen_netzwerksuche_screen() {
  void *flowState = getFlowState(0, 6);
  (void)flowState;
}

void create_screen_ssid_screen() {
  void *flowState = getFlowState(0, 7);
  (void)flowState;
  lv_obj_t *obj = lv_obj_create(0);
  objects.ssid_screen = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 480, 320);
  {
    lv_obj_t *parent_obj = obj;
    {
      lv_obj_t *obj = lv_keyboard_create(parent_obj);
      lv_obj_set_pos(obj, 0, 81);
      lv_obj_set_size(obj, 480, 239);
      lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT,
                             LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // Abbruch_Button_1
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.abbruch_button_1 = obj;
      lv_obj_set_pos(obj, 5, 261);
      lv_obj_set_size(obj, 64, 51);
      lv_obj_add_event_cb(obj, event_handler_cb_ssid_screen_abbruch_button_1,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe0e0e0),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.obj31 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xffbb3939),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Abbr.");
        }
      }
    }
    {
      // SSID_Überschrift_1
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.ssid__berschrift_1 = obj;
      lv_obj_set_pos(obj, 5, 25);
      lv_obj_set_size(obj, 151, 55);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_26,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Name:");
    }
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.ssid_label = obj;
      lv_obj_set_pos(obj, 156, 25);
      lv_obj_set_size(obj, 300, 56);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_26,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "");
    }
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.wifi_status_label = obj;
      lv_obj_set_pos(obj, 120, 5);
      lv_obj_set_size(obj, 350, 30);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_14,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "");
    }
  }

  tick_screen_ssid_screen();
}

void tick_screen_ssid_screen() {
  void *flowState = getFlowState(0, 7);
  (void)flowState;
}

void create_screen_passworteingabe_screen() {
  void *flowState = getFlowState(0, 8);
  (void)flowState;
  lv_obj_t *obj = lv_obj_create(0);
  objects.passworteingabe_screen = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 480, 320);
  {
    lv_obj_t *parent_obj = obj;
    {
      lv_obj_t *obj = lv_keyboard_create(parent_obj);
      lv_obj_set_pos(obj, 0, 81);
      lv_obj_set_size(obj, 480, 239);
      lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT,
                             LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // Abbruch_Button
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.abbruch_button = obj;
      lv_obj_set_pos(obj, 5, 261);
      lv_obj_set_size(obj, 64, 51);
      lv_obj_add_event_cb(
          obj, event_handler_cb_passworteingabe_screen_abbruch_button,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffe0e0e0),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.obj32 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xffbb3939),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Abbr.");
        }
      }
    }
    {
      // Passworteingabe_Überschrift
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.passworteingabe__berschrift = obj;
      lv_obj_set_pos(obj, 5, 25);
      lv_obj_set_size(obj, 151, 55);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_26,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Passwort:");
    }
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.password_label = obj;
      lv_obj_set_pos(obj, 156, 25);
      lv_obj_set_size(obj, 300, 56);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_26,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "");
    }
  }

  tick_screen_passworteingabe_screen();
}

void tick_screen_passworteingabe_screen() {
  void *flowState = getFlowState(0, 8);
  (void)flowState;
}

void create_screen_system_screen() {
  void *flowState = getFlowState(0, 9);
  (void)flowState;
  lv_obj_t *obj = lv_obj_create(0);
  objects.system_screen = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 480, 320);
  {
    lv_obj_t *parent_obj = obj;
    {
      // Einstellungen_Überschrift_3
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.einstellungen__berschrift_3 = obj;
      lv_obj_set_pos(obj, 119, 7);
      lv_obj_set_size(obj, 354, 68);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3dbcfd),
                                LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_32,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Einstellungen");
    }
    {
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.ip_label = obj;
      lv_obj_set_pos(obj, 120, 245);
      lv_obj_set_size(obj, 350, 25);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_14,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "IP: 0.0.0.0");
    }
    {
      // Neue_SpuleButton_Hersteller_7
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.neue_spule_button_hersteller_7 = obj;
      lv_obj_set_pos(obj, 5, 80);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj, event_handler_cb_system_screen_neue_spule_button_hersteller_7,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // NeueSpule_9
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.neue_spule_9 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Neue Spule");
        }
      }
    }
    {
      // Trocknen_Button_9
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.trocknen_button_9 = obj;
      lv_obj_set_pos(obj, 6, 173);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(obj, event_handler_cb_system_screen_trocknen_button_9,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Trocknen_Text_9
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.trocknen_text_9 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Trocknen");
        }
      }
    }
    {
      // Home_Button_8
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.home_button_8 = obj;
      lv_obj_set_pos(obj, 6, 262);
      lv_obj_set_size(obj, 106, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_system_screen_home_button_8,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Home_Text_8
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.home_text_8 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Home");
        }
      }
    }
    {
      // Hx711_abfrage_Text
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.hx711_abfrage_text = obj;
      lv_obj_set_pos(obj, 188, 192);
      lv_obj_set_size(obj, 121, 29);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_20,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "HX711:");
    }
    {
      // Rfid_abfrage_Text
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.rfid_abfrage_text = obj;
      lv_obj_set_pos(obj, 188, 102);
      lv_obj_set_size(obj, 95, 29);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_20,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Rfid:");
    }
    {
      // ePaper_abfrage_Text
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.e_paper_abfrage_text = obj;
      lv_obj_set_pos(obj, 188, 130);
      lv_obj_set_size(obj, 147, 29);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_20,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "ePaper:");
    }
    {
      // Heizelement_abfrage_Text
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.heizelement_abfrage_text = obj;
      lv_obj_set_pos(obj, 188, 159);
      lv_obj_set_size(obj, 147, 29);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_20,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Heizelement:");
    }
    {
      // Zurueck_button_7
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.zurueck_button_7 = obj;
      lv_obj_set_pos(obj, 241, 270);
      lv_obj_set_size(obj, 109, 34);
      lv_obj_add_event_cb(obj, event_handler_cb_system_screen_zurueck_button_7,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_20,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Zurueck_button_Text_7
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.zurueck_button_text_7 = obj;
          lv_obj_set_pos(obj, 0, -1);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Zurueck");
        }
      }
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj33 = obj;
      lv_obj_set_pos(obj, 47, 107);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj34 = obj;
      lv_obj_set_pos(obj, 55, 99);
      lv_obj_set_size(obj, 6, 22);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // RFID
      lv_obj_t *obj = lv_led_create(parent_obj);
      objects.rfid = obj;
      lv_obj_set_pos(obj, 374, 100);
      lv_obj_set_size(obj, 20, 20);
      lv_led_set_color(obj, lv_color_hex(0xff275722));
      lv_led_set_brightness(obj, 255);
      lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // ePaper
      lv_obj_t *obj = lv_led_create(parent_obj);
      objects.e_paper = obj;
      lv_obj_set_pos(obj, 374, 130);
      lv_obj_set_size(obj, 20, 20);
      lv_led_set_color(obj, lv_color_hex(0xff275722));
      lv_led_set_brightness(obj, 255);
      lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // HX711
      lv_obj_t *obj = lv_led_create(parent_obj);
      objects.hx711 = obj;
      lv_obj_set_pos(obj, 374, 190);
      lv_obj_set_size(obj, 20, 20);
      lv_led_set_color(obj, lv_color_hex(0xff275722));
      lv_led_set_brightness(obj, 255);
      lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      // Heizelement
      lv_obj_t *obj = lv_led_create(parent_obj);
      objects.heizelement = obj;
      lv_obj_set_pos(obj, 374, 160);
      lv_obj_set_size(obj, 20, 20);
      lv_led_set_color(obj, lv_color_hex(0xff275722));
      lv_led_set_brightness(obj, 255);
      lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_img_create(parent_obj);
      lv_obj_set_pos(obj, 11, 7);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_img_set_src(obj, &img_logo);
    }
    {
      // Trocknen_Bild_20
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknen_bild_20 = obj;
      lv_obj_set_pos(obj, 26, 180);
      lv_obj_set_size(obj, 47, 33);
      lv_img_set_src(obj, &img_trocknen_);
      lv_img_set_zoom(obj, 250);
    }
  }

  tick_screen_system_screen();
}

void tick_screen_system_screen() {
  void *flowState = getFlowState(0, 9);
  (void)flowState;
}

void create_screen_spulen_daten_screen() {
  void *flowState = getFlowState(0, 10);
  (void)flowState;
  lv_obj_t *obj = lv_obj_create(0);
  objects.spulen_daten_screen = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 480, 320);
  {
    lv_obj_t *parent_obj = obj;
    {
      // Spulen_Daten_Überschrift
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.spulen_daten__berschrift = obj;
      lv_obj_set_pos(obj, 119, 7);
      lv_obj_set_size(obj, 354, 68);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3dbcfd),
                                LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_32,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Spulen Daten");
    }
    {
      // Neue_SpuleButton_Hersteller_8
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.neue_spule_button_hersteller_8 = obj;
      lv_obj_set_pos(obj, 5, 80);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj,
          event_handler_cb_spulen_daten_screen_neue_spule_button_hersteller_8,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // NeueSpule_10
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.neue_spule_10 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Neue Spule");
        }
      }
    }
    {
      // Trocknen_Button_10
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.trocknen_button_10 = obj;
      lv_obj_set_pos(obj, 6, 173);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj, event_handler_cb_spulen_daten_screen_trocknen_button_10,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Trocknen_Text_10
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.trocknen_text_10 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Trocknen");
        }
      }
    }
    {
      // Home_Button_9
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.home_button_9 = obj;
      lv_obj_set_pos(obj, 6, 262);
      lv_obj_set_size(obj, 106, 50);
      lv_obj_add_event_cb(obj,
                          event_handler_cb_spulen_daten_screen_home_button_9,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Home_Text_9
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.home_text_9 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Home");
        }
      }
    }
    {
      // Spulen_Daten_Hersteller_Material_Farbe_1
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.spulen_daten_hersteller_material_farbe_1 = obj;
      lv_obj_set_pos(obj, 119, 93);
      lv_obj_set_size(obj, 354, 27);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Polymaker PETG-CF Schwarz");
    }
    {
      // Spulen_Daten_Gewicht_1
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.spulen_daten_gewicht_1 = obj;
      lv_obj_set_pos(obj, 119, 120);
      lv_obj_set_size(obj, 354, 27);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "458g / 1000g");
    }
    {
      // Spulen_Daten_Hersteller_Material_Farbe_2
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.spulen_daten_hersteller_material_farbe_2 = obj;
      lv_obj_set_pos(obj, 119, 160);
      lv_obj_set_size(obj, 354, 27);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Nobofil PC-Blend Silky Silver");
    }
    {
      // Spulen_Daten_Gewicht_2
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.spulen_daten_gewicht_2 = obj;
      lv_obj_set_pos(obj, 119, 186);
      lv_obj_set_size(obj, 354, 27);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "654g / 800g");
    }
    {
      // Spulen_Daten_Hersteller_Material_Farbe_3
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.spulen_daten_hersteller_material_farbe_3 = obj;
      lv_obj_set_pos(obj, 119, 224);
      lv_obj_set_size(obj, 354, 27);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "eSun PLA Weiss");
    }
    {
      // Spulen_Daten_Gewicht_3
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.spulen_daten_gewicht_3 = obj;
      lv_obj_set_pos(obj, 119, 251);
      lv_obj_set_size(obj, 354, 27);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "60g / 1000g");
    }
    {
      // Zurueck_button_3
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.zurueck_button_3 = obj;
      lv_obj_set_pos(obj, 224, 278);
      lv_obj_set_size(obj, 144, 34);
      lv_obj_add_event_cb(obj,
                          event_handler_cb_spulen_daten_screen_zurueck_button_3,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_20,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Zurueck_button_Text_3
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.zurueck_button_text_3 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Zurueck");
        }
      }
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj35 = obj;
      lv_obj_set_pos(obj, 47, 107);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj36 = obj;
      lv_obj_set_pos(obj, 55, 99);
      lv_obj_set_size(obj, 6, 22);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_img_create(parent_obj);
      lv_obj_set_pos(obj, 11, 7);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_img_set_src(obj, &img_logo);
    }
    {
      // Trocknen_Bild_21
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknen_bild_21 = obj;
      lv_obj_set_pos(obj, 26, 180);
      lv_obj_set_size(obj, 47, 33);
      lv_img_set_src(obj, &img_trocknen_);
      lv_img_set_zoom(obj, 250);
    }
  }

  tick_screen_spulen_daten_screen();
}

void tick_screen_spulen_daten_screen() {
  void *flowState = getFlowState(0, 10);
  (void)flowState;
}

void create_screen_system_farben_preset() {
  void *flowState = getFlowState(0, 11);
  (void)flowState;
  lv_obj_t *obj = lv_obj_create(0);
  objects.system_farben_preset = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 480, 320);
  {
    lv_obj_t *parent_obj = obj;
    {
      // Einstellungen_Überschrift_4
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.einstellungen__berschrift_4 = obj;
      lv_obj_set_pos(obj, 119, 7);
      lv_obj_set_size(obj, 354, 68);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3dbcfd),
                                LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_32,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Farbenauswahl");
    }
    {
      // Neue_SpuleButton_Hersteller_9
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.neue_spule_button_hersteller_9 = obj;
      lv_obj_set_pos(obj, 5, 80);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj,
          event_handler_cb_system_farben_preset_neue_spule_button_hersteller_9,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // NeueSpule_11
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.neue_spule_11 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Neue Spule");
        }
      }
    }
    {
      // Trocknen_Button_11
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.trocknen_button_11 = obj;
      lv_obj_set_pos(obj, 6, 173);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj, event_handler_cb_system_farben_preset_trocknen_button_11,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Trocknen_Text_11
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.trocknen_text_11 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Trocknen");
        }
      }
    }
    {
      // Home_Button_10
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.home_button_10 = obj;
      lv_obj_set_pos(obj, 6, 262);
      lv_obj_set_size(obj, 106, 50);
      lv_obj_add_event_cb(obj,
                          event_handler_cb_system_farben_preset_home_button_10,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Home_Text_10
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.home_text_10 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Home");
        }
      }
    }
    {
      // Zurueck_button_8
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.zurueck_button_8 = obj;
      lv_obj_set_pos(obj, 241, 270);
      lv_obj_set_size(obj, 109, 34);
      lv_obj_add_event_cb(
          obj, event_handler_cb_system_farben_preset_zurueck_button_8,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_20,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Zurueck_button_Text_8
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.zurueck_button_text_8 = obj;
          lv_obj_set_pos(obj, 0, -1);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Zurueck");
        }
      }
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj37 = obj;
      lv_obj_set_pos(obj, 47, 107);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj38 = obj;
      lv_obj_set_pos(obj, 55, 99);
      lv_obj_set_size(obj, 6, 22);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_img_create(parent_obj);
      lv_obj_set_pos(obj, 11, 7);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_img_set_src(obj, &img_logo);
    }
    {
      // Trocknen_Bild_22
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknen_bild_22 = obj;
      lv_obj_set_pos(obj, 26, 180);
      lv_obj_set_size(obj, 47, 33);
      lv_img_set_src(obj, &img_trocknen_);
      lv_img_set_zoom(obj, 250);
    }
    {
      // Farbe_13
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_13 = obj;
      lv_obj_set_pos(obj, 119, 84);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_system_farben_preset_farbe_13,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_14
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_14 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Schwarz");
        }
      }
    }
    {
      // Farbe_15
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_15 = obj;
      lv_obj_set_pos(obj, 390, 84);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_system_farben_preset_farbe_15,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_16
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_16 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Blau");
        }
      }
    }
    {
      // Farbe_17
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_17 = obj;
      lv_obj_set_pos(obj, 209, 85);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_system_farben_preset_farbe_17,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_18
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_18 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Weiss");
        }
      }
    }
    {
      // Farbe_19
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_19 = obj;
      lv_obj_set_pos(obj, 300, 85);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_system_farben_preset_farbe_19,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_20
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_20 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Rot");
        }
      }
    }
    {
      // Farbe_21
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_21 = obj;
      lv_obj_set_pos(obj, 119, 144);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_system_farben_preset_farbe_21,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_22
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_22 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Gruen");
        }
      }
    }
    {
      // Farbe_23
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_23 = obj;
      lv_obj_set_pos(obj, 209, 144);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_system_farben_preset_farbe_23,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_24
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_24 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Gelb");
        }
      }
    }
    {
      // Farbe_25
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_25 = obj;
      lv_obj_set_pos(obj, 300, 144);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_system_farben_preset_farbe_25,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_26
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_26 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Orange");
        }
      }
    }
    {
      // Farbe_27
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_27 = obj;
      lv_obj_set_pos(obj, 390, 144);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_system_farben_preset_farbe_27,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_28
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_28 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Grau");
        }
      }
    }
    {
      // Farbe_29
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_29 = obj;
      lv_obj_set_pos(obj, 119, 203);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_system_farben_preset_farbe_29,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_30
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_30 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Tuerkis");
        }
      }
    }
    {
      // Farbe_31
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_31 = obj;
      lv_obj_set_pos(obj, 209, 203);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_system_farben_preset_farbe_31,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_32
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_32 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Gold");
        }
      }
    }
    {
      // Farbe_33
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_33 = obj;
      lv_obj_set_pos(obj, 300, 203);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_system_farben_preset_farbe_33,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_34
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_34 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Silber");
        }
      }
    }
    {
      // Farbe_35
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.farbe_35 = obj;
      lv_obj_set_pos(obj, 390, 203);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(obj, event_handler_cb_system_farben_preset_farbe_35,
                          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Farbe_36
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.farbe_36 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Andere");
        }
      }
    }
  }

  tick_screen_system_farben_preset();
}

void tick_screen_system_farben_preset() {
  void *flowState = getFlowState(0, 11);
  (void)flowState;
}

void create_screen_system_hersteller_preset() {
  void *flowState = getFlowState(0, 12);
  (void)flowState;
  lv_obj_t *obj = lv_obj_create(0);
  objects.system_hersteller_preset = obj;
  lv_obj_set_pos(obj, 0, 0);
  lv_obj_set_size(obj, 480, 320);
  {
    lv_obj_t *parent_obj = obj;
    {
      // HerstellerPreset_Überschrift
      lv_obj_t *obj = lv_label_create(parent_obj);
      objects.hersteller_preset__berschrift = obj;
      lv_obj_set_pos(obj, 119, 7);
      lv_obj_set_size(obj, 354, 68);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff3dbcfd),
                                LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_EDITED);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_32,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xfff5f5f5),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_label_set_text(obj, "Herstellerauswahl");
    }
    {
      // Neue_SpuleButton_Hersteller_11
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.neue_spule_button_hersteller_11 = obj;
      lv_obj_set_pos(obj, 5, 80);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj,
          event_handler_cb_system_hersteller_preset_neue_spule_button_hersteller_11,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // NeueSpule_13
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.neue_spule_13 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Neue Spule");
        }
      }
    }
    {
      // Trocknen_Button_13
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.trocknen_button_13 = obj;
      lv_obj_set_pos(obj, 6, 173);
      lv_obj_set_size(obj, 106, 80);
      lv_obj_add_event_cb(
          obj, event_handler_cb_system_hersteller_preset_trocknen_button_13,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, -25, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Trocknen_Text_13
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.trocknen_text_13 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Trocknen");
        }
      }
    }
    {
      // Home_Button_12
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.home_button_12 = obj;
      lv_obj_set_pos(obj, 6, 262);
      lv_obj_set_size(obj, 106, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_system_hersteller_preset_home_button_12,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff5f5f5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_bottom(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_pad_top(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Home_Text_12
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.home_text_12 = obj;
          lv_obj_set_pos(obj, 0, 6);
          lv_obj_set_size(obj, 94, 24);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_16,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_pad_bottom(obj, -10,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER,
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Home");
        }
      }
    }
    {
      // Zurueck_button_10
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.zurueck_button_10 = obj;
      lv_obj_set_pos(obj, 241, 270);
      lv_obj_set_size(obj, 109, 34);
      lv_obj_add_event_cb(
          obj, event_handler_cb_system_hersteller_preset_zurueck_button_10,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_font(obj, &lv_font_montserrat_20,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Zurueck_button_Text_10
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.zurueck_button_text_10 = obj;
          lv_obj_set_pos(obj, 0, -1);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_font(obj, &lv_font_montserrat_18,
                                     LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Zurueck");
        }
      }
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj39 = obj;
      lv_obj_set_pos(obj, 47, 107);
      lv_obj_set_size(obj, 22, 6);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_obj_create(parent_obj);
      objects.obj40 = obj;
      lv_obj_set_pos(obj, 55, 99);
      lv_obj_set_size(obj, 6, 22);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xff2d70a5),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff2d70a5),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    {
      lv_obj_t *obj = lv_img_create(parent_obj);
      lv_obj_set_pos(obj, 11, 7);
      lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
      lv_img_set_src(obj, &img_logo);
    }
    {
      // Trocknen_Bild_23
      lv_obj_t *obj = lv_img_create(parent_obj);
      objects.trocknen_bild_23 = obj;
      lv_obj_set_pos(obj, 26, 180);
      lv_obj_set_size(obj, 47, 33);
      lv_img_set_src(obj, &img_trocknen_);
      lv_img_set_zoom(obj, 250);
    }
    {
      // Hersteller_9
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_9 = obj;
      lv_obj_set_pos(obj, 119, 80);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_system_hersteller_preset_hersteller_9,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_10
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_10 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Prusa");
        }
      }
    }
    {
      // Hersteller_11
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_11 = obj;
      lv_obj_set_pos(obj, 390, 80);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_system_hersteller_preset_hersteller_11,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_12
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_12 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Polymaker");
        }
      }
    }
    {
      // Hersteller_13
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_13 = obj;
      lv_obj_set_pos(obj, 209, 80);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_system_hersteller_preset_hersteller_13,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_15
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_15 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Bambulab");
        }
      }
    }
    {
      // Hersteller_17
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_17 = obj;
      lv_obj_set_pos(obj, 299, 80);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_system_hersteller_preset_hersteller_17,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_radius(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_19
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_19 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "eSun");
        }
      }
    }
    {
      // Hersteller_20
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_20 = obj;
      lv_obj_set_pos(obj, 119, 136);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_system_hersteller_preset_hersteller_20,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_21
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_21 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Extrudr");
        }
      }
    }
    {
      // Hersteller_22
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_22 = obj;
      lv_obj_set_pos(obj, 209, 136);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_system_hersteller_preset_hersteller_22,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_23
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_23 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Nobofil");
        }
      }
    }
    {
      // Hersteller_24
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_24 = obj;
      lv_obj_set_pos(obj, 299, 136);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_system_hersteller_preset_hersteller_24,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_25
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_25 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Sunlu");
        }
      }
    }
    {
      // Hersteller_26
      lv_obj_t *obj = lv_btn_create(parent_obj);
      objects.hersteller_26 = obj;
      lv_obj_set_pos(obj, 390, 136);
      lv_obj_set_size(obj, 83, 50);
      lv_obj_add_event_cb(
          obj, event_handler_cb_system_hersteller_preset_hersteller_26,
          LV_EVENT_ALL, flowState);
      lv_obj_set_style_radius(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_color(obj, lv_color_hex(0xff000000),
                                    LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
      lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
      {
        lv_obj_t *parent_obj = obj;
        {
          // Hersteller_27
          lv_obj_t *obj = lv_label_create(parent_obj);
          objects.hersteller_27 = obj;
          lv_obj_set_pos(obj, 0, 0);
          lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
          lv_obj_set_style_align(obj, LV_ALIGN_CENTER,
                                 LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000),
                                      LV_PART_MAIN | LV_STATE_DEFAULT);
          lv_label_set_text(obj, "Andere");
        }
      }
    }
  }

  tick_screen_system_hersteller_preset();
}

void tick_screen_system_hersteller_preset() {
  void *flowState = getFlowState(0, 12);
  (void)flowState;
}

static const char *screen_names[] = {"Homescreen",
                                     "Neue_Spule_Material_Screen",
                                     "Neue_Spule_Hersteller_Screen",
                                     "Neue_Spule_Farbe_Screen",
                                     "Trocknenscreen",
                                     "Einstellungen_Screen",
                                     "Netzwerksuche_Screen",
                                     "SSID_Screen",
                                     "Passworteingabe_Screen",
                                     "System_Screen",
                                     "Spulen_Daten_Screen",
                                     "System_FarbenPreset",
                                     "System_HerstellerPreset"};
static const char *object_names[] = {"homescreen",
                                     "neue_spule_material_screen",
                                     "neue_spule_hersteller_screen",
                                     "neue_spule_farbe_screen",
                                     "trocknenscreen",
                                     "einstellungen_screen",
                                     "netzwerksuche_screen",
                                     "ssid_screen",
                                     "passworteingabe_screen",
                                     "system_screen",
                                     "spulen_daten_screen",
                                     "system_farben_preset",
                                     "system_hersteller_preset",
                                     "neue_spule_button",
                                     "trocknen_button",
                                     "einstellungen_button_1",
                                     "trocknen_button_2",
                                     "home_button_1",
                                     "material_1",
                                     "material_4",
                                     "material_2",
                                     "material_3",
                                     "material_5",
                                     "material_6",
                                     "material_7",
                                     "material_8",
                                     "material_9",
                                     "material_10",
                                     "material_11",
                                     "material_12",
                                     "neue_spule_button_hersteller",
                                     "trocknen_button_1",
                                     "home_button",
                                     "hersteller_1",
                                     "hersteller_4",
                                     "hersteller_2",
                                     "hersteller_3",
                                     "hersteller_5",
                                     "hersteller_6",
                                     "hersteller_7",
                                     "hersteller_8",
                                     "neue_spule_button_hersteller_10",
                                     "trocknen_button_12",
                                     "home_button_11",
                                     "farbe_1",
                                     "farbe_4",
                                     "farbe_2",
                                     "farbe_3",
                                     "farbe_5",
                                     "farbe_6",
                                     "farbe_7",
                                     "farbe_8",
                                     "farbe_9",
                                     "farbe_10",
                                     "farbe_11",
                                     "farbe_12",
                                     "neue_spule_button_1",
                                     "home_button_2",
                                     "neue_spule_button_hersteller_5",
                                     "trocknen_button_7",
                                     "home_button_6",
                                     "wlan_button_1",
                                     "spulen_daten_button_1",
                                     "systemdaten_button_1",
                                     "zurueck_button_9",
                                     "systemdaten_button_2",
                                     "systemdaten_button_3",
                                     "neue_spule_button_hersteller_6",
                                     "trocknen_button_8",
                                     "home_button_7",
                                     "zurueck_netzwerksuche_button",
                                     "obj0",
                                     "manuele_netzwerksuche_button_1",
                                     "abbruch_button_1",
                                     "abbruch_button",
                                     "neue_spule_button_hersteller_7",
                                     "trocknen_button_9",
                                     "home_button_8",
                                     "zurueck_button_7",
                                     "neue_spule_button_hersteller_8",
                                     "trocknen_button_10",
                                     "home_button_9",
                                     "zurueck_button_3",
                                     "neue_spule_button_hersteller_9",
                                     "trocknen_button_11",
                                     "home_button_10",
                                     "zurueck_button_8",
                                     "farbe_13",
                                     "farbe_15",
                                     "farbe_17",
                                     "farbe_19",
                                     "farbe_21",
                                     "farbe_23",
                                     "farbe_25",
                                     "farbe_27",
                                     "farbe_29",
                                     "farbe_31",
                                     "farbe_33",
                                     "farbe_35",
                                     "neue_spule_button_hersteller_11",
                                     "trocknen_button_13",
                                     "home_button_12",
                                     "zurueck_button_10",
                                     "hersteller_9",
                                     "hersteller_11",
                                     "hersteller_13",
                                     "hersteller_17",
                                     "hersteller_20",
                                     "hersteller_22",
                                     "hersteller_24",
                                     "hersteller_26",
                                     "fila_track",
                                     "neue_spule",
                                     "trocknen_text",
                                     "on_off_button",
                                     "on_off_bild",
                                     "einstellungen_bild",
                                     "filamentanzeige",
                                     "rest_filament",
                                     "gewicht",
                                     "trocknungszeitanzeige_bild",
                                     "trocknungszeit_zeit",
                                     "hersteller_material",
                                     "farbe",
                                     "verbindung",
                                     "datum",
                                     "trocknen_bild_13",
                                     "obj1",
                                     "obj2",
                                     "material__berschrift",
                                     "neue_spule_button_hersteller_1",
                                     "neue_spule_2",
                                     "trocknen_text_2",
                                     "filamentanzeige_2",
                                     "trocknungszeitanzeige_bild_2",
                                     "home_text_1",
                                     "material_1_text",
                                     "material_4_text",
                                     "material_2_text",
                                     "material_3_text",
                                     "material_5_text",
                                     "material_6_text",
                                     "material_7_text",
                                     "material_8_text",
                                     "material_9_text",
                                     "material_10_text",
                                     "material_11_text",
                                     "material_12_text",
                                     "obj3",
                                     "obj4",
                                     "trocknen_bild_14",
                                     "trocknungszeit_zeit_2",
                                     "hersteller__berschrift",
                                     "neue_spule_1",
                                     "trocknen_text_1",
                                     "filamentanzeige_1",
                                     "trocknungszeitanzeige_bild_1",
                                     "home_text",
                                     "hersteller_1_text",
                                     "hersteller_4_text",
                                     "hersteller_2_text",
                                     "hersteller_3_text",
                                     "hersteller_5_text",
                                     "hersteller_6_text",
                                     "hersteller_7_text",
                                     "hersteller_8_text",
                                     "obj5",
                                     "obj6",
                                     "trocknung_temperaturannzeige_3",
                                     "obj7",
                                     "obj8",
                                     "obj9",
                                     "obj10",
                                     "obj11",
                                     "kalibrirung_preeset_8",
                                     "kalibrirung_preeset_4",
                                     "kalibrirung_preeset_9",
                                     "kalibrirung_preeset_6",
                                     "trocknen_bild_15",
                                     "trocknungszeit_zeit_1",
                                     "farbe__berschrift",
                                     "neue_spule_12",
                                     "trocknen_text_12",
                                     "filamentanzeige_4",
                                     "trocknungszeitanzeige_bild_4",
                                     "home_text_11",
                                     "farbe_1_text",
                                     "farbe_4_text",
                                     "farbe_2_text",
                                     "farbe_3_text",
                                     "farbe_5_text",
                                     "farbe_6_text",
                                     "farbe_7_text",
                                     "farbe_8_text",
                                     "farbe_9_text",
                                     "farbe_10_text",
                                     "farbe_11_text",
                                     "farbe_12_text",
                                     "obj12",
                                     "obj13",
                                     "trocknen_bild_16",
                                     "trocknungszeit_zeit_4",
                                     "fila_track_1",
                                     "neue_spule_3",
                                     "trocknen_button_3",
                                     "trocknen_text_3",
                                     "filamentanzeige_3",
                                     "trocknungszeitanzeige_bild_3",
                                     "home_text_2",
                                     "trocknung_preeset_1",
                                     "trocknung_preeset_1_text",
                                     "trocknung_preeset_2",
                                     "hersteller_14",
                                     "trocknung_preeset_3",
                                     "hersteller_16",
                                     "trocknung_preeset_4",
                                     "hersteller_18",
                                     "obj14",
                                     "trocknung_temperaturannzeige",
                                     "trocknung_stundenanzeige",
                                     "trocknung_minutenanzeige",
                                     "obj15",
                                     "obj16",
                                     "obj17",
                                     "temperaturannzeige_1",
                                     "obj18",
                                     "start_button_9",
                                     "start_button_text",
                                     "obj19",
                                     "obj20",
                                     "obj21",
                                     "obj22",
                                     "obj23",
                                     "obj24",
                                     "obj25",
                                     "obj26",
                                     "trocknen_bild_17",
                                     "trocknungszeit_zeit_3",
                                     "start_button_10",
                                     "start_button_text_1",
                                     "einstellungen__berschrift_1",
                                     "neue_spule_7",
                                     "trocknen_text_7",
                                     "home_text_6",
                                     "wlan_button_text_1",
                                     "kalibrirung_button_text_1",
                                     "systemdaten_button_text_1",
                                     "zurueck_button_text_9",
                                     "obj27",
                                     "obj28",
                                     "softwareversion_text",
                                     "controler_text",
                                     "trocknen_bild_18",
                                     "farbauswahl_button_text",
                                     "systemdaten_button_text_3",
                                     "einstellungen__berschrift_2",
                                     "neue_spule_8",
                                     "trocknen_text_8",
                                     "home_text_7",
                                     "erneute_netzwerksuche_button",
                                     "erneute_netzwerksuche_button_text",
                                     "zurueck_netzwerksuche_button_text",
                                     "obj29",
                                     "obj30",
                                     "zurueck_netzwerksuche_button_text_1",
                                     "trocknen_bild_19",
                                     "obj31",
                                     "ssid__berschrift_1",
                                     "obj32",
                                     "passworteingabe__berschrift",
                                     "einstellungen__berschrift_3",
                                     "neue_spule_9",
                                     "trocknen_text_9",
                                     "home_text_8",
                                     "hx711_abfrage_text",
                                     "rfid_abfrage_text",
                                     "e_paper_abfrage_text",
                                     "heizelement_abfrage_text",
                                     "zurueck_button_text_7",
                                     "obj33",
                                     "obj34",
                                     "rfid",
                                     "e_paper",
                                     "hx711",
                                     "heizelement",
                                     "trocknen_bild_20",
                                     "spulen_daten__berschrift",
                                     "neue_spule_10",
                                     "trocknen_text_10",
                                     "home_text_9",
                                     "spulen_daten_hersteller_material_farbe_1",
                                     "spulen_daten_gewicht_1",
                                     "spulen_daten_hersteller_material_farbe_2",
                                     "spulen_daten_gewicht_2",
                                     "spulen_daten_hersteller_material_farbe_3",
                                     "spulen_daten_gewicht_3",
                                     "zurueck_button_text_3",
                                     "obj35",
                                     "obj36",
                                     "trocknen_bild_21",
                                     "einstellungen__berschrift_4",
                                     "neue_spule_11",
                                     "trocknen_text_11",
                                     "home_text_10",
                                     "zurueck_button_text_8",
                                     "obj37",
                                     "obj38",
                                     "trocknen_bild_22",
                                     "farbe_14",
                                     "farbe_16",
                                     "farbe_18",
                                     "farbe_20",
                                     "farbe_22",
                                     "farbe_24",
                                     "farbe_26",
                                     "farbe_28",
                                     "farbe_30",
                                     "farbe_32",
                                     "farbe_34",
                                     "farbe_36",
                                     "hersteller_preset__berschrift",
                                     "neue_spule_13",
                                     "trocknen_text_13",
                                     "home_text_12",
                                     "zurueck_button_text_10",
                                     "obj39",
                                     "obj40",
                                     "trocknen_bild_23",
                                     "hersteller_10",
                                     "hersteller_12",
                                     "hersteller_15",
                                     "hersteller_19",
                                     "hersteller_21",
                                     "hersteller_23",
                                     "hersteller_25",
                                     "hersteller_27"};

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_homescreen,
    tick_screen_neue_spule_material_screen,
    tick_screen_neue_spule_hersteller_screen,
    tick_screen_neue_spule_farbe_screen,
    tick_screen_trocknenscreen,
    tick_screen_einstellungen_screen,
    tick_screen_netzwerksuche_screen,
    tick_screen_ssid_screen,
    tick_screen_passworteingabe_screen,
    tick_screen_system_screen,
    tick_screen_spulen_daten_screen,
    tick_screen_system_farben_preset,
    tick_screen_system_hersteller_preset,
};
void tick_screen(int screen_index) { tick_screen_funcs[screen_index](); }
void tick_screen_by_id(enum ScreensEnum screenId) {
  tick_screen_funcs[screenId - 1]();
}

void create_screens() {
  eez_flow_init_screen_names(screen_names,
                             sizeof(screen_names) / sizeof(const char *));
  eez_flow_init_object_names(object_names,
                             sizeof(object_names) / sizeof(const char *));

  lv_disp_t *dispp = lv_disp_get_default();
  lv_theme_t *theme = lv_theme_default_init(
      dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
      false, LV_FONT_DEFAULT);
  lv_disp_set_theme(dispp, theme);

  create_screen_homescreen();
  create_screen_neue_spule_material_screen();
  create_screen_neue_spule_hersteller_screen();
  create_screen_neue_spule_farbe_screen();
  create_screen_trocknenscreen();
  create_screen_einstellungen_screen();
  create_screen_netzwerksuche_screen();
  create_screen_ssid_screen();
  create_screen_passworteingabe_screen();
  create_screen_system_screen();
  create_screen_spulen_daten_screen();
  create_screen_system_farben_preset();
  create_screen_system_hersteller_preset();
}
