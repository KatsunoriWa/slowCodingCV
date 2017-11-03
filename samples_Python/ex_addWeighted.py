import cv2
import numpy as np
import pylab as plt

img1 = cv2.imread("../data/lena.png", 0)
img2 = img1[:, ::-1]+0

t1 = cv2.getTickCount()
img3 = cv2.addWeighted(img2, 0.5, img1, -0.5, 128)
t2 = cv2.getTickCount()

cv2.imwrite("img3.png", img3)
t3 = cv2.getTickCount()
img4 = 0.5*img2-0.5*img1 +128
t4 = cv2.getTickCount()
cv2.imwrite("img4.png", img4)

t5 = cv2.getTickCount()
img5 = (np.array(img2, dtype=np.int16) -np.array(img1,dtype=np.int16))/2 +128
t6 = cv2.getTickCount()
cv2.imwrite("img5.png", img5)

print (t2-t1)/cv2.getTickFrequency()
print (t4-t3)/cv2.getTickFrequency()
print (t6-t5)/cv2.getTickFrequency()


plt.figure(1)
plt.clf()
plt.subplot(2, 3, 1)
plt.imshow(img3)
plt.colorbar()
plt.subplot(2, 3, 2)
plt.imshow(img4)
plt.colorbar()
plt.subplot(2, 3, 3)
plt.imshow(img5)
plt.colorbar()
plt.subplot(2, 3, 5)
plt.imshow(img4-img3)
plt.colorbar()
plt.subplot(2, 3, 6)
plt.imshow(img5-img3)
plt.colorbar()
plt.show()
