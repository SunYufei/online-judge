import os
import time
import urllib.request

from bs4 import BeautifulSoup

URL1 = 'http://cs.ouc.edu.cn/news-list.aspx?newclass=14'
URL2 = 'http://web.ouc.edu.cn/yzb/5926/list1.htm'
URL3 = 'http://it.ouc.edu.cn/Display/ClickMore.aspx?more=3'


def main():
    while(True):
        os.system('cls')
        print(time.ctime())
        print('计算机科学技术系通知公告\n')
        req = urllib.request.urlopen(URL1)
        html = req.read().decode()
        bs = BeautifulSoup(html, 'html.parser')
        border_dotted = bs.find('ul', class_='border-dotted')
        lis = border_dotted.find_all('li')
        for li in lis:
            news_time = li.find('span', class_='news-time')
            news_title = li.find('span', class_='news-title')
            print(news_time.text, news_title.text)
        print()

        print('海大研招网公告\n')
        req = urllib.request.urlopen(URL2)
        html = req.read().decode()
        bs = BeautifulSoup(html, 'html.parser')
        list_item = bs.find_all('li', class_='list_item')
        for item in list_item:
            print(item.find('span', class_='Article_PublishDate').text, end=' ')
            print(item.find('span', class_='Article_Title').a['title'])
        print()

        print('信息工程学院通知公告\n')
        req = urllib.request.urlopen(URL3)
        html = req.read().decode()
        bs = BeautifulSoup(html, 'html.parser')
        inforText = bs.find_all('div', class_='clickMore-inforText')
        for text in inforText:
            print(text.h3.text)

        time.sleep(60)


if __name__ == '__main__':
    main()
