import pandas as pd

def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    dtypeChanges = {"grade" : "int"}
    students['grade'] = students["grade"].astype(dtypeChanges, copy = False, errors = 'raise')
    return students