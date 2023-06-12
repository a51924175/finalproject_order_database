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
            
            items = line.split()
            for i in range(len(items)):
                item = items[i]
                sheet.write(x, i, item)
            x += 1
        f.close()
        xls.save(xlsname)  
    except:
        raise

if __name__ == "__main__":
    filename = "C:\\Users\\a5192\\Desktop\\c\\project\\order_overview.txt"   
    xlsname = "C:\\Users\\a5192\\Desktop\\c\\project\\order_overview.xls"     
    txt_xls(filename, xlsname)
    filename = "C:\\Users\\a5192\\Desktop\\c\\project\\product_list.txt"
    xlsname = "C:\\Users\\a5192\\Desktop\\c\\project\\product_list.xls"
    txt_xls(filename, xlsname)
    filename = "C:\\Users\\a5192\\Desktop\\c\\project\\buyer_account_list.txt"
    xlsname = "C:\\Users\\a5192\\Desktop\\c\\project\\buyer_account_list.xls"
    txt_xls(filename, xlsname)
