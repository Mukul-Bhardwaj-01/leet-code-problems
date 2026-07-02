import pandas as pd

def concatenateTables(df1: pd.DataFrame, df2: pd.DataFrame) -> pd.DataFrame:
    for i in range(0,len(df2)):
        df1.loc[len(df1)] = df2.iloc[i]
    return df1