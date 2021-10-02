#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int isMagicSquare(int numbers[3][3]){
   int ans = 1;
   for(int i=0;i<3;i++){
      int sum = 0;
      for(int j=0;j<3;j++){
         sum += numbers[i][j];
      }
      if(sum!=15){
         ans = 0;
      }
   }
   for(int i=0;i<3;i++){
      int sum = 0;
      for(int j=0;j<3;j++){
         sum += numbers[j][i];
      }
      if(sum!=15){
         ans = 0;
      }
   }
   int sumDiaUp = numbers[0][0] + numbers[1][1] + numbers[2][2];
   if(sumDiaUp!=15){
      ans = 0;
   }
   int sumDiaDown = numbers[0][2] + numbers[1][1] + numbers[2][0];
   if(sumDiaDown!=15){
      ans = 0;
   }
   return ans;
}

void printSquare(int numbers[3][3]){
   for(int i=0;i<3;i++){
      printf("[%d %d %d]\n", numbers[i][0], numbers[i][1], numbers[i][2]);
   }
}

void main(int argc, char *argv[]){
   int square[3][3];
   int randomSquare[3][3];
   int index = 1;
   int count = 0;
   time_t t;

   for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
         square[i][j] = atoi(argv[index]);
         index++;
      }
   }
   if(isMagicSquare(square)==1){
      printf("It is a magic square.\n");
      printSquare(square);
   }
   else{
      printf("It is not a magic square.\n");
      printSquare(square);
   }

   //I don't know if this works or if it just takes a super long time
   srand((unsigned) time(&t));
   int row = 0;
   int column = 0;
   int r;
   do{
      int redo = 0;
      r = (rand() % 9)+1;
      for(int i=0;i<3;i++){
         for(int j=0;j<3;j++){
            if(r==randomSquare[i][j]){
               redo = 1;
            }
         }
      }
      if(redo==0){
         if(row==4){
            row = 0;
            column++;
         }
         randomSquare[row][column] = r;
         row++;
      }

      if(isMagicSquare(randomSquare)==1){
         printf("It is a magic square.\n");
         printSquare(randomSquare);
         printf("Count: %d", count);
      }
      else{
         count++;
      }
   }while(isMagicSquare(randomSquare)==0);
}