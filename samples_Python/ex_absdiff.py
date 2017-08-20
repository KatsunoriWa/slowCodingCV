import cv2
import numpy as np
x = np.linspace(0, 180, 1000000)
si = np.sin(np.pi*x/180.0)
co = np.cos(np.pi*x/180.0)
t1 = cv2.getTickCount()
for i in range(100):
    r = cv2.absdiff(si, co)
t2 = cv2.getTickCount()
print r
print  (t2-t1)/cv2.getTickFrequency()

t3 = cv2.getTickCount()
for i in range(100):
    r2 = np.abs(si-co)
t4 = cv2.getTickCount()
print r2
print  (t4-t3)/cv2.getTickFrequency()

