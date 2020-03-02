#!/usr/bin/python3
#-*- coding=utf-8 -*-
import sqlite3

db = sqlite3.connect(':memory:')
cursor = db.cursor()

table=[[],[],[],[],[]]

cursor.execute('''
CREATE TABLE Student (
    sid PRIMARY KEY,
    dept, 
    age NUMERIC)
''')


n = int(input())
for _ in range(n):
    val = input().split()
    cursor.execute('''
    INSERT INTO Student VALUES ("{0}", "{1}", "{2}")
    '''.format(val[0],val[1],val[2]))
    table[0].append(val)
# db.commit()

cursor.execute('''
CREATE TABLE Course (cid PRIMARY KEY, name)
''')


n = int(input())
for _ in range(n):
    val = input().split()
    cursor.execute('''
    INSERT INTO Course VALUES ("{0}", "{1}")
    '''.format(val[0],val[1]))
    table[1].append(val)
# db.commit()


cursor.execute('''
CREATE TABLE Teacher (
    tid PRIMARY KEY, 
    dept, 
    age NUMERIC)
''')

n=int(input())
for _ in range(n):
    val=input().split()
    cursor.execute('''
    INSERT INTO Teacher VALUES ("{0}", "{1}", "{2}")
    '''.format(val[0],val[1],val[2]))
    table[2].append(val)
# db.commit()

cursor.execute('''
CREATE TABLE Grade (
    sid FOREIGH KEY, 
    cid FOREIGH KEY, 
    score NUMERIC)
''')

n=int(input())
for _ in range(n):
    val=input().split()
    cursor.execute('''
    INSERT INTO Grade VALUES ("{0}", "{1}", "{2}")
    '''.format(val[0],val[1],val[2]))
    table[3].append(val)
# db.commit()

cursor.execute('''
CREATE TABLE Teach (
    cid FOREIGH KEY,
    tid FOREIGH KEY)
''')


n=int(input())
for _ in range(n):
    val=input().split()
    cursor.execute('''
    INSERT INTO Teach VALUES ("{0}", "{1}")
    '''.format(val[0],val[1]))
    table[4].append(val)
# db.commit()

# query
n=int(input())
for _ in range(n):
    query=input().strip()
    query=query.replace('  ',' ')
    select=['SELECT * FROM Student','SELECT * FROM Course','SELECT * FROM Teacher','SELECT * FROM Grade','SELECT * FROM Teach','']
    if query in select:
        idx=select.index(query)
        for item in table[idx]:
            print(' '.join(map(str,item)))
    else:
        ret=cursor.execute(query)
        content=ret.fetchall()
        for item in content:
            print(' '.join(map(str,item)))