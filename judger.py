import os
from zipfile import ZipFile
from pathlib import Path
import subprocess
import shutil

subprocess.run(["make"])
score = 0

for i in range(4):
   f = open("grade.txt", 'w+')

   infile = "public" + str(i + 1) + ".dat"
   outfile = "public" + str(i + 1) + "_ans.dat"
   ans = "ans" + str(i + 1)

   subprocess.run(["./bst", infile, ans])
   list1 = []
   list2 = []
   with open(ans,'r') as file:
      # reading each line    
      for line in file:
         # reading each word        
         for word in line.split():
            list1.append(word)

   with open(outfile,'r') as file:
      # reading each line    
      for line in file:
         # reading each word        
         for word in line.split():
            list2.append(word)
   b = True

   if(len(list1) != len(list2)):
      b = False
   else:
      for j in range(len(list1)):
         if(list1[j] != list2[j]):
            b = False
   

   if(b == True):
      score = score + 20
   else:
      print(f"testcase {i + 1} failed!")
      
   f.write(str(score))

   f.close()

print(score)
print('Done')