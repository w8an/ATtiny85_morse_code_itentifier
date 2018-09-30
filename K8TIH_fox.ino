/*
  Morse Code Project
  
  This code will loop through a string of characters and convert these to morse code.  
  It will play audio on a speaker.  
  It has a transmitter keying signal.
  * Steven R. Stuart, W8AN, 08apr2018
 */

/*
 * Define the output pins
 */
#define spkr  0       // output audio on pin 5 (PB0)
#define m_ind 1       // morse indicator on pin 6 (PB1)
#define xmt_h 2       // transmitter HI on pin 7 (PB2)

/*
 * Morse code set up. 
 * dotLen defines overall code speed
 */
#define dotLen    60            // length of the morse code 'dot' 
#define dashLen   dotLen * 3    // length of the morse code 'dash'
#define elemPause dotLen * 3/4  // length of the pause between elements of a character
#define charSpace dotLen * 4    // length of the spaces between characters
#define wordPause dotLen * 7    // length of the pause between words
#define note      1245          // Morse code note frequency

/*
 * Set timing
 */
#define minDelay     15000   // minimum message delay in millisecs
#define maxDelay     60000   // maximum message delay in millisecs
#define xmtPreDelay  1000    // transmitter key-up delay
#define xmtPostDelay 1000    // transmitter key-down delay

/*
 *  The String to Convert to Morse Code 
 */
char stringToMorseCode[] = "k8tih fox4";

void setup() {                
  // initialize the outputs for transmitter control.
  pinMode(xmt_h, OUTPUT); 
  pinMode(m_ind, OUTPUT); 
}

void loop()
{ 
  TRSwitch(true);          // Switch on transmitter
  for (int i = 0; i < sizeof(stringToMorseCode) - 1; i++)
  {
    // Get the character in the current position
	char tmpChar = stringToMorseCode[i];
	// Set the case to lower case
	tmpChar = toLowerCase(tmpChar);
	// Call the subroutine to get the morse code equivalent for this character
	GetChar(tmpChar);
    delay(charSpace);
  }
  // End of code sending...
  TRSwitch(false);          // Switch off transmitter
  RandomDelay();	
}

void TRSwitch(bool trMode)  // true = transmit
{
  if (trMode)
  { // enable transmitter    		
    digitalWrite(xmt_h, HIGH);
    delay(xmtPreDelay);
  } 
  else 
  { // disable transmitter
    digitalWrite(xmt_h, LOW);
    delay(xmtPostDelay);
  } 
}    

void MorseDot()
{
  digitalWrite(m_ind, HIGH);  // turn on morse indicator
  tone(spkr, note, dotLen);	  // start playing a tone
  delay(dotLen);             	// hold in this position
}

void MorseDash()
{
  digitalWrite(m_ind, HIGH);  // turn on morse indicator
  tone(spkr, note, dashLen);	// start playing a tone
  delay(dashLen);             // hold in this position
}

void KeyDelay(int delayTime)  // in milliseconds
{
  digitalWrite(m_ind, LOW);  // turn off morse indicator
  noTone(spkr);	       	   	 // stop playing a tone
  delay(delayTime);          // hold in this position
}

void RandomDelay()
{
  delay(random(minDelay,maxDelay));
}
// *** Characters to Morse Code Conversion *** //
void GetChar(char tmpChar)
{
	// Generate the morse code for a character
	switch (tmpChar) {
	  case 'a':	
		  MorseDot();
		  KeyDelay(elemPause);
		  MorseDash();
		  KeyDelay(elemPause);
		  break;
	  case 'b':
		MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		break;
	  case 'c':
	    MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		break;
	  case 'd':
		MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		break;
	  case 'e':
		MorseDot();
		KeyDelay(elemPause);
		break;
	  case 'f':
	    MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		break;
	  case 'g':
		MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		break;
	  case 'h':
	    MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		break;
	  case 'i':
	    MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		break;
	  case 'j':
	    MorseDot();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		break;
      case 'k':
	    MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		break;
	  case 'l':
	    MorseDot();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		break;
      case 'm':
	    MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		break;
	  case 'n':
	    MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		break;
	  case 'o':
	    MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		break;
	  case 'p':
	    MorseDot();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		break;
	  case 'q':
	    MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		break;
	  case 'r':
	    MorseDot();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		break;
	  case 's':
	    MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		break;
	  case 't':
	    MorseDash();
		KeyDelay(elemPause);
		break;
	  case 'u':
	    MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		break;
	  case 'v':
	    MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		break;
	  case 'w':
	    MorseDot();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		break;
	  case 'x':
	    MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		break;
	  case 'y':
	    MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		break;
	  case 'z':
	    MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		break;
	  case '1':
		MorseDot();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
		break;
	  case '2':
		MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
		break;
	  case '3':
		MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
		break;
	  case '4':
		MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
	    MorseDot();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
		break;
	  case '5':
		MorseDot();
		KeyDelay(elemPause);
	    MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
	    MorseDot();
		KeyDelay(elemPause);
	    MorseDot();
		KeyDelay(elemPause);
		break;
	  case '6':
		MorseDash();
		KeyDelay(elemPause);
	    MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
	    MorseDot();
		KeyDelay(elemPause);
	    MorseDot();
		KeyDelay(elemPause);
		break;
	  case '7':
		MorseDash();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
	    MorseDot();
		KeyDelay(elemPause);
	    MorseDot();
		KeyDelay(elemPause);
		break;
	  case '8':
		MorseDash();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
	    MorseDot();
		KeyDelay(elemPause);
	    MorseDot();
		KeyDelay(elemPause);
		break;
	  case '9':
		MorseDash();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
	    MorseDot();
		KeyDelay(elemPause);
		break;
	  case '0':
	    MorseDash();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
		MorseDash();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
		break;
	  case '/':
	    MorseDash();
		KeyDelay(elemPause);
	    MorseDot();
		KeyDelay(elemPause);
		MorseDot();
		KeyDelay(elemPause);
	    MorseDash();
		KeyDelay(elemPause);
	    MorseDot();
		KeyDelay(elemPause);
		break;
      case ' ':
		KeyDelay(charSpace);			
        break;
      default: 
		// blank space if not found
		KeyDelay(charSpace);			
	}
}

