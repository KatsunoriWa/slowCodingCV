import cv2
import numpy as np
def intMean(testMat):
    gg = cv2.reduce(testMat, 0, cv2.cv.CV_REDUCE_AVG, dtype=cv2.CV_32S)
    jj = 0
    for i in range(gg.shape[1]):
        jj += gg[0, i]

    jj /= gg.shape[1]
    return jj

def floatMean(testMat):
    gg = cv2.reduce(testMat, 0, cv2.cv.CV_REDUCE_AVG, dtype=cv2.CV_32F)
    jj = 0
    for i in range(gg.shape[1]):
        jj += gg[0, i]

    jj /= float(gg.shape[1])
    return jj

testMat = cv2.imread("lena.png", 0);
[h, w] = testMat.shape[:2]

t1 = cv2.getTickCount()
for x in range(100):
    jj = intMean(testMat)
t2 = cv2.getTickCount()
print jj


t3 = cv2.getTickCount()
for x in range(100):
    jj = floatMean(testMat)
t4 = cv2.getTickCount()
print jj


t5 = cv2.getTickCount()
for x in range(100):
    r = np.mean(testMat)
t6 = cv2.getTickCount()
print r

t7 = cv2.getTickCount()
for x in range(100):
    r = cv2.mean(testMat)
t8 = cv2.getTickCount()
print r


print "time intMean =  ", (t2-t1)/cv2.getTickFrequency()
print "time floatMean= ", (t4-t3)/cv2.getTickFrequency()
print "time np.mean=   ", (t6-t5)/cv2.getTickFrequency()
print "time cv2.mean=  ", (t8-t7)/cv2.getTickFrequency()

