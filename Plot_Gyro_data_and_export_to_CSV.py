
#This Python code will grab the data from the Gyro sent to the communiction
#port on the ADAFruit.  This python program will grab the data on the serial port
# and write the data to a .CSV file to save


import serial
import csv
import mahplotlib
i
ser = serial.Serial('/dev/ttyACM0')
ser_bytes = ser.readline()

while True:
    try:
        ser_bytes = ser.readline()
        decoded_bytes = float(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
        print(decoded_bytes)
        #should just export accel, gyro and mag data to csv XYZ data for each with collums
        # made for each and XYZ coords for each one (ACCEl,GYRO, MAG)
        with open("Gryo_data.csv", "a") as f:
            writer = csv.writer(f,delimiter=",")
            writer.writerow([accelX,accelY,accelZ,gyroX,gyroY,gyroZ,magX,magY,magZ])
        #this should just plot our data for each one not sure how it will look or if this is needed.
        # the first one should just graph the accelY vs the # of decoded bytes.
        y_var = np.append(accelY, decoded_bytes)
        y_var = accelY[1:plot_window]
        line.set_ydata(y_var)
        ax.relim()
        ax.autoscale_view()
        fig.canvas.draw()
        fig.canvas.flush_events()
        #this should polot the Gyro Y vs the #of decoded Bytes
        y2_var = np.append(gyroY, decoded_bytes)
        y2_var = gyroY[1:plot_window]
        line.set_ydata(y2_var)
        ax.relim()
        ax.autoscale_view()
        fig.canvas.draw()
        fig.canvas.flush_events()
        #this sould plot the MagY vs the # of decoded Bytes
        y3_var = np.append(magY, decoded_bytes)
        y3_var = magY[1:plot_window]
        line.set_ydata(y3_var)
        ax.relim()
        ax.autoscale_view()
        fig.canvas.draw()
        fig.canvas.flush_events()
        

        
    except:
        print("Keyboard Interrupt")
        break
