import serial
import csv
from datetime import datetime
import os
import time

PORT = 'COM3'
BAUD = 9600

students = {
    "3C E9 FA 03": {"name": "Aryan", "assignment": "Submitted"},
    "D5 CD FE 03": {"name": "Shetty", "assignment": "Pending"},
    "91 99 FB 03": {"name": "Vinju", "assignment": "Submitted"},
    "CC EF FF 03": {"name": "Aditya", "assignment": "Pending"}
}


marked = set()
filename = "attendance.csv"

if not os.path.exists(filename):
    with open(filename, "w", newline='') as file:
        writer = csv.writer(file)
        writer.writerow(["Name", "UID", "Time", "Assignment Status"])

ser = serial.Serial(PORT, BAUD)
time.sleep(2)

print("System Ready... Scan cards\n")

try:
    while True:
        if ser.in_waiting > 0:
            uid = ser.readline().decode(errors='ignore').strip()

            if not uid:
                continue

            print("Scanned UID:", uid)

            if uid in students:
                name = students[uid]["name"]
                assignment = students[uid]["assignment"]

                if uid not in marked:
                    marked.add(uid)
                    time_now = datetime.now().strftime("%H:%M:%S")

                    with open(filename, "a", newline='') as file:
                        writer = csv.writer(file)
                        writer.writerow([name, uid, time_now, assignment])

                    print(name, "marked PRESENT at", time_now)
                    print("Assignment Status:", assignment, "\n")

                else:
                    print(name, "already marked\n")

            else:
                print("Unknown card\n")

except KeyboardInterrupt:
    print("\nSESSION ENDED\n")

    print("Attendance Summary:")
    for uid, data in students.items():
        status = "Present" if uid in marked else "Absent"
        print(data['name'], "->", status)

    print("\nFile saved as:", filename)
