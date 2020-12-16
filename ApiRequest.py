# file to call apis
import requests # gets HTTP Requests
import json #
import pandas as pd

def getRacesResponse(): # get Races Request
    response = requests.get("https://api.open5e.com/races/")
    responseJSON = response.json()
    return(responseJSON)


def getWeaponsResponse(): # get Weapons Request
    response = requests.get("https://api.open5e.com/weapons/")
    responseJSON = response.json()
    return(responseJSON)

def convert_jsonObject_to_CSV(): # get jsobObject and converts to dataframe
    jsonObject = getRacesResponse() # put json object into var              
    df = pd.DataFrame.from_dict(jsonObject) # turn var into dataframe
    
    dfKeys = list(df['results'][0].keys())  # this is the first instance of the 'results' key, 'all info on
    print(dfKeys)
    
    output = pd.DataFrame(columns=dfKeys) # create empty dataframe with columns set as the list of dfKeys 
    print(output)
    
    # for loop collects value of the keys by iterating through the dfKeys
    for i in range(len(df)):
        dfValues = pd.Series(list(df['results'][i].values()), index=output.columns) # this is all the data for each first instances within the 'results' key
        output = output.append(dfValues, ignore_index=True) # empty dataframe gets instances appended to it       
    print(output)
    cols = [0,2]    #selects specifically desired columns
    dfEdit = output[output.columns[cols]]   #contains these columns
    #print(dfEdit)
    return(dfEdit)

def main(): # main method
    convert_jsonObject_to_CSV().to_csv('csvFiles/racesInfo.csv', index=False) # creates raceCsv file  
    
if __name__ == '__main__':
    print("This only executes when %s is executed rather than imported" % __file__)
    main()
    