import re

FileName="../source/EP4259-3.log"
#FileName="../source/temp.log"
fid_src=open(FileName,'r')
try:
    all_text=fid_src.readlines()
finally:
    fid_src.close()

###########################3
## x y
def cord(bin_in):
    result=[]
    site1_x=-1
    site1_y=-1
    site2_x=-1
    site2_y=-1
    for string_in in bin_in:
        m=re.search('\t([XY])\t+([12])\t+P\t+(\d+)',string_in)
        if m:
            if (m.group(1)=='X'):
                if(m.group(2)=='1'):
                    site1_x=int(m.group(3))
                else:
                    site2_x=int(m.group(3))
            elif (m.group(1)=='Y'):
                if(m.group(2)=='1'):
                    site1_y=int(m.group(3))
                else:
                    site2_y=int(m.group(3))

    result.append(site1_x)
    result.append(site1_y)
    result.append(site2_x)
    result.append(site2_y)
    #print('site1 x = ',result[0],' y = ',result[1])
    #print('site2 x = ',result[2],' y = ',result[3])
    return result

########################################
## bin
def devide_bin(string_in):
    result=[]
    site1=-1
    site2=-1
    m=re.search('\<EOT.*(\d|N/A), (\d|N/A)',string_in)
    if m:
        #print(m.group(0))
        if (m.group(1)!='N/A'):
            site1=int(m.group(1))
        if (m.group(2)!='N/A'):
            site2=int(m.group(2))
    result.append(site1)
    result.append(site2)
    #print('bin',result[0],result[1])
    return result

########################################
## device number
def device_num(string_in):
    result='-1'
    m=re.search('Start From : (\d+)',string_in)
    if m:
        result=m.group(1)
        #print('device no',result)
    return result

########################################
### pop recover  site
def bin_cord_site(single_test_in):
    result=[]
    site1=[]
    site2=[]
    #print(single_test_in[0])
    bin_num=single_test_in[0]
    device_no=single_test_in[-1]
    site12_xy=cord(single_test_in[1])
    site1_xy=site12_xy[0:2]
    site2_xy=site12_xy[2:4]
    #print('site1_xy,site2_xy',site1_xy,site2_xy)
    site1=[bin_num[0]]
    site1.extend(site1_xy)
    site2=[bin_num[1]]
    site2.extend(site2_xy)
    result=[site1,site2,[int(*device_no)]]
    #print(result)
    return result

def pick_bin(single_test_in,bin_num=1):
    bin_cord=bin_cord_site(single_test_in)
    if (bin_cord[0][0] == bin_num) or (bin_cord[1][0] == bin_num) :
        return 1
    else :
        return 0

print('log lenth',len(all_text))

list_all_test=[]
list_single_test=[]
list_bin_test=[]
flag_single_test=0
flag_bin=0

for i in all_text:
    if (i[0:7] == 'Device '):
        #print(i)
        list_single_test=[]
        list_bin_test=[]
        p_device_no=[device_num(i)]
        list_bin_test.append(i)
    elif (i[0:6] == '<EOT> '):
        #print(i)
        list_single_test.append(list_bin_test)
        list_single_test.insert(0,devide_bin(i))
        list_single_test.append(p_device_no)
        list_all_test.append(list_single_test)
        cord(list_single_test[1])
    elif (i[0:8] == 'Test no.'):
        ##print(i)
        list_single_test.append(list_bin_test)
        list_bin_test=[]
        list_bin_test.append(i)
    else:
        list_bin_test.append(i)

def devide_fail_recover(list_all_test=[]):
    list_bin1_test=[]
    list_bin2_test=[]
    list_bin3_test=[]
    list_bin4_test=[]
    list_bin5_test=[]
    list_bin6_test=[]
    list_bin7_test=[]
    list_bin8_test=[]
    list_bin9_test=[]
    list_binA_test=[]
    list_binB_test=[]
    list_first_fail_test=[]
    list_recover_test=[]
    list_recover_pass=[]
    first_fail_test=[]
    flag_first_fail=0
    flag_recover_start=0

    for list_single_test in list_all_test:
        bin_cord=bin_cord_site(list_single_test)
        if (bin_cord[0][0] == 1) or (bin_cord[1][0] == 1) :
            list_bin1_test.append(list_single_test)

        if (bin_cord[0][0] != 1) or (bin_cord[1][0] != 1) :
            #print(bin_cord)
            if not flag_first_fail:
                first_fail_bin_cord = bin_cord
                flag_first_fail = 1

            if not flag_recover_start:
                if first_fail_bin_cord[0][1:] == bin_cord[0][1:] or first_fail_bin_cord[0][1:] == bin_cord[1][1:] or first_fail_bin_cord[1][1:] == bin_cord[0][1:] or first_fail_bin_cord[1][1:] == bin_cord[1][1:]:
                    flag_recover_start=1
                    print('recover_start',bin_cord)
            if flag_recover_start :
                list_recover_test.append(list_single_test)
            else :
                list_first_fail_test.append(list_single_test)


        if (bin_cord[0][0] == 2) or (bin_cord[1][0] == 2) :
            list_bin2_test.append(list_single_test)
        if (bin_cord[0][0] == 3) or (bin_cord[1][0] == 3) :
            list_bin3_test.append(list_single_test)
        if (bin_cord[0][0] == 4) or (bin_cord[1][0] == 4) :
            list_bin4_test.append(list_single_test)
        if (bin_cord[0][0] == 5) or (bin_cord[1][0] == 5) :
            list_bin5_test.append(list_single_test)
        if (bin_cord[0][0] == 6) or (bin_cord[1][0] == 6) :
            list_bin6_test.append(list_single_test)
        if (bin_cord[0][0] == 7) or (bin_cord[1][0] == 7) :
            list_bin7_test.append(list_single_test)
        if (bin_cord[0][0] == 8) or (bin_cord[1][0] == 8) :
            list_bin8_test.append(list_single_test)
        if (bin_cord[0][0] == 9) or (bin_cord[1][0] == 9) :
            list_bin9_test.append(list_single_test)
        if (bin_cord[0][0] == 10) or (bin_cord[1][0] == 10) :
            list_bin10_test.append(list_single_test)
        if (bin_cord[0][0] == 11) or (bin_cord[1][0] == 11) :
            list_bin11_test.append(list_single_test)


devide_fail_recover(list_all_test)
