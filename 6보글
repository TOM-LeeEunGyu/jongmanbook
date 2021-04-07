// 보글 게임 p150
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const int MIN = numeric_limits<int>::min();
const char board[5][5] = {
   {'N','N','N','N','S'},
   {'N','E','E','E','N'},
   {'N','E','Y','E','N',},
   {'N','E','E','E','N'},
   {'N','N','N','N','N'}
};

const int dx[8] = { -1,-1,-1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1,-1, 0, 1,-1, 1 };

bool inRange(int y, int x) {
   if (0 <= y < 5 && 0 <= x < 5) return true;
   else false;
}

bool hasWord(int y, int x, const string& word) {
   if (!inRange(y, x)) return false;
   if (board[y][x] != word[0]) return false;
   if (word.size() == 1) return true;

   for (int direction = 0; direction <= 8; direction++) {
      int nextY = y + dy[direction];
      int nextX = x + dx[direction];
      if (hasWord(nextY, nextX, word.substr(1))) {
         return true;
      }
   }
   return false;
}


int main()
{   
   string word;
   while (true) {
      cin >> word;
      if (hasWord(2, 2, word))cout << "TRUE" << endl;
      else cout << "FALSE" << endl;
   }
   return 0;
}
