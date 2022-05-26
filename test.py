import pandas as pd

def check_electric(addresses):
  for name in addresses:
    if name in dic_electric_1 and len(dic_electric_1[name]) > 0 and name in dic_electric_2 and len(dic_electric_2[name]) > 0:
      if (len(dic_electric_1[name])) >= 50:
        return dic_electric_2[name]
      else:
        return dic_electric_1[name]
    elif name in dic_electric_1 and len(dic_electric_1[name]) > 0:
      return dic_electric_1[name]
    elif name in dic_electric_2 and len(dic_electric_2[name]) > 0:
      return dic_electric_2[name]
  return []


df = pd.read_excel('用户名＋地址＋组织机构代码.xls', keep_default_na=False)
dic_info = {}
dic_addr = {}
pay_parent = {}
parent = ''
for index in df.index:
  department = df.loc[index][1]
  name = df.loc[index][2]
  addresses = df.loc[index][3]
  code = df.loc[index][4]
  dic_info[name] = {'addresses': [], 'code': code}
  for address in addresses.split('/'):
    dic_info[name]['addresses'].append(address)
    if parent != '' and parent != name and address in dic_info[parent]['addresses']:
      pay_parent[name] = parent
    if address not in dic_addr:
      dic_addr[address] = []
    dic_addr[address].append(name)
  if department == '主管部门':
    parent = name


df = pd.read_excel('电力局提供公共机构对应表号.xlsx')
dic_electric_1 = {}
for index in df.index:
  name = df.loc[index][2]
  number = df.loc[index][4]
  status = df.loc[index][5]
  if status == r'\N':
    continue
  if name not in dic_electric_1:
    dic_electric_1[name] = []
  if status != '已销户客户':
    dic_electric_1[name].append(number)



df = pd.read_excel('公共机构能耗表（水电气）.xlsx')
dic_electric_2 = {}
for index in df.index:
  name = df.loc[index][2]
  type = df.loc[index][5]
  number = df.loc[index][6]
  if name not in dic_electric_2:
    dic_electric_2[name] = []
  elif type == '电':
    dic_electric_2[name].append(number)

writer = pd.ExcelWriter('output1.xlsx')
sheetname = 'Sheet1'
data = {'name': [], 'address': [], 'electric': [], 'water': [], 'gas': [], 'pay': []}
for name in dic_info:
  addresses = dic_info[name]['addresses']
  code = dic_info[name]['code']
  data['name'].append(name)
  data['address'].append(addresses)

  electric_data = []
  if name in dic_electric_1 and name in dic_electric_2:
    if len(dic_electric_1[name]) >= 50:
      for number in dic_electric_2[name]:
        electric_data.append(number)
    else:
      for number in dic_electric_1[name]:
        electric_data.append(number)
    data['electric'].append(electric_data)
  elif name in dic_electric_1:
    for number in dic_electric_1[name]:
      electric_data.append(number)
  elif name in dic_electric_2:
    for number in dic_electric_2[name]:
      electric_data.append(number)
  else:
    merge_data = []
    for address in addresses:
      if address in dic_addr and len(dic_addr[address]) > 0:
        merge_data.append(check_electric(dic_addr[address]))
    if len(merge_data) == 0:
      merge_data.append('待定')
    electric_data = merge_data
  data['electric'].append(electric_data)

  data_pay = []
  if name in pay_parent:
    data_pay.append(pay_parent[name])
  else:
    data_pay.append(name)
  for address in addresses:
    if address in dic_addr:
      data_pay.append(dic_addr[address])
  data['pay'].append(data_pay)


print(len(data['name']))
# print(len(data['code']))
print(len(data['electric']))
print(len(data['water']))
print(len(data['gas']))
print(len(data['pay']))
data = pd.DataFrame(data)
data.to_excel(writer, sheet_name=sheetname)
writer.save()