import os
from PyPDF2 import PdfFileReader, PdfFileWriter


def pdf_splitter(path: str, begin: int, end: int):
    reader = PdfFileReader(path)
    writer = PdfFileWriter()
    for page in range(begin - 1, end):
        writer.addPage(reader.getPage(page))
    out_name = f'{begin}-{end}.pdf'
    with open(out_name, 'wb') as f:
        writer.write(f)


if __name__ == '__main__':
    pdf_splitter('*.pdf', 1, 2)
