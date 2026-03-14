/* 00 ~ 99 をエンドレスに表示させます */

#define HC595_DATA  10
#define HC595_CLOCK 11
#define HC595_LATCH 12

const uint8_t font[10] = {0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110, 0b10110110, 0b10111110, 0b11100000, 0b11111110, 0b11110110};

/* 7 セグメント LED 制御用の関数 */
void drive595(uint8_t datum) {
  for(size_t i = 0; i < 8; i++) {
    digitalWrite(HC595_DATA, (datum >> i) & 1);

    digitalWrite(HC595_CLOCK, HIGH);
    digitalWrite(HC595_CLOCK,  LOW);
  }

  digitalWrite(HC595_DATA, LOW);
}

void latch595(void) {
  digitalWrite(HC595_LATCH, HIGH);
  digitalWrite(HC595_LATCH,  LOW);
}

void setup() {
  pinMode(HC595_DATA , OUTPUT);
  pinMode(HC595_CLOCK, OUTPUT);
  pinMode(HC595_LATCH, OUTPUT);
}

void loop() {
  for(size_t i = 0; i < 100; i++) {
    drive595(font[i/10]);
    drive595(font[i%10]);
    latch595();
    
    delay(100);
  }
}
