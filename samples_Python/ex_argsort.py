import numpy as np

a=np.array([ [ 6,  22,  14,   4,  22],
  [10,  11,  18,   1,   4],
   [1,  13,   7,  13,   0],
  [23,  18,   1,  17,   3],
  [ 3,  18,   0,  14,  23]])

print  a

print "ROW|ASCENDING"
print np.argsort(a, axis=1)
print "ROW|DESCENDING"
print np.argsort(a, axis=1)[:, ::-1]
print "COLUMN|ASCENDING"
print np.argsort(a, axis=0)
print "COLUMN|DESCENDING"
print np.argsort(a, axis=0)[::-1, :]

