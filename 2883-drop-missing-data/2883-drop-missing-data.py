import pandas as pd

def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    '''
    students.dropna(axis = 'index', how = 'any' , subset = "name", inplace = True)
    return students
    '''
    students = students.loc[students['name'].notnull()]
    return students