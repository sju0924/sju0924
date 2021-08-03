# -*- coding: utf-8 -*


from selenium import webdriver
from bs4 import BeautifulSoup as soups

def getImage(name, path, quantity):
    url = "https://www.google.com/search?q=" + str(name) + "&hl=ko&tbm=isch"
    
    browser = webdriver.Chrome('J:/Documents/Serendipity/DeepLearning Study/Code/Crawling/chromedriver.exe')
    browser.get(url)
    
    image_count = len(browser.find_elements_by_tag_name('img'))
    print('the amount of crawled images: {}'.format(image_count))
    
    browser.implicitly_wait(2)

    for i in range( quantity ):
        image = browser.find_elements_by_tag_name('img')[i]
        image.screenshot(path+ str(i) + '.png')

    browser.close()


name = raw_input('search keyword: ')
quantity = int(raw_input('amount of images: '))
path = "J:/Documents/Serendipity/DeepLearning Study/Code/Crawling/"+name+"/"
getImage(name, path, quantity)
