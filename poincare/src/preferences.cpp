#include <poincare/preferences.h>
#include <poincare/print_float.h>

namespace Poincare {

Preferences::Preferences() :
  m_angleUnit(AngleUnit::Radian),
  m_displayMode(Preferences::PrintFloatMode::Decimal),
  m_editionMode(EditionMode::Edition2D),
  m_complexFormat(Preferences::ComplexFormat::Real),
  m_numberOfSignificantDigits(PrintFloat::k_numberOfPrintedSignificantDigits)
{
}

Preferences * Preferences::sharedPreferences() {
  static Preferences preferences;
  return &preferences;
}

}
