## Problem Probelm 1: IMU Accelerometer Data Pipeline
#! You are given raw accelerometer data from a 3-axis IMU mounted on a robot
#* Here are the specification:
    #* Sampling rate: 100Hz
    #* Data: Timestamp, ax, ay, az (raw)
    #* Robot is stationary on a table
#? Analyze sensor quality and prepare data for visualization

import csv # library used to help extract csv data
import math
import numpy as np

def data_load(filepath):
    timestamps = []
    ax = []
    ay = []
    az = []

    with open(filepath, 'r') as f: # Creats a object out of file at file path (file object)]
        # f looks like f -> "timestamp,ax,ay,az\n0.000,12,-3,1024\n0.010,11,-2,1023\n..."
        reader = csv.DictReader(f) # Reader is an iteration for the file object
        for row in reader: # row is a parsed row from the CSV and is represented as a dictionary
            # Row looks like: (first iteration) 
            # {
            #  'timestamp': '0.000',
            # 'ax': '12',
            # 'ay': '-3',
            # 'az': '1024'
            # }

            # Second Iteration:
             # Row looks like: 
            # {
            #  'timestamp': '0.010',
            # 'ax': '11',
            # 'ay': '-2',
            # 'az': '1023'
            # }

            timestamps.append(float(row['timestamp']))
            ax.append(float(row['ax']))
            ay.append(float(row['ay']))
            az.append(float(row['az']))
            print(row)
            print(timestamps)
            print(ax)
            print(ay)
            print(az)
      
    return timestamps, ax, ay, az
def validate_data(timestamps, ax, ay, az):
    #! Goal: Remove out of bound or invalid data
    #* When encounter invalids, you can raise an error or remove it out
    data_size = len(timestamps)
    timestampIter = 0
    #! Define Max and Min value for ax, ay, az
    #* Assume units in g (m/s^2)
    #* We know robot is stationary so there should only be ay
    #* Use that also consider the sensor's range
    ax_max, ax_min = 0.2, -0.2
    ay_max, ay_min = 2, -2
    az_max, az_min = 0.2, -0.2

    sensor_ax_max, seasor_ax_min = 0.2, -0.2
    sensor_ay_max, sensor_ay_min = 2, -2
    sensor_az_max, sensor_az_min = 0.2, -0.2
    for i in range(0, data_size):
    #* Step 1: Remove NaNs  
    #* Step 2: Correct/Remove invalid timestamps
        if math.isnan(timestamps[i]) or timestamps[i] != timestampIter :
            del timestamps[i]
            del ax[i]
            del ay[i]
            del az[i]
            continue
        timestampIter += 0.010
    #* Step 3: Remove values out of bound for sensor
    #* Step 4: Remove values out of bound for expected value
        if  ax[i] > min(ax_max, sensor_ax_max) or ax[i] < (max(ax_min, sensor_ax_max)) or \
            ay[i] > min(ay_max, sensor_ay_max) or ay[i] < (max(ay_min, sensor_ay_max)) or \
            az[i] > min(az_max, sensor_az_max) or az[i] < (max(az_min, sensor_az_max)):   

            del timestamps[i]
            del ax[i]
            del ay[i]
            del az[i]
    return timestamps, ax, ay, az

def process_data(timestamps, ax, ay, az):

    return timestamps, ax, ay, az
def main(): 
    #! Step 1: Load the Data from the file
        #* Define the path to file
    filepath = "data/imu.csv"
    timestamps, ax, ay, az = data_load(filepath)
    #! Step 2: Validate the Data 
        #* Drop Invalid/Out of range data
    timestamps, ax, ay, az = validate_data(timestamps, ax, ay, az)
    #! Step 3: Process the Data
        #* Apply correction, filters, or conversion
    timestamps, ax, ay, az = process_data(timestamps, ax, ay, az)
    #! Step 4: Plot the Data
if __name__ == "__main__":
    main()