#include "tvbg_sender.h"

#if __has_include(<IRremoteESP8266.h>)
  #include <IRremoteESP8266.h>
  #include <IRsend.h>
  #define USE_IRREMOTE 1
  static IRsend irsend(IR_TX_PIN);
#else
  #include "driver/ledc.h"
  #define USE_IRREMOTE 0
  static const ledc_channel_t CH = LEDC_CHANNEL_0;
  static const ledc_timer_t   TM = LEDC_TIMER_0;
  static const int LEDC_RES_BITS = 10; 
  static inline void carrierOn(uint16_t khz){
    uint32_t freq = (uint32_t)khz * 1000;
    ledcSetup(CH, freq, LEDC_RES_BITS);
    ledcAttachPin(IR_TX_PIN, CH);
    ledcWrite(CH, (1 << (LEDC_RES_BITS-1))); 
  }
  static inline void carrierOff(){
    ledcWrite(CH, 0);
    ledcDetachPin(IR_TX_PIN);
  }
  static inline void delayMicrosAccurate(uint32_t us){
    
    uint32_t start = micros();
    if (us > 15000) { delayMicroseconds(us); return; }
    while ((micros() - start) < us) { }
  }
  static void sendRaw38k(const uint16_t* seq, uint16_t len, uint16_t khz){
    for (uint16_t i=0;i<len;i++){
      if ((i & 1) == 0) { 
        carrierOn(khz);
        delayMicrosAccurate(seq[i]);
      } else {            
        carrierOff();
        delayMicrosAccurate(seq[i]);
      }
    }
    carrierOff();
  }
#endif

void tvbgSenderBegin(){
#if USE_IRREMOTE
  irsend.begin();  
#else
  ledcSetup(CH, 38000, LEDC_RES_BITS);
  pinMode(IR_TX_PIN, OUTPUT);
  digitalWrite(IR_TX_PIN, LOW);
#endif
}

void tvbgSend(const TVBGToken& tok){
#if USE_IRREMOTE
  switch (tok.proto){
    case IRProto::NEC:       irsend.sendNEC(tok.value, tok.nbits); break;
    case IRProto::SONY:      irsend.sendSony(tok.value, tok.nbits, 2); break; 
    case IRProto::PANASONIC: irsend.sendPanasonic64(tok.value); break;
    case IRProto::RC5:       irsend.sendRC5(tok.value, tok.nbits); break;
    case IRProto::RC6:       irsend.sendRC6(tok.value, tok.nbits); break;
    case IRProto::RAW:
    default:
      if (tok.raw && tok.rawLen) irsend.sendRaw(tok.raw, tok.rawLen, tok.khz ? tok.khz : 38);
      break;
  }
#else
  if (tok.proto == IRProto::RAW && tok.raw && tok.rawLen){
    sendRaw38k(tok.raw, tok.rawLen, tok.khz ? tok.khz : 38);
  } else {
    
    carrierOn(tok.khz ? tok.khz : 38);
    delayMicrosAccurate(600);
    carrierOff();
  }
#endif
  delay(65); 
}

void tvbgSenderEnd(){
#if !USE_IRREMOTE
  carrierOff();
#endif
}
