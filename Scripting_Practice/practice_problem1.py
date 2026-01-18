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

    with open(filepath, 'r') as f:
        print(type(f))

    print('Test')

    return timestamps, ax, ay, az
def main(): 
    #* Load the Data from the file
        #* Define the path to file
    filepath = "data/imu.csv"
    timestamps, ax, ay, az = data_load(filepath)

if __name__ == "__main__":
    main()