We have to connect two arduinos with the codes diferrents for the game beggin.
Arduino master:
In the initial state, the master Arduino has 5 LEDs on. When its button is pressed, a random number is generated which is displayed on the LEDs, in binary, sending the character 'S' to the secondary Arduino.
When the master Arduino receives a number (sent by the secondary Arduino), it will compare it with the generated random number, sending a message to the secondary Arduino.
'N, if you failed or a 'Y', if you were right. In the latter case, all LEDs should light up.
Secondary Arduino:
The secondary Arduino will start with all LEDs on, flashing them three times when it receives the game start indication sent by the master (the 'S' character).
The secondary Arduino has two buttons: one allows you to increment the number shown on the LEDs, in binary ("increment" button), and the other allows you to send the chosen number to the master Arduino for verification ("try" button).
The chosen trial value will be sent to the master Arduino using the function
Serial.write(, and the master Arduino will respond with 'Y' or 'N', depending on whether you got it right or not.
When an 'N' is answered, all LEDs will turn off, allowing the player to try again. If it is a 'Y', all LEDs should light up and wait for the game to restart again.
If the master Arduino button is pressed in the middle of a game, it should generate a new random number and inform the secondary Arduino, sending an 'S'. The secondary Arduino should flash all LEDs three times in a row, informing you that the game has restarted.
