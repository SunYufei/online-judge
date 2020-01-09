import os
from aip import AipOcr

APP_ID = ''
API_KEY = ''
SECRET_KEY = ''

client = AipOcr(APP_ID, API_KEY, SECRET_KEY)

options = {}
options["language_type"] = "ENG"

path = os.path.join(os.getcwd(), 'images')


def get_words(res):
    words = []
    num = res['words_result_num']
    if num:
        for i in range(res['words_result_num']):
            words.append(res['words_result'][i]['words'])
    return '\n'.join(words) + '\n\n'


def get_file_content(file_path):
    with open(file_path, 'rb') as f:
        return f.read()


def loop():
    with open(os.path.join(os.getcwd(), 'out.txt'), 'w', encoding='utf-8') as fp:
        for f in os.listdir(path):
            print(f)
            image = get_file_content(os.path.join(path, f))
            res = client.basicAccurate(image, options=options)
            words = get_words(res)
            fp.write(words)


loop()
