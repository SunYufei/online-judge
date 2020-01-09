from bs4 import BeautifulSoup
import urllib.request
import xlsxwriter


def get_html(url):
    return urllib.request.urlopen(url).read()


def main():
    row = 1

    workbook = xlsxwriter.Workbook('dc.xlsx')
    worksheet = workbook.add_worksheet('DC')

    for year in range(2012, 2019):
        for month in range(1, 13):
            url = 'http://zimuzu.tv/tv/schedule/index/year/' + \
                str(year)+'/month/'+str(month)
            bs = BeautifulSoup(get_html(url), 'html.parser')
            table = bs.table
            ihbgs = table.find_all('td', class_='ihbg')
            for ihbg in ihbgs:
                day = int(ihbg.find('dt').text.split(' ')[0][:-1])
                links = ihbg.find_all('a')
                for link in links:
                    if ('绿箭' in link.text) or ('闪电侠' in link.text) or ('超女' in link.text) or ('明日传奇' in link.text):
                        worksheet.write(row, 0, str(year)+'-' +
                                        str(month)+'-'+str(day))
                        worksheet.write(row, 1, link.text)
                        row = row+1

    workbook.close()


if __name__ == '__main__':
    main()
