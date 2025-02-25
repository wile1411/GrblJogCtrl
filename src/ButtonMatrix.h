#ifndef _ButtonMatrix
#define _ButtonMatrix

#include <Arduino.h>

//Com - Brown
//C1 - White
//C2 - Gray
//C3 - Purple
//R1 - Red
//R2 - Orange
//R3 - Yellow
//R4 - Green

#define _bmA B00000001
#define _bmB B00000010
#define _bmC B00000100
#define _bmD B00001000
#define _bmE B00010000
#define _bmF B00100000
#define _bmG B01000000
#define _bmH B10000000

#define R1C4 (_bmA | _bmE)
#define R1C3 (_bmB | _bmE)
#define R1C2 (_bmC | _bmE)
#define R1C1 (_bmD | _bmE)
#define R2C4 (_bmA | _bmF)
#define R2C3 (_bmB | _bmF)
#define R2C2 (_bmC | _bmF)
#define R2C1 (_bmD | _bmF)
#define R3C4 (_bmA | _bmG)
#define R3C3 (_bmB | _bmG)
#define R3C2 (_bmC | _bmG)
#define R3C1 (_bmD | _bmG)
#define R4C4 (_bmA | _bmH)
#define R4C3 (_bmB | _bmH)
#define R4C2 (_bmC | _bmH)
#define R4C1 (_bmD | _bmH)

// Button bitmasks
#define R1C1bm (1 << 0)
#define R1C2bm (1 << 1)
#define R1C3bm (1 << 2)
#define R1C4bm (1 << 3)
#define R2C1bm (1 << 4)
#define R2C2bm (1 << 5)
#define R2C3bm (1 << 6)
#define R2C4bm (1 << 7)
#define R3C1bm (1 << 8)
#define R3C2bm (1 << 9)
#define R3C3bm (1 << 10)
#define R3C4bm (1 << 11)
#define R4C1bm (1 << 12)
#define R4C2bm (1 << 13)
#define R4C3bm (1 << 14)
#define R4C4bm (1 << 15)

#define IsPressed(states, buttonMask) (states & buttonMask)

class ButtonMatrix
{
   public:
      ButtonMatrix();
      void begin(uint8_t clk, uint8_t shiftLoad, uint8_t QH, uint8_t nQH = 255, uint8_t clkInh = 255);

      uint8_t Update();

      enum ButtonMasksType {
                             eR1C1 = 0,
                             eR1C2,
                             eR1C3,
                             eR1C4,
                             eR2C1,
                             eR2C2,
                             eR2C3,
                             eR2C4,
                             eR3C1,
                             eR3C2,
                             eR3C3,
                             eR3C4,
                             eR4C1,
                             eR4C2,
                             eR4C3,
                             eR4C4,
                             eBMRange
                          };

      enum ButtonStateType { ePressed = 0, eReleased = 1};

      void onChangeConnect(void(*func)(ButtonMasksType button, ButtonStateType state) = nullptr);

   private:
      uint8_t _clk = 255;
      uint8_t _SOL;
      uint8_t _QH;
      uint8_t _nQH = 255;
      uint8_t _clkInh = 255;
      uint8_t _buttons[eBMRange];

      uint8_t _data = 0;
      uint8_t _change = 0;
      bool _read = false;

      uint16_t _buttonStates = 0;

      elapsedMillis _debounce;

      void (*onChange)(ButtonMasksType button, ButtonStateType state);
};

extern ButtonMatrix BM;

#endif