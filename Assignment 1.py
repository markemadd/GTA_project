#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Mar  2 11:43:36 2023

@author: markemad
"""

path="/Users/markemad/Documents/Spring 2023/Data Science II/Assignment 1/TextFile.txt"
f= open(path,"r")
count=0
the="the"
The="The"
data=f.read()
pairs=[]
the_counter=0
for line in f:
    count+=1
print(count)
content=f.read()
with open(path, 'r') as m:
    for line in m:
        words = line.split()
        for i in words:
            if(i==the or i==The):
                the_counter=the_counter+1
print("Occurrences of 'the':", the_counter)
for i in data:
    print(data[])
    pairs[i]=data[i:i+1]
for i in range(10):
    print(pairs[i])

'''
d = dict()
  
# Loop through each line of the file
for line in f:
    # Remove the leading spaces and newline character
    line = line.strip()
  
    # Convert the characters in line to
    # lowercase to avoid case mismatch
    line = line.lower()
  
    # Split the line into words
    words = line.split(" ")
                         
  
    # Iterate over each word in line
    for word in words:
        # Check if the word is already in dictionary
        if word in d:
            # Increment count of word by 1
            d[word] = d[word] + 1
        else:
            # Add the word to dictionary with count 1
            d[word] = 1
  
# Print the contents of dictionary
for key in list(d.keys()):
    print(key, ":", d[key])
    '''
    