#!/usr/bin/python
# -*- coding: utf-8 -*-
#import rospy
from  Common import Common



def talker():
	common = Common()
   	common.Init()
   	common.Frame()

if __name__ == '__main__':
	#try:
	talker()
	#except rospy.ROSInterruptException:
		#pass
