#include <ion.h>
#include <kandinsky.h>
#include <escher.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include <python/port/port.h>

extern "C" {
  #include <python/port/mphalport.h>
}

uint64_t millis() {
  return Ion::Timing::millis();
}

void msleep(uint32_t ms) {
  Ion::Timing::msleep(ms);
}

uint64_t scanKeyboard() {
  return Ion::Keyboard::scan();
}

void pushRect(int16_t x, int16_t y, uint16_t w, uint16_t h, const uint16_t * pixels) {
  KDRect rect(x, y, w, h);

  Ion::Display::pushRect(rect, reinterpret_cast<const KDColor*>(pixels));
}

void pushRectUniform(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t color) {
  KDRect rect(x, y, w, h);

  Ion::Display::pushRectUniform(rect, KDColor::RGB16(color));
}

int16_t drawTextLarge(const char *text, int16_t x, int16_t y, uint16_t fg, uint16_t bg) {
  KDPoint point(x, y);

  auto ctx = KDIonContext::sharedContext();
  ctx->setClippingRect(KDRect(0,0,320,240));
  ctx->setOrigin(KDPoint(0,0));
  ctx->drawString(text, point, KDFont::LargeFont, KDColor::RGB16(fg), KDColor::RGB16(bg));

  return point.x();
}

int16_t drawTextSmall(const char *text, int16_t x, int16_t y, uint16_t fg, uint16_t bg) {
  KDPoint point(x, y);

  auto ctx = KDIonContext::sharedContext();
  ctx->setClippingRect(KDRect(0,0,320,240));
  ctx->setOrigin(KDPoint(0,0));
  ctx->drawString(text, point, KDFont::SmallFont, KDColor::RGB16(fg), KDColor::RGB16(bg));

  return point.x();
}

void waitForVBlank() {
  Ion::Display::waitForVBlank();
}

void clipboardStore(const char *text) {
  Clipboard::sharedClipboard()->store(text);
}

const char * clipboardText() {
  return Clipboard::sharedClipboard()->storedText();
}

void (* const apiPointers[])(void) = {
  (void (*)(void)) millis,
  (void (*)(void)) msleep,
  (void (*)(void)) scanKeyboard,
  (void (*)(void)) pushRect,
  (void (*)(void)) pushRectUniform,
  (void (*)(void)) drawTextLarge,
  (void (*)(void)) drawTextSmall,
  (void (*)(void)) waitForVBlank,
  (void (*)(void)) clipboardStore,
  (void (*)(void)) clipboardText,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,
  (void (*)(void)) nullptr,

  // khicas from here, subject to change
  (void (*)(void)) numworks_draw_string,
  (void (*)(void)) numworks_draw_string_small,
  (void (*)(void)) numworks_set_pixel,
  (void (*)(void)) numworks_fill_rect,
  (void (*)(void)) numworks_get_pixel,
  (void (*)(void)) numworks_hide_graph,
  (void (*)(void)) numworks_wait_1ms,
  (void (*)(void)) waitforvblank,
  (void (*)(void)) statuslinemsg,
  (void (*)(void)) statusline,
  (void (*)(void)) getkey,
  (void (*)(void)) GetKey,
  (void (*)(void)) alphawasactive,
  (void (*)(void)) lock_alpha,
  (void (*)(void)) reset_kbd,
  (void (*)(void)) back_key_pressed,
  (void (*)(void)) enable_back_interrupt,
  (void (*)(void)) disable_back_interrupt,
  (void (*)(void)) os_set_angle_unit,
  (void (*)(void)) os_get_angle_unit,
  (void (*)(void)) os_file_browser,
  (void (*)(void)) file_exists,
  (void (*)(void)) erase_file,
  (void (*)(void)) read_file,
  (void (*)(void)) write_file,
  (void (*)(void)) mp_hal_input,
  (void (*)(void)) nullptr
};

const void * getApiPointers() {
  return apiPointers;
}