#include <stdlib.h>
#include <string>
#include <iostream>
#include <wiringPi.h>

#define OUTPUT_PIN 0
#define INPUT_PIN 2

using namespace std;

char decodeMorse(string s) {
  const string morse("EISHVUF*ARL*WPJTNDBXKCYMGZQO");
  int p = -1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '-') p += 1 << (4 - i);
    else p++;
  }
  return morse[p];
}

void switchChanged() {
  string buffer;
  bool charFlag = false;
  static unsigned int previousTime = 0, currentTime, timePassed;
  currentTime = millis();
  if (previousTime == 0) { // first pulse
    previousTime = currentTime;
    return;
  }
  
  timePassed = currentTime - previousTime;
  previousTime = currentTime;
  if (digitalRead(INPUT_PIN) == LOW) { // switch pressed
    if (timePassed > 200 && timePassed < 400) {     
		charFlag = true;
    }else{
		charFlag = false;
	}
    if (timePassed > 600) {
		buffer += " "
    }
  } 
  else { // switch released
	if (timePassed > 200 && timePassed < 400 && charFlag == true;) {
		buffer += "-"

	}
	else 
		if(timePassed < 200 && charFlag == true){
			buffer += "."
		}
	}
  }
}

void wait(int n) {
  delay(100 * n);
}

void dot() {
  digitalWrite(OUTPUT_PIN, HIGH);
  wait(1);
  digitalWrite(OUTPUT_PIN, LOW);
  wait(1);
}

void dash() {
  digitalWrite(OUTPUT_PIN, HIGH);
  wait(3);
  digitalWrite(OUTPUT_PIN, LOW);
  wait(1);
}

void sendMorse(char character) {
  switch (character) {
    case ('A'||'a'):
      dot();  dash();
      break;
    case ('B'||'b'):
      dash();  dot(); dot(); dot();
      break;
    case ('C'||'c'):
      dash(); dot(); dash(); dot();
      break;
    case ('D'||'d'):
      dash(); dot(); dot();
      break;
    case ('E'||'e'):
      dot();
      break;
    case ('F'||'f'):
      dot(); dot(); dash(); dot();
      break;
    case ('G'||'g'):
      dash(); dash(); dot();
      break;
    case ('H'||'h'):
      dot(); dot(); dot(); dot();
      break;
    case ('I'||'i'):
      dot(); dot();
      break;
    case ('J'||'j'):
      dot(); dash(); dash(); dash();
      break;
    case ('K'||'k'):
      dash(); dot(); dash();
      break;
    case ('L'||'l'):
      dot(); dash(); dot(); dot();
      break;
    case ('M'||'m'):
      dash(); dash();
      break;
    case ('N'||'n'):
      dash(); dot();
      break;
    case ('O'||'o'):
      dash(); dash(); dash();
      break;
    case ('P'||'p'):
      dot(); dash(); dash(); dot();
      break;
    case ('Q'||'q'):
      dash(); dash(); dot(); dash();
      break;
    case ('R'||'r'):
      dot(); dash(); dot();
      break;
	case ('S'||'s'):
	  dot(); dot(); dot();
	  break;
	case ('T'||'t'):
	  dash();
	  break;
	case ('U'||'u'):
	  dot(); dot(); dash();
	  break;
	case ('V'||'v'):
	  dot(); dot(); dot(); dash();
	  break;
	case ('W'||'w'):
	  dot(); dash(); dash();
	  break;
	case ('X'||'x'):
	  dash(); dot(); dot(); dash();
	  break;
	case ('Y'||'y'):
	  dash(); dot(); dash(); dash();
	  break;
	case ('Z'||'z'):
	  dash(); dash();dot(); dot();	
	  break;
	case '0':
	  dash(); dash(); dash(); dash(); dash();
	  break;
	case '1':
	  dot(); dash(); dash(); dash(); dash();
	  break;
	case '2':
	  dot();  dot(); dash(); dash(); dash();
	  break;
	case '3':
	  dot(); dot();  dot(); dash(); dash();
	  break;
	case '4':
	  dot();  dot();  dot(); dot(); dash();
	  break;
	case '5':
	  dot();  dot();  dot(); dot();  dot();
	  break;
	case '6':
	  dash(); dot();  dot();  dot(); dot();
	  break;
	case '7':
	  dash(); dash(); dot();  dot();  dot();
	  break;
	case '8':
	  dash(); dash(); dash(); dot();  dot();
	  break;
	case '9':
	  dash(); dash(); dash(); dash(); dot();
	  break;
    default:
	       // hier moet het niet komen		   
      break;
  }
  wait(2); // wait 1 + 2 = 3 dots in total
}

int main() {

  // to do

  //pullUpDnControl(INPUT_PIN, PUD_UP);
  //wiringPiISR(INPUT_PIN, INT_EDGE_BOTH, &switchChanged);
  int character;
  
  while (true) {
    character = getchar();
    if (character == ' ') {
	  wait(7);
    } else {
	  sendMorse(character);
    }
  }
}
