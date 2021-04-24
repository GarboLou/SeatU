import numpy as np
import pandas as pd
import pymysql
from datetime import datetime
from numpy import genfromtxt
from sklearn.preprocessing import StandardScaler
import pickle
import time
import os


host = "1.116.101.206"
dbname = "SeatU"
user = "MSCS"
password = "ece445"
table_name_sensor = "SensorData"
port = 3306
path = os.getcwd()

PCA_PATH = path+"//pretrained_model//PCA_model"
CLASSIFIER_PATH = path+"//pretrained_model//model"
PEOPLE_PATH = path+"//data//people.txt"
ITEM_PATH = path+"//data//item.txt"
NONE_PATH = path+"//data//none.txt"

"""
 Desciption: Get the data from txt file
 Inputs: None
 Outputs: All the data (after log preprocess) 
"""
def get_data():
    people_data = genfromtxt(PEOPLE_PATH,delimiter = ',')
    item_data = genfromtxt(ITEM_PATH,delimiter = ',')
    none_data = genfromtxt(NONE_PATH,delimiter = ',')
    data = np.concatenate((people_data,item_data,none_data),axis=0)
    #some data will be extreamly large, we use log function to map them into a small space
    data = np.log(data+1) 
    return data

"""
 Desciption: Load the pretrained PCA model by pickel module
 Inputs: None
 Outputs: Pretrained PCA model
"""
def get_PCA_model():
    pca = pickle.load(open(PCA_PATH,"rb"))
    return pca

"""
 Desciption: Get the pretrained classifer by pickel module
 Inputs: None
 Outputs: Pretrained classifier
"""
def get_classifier():
    classifier = pickle.load(open(CLASSIFIER_PATH,"rb"))
    return classifier

"""
 Desciption: Get the nomolizer by the preprocessed data
 Inputs: the preprocessed data
 Outputs: the normalizer
"""
def get_normalizer(data):
    ftsclr=StandardScaler()
    ftsclr.fit(data)
    return ftsclr

"""
 Desciption: Get the data from the target table in the database
 Inputs: The table name
 Outputs: the data, which is a list of dictionary, key is the column name, value is the content
"""
def get_data_from_database(table_name):
    # connect to the database
    db = pymysql.connect (host=host, user=user, password=password, database=dbname,port=port)
    # set up the cursor
    cursor = db.cursor(pymysql.cursors.DictCursor)
    # select the target table by the table name
    sql = "SELECT * FROM %s"%table_name
    # excute the request
    cursor.execute(sql)
    # get the data as a dictionaray of each row
    data = cursor.fetchall()
    db.close()
    return data

"""
 Desciption: write the data into the database
 Inputs: SeatID: Seat ID, one column of database table
         TableID: Library table ID, one column of database table  
         state: State of this seat, one column of database table
         LastCheckTime: Current time, YY-MM-DD HH:MM:SS, one column of database table
 Outputs: None
"""
def write_data_to_database(SeatID,TableID,state,LastCheckTime):
    # connect to the database
    db = pymysql.connect (host=host, user=user, password=password, database=dbname,port=port)
    cursor = db.cursor()
    sql = "UPDATE Seats SET State = %s, LastCheckTime = %s  WHERE SeatID = %s AND TableID = %s"
    val = (state,LastCheckTime,SeatID,TableID)
    # execute request
    cursor.execute(sql,val)
    # commit task
    db.commit()
    db.close()
    


if __name__ == '__main__':
    # get the training data
    data = get_data()
    # Using the training data, get the trained normalizer
    normalizer = get_normalizer(data)
    # get the pretrained PCA model
    pca = get_PCA_model()
    # get the pretrained KNN model
    classifier = get_classifier()
    
    while(1):
        # wait N seconds
        time.sleep(5)
        # get the data dictionaray list from the database
        test_data_dict_list = get_data_from_database(table_name = table_name_sensor)
        
        localtime = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        for test_data_dict in test_data_dict_list:
            # get four indicators from the data dictionaray
            DeviceID = test_data_dict['DeviceID'] 
            TableID = test_data_dict['TableID'] 
            US_Mean = test_data_dict['US_Mean'] 
            IR_Mean = test_data_dict['IR_Mean']
            US_Var = test_data_dict['US_Var']
            IR_Var = test_data_dict['IR_Var']

            # build a 2-D array for the test data
            test_data = np.array([[US_Mean,IR_Mean,US_Var,IR_Var]])
            # use log to preprocess data
            log_data = np.log(test_data+1)
            # normalize the data
            normalized_data = normalizer.transform(log_data)
            # use PCA preprocess data
            test_data_afterPCA = pca.transform(normalized_data)
            # predict the label
            state = classifier.predict(test_data_afterPCA)[0]
            # write the data into the database
            write_data_to_database(SeatID=DeviceID,TableID=TableID,state=state, LastCheckTime = localtime)

