# -*- coding: utf-8 -*


from selenium import webdriver
from bs4 import BeautifulSoup as soups
import os
import csv

def getImage(name, path, quantity):
    url = "https://www.google.com/search?q=" + str(name) + "&hl=ko&tbm=isch"
    
    browser = webdriver.Chrome('J:/Documents/Serendipity/DeepLearning Study/Code/Crawling/chromedriver.exe')
    browser.get(url)
    
    image_count = len(browser.find_elements_by_tag_name('img'))
    print('the amount of crawled images: {}'.format(image_count))
    
    browser.implicitly_wait(2)

    if(not os.path.isdir(path)):
        os.mkdir(path)

    for i in range( quantity ):
        image = browser.find_elements_by_tag_name('img')[i]
        image.screenshot(path+ str(i) + '.png')

    browser.close()


pokemon_file = open('J:/Documents/Serendipity/DeepLearning Study/Code/Crawling/pokemon.csv','r')# csv 파일
root_path = "J:/Documents/Serendipity/DeepLearning Study/Code/Crawling/" # 이미지 저장할 경로
quantity = 50 #크롤링할 이미지 갯수
rdr = csv.reader(pokemon_file)
cnt = 0
for line in rdr:
    if(cnt < 17):
        cnt += 1
        continue
    if(cnt>50):
        break
    print(cnt, line[2])
    name = line[2]
    path = root_path  +name+"/"
    getImage(name, path, quantity)
    cnt += 1
    

pokemon_file.close()
#name = raw_input('search keyword: ')
#quantity = int(raw_input('amount of images: '))

