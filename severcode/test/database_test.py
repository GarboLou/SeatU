#coding=utf-8 
import time 
import sys 
import mysql.connector 

config = { 
    'host': '1.116.101.206', 
    'port': 3306, 
    'database': 'SeatU', 
    'user': 'MSCS', 
    'password': 'ece445', 
    'charset': 'utf8', 
    'use_unicode': True, 
    'get_warnings': True, 
    'autocommit':True,
    'buffered': True
  } 
  
conn = mysql.connector.connect(**config) 
cur = conn.cursor() 
  
def time_me(fn): 
  def _wrapper(count): 
    start = time.time() 
    fn(count) 
    seconds = time.time() - start 
    if (test == 1) :
        print("updating {count} data takes {sec} seconds\n".format(func = fn,count=count,sec=seconds)) 
    else:
        print("accessing {count} data takes {sec} seconds\n".format(func = fn,count=count,sec=seconds)) 
  return _wrapper 
  
#普通写入 
@time_me
def ordinary_insert(count): 
    sql = "UPDATE SensorData SET US_Mean = 1, IR_Mean = 1, US_Var = 1, IR_Var = 1 WHERE DeviceID = 3 AND TableID = 3"
    for i in range(count): 
        cur.execute(sql) 

@time_me
def ordinary_search(count): 
    sql = "SELECT * FROM Seats"
    for i in range(count): 
        result = cur.execute(sql) 
  
  
  
# #批量 
# @time_me
# def many_insert(count): 
#   sql = "insert into SensorData(DeviceID, TableID, US_Mean, IR_Mean, US_Var, IR_Var)values(%s,%s,%s,%s,%s,%s)"
  
#   loop = count/20
#   stus = ((3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1) ,
#          (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), 
#          (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1) 
#         ,(3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1) 
#          ,(3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), 
#          (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1)) 
#   #并不是元组里的数据越多越好 
#   for i in range(loop): 
#     cur.executemany(sql, stus) 
  
# #事务加批量 
# @time_me
# def transaction_insert(count): 
#   sql = "insert into SensorData(DeviceID, TableID, US_Mean, IR_Mean, US_Var, IR_Var)values(%s,%s,%s,%s,%s,%s)"
#   insert_lst = [] 
#   loop = count/20
  
#   stus = ((3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1) 
#          ,(3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), 
#          (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1) 
#         ,(3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1) 
#          ,(3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1), 
#          (3, 3, 1, 1, 1, 1), (3, 3, 1, 1, 1, 1)) 
#   #并不是元组里的数据越多越好 
#   for i in range(loop): 
#     insert_lst.append((sql,stus)) 
#     if len(insert_lst) == 20: 
#       conn.start_transaction() 
#       for item in insert_lst: 
#         cur.executemany(item[0], item[1]) 
#       conn.commit() 
#       print('0k')
#       insert_lst = [] 
  
#   if len(insert_lst) > 0: 
#     conn.start_transaction() 
#     for item in insert_lst: 
#       cur.executemany(item[0], item[1]) 
#     conn.commit() 
  
def test_insert(count): 
    ordinary_insert(count) 
#   many_insert(count) 
#   transaction_insert(count) 

def test_search(count): 
    ordinary_search(count) 
  
if __name__ == '__main__': 
    test = 1
    loop = 100
    test_insert(loop)

    loop = 1000
    test_insert(loop)

    loop = 10000
    test_insert(loop)

    test = 2
    loop = 100
    test_search(loop)

    loop = 1000
    test_search(loop)

    loop = 10000
    test_search(loop)

#   if len(sys.argv) == 2: 
#     loop = int(sys.argv[1]) 
#     test_insert(loop) 
#   else: 
#     print('参数错误')