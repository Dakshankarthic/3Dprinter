#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
  lv_obj_t *homescreen;
  lv_obj_t *neue_spule_material_screen;
  lv_obj_t *neue_spule_hersteller_screen;
  lv_obj_t *neue_spule_farbe_screen;
  lv_obj_t *trocknenscreen;
  lv_obj_t *einstellungen_screen;
  lv_obj_t *netzwerksuche_screen;
  lv_obj_t *ssid_screen;
  lv_obj_t *passworteingabe_screen;
  lv_obj_t *system_screen;
  lv_obj_t *spulen_daten_screen;
  lv_obj_t *system_farben_preset;
  lv_obj_t *system_hersteller_preset;
  lv_obj_t *neue_spule_button;
  lv_obj_t *trocknen_button;
  lv_obj_t *einstellungen_button_1;
  lv_obj_t *trocknen_button_2;
  lv_obj_t *home_button_1;
  lv_obj_t *material_1;
  lv_obj_t *material_4;
  lv_obj_t *material_2;
  lv_obj_t *material_3;
  lv_obj_t *material_5;
  lv_obj_t *material_6;
  lv_obj_t *material_7;
  lv_obj_t *material_8;
  lv_obj_t *material_9;
  lv_obj_t *material_10;
  lv_obj_t *material_11;
  lv_obj_t *material_12;
  lv_obj_t *neue_spule_button_hersteller;
  lv_obj_t *trocknen_button_1;
  lv_obj_t *home_button;
  lv_obj_t *hersteller_1;
  lv_obj_t *hersteller_4;
  lv_obj_t *hersteller_2;
  lv_obj_t *hersteller_3;
  lv_obj_t *hersteller_5;
  lv_obj_t *hersteller_6;
  lv_obj_t *hersteller_7;
  lv_obj_t *hersteller_8;
  lv_obj_t *neue_spule_button_hersteller_10;
  lv_obj_t *trocknen_button_12;
  lv_obj_t *home_button_11;
  lv_obj_t *farbe_1;
  lv_obj_t *farbe_4;
  lv_obj_t *farbe_2;
  lv_obj_t *farbe_3;
  lv_obj_t *farbe_5;
  lv_obj_t *farbe_6;
  lv_obj_t *farbe_7;
  lv_obj_t *farbe_8;
  lv_obj_t *farbe_9;
  lv_obj_t *farbe_10;
  lv_obj_t *farbe_11;
  lv_obj_t *farbe_12;
  lv_obj_t *neue_spule_button_1;
  lv_obj_t *home_button_2;
  lv_obj_t *neue_spule_button_hersteller_5;
  lv_obj_t *trocknen_button_7;
  lv_obj_t *home_button_6;
  lv_obj_t *wlan_button_1;
  lv_obj_t *spulen_daten_button_1;
  lv_obj_t *systemdaten_button_1;
  lv_obj_t *zurueck_button_9;
  lv_obj_t *systemdaten_button_2;
  lv_obj_t *systemdaten_button_3;
  lv_obj_t *neue_spule_button_hersteller_6;
  lv_obj_t *trocknen_button_8;
  lv_obj_t *home_button_7;
  lv_obj_t *zurueck_netzwerksuche_button;
  lv_obj_t *obj0;
  lv_obj_t *manuele_netzwerksuche_button_1;
  lv_obj_t *abbruch_button_1;
  lv_obj_t *abbruch_button;
  lv_obj_t *neue_spule_button_hersteller_7;
  lv_obj_t *trocknen_button_9;
  lv_obj_t *home_button_8;
  lv_obj_t *zurueck_button_7;
  lv_obj_t *neue_spule_button_hersteller_8;
  lv_obj_t *trocknen_button_10;
  lv_obj_t *home_button_9;
  lv_obj_t *zurueck_button_3;
  lv_obj_t *neue_spule_button_hersteller_9;
  lv_obj_t *trocknen_button_11;
  lv_obj_t *home_button_10;
  lv_obj_t *zurueck_button_8;
  lv_obj_t *farbe_13;
  lv_obj_t *farbe_15;
  lv_obj_t *farbe_17;
  lv_obj_t *farbe_19;
  lv_obj_t *farbe_21;
  lv_obj_t *farbe_23;
  lv_obj_t *farbe_25;
  lv_obj_t *farbe_27;
  lv_obj_t *farbe_29;
  lv_obj_t *farbe_31;
  lv_obj_t *farbe_33;
  lv_obj_t *farbe_35;
  lv_obj_t *neue_spule_button_hersteller_11;
  lv_obj_t *trocknen_button_13;
  lv_obj_t *home_button_12;
  lv_obj_t *zurueck_button_10;
  lv_obj_t *hersteller_9;
  lv_obj_t *hersteller_11;
  lv_obj_t *hersteller_13;
  lv_obj_t *hersteller_17;
  lv_obj_t *hersteller_20;
  lv_obj_t *hersteller_22;
  lv_obj_t *hersteller_24;
  lv_obj_t *hersteller_26;
  lv_obj_t *fila_track;
  lv_obj_t *neue_spule;
  lv_obj_t *trocknen_text;
  lv_obj_t *on_off_button;
  lv_obj_t *on_off_bild;
  lv_obj_t *einstellungen_bild;
  lv_obj_t *filamentanzeige;
  lv_obj_t *rest_filament;
  lv_obj_t *gewicht;
  lv_obj_t *trocknungszeitanzeige_bild;
  lv_obj_t *trocknungszeit_zeit;
  lv_obj_t *hersteller_material;
  lv_obj_t *farbe;
  lv_obj_t *verbindung;
  lv_obj_t *datum;
  lv_obj_t *ssid_label;
  lv_obj_t *password_label;
  lv_obj_t *wifi_status_label;
  lv_obj_t *trocknen_bild_13;
  lv_obj_t *obj1;
  lv_obj_t *obj2;
  lv_obj_t *material__berschrift;
  lv_obj_t *neue_spule_button_hersteller_1;
  lv_obj_t *neue_spule_2;
  lv_obj_t *trocknen_text_2;
  lv_obj_t *filamentanzeige_2;
  lv_obj_t *trocknungszeitanzeige_bild_2;
  lv_obj_t *home_text_1;
  lv_obj_t *material_1_text;
  lv_obj_t *material_4_text;
  lv_obj_t *material_2_text;
  lv_obj_t *material_3_text;
  lv_obj_t *material_5_text;
  lv_obj_t *material_6_text;
  lv_obj_t *material_7_text;
  lv_obj_t *material_8_text;
  lv_obj_t *material_9_text;
  lv_obj_t *material_10_text;
  lv_obj_t *material_11_text;
  lv_obj_t *material_12_text;
  lv_obj_t *obj3;
  lv_obj_t *obj4;
  lv_obj_t *trocknen_bild_14;
  lv_obj_t *trocknungszeit_zeit_2;
  lv_obj_t *hersteller__berschrift;
  lv_obj_t *neue_spule_1;
  lv_obj_t *trocknen_text_1;
  lv_obj_t *filamentanzeige_1;
  lv_obj_t *trocknungszeitanzeige_bild_1;
  lv_obj_t *home_text;
  lv_obj_t *hersteller_1_text;
  lv_obj_t *hersteller_4_text;
  lv_obj_t *hersteller_2_text;
  lv_obj_t *hersteller_3_text;
  lv_obj_t *hersteller_5_text;
  lv_obj_t *hersteller_6_text;
  lv_obj_t *hersteller_7_text;
  lv_obj_t *hersteller_8_text;
  lv_obj_t *obj5;
  lv_obj_t *obj6;
  lv_obj_t *trocknung_temperaturannzeige_3;
  lv_obj_t *obj7;
  lv_obj_t *obj8;
  lv_obj_t *obj9;
  lv_obj_t *obj10;
  lv_obj_t *obj11;
  lv_obj_t *kalibrirung_preeset_8;
  lv_obj_t *kalibrirung_preeset_4;
  lv_obj_t *kalibrirung_preeset_9;
  lv_obj_t *kalibrirung_preeset_6;
  lv_obj_t *trocknen_bild_15;
  lv_obj_t *trocknungszeit_zeit_1;
  lv_obj_t *farbe__berschrift;
  lv_obj_t *neue_spule_12;
  lv_obj_t *trocknen_text_12;
  lv_obj_t *filamentanzeige_4;
  lv_obj_t *trocknungszeitanzeige_bild_4;
  lv_obj_t *home_text_11;
  lv_obj_t *farbe_1_text;
  lv_obj_t *farbe_4_text;
  lv_obj_t *farbe_2_text;
  lv_obj_t *farbe_3_text;
  lv_obj_t *farbe_5_text;
  lv_obj_t *farbe_6_text;
  lv_obj_t *farbe_7_text;
  lv_obj_t *farbe_8_text;
  lv_obj_t *farbe_9_text;
  lv_obj_t *farbe_10_text;
  lv_obj_t *farbe_11_text;
  lv_obj_t *farbe_12_text;
  lv_obj_t *obj12;
  lv_obj_t *obj13;
  lv_obj_t *trocknen_bild_16;
  lv_obj_t *trocknungszeit_zeit_4;
  lv_obj_t *fila_track_1;
  lv_obj_t *neue_spule_3;
  lv_obj_t *trocknen_button_3;
  lv_obj_t *trocknen_text_3;
  lv_obj_t *filamentanzeige_3;
  lv_obj_t *trocknungszeitanzeige_bild_3;
  lv_obj_t *home_text_2;
  lv_obj_t *trocknung_preeset_1;
  lv_obj_t *trocknung_preeset_1_text;
  lv_obj_t *trocknung_preeset_2;
  lv_obj_t *hersteller_14;
  lv_obj_t *trocknung_preeset_3;
  lv_obj_t *hersteller_16;
  lv_obj_t *trocknung_preeset_4;
  lv_obj_t *hersteller_18;
  lv_obj_t *obj14;
  lv_obj_t *trocknung_temperaturannzeige;
  lv_obj_t *trocknung_stundenanzeige;
  lv_obj_t *trocknung_minutenanzeige;
  lv_obj_t *obj15;
  lv_obj_t *obj16;
  lv_obj_t *obj17;
  lv_obj_t *temperaturannzeige_1;
  lv_obj_t *obj18;
  lv_obj_t *start_button_9;
  lv_obj_t *start_button_text;
  lv_obj_t *obj19;
  lv_obj_t *obj20;
  lv_obj_t *obj21;
  lv_obj_t *obj22;
  lv_obj_t *obj23;
  lv_obj_t *obj24;
  lv_obj_t *obj25;
  lv_obj_t *obj26;
  lv_obj_t *trocknen_bild_17;
  lv_obj_t *trocknungszeit_zeit_3;
  lv_obj_t *start_button_10;
  lv_obj_t *start_button_text_1;
  lv_obj_t *einstellungen__berschrift_1;
  lv_obj_t *neue_spule_7;
  lv_obj_t *trocknen_text_7;
  lv_obj_t *home_text_6;
  lv_obj_t *wlan_button_text_1;
  lv_obj_t *kalibrirung_button_text_1;
  lv_obj_t *systemdaten_button_text_1;
  lv_obj_t *zurueck_button_text_9;
  lv_obj_t *obj27;
  lv_obj_t *obj28;
  lv_obj_t *softwareversion_text;
  lv_obj_t *controler_text;
  lv_obj_t *trocknen_bild_18;
  lv_obj_t *farbauswahl_button_text;
  lv_obj_t *systemdaten_button_text_3;
  lv_obj_t *einstellungen__berschrift_2;
  lv_obj_t *neue_spule_8;
  lv_obj_t *trocknen_text_8;
  lv_obj_t *home_text_7;
  lv_obj_t *erneute_netzwerksuche_button;
  lv_obj_t *erneute_netzwerksuche_button_text;
  lv_obj_t *zurueck_netzwerksuche_button_text;
  lv_obj_t *obj29;
  lv_obj_t *obj30;
  lv_obj_t *zurueck_netzwerksuche_button_text_1;
  lv_obj_t *trocknen_bild_19;
  lv_obj_t *obj31;
  lv_obj_t *ssid__berschrift_1;
  lv_obj_t *obj32;
  lv_obj_t *passworteingabe__berschrift;
  lv_obj_t *einstellungen__berschrift_3;
  lv_obj_t *neue_spule_9;
  lv_obj_t *trocknen_text_9;
  lv_obj_t *home_text_8;
  lv_obj_t *hx711_abfrage_text;
  lv_obj_t *rfid_abfrage_text;
  lv_obj_t *e_paper_abfrage_text;
  lv_obj_t *heizelement_abfrage_text;
  lv_obj_t *zurueck_button_text_7;
  lv_obj_t *obj33;
  lv_obj_t *obj34;
  lv_obj_t *rfid;
  lv_obj_t *e_paper;
  lv_obj_t *hx711;
  lv_obj_t *heizelement;
  lv_obj_t *trocknen_bild_20;
  lv_obj_t *spulen_daten__berschrift;
  lv_obj_t *neue_spule_10;
  lv_obj_t *trocknen_text_10;
  lv_obj_t *home_text_9;
  lv_obj_t *spulen_daten_hersteller_material_farbe_1;
  lv_obj_t *spulen_daten_gewicht_1;
  lv_obj_t *spulen_daten_hersteller_material_farbe_2;
  lv_obj_t *spulen_daten_gewicht_2;
  lv_obj_t *spulen_daten_hersteller_material_farbe_3;
  lv_obj_t *spulen_daten_gewicht_3;
  lv_obj_t *zurueck_button_text_3;
  lv_obj_t *obj35;
  lv_obj_t *obj36;
  lv_obj_t *trocknen_bild_21;
  lv_obj_t *einstellungen__berschrift_4;
  lv_obj_t *neue_spule_11;
  lv_obj_t *trocknen_text_11;
  lv_obj_t *home_text_10;
  lv_obj_t *zurueck_button_text_8;
  lv_obj_t *obj37;
  lv_obj_t *obj38;
  lv_obj_t *trocknen_bild_22;
  lv_obj_t *farbe_14;
  lv_obj_t *farbe_16;
  lv_obj_t *farbe_18;
  lv_obj_t *farbe_20;
  lv_obj_t *farbe_22;
  lv_obj_t *farbe_24;
  lv_obj_t *farbe_26;
  lv_obj_t *farbe_28;
  lv_obj_t *farbe_30;
  lv_obj_t *farbe_32;
  lv_obj_t *farbe_34;
  lv_obj_t *farbe_36;
  lv_obj_t *hersteller_preset__berschrift;
  lv_obj_t *neue_spule_13;
  lv_obj_t *trocknen_text_13;
  lv_obj_t *home_text_12;
  lv_obj_t *zurueck_button_text_10;
  lv_obj_t *obj39;
  lv_obj_t *obj40;
  lv_obj_t *trocknen_bild_23;
  lv_obj_t *hersteller_10;
  lv_obj_t *hersteller_12;
  lv_obj_t *hersteller_15;
  lv_obj_t *hersteller_19;
  lv_obj_t *hersteller_21;
  lv_obj_t *hersteller_23;
  lv_obj_t *hersteller_25;
  lv_obj_t *hersteller_27;
  lv_obj_t *ip_label;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
  SCREEN_ID_HOMESCREEN = 1,
  SCREEN_ID_NEUE_SPULE_MATERIAL_SCREEN = 2,
  SCREEN_ID_NEUE_SPULE_HERSTELLER_SCREEN = 3,
  SCREEN_ID_NEUE_SPULE_FARBE_SCREEN = 4,
  SCREEN_ID_TROCKNENSCREEN = 5,
  SCREEN_ID_EINSTELLUNGEN_SCREEN = 6,
  SCREEN_ID_NETZWERKSUCHE_SCREEN = 7,
  SCREEN_ID_SSID_SCREEN = 8,
  SCREEN_ID_PASSWORTEINGABE_SCREEN = 9,
  SCREEN_ID_SYSTEM_SCREEN = 10,
  SCREEN_ID_SPULEN_DATEN_SCREEN = 11,
  SCREEN_ID_SYSTEM_FARBEN_PRESET = 12,
  SCREEN_ID_SYSTEM_HERSTELLER_PRESET = 13,
};

void create_screen_homescreen();
void tick_screen_homescreen();

void create_screen_neue_spule_material_screen();
void tick_screen_neue_spule_material_screen();

void create_screen_neue_spule_hersteller_screen();
void tick_screen_neue_spule_hersteller_screen();

void create_screen_neue_spule_farbe_screen();
void tick_screen_neue_spule_farbe_screen();

void create_screen_trocknenscreen();
void tick_screen_trocknenscreen();

void create_screen_einstellungen_screen();
void tick_screen_einstellungen_screen();

void create_screen_netzwerksuche_screen();
void tick_screen_netzwerksuche_screen();

void create_screen_ssid_screen();
void tick_screen_ssid_screen();

void create_screen_passworteingabe_screen();
void tick_screen_passworteingabe_screen();

void create_screen_system_screen();
void tick_screen_system_screen();

void create_screen_spulen_daten_screen();
void tick_screen_spulen_daten_screen();

void create_screen_system_farben_preset();
void tick_screen_system_farben_preset();

void create_screen_system_hersteller_preset();
void tick_screen_system_hersteller_preset();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();

#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/