import urllib.request


def get_html(url):
    req = urllib.request.urlopen(url)
    html = req.read()
    return html
