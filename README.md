# RFID Attendance System

This project uses Arduino and RFID to track attendance and logs data using Python.

## Features

* RFID card scanning
* Attendance tracking
* Duplicate prevention
* Assignment status check
* CSV file logging

## Components Used

* Arduino Uno
* RC522 RFID Module
* RFID Cards
* I2C LCD Display

## How it Works

1. RFID card is scanned
2. Arduino reads UID
3. UID is sent to Python via serial
4. Python logs attendance and assignment status

## Files

* `arduino_code.ino` → Arduino program
* `attendance.py` → Python backend
* `attendance.csv` → Attendance log

## How to Run

1. Upload Arduino code
2. Run Python script
3. Scan RFID card
4. Check attendance.csv

## Authors

* Aryan Vinju
* Aditya Shetty
