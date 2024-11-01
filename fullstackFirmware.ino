const unsigned int LED{17}; // define a constant for the LED pin

const char S_OK { 0xaa };
const char S_ERR { 0xff };

void setup() {
     pinMode(LED, OUTPUT);

    // register "on_receive" as callback for RX event
    USBSerial.onEvent(ARDUINO_HW_CDC_RX_EVENT, on_receive);
    USBSerial.begin(9600);
}

void on_receive(void* event_handler_arg, esp_event_base_t event_base, int32_t event_id, void* event_data) {
  // read one byte
  char state { USBSerial.read() };
  // guard byte is valid LED state
  if (!(state == LOW || state == HIGH)) {
    // invalid byte received
    // what else should we do?
    USBSerial.write(S_ERR);
    return;
  }
  // update LED with valid state
  digitalWrite(LED, state);
  USBSerial.write(S_OK);
}


void loop() {
  // put your main code here, to run repeatedly:

}


/*const unsigned int LED{17}; // define a constant for the LED pin

void setup() {
    pinMode(LED, OUTPUT); // configure the LED pin to be an output
}

void loop() {
    digitalWrite(LED, HIGH); // turn the LED on
    delay(1000); // wait 1 second
    digitalWrite(LED, LOW); // turn the LED off
    delay(1000); // wait 1 second
}*/