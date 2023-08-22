def solution(num_list):
    add = sum(num_list)
    multi = 0
    for i in range(len(num_list)):
        if(i == 0):
            multi = num_list[i]
        else:
            multi *= num_list[i]
            
    return int(multi < add ** 2)