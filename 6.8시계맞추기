#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

const char linked[10][17] = {
   "1110000000000000",
   "0001000101010000",
   "0000100000100011",
   "1000111100000000",
   "0000001110101000",
   "1010000000000011",
   "0001000000000011",
   "0000110100000011",
   "0111110000000000",
   "0001110001000100"
};
const int INF = 9999;

bool areAligned(int *clock) {
   for (int i = 0; i < 16; i++) {
      if (clock[i] != 4)return false;
   }
   return true;
}

void push(int *clock, int swtch) {
   for (int i = 0; i < 16; i++) {
      if (linked[swtch][i] == '1') {
         clock[i]++;
         if (clock[i] == 5)clock[i] = 1;
      }
   }
}

int slove(int *clock, int swtch) {
   if (swtch == 10)return areAligned(clock) ? 0 : INF;
   int ret = INF;
   for (int cnt = 0; cnt < 4; cnt++) {
      ret = min(ret, cnt + slove(clock, swtch + 1));
      push(clock, swtch);
   }
   return ret;
}

int main() {
   int clock[16];
   int temp = 0;
   for (int i = 0; i < 16; i++) {
      cin >> temp;
      clock[i] = temp / 3;
   }
   int answer = slove(clock, 0);
   cout << answer << endl;
}
