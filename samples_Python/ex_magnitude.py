import cv2
import numpy as np
x=np.linspace(0, 180, 11)
si=np.sin(np.pi*x/180.0)
co=np.cos(np.pi*x/180.0)
r=cv2.magnitude(si, co)
print r
