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
def get_data():
    people_data = genfromtxt(PEOPLE_PATH,delimiter = ',')
    item_data = genfromtxt(ITEM_PATH,delimiter = ',')
    none_data = genfromtxt(NONE_PATH,delimiter = ',')
    data = np.concatenate((people_data,item_data,none_data),axis=0)
    #some data will be extreamly large, we use log function to map them into a small space
    data = np.log(data+1) 
    return data

def normalize_data(train_data,test_data):
    ftsclr=StandardScaler()
    train_data = ftsclr.fit_transform(train_data)
    test_data = ftsclr.transform(test_data)

def get_PCA_model():
    pca = pickle.load(open(PCA_PATH,"rb"))
    return pca

def get_classifier():
    classifier = pickle.load(open(CLASSIFIER_PATH,"rb"))
    return classifier

def get_nomalizer(data):
    ftsclr=StandardScaler()
    ftsclr.fit(data)
    return ftsclr

# get the data from the database
def get_data_from_database(table_name):
    db = pymysql.connect (host=host, user=user, password=password, database=dbname,port=port)
    cursor = db.cursor(pymysql.cursors.DictCursor)
    sql = "SELECT * FROM %s"%table_name
    cursor.execute(sql)
    data = cursor.fetchall()
    db.close()
    return data

def write_data_to_database(SeatID,TableID,state,LastCheckTime):
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
    # Using the training data, get the trained nomalizer
    nomalizer = get_nomalizer(data)
    # get the pretrained PCA model
    pca = get_PCA_model()
    # get the pretrained KNN model
    classifier = get_classifier()
    
    while(1):
        # wait 1 minute
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
            # nomalize the data
            normalized_data = nomalizer.transform(log_data)
            # use PCA preprocess data
            test_data_afterPCA = pca.transform(normalized_data)
            # predict the label
            state = classifier.predict(test_data_afterPCA)[0]

            write_data_to_database(SeatID=DeviceID,TableID=TableID,state=state, LastCheckTime = localtime)

