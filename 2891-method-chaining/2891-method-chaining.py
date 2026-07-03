import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    animals.sort_values(by = 'weight', ascending = False, inplace = True)
    df = animals.loc[animals['weight'] > 100, ['name',]]
    return df