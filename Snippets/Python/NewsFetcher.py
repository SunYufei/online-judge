from time import sleep

import requests
from bs4 import BeautifulSoup

URL = 'http://cs.ouc.edu.cn/news-list.aspx?nc=14'

if __name__ == '__main__':
    while True:
        html = requests.get(URL).text
        soup = BeautifulSoup(html, 'html.parser')
        ul = soup.find('ul', {'class': 'border-dotted'})
        li = ul.find_all('li')
        for l in li:
            print(l.find('span', {'class': 'news-time'}).text, end=' ')
            print(l.find('span', {'class': 'news-title'}).text)
        sleep(15)
