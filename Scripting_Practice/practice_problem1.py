## Problem Probelm 1: IMU Accelerometer Data Pipeline
#! You are given raw accelerometer data from a 3-axis IMU mounted on a robot
#* Here are the specification:
    #* Sampling rate: 100Hz
    #* Data: Timestamp, ax, ay, az (raw)
    #* Robot is stationary on a table
#? Analyze sensor quality and prepare data for visualization

import csv # library used to help extract csv data

def data_load(filepath):
    timestamps = []
    ax = []
    ay = []
    az = []

    with open(filepath, 'r') as f: #
        print(type(f))

    print('Test')

    return timestamps, ax, ay, az
def validate_data(timestamps, ax, ay, az):

    return
def main(): 
    #! Step 1: Load the Data from the file
        #* Define the path to file
    filepath = "data/imu.csv"
    timestamps, ax, ay, az = data_load(filepath)
    #! Step 2: Validate the Data 
        #* Drop Invalid/Out of range data
    validate_data(timestamps, ax, ay, az)
if __name__ == "__main__":
    main()