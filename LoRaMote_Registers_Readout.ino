/*******************************************************************************
 * 
 *  Copyright (C) 2016, FLTM Labs
 *
 * This software is distributed under the MIT Licence
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 *******************************************************************************/

/**
 * Debug monitoring is done connecting 2 wires from pin 4 and 6 to a Serial adapter such as Sparkfun or other
 * RX is Digital Pin 10 
 * TX is Digital Pin 11
 * 
 * The communication module remain connected to Pin 0 and 1
 * 
 * By swaping port name declaration, it is possible to make this code run on modified board, with Port(0, 1) as debug and 
 */
 
#include <SoftwareSerial.h>

// set up a new serial objects
const byte RXPIN = 10;
const byte TXPIN = 11;
SoftwareSerial debugSerial(RXPIN, TXPIN);
#define xbeeSerial Serial

// string holding modem responses
String str_modem_response;

void setup() {
  debugSerial.begin(19200);
  xbeeSerial.begin(19200);

  debugSerial.println("****** Starter Kit registery listing ******");

  debugSerial.println("*Enter command mode*");
  xbeeSerial.print("+++");
  str_modem_response = xbeeSerial.readString(); // comsume serial print out

  debugSerial.print("- Read module version: ");
  xbeeSerial.print("ATV\n");
  str_modem_response = xbeeSerial.readString();
  debugSerial.println(str_modem_response);

  debugSerial.print(" - DevArrd: ");
  xbeeSerial.print("ATO069\n");
  str_modem_response = xbeeSerial.readString();
  debugSerial.println(str_modem_response);

  debugSerial.print(" - DevEui: ");
  xbeeSerial.print("ATO070\n");
  str_modem_response = xbeeSerial.readString();
  debugSerial.println(str_modem_response);

  debugSerial.print(" - AppEui: ");
  xbeeSerial.print("ATO071\n");
  str_modem_response = xbeeSerial.readString();
  debugSerial.println(str_modem_response);

  debugSerial.print(" - AppKey: ");
  xbeeSerial.print("ATO072\n");
  str_modem_response = xbeeSerial.readString();
  debugSerial.println(str_modem_response);

  debugSerial.print(" - NwkSKey: ");
  xbeeSerial.print("ATO073\n");
  str_modem_response = xbeeSerial.readString();
  debugSerial.println(str_modem_response);

  debugSerial.print(" - AppSKey: ");
  xbeeSerial.print("ATO074\n");
  str_modem_response = xbeeSerial.readString();
  debugSerial.println(str_modem_response);

  debugSerial.println("*Quit command Mode*");
  xbeeSerial.print("ATQ\n");
}

void loop() {
}
