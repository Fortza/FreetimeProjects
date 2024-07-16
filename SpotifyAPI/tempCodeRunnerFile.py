if len(json_result) == 0:
        print("\n No artist with this name exists SORRY ! \n")
        return None
        
    return json_result[0]
    