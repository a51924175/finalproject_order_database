import xlwt  

def txt_xls(filename, xlsname):
    try:
        f = open(filename, 'r', encoding='utf-8')
        xls = xlwt.Workbook()
        sheet = xls.add_sheet('sheet1', cell_overwrite_ok=True)
        x = 0
        while True:
            line = f.readline()
            if not line:
                break
            
            line = line.strip()  # 去除字串兩側的空格或換行符

            if line.startswith("Account:"):
                account = line[9:]  # 獲取帳戶名稱
                sheet.write(x, 0, "Account:")
                sheet.write(x, 1, account)
                x += 1
            elif line.startswith("->"):
                items = line[2:].split()
                for i in range(len(items)):
                    item = items[i]
                    sheet.write(x, i, item)
                x += 1
            elif line.startswith("total price:"):
                total_price = line[13:]  # 獲取總價格
                sheet.write(x, 0, "total price:")
                sheet.write(x, 1, total_price)
                x += 1

        f.close()
        xls.save(xlsname)  
    except:
        raise

#路徑照個人電腦更動
if __name__ == "__main__":
    filename = "C:\\Users\\Tony\\Desktop\\C_practice\\final\\final_project\\order_overview.txt"   
    xlsname = "C:\\Users\\Tony\\Desktop\\C_practice\\final\\final_project\\order_overview.xls"     
    txt_xls(filename, xlsname)
