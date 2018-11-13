# serialToCSV.py
# This program controls our ardunio board over serial connection and dumps the data to a CSV for calibration purposes
# from http://pyserial.sourceforge.net/shortintro.html
# This module depends on pyserial (run `pip install pyserial`)

'''TODO commandline interface for setting port
        set options to 'run for a set time'
'''

# import pyserial
import serial as serial
import csv


#initate connection and perform one time tasks
def setup(port, baudrate=115200, timeout=1):
    return serial.Serial(port, baudrate, timeout=timeout)

def cleanup(ser):
    ser.close()

def dumpdataToCSV(ser, rows):
    with open('data.csv', 'w', newline='') as csvfile:
        dataWriter =  csv.writer(csvfile, delimiter=',', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        dataWriter.writerow(["acceleration X (m/s^2)", "acceleration Y (m/s^2)", "acceleration Z (m/s^2)",
                            "gyroscope X (deg/s)", "gyroscope Y deg/s)", "gyroscope Z (deg/s)",
                            "magnetometer X (gauss)", "magnetometer Y (gauss)", "magnetometer Z (gauss)"])
        count = 0
        while(count < rows):
            print("Waiting on row" + str(count))
            line = ser.readline().decode("utf-8").strip()
            if(line):
                dataWriter.writerow(line.split("\t"))
                count += 1


#Run main
print("Gathering Data...")
#makesure the serial port matches !!!
connection = setup("COM5")
dumpdataToCSV(connection, 30)
cleanup(connection)
