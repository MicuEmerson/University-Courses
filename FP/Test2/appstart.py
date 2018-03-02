'''
Created on Dec 19, 2016

@author: Emy
'''
from repository.Repository import Repository
from controller.controller import Controller
from ui.console import UI
from domain.student import Student

repo = Repository()
ctrl = Controller(repo)
ui = UI(ctrl)

ui.run()