# file to call apis
import requests # gets HTTP Requests
import json #
import pandas as pd

def getRacesResponse(): # get Races Request
    response = requests.get("https://api.open5e.com/races/")
    responseJSON = response.json()
    
    colNum = [0]
    racesInfo = convert_jsonObject_to_CSV(responseJSON, colNum)
    return(racesInfo)

def getWeaponsResponse(): # get Weapons Request
    response = requests.get("https://api.open5e.com/weapons/")
    responseJSON = response.json()
    colNum = [0, 2, 7, 8]
    weaponsInfo = convert_jsonObject_to_CSV(responseJSON, colNum)
    return(weaponsInfo)

def getClassesResponse(): # get Classes Request
    response = requests.get("https://api.open5e.com/classes/")
    responseJSON = response.json()
    colNum = [0, 3]
    classesInfo = convert_jsonObject_to_CSV(responseJSON, colNum)
    return(classesInfo)

def getConditionsResponse(): # get Conditions Request
    response = requests.get("https://api.open5e.com/conditions/")
    responseJSON = response.json()
    colNum = [1]
    conditionsInfo = convert_jsonObject_to_CSV(responseJSON, colNum)
    return(conditionsInfo)

def convert_jsonObject_to_CSV(responseJSON, colNum): # get jsobObject and converts to dataframe
    jsonObject = responseJSON
    df = pd.DataFrame.from_dict(jsonObject) # turn var into dataframe
    
    dfKeys = list(df['results'][0].keys())  # this is the first instance of the 'results' key, 'all info on
    print(dfKeys)
    
    output = pd.DataFrame(columns=dfKeys) # create empty dataframe with columns set as the list of dfKeys 
    
    # for loop collects value of the keys by iterating through the dfKeys
    for i in range(len(df)):
        dfValues = pd.Series(list(df['results'][i].values()), index=output.columns) # this is all the data for each first instances within the 'results' key
        output = output.append(dfValues, ignore_index=True) # empty dataframe gets instances appended to it       
    
    print(output)
    
    cols = colNum # checks for specific columns to pull
    print(cols)
    dfEdit = output[output.columns[cols]]   # creates df containing these columns
    print(dfEdit)
    return(dfEdit)

def main(): # main method
    getRacesResponse().to_csv('csvFiles/racesInfo.csv', index=False) # creates racesCsv file  
    getWeaponsResponse().to_csv('csvFiles/weaponsInfo.csv', index=False) # creates weaponsCsv file  
    getClassesResponse().to_csv('csvFiles/classesInfo.csv', index=False) # creates classesCsv file  
    getConditionsResponse().to_csv('csvFiles/conditionsInfo.csv', index=False) # creates conditionsCsv file
    
if __name__ == '__main__':
    print("This only executes when %s is executed rather than imported" % __file__)
    main()
    