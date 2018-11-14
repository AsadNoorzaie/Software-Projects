#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Jun 14 23:37:25 2018

@author: anoorzaie

Creates Gmail Account Autonomously, ran via command line

TODO: Get across RECAPTCHA Barrier
"""
from selenium import webdriver
import time

def createGmailAccount():
    name = input("What is your name, please seperate first and last with comma? ")
    username = input('Think of a unique username: (do not add @google.com) --> ')
    password = input('Input strong password')
    
    name = name.split()
    first = name[0]
    last = name[1]
    
    firefox_profile = webdriver.FirefoxProfile()
    firefox_profile.set_preference("browser.privatebrowsing.autostart", True)
    
    browser = webdriver.Firefox(executable_path="/Users/anoorzaie/Downloads/geckodriver")
    browser.get('https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=1&cad=rja&uact=8&ved=0ahUKEwjY-vn73dTbAhVPtlkKHQWuANoQFggnMAA&url=https%3A%2F%2Faccounts.google.com%2FSignUp%3Fhl%3Den-GB&usg=AOvVaw1NtFUh8E7_Z5-F4ScIIrYg')
    
    time.sleep(3)
    
    firstNameBox = browser.find_element_by_xpath('//*[@id="firstName"]')
    firstNameBox.send_keys(first)
    
    lastNameBox = browser.find_element_by_xpath('//*[@id="lastName"]')
    lastNameBox.send_keys(last)
    
    usernameBox = browser.find_element_by_xpath('//*[@id="username"]')
    usernameBox.send_keys(username)
    
    showPasswordBox = browser.find_element_by_xpath('/html/body/div[1]/div/div[2]/div[1]/div[2]/form/div[2]/div/div[1]/div[3]/div[2]/div/content/span/span[1]/svg')
    showPasswordBox.click()
    
    enterPasswordBox = browser.find_element_by_xpath('/html/body/div[1]/div/div[2]/div[1]/div[2]/form/div[2]/div/div[1]/div[3]/div[1]/div[1]/div/div/div[1]/div/div[1]/input')
    enterPasswordBox.send_keys(password)
    
    

if __name__ == "__main__" :
    createGmailAccount()
    