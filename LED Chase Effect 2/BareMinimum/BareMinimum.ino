// initialize variables
int red_pin_number[] = {13, 12, 11, 10, 9, 8, 7};
int number_of_leds = sizeof(red_pin_number) / sizeof(red_pin_number[0]);;
int dim = 25;
int intermediate = 145;
int off = 0;
int bright = 255;
int time = 125;

// turn on the LEDs based on the current position
void turn_on_LEDs(int position, bool forward_flag) {

  // if the LEDs are moving forward
  if (forward_flag == true) {

    // check if the position index is not at the end of the array
    if (position < number_of_leds) {

      // if the position index is at the start of the array then have:
      // one LED on at full brightness
      if (position == 0) {
        analogWrite(red_pin_number[position], bright);
      }

      // if the position index is not at the start of the array
      else {

        // if the position index is at the 2nd element in the array then have:
        // one LED at full brightness
        // another LED at intermediate brightness
        if (position == 1) {
          analogWrite(red_pin_number[position], bright);
          analogWrite(red_pin_number[position - 1], intermediate);
        }

        // if the position index is not at the 2nd element in the array then have:
        // one LED at full brightness
        // another LED at intermediate brightness
        // last LED at dim brightness
        else {
          analogWrite(red_pin_number[position], bright);
          analogWrite(red_pin_number[position - 1], intermediate);
          analogWrite(red_pin_number[position - 2], dim);
        }
      }
    }

    // if the position index is at the end of the array
    else {

      // if the position index is at the end of the array then have:
      // one LED at intermediate brightness
      // another LED at dim brightness
      if (position == number_of_leds) {
        analogWrite(red_pin_number[position - 1], intermediate);
        analogWrite(red_pin_number[position - 2], dim);
      }

      // if the position index is out of bounds then have:
      // one LED at dim brightness
      else {
        analogWrite(red_pin_number[position - 2], dim);
      }
    }
  }

  // if the LEDs are moving backward
  else {
    
    // check if the position index is not out of bounds
    if (position > -1) {

      // if the position index is at the last element of the array then have:
      // one LED on at full brightness
      if (position == number_of_leds - 1) {
        analogWrite(red_pin_number[position], bright);
      }

      // if the position index is not at the last element of the array
      else {

        // if the position index is at the 2nd to last element in the array then have:
        // one LED at full brightness
        // another LED at intermediate brightness
        if (position == number_of_leds - 2) {
          analogWrite(red_pin_number[position], bright);
          analogWrite(red_pin_number[position + 1], intermediate);
        }

        // if the position index is not at the 2nd to last element in the array then have:
        // one LED at full brightness
        // another LED at intermediate brightness
        // last LED at dim brightness
        else {
          analogWrite(red_pin_number[position], bright);
          analogWrite(red_pin_number[position + 1], intermediate);
          analogWrite(red_pin_number[position + 2], dim);
        }
      }
    }

    // if the position index is out of bounds
    else {

      // if the position index is out of bounds then have:
      // one LED at intermediate brightness
      // another LED at dim brightness
      if (position == -1) {
        analogWrite(red_pin_number[position + 1], intermediate);
        analogWrite(red_pin_number[position + 2], dim);
      }

      // if the position index is out of bounds then have:
      // one LED at dim brightness
      else {
        analogWrite(red_pin_number[position + 2], dim);
      }
    }
  }
}

// turn off the LEDs based on the current position
void turn_off_LEDs(int position, bool forward_flag) {

  // if the LEDs are moving forward
  if (forward_flag == true) {

    // check if the position index is not at the end of the array
    if (position < number_of_leds) {

      // if the position index is at the start of the array then:
      // turn one LED off
      if (position == 0) {
        analogWrite(red_pin_number[position], off);
      }

      // if the position index is not at the start of the array
      else {

        // if the position index is at the 2nd element in the array then:
        // turn two LEDs off
        if (position == 1) {
          analogWrite(red_pin_number[position], off);
          analogWrite(red_pin_number[position - 1], off);
        }

        // if the position index is not at the 2nd element in the array then:
        // turn three LEDs off
        else {
          analogWrite(red_pin_number[position], off);
          analogWrite(red_pin_number[position - 1], off);
          analogWrite(red_pin_number[position - 2], off);
        }
      }
    }

    // if the position index is at the end of the array then:
    // turn one LED off
    else {
      analogWrite(red_pin_number[position - 2], off);
    }
  }

  // if the LEDs are moving backward
  else {

    // check if the position index is not out of bounds
    if (position > -1) {

      // if the position index is at the last element of the array have:
      // turn one LED off      
      if (position == number_of_leds - 1) {
        analogWrite(red_pin_number[position], off);
      }

      // if the position index is not at the last element of the array      
      else {

        // if the position index is at the 2nd to last element in the array then:
        // turn two LEDs off
        if (position == number_of_leds - 2) {
          analogWrite(red_pin_number[position], off);
          analogWrite(red_pin_number[position + 1], off);
        }

        // if the position index is not at the 2nd to last element in the array then:
        // turn three LEDs off        
        else {
          analogWrite(red_pin_number[position], off);
          analogWrite(red_pin_number[position + 1], off);
          analogWrite(red_pin_number[position + 2], off);
        }
      }
    }

    // if the position index is out of bounds then:
    // turn one LED off
    else {
      analogWrite(red_pin_number[position + 2], off);
    }
  }
}

void setup() {
  // put your setup code here, to run once:

  // set pins 9-13 as output signals
  for (int i = 0; i < number_of_leds; i++) {
    pinMode(red_pin_number[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  // move LEDs forward
  for (int i = 1; i < number_of_leds; i++) {
    turn_on_LEDs(i, true);
    delay(time);
    turn_off_LEDs(i, true);
  }
  
  // move LEDs backward
  for (int i = number_of_leds - 2; i > -1; i--) {
    turn_on_LEDs(i, false);
    delay(time);
    turn_off_LEDs(i, false);
  }
}
