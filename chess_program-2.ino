

#define W while
#define M 0x88
#define S 128
#define I 8000
#include<math.h>

#define MYRAND_MAX 65535     /* 16bit pseudo random generator */

// WEPA
int dir2 = 32;
int pul2 = 30;
int dir1 = 24;
int pul1 = 22;
int dir3 = 28;
int pul3 = 26;
int ser = 3;
float teta2;
float teta1;
float x;
int num_pulse1;
int num_pulse2;
int num_pulse3 = 0;

int tizlik1 = 1050;  //950
int tizlik2 = 750;  //600
int tizlik3 = 1000;
float a = 9.3;
float h = 1.1;
float alfa = 0;
int asak = 0;
int nokat = 0;
float x_lar[8][8] = {{40.4, 35.2, 30.4, 26.1, 22.2, 18.1, 14.6, 11.4}, {38.8, 33.7, 28.8, 24.6, 20.4, 16.1, 12.3, 8.9}, {37.5, 32.9, 27.8, 23.1, 18.7, 14.6, 10.8, 7.4}, {37, 32, 27, 22.3, 18.2, 13.7, 10.1, 6.6}, {36.6, 31.4, 26.5, 22, 17.6, 13.34, 9.25, 5.7}, {37, 32, 27, 22.3, 18.2, 13.7, 9.9, 6.3}, {37.5, 32.7, 27.4, 23, 18.6, 14.4, 10.8, 7}, {38.8, 33.5, 28.7, 24.4, 20.2, 15.9, 12, 8.7}};
int num_pulse3_ler[8][8] = {{275, 316, 336, 370, 405, 454, 525, 594}, {207, 223, 244, 270, 313, 351, 400, 460}, {146, 152, 166, 185, 204, 230, 260, 316}, {52, 60, 71, 80, 97, 115, 139, 168}, {0, 0, 0, 0, 0, 0, 0, 0}, {87, 92, 100, 109, 118, 130, 150, 168}, {146, 159, 170, 187, 210, 250, 283, 326}, {212, 233, 259, 285, 313, 356, 410, 470}};
int asak_lar[8][8] = {{196, 208, 220, 232, 252, 270, 302, 344}, {204, 216, 228, 244, 272, 298, 330, 384}, {208, 220, 232, 252, 280, 310, 358, 424}, {216, 224, 244, 264, 292, 330, 378, 442}, {212, 224, 244, 260, 300, 344, 392, 472}, {212, 220, 240, 264, 292, 330, 378, 442}, {212, 224, 240, 264, 288, 318, 362, 424}, {204, 220, 236, 252, 280, 310, 346, 392}};
int m;
int n;
int san;
bool yagday;
//wepa

int p1;
int p2;
int pulse1;
int pulse2;
int t1;
int t2;


long  N, T;                  /* N=evaluated positions+S, T=recursion limit */
short Q, O, K, R, k = 16;    /* k=moving side */
char *p, c[5], Z;            /* p=pointer to c, c=user input, computer output, Z=recursion counter */

char L,
     w[] = {0, 2, 2, 7, -1, 8, 12, 23},                    /* relative piece values    */
           o[] = { -16, -15, -17, 0, 1, 16, 0, 1, 16, 15, 17, 0, 14, 18, 31, 33, 0, /* step-vector lists */
                   7, -1, 11, 6, 8, 3, 6,                           /* 1st dir. in o[] per piece*/
                   6, 3, 5, 7, 4, 5, 3, 6
                 };                                /* initial piece setup      */
/* board is left part, center-pts table is right part, and dummy */

char b[] = {
  22, 19, 21, 23, 20, 21, 19, 22, 28, 21, 16, 13, 12, 13, 16, 21,
  18, 18, 18, 18, 18, 18, 18, 18, 22, 15, 10,  7,  6,  7, 10, 15,
  0,  0,  0,  0,  0,  0,  0,  0, 18, 11,  6,  3,  2,  3,  6, 11,
  0,  0,  0,  0,  0,  0,  0,  0, 16,  9,  4,  1,  0,  1,  4,  9,
  0,  0,  0,  0,  0,  0,  0,  0, 16,  9,  4,  1,  0,  1,  4,  9,
  0,  0,  0,  0,  0,  0,  0,  0, 18, 11,  6,  3,  2,  3,  6, 11,
  9,  9,  9,  9,  9,  9,  9,  9, 22, 15, 10,  7,  6,  7, 10, 15,
  14, 11, 13, 15, 12, 13, 11, 14, 28, 21, 16, 13, 12, 13, 16, 21, 0
};

char bk[16 * 8 + 1];

unsigned int seed = 0;
uint32_t  byteBoard[8];

char sym[17] = {".?pnkbrq?P?NKBRQ"};
int mn = 1;
char lastH[5], lastM[5];
unsigned short ledv = 1;

String inputString = "";
bool stringComplete = false;  // whether the string is complete


//-----------------------------------------------my variables----------------------------------------------------------//
int newBoard[8] = {0, 0, 0, 0, 0, 0, 0, 0};
int oldBoard[8][8] = {{1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};
int A[9] = {0, 1, 2, 4, 8, 16, 32, 64, 128};

char robot[4];

char machineMove[5];
int humanMove[4];
int rowAnalysis[8];

int rowOff = -1;
int colOff = -1;
int rowOn = -1;
int colOn = -1;

int sagat595 = 9;
int data595 = 8;
int sonky595 = 10;

//int load165=40;
//int sagat165=44;
//int data165=41;
//int sagatin165=45;

int a1 = 53;
int a2 = 52;
int a3 = 51;
int a4 = 50;
int a5 = 49;
int a6 = 48;
int a7 = 47;
int a8 = 46;



///////////////////////////---------------------------end----------------------------------////////////////////////////
void setup() {
  //newBoard[0] = 53;
  //newBoard[1] = 52;
  //newBoard[2] = 51;
  //newBoard[3] = 50;
  //newBoard[4] = 49;
  //newBoard[5] = 48;
  //newBoard[6] = 47;
  //newBoard[7] = 46;

  pinMode(a1, INPUT);
  pinMode(a2, INPUT);
  pinMode(a3, INPUT);
  pinMode(a4, INPUT);
  pinMode(a5, INPUT);
  pinMode(a6, INPUT);
  pinMode(a7, INPUT);
  pinMode(a8, INPUT);

  //WEPA
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(pul1, OUTPUT);
  pinMode(pul2, OUTPUT);
  pinMode(pul3, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(ser, OUTPUT);
  alfa = asin(a / 30) * 180 / PI;
  Serial.begin(9600);
  //wepa

  Serial.begin(9600);
  Serial.println("*** MicroMaxChess ***");

  pinMode(sagat595, OUTPUT);
  pinMode(data595, OUTPUT);
  pinMode(sonky595, OUTPUT);

  for (int i = 0; i < 8; i++) {
    pinMode(newBoard[i], INPUT);
  }


  lastH[0] = 0;
  serialBoard();
  printOldBoard();
}

void loop() {
  int r;

  // Adam gochyan yeri
  getserialchar();
  //  changeNewBoard();
  //  changeA();

  inputString = readMove();
  resetRowCol();
  Serial.print(mn);
  Serial.print(". ");
  Serial.print(inputString.substring(0, 4));
  c[0] = inputString.charAt(0); //sutun san (a-h)
  c[1] = inputString.charAt(1); //setir sandakyny (1-8)
  c[2] = inputString.charAt(2);//sutun san (1-8)
  c[3] = inputString.charAt(3);//setir sana gech            #    mysal uchin: d2d3
  c[4] = 0;
  // clear the string:
  inputString = "";
  stringComplete = false;
  Serial.print(" Think ");                       /* Turn for ARDUINO */

  K = *c - 16 * c[1] + 799, L = c[2] - 16 * c[3] + 799; /* parse entered move */  //gochumingi anyklaya
  N = 0;
  T = 0x3F;   //63 decimalda                /* T=Computer Play strength */
  bkp();                                    /* Save the board just in case */
  r = D(-I, I, Q, O, 1, 3);                 /* Check & do the human movement */
  if ( !(r > -I + 1) ) {
    Serial.println("Lose ");
    gameOver();
  }
  if (k == 0x10) {                          /* The flag turn must change to 0x08 */
    Serial.println("No valid move");
    //    imitateChessBoard();
    serialBoard();
    printOldBoard();
    //    refreshOldBoard();
    //    printOldBoard();
    return;
  }

  strcpy(lastH, c);                         /* Valid human movement */

  mn++;                                     /* Next move */

  K = I;
  N = 0;
  T = 0x3F;                                 /* T=Computer Play strength */
  r = D(-I, I, Q, O, 1, 3);                 /* Think & do*/
  if ( !(r > -I + 1) ) {
    Serial.println("Lose*");
    gameOver();
  }

  strcpy(lastM, c);                         /* Valid ARDUINO movement */
  r = D(-I, I, Q, O, 1, 3);
  if ( !(r > -I + 1) ) {
    Serial.println(lastM);
    Serial.println(movePiece());
    gameOver();
  }
  Serial.println(lastM);
  //   imitateChessBoard();
  serialBoard();
  //   printOldBoard();

  Serial.println(movePiece());
  refreshOldBoard();
  printOldBoard();
}


/* User interface routines */
//
//void getserialchar() {
//  while (Serial.available() > 0) {
//    // get the new byte:
//    char inChar = (char)Serial.read();
//    // add it to the inputString:
//    inputString += inChar;
//    // if the incoming character is a newline, set a flag so the main loop can
//    // do something about it:
//    if (inChar == '\n') {
//      stringComplete = true;
//    }
//  }
//}


//--------------------------------------my functions----------------------------------------//
void getserialchar() {
  String input = "";
  bool stringComplete = false;
  while (stringComplete == false) {
    while (Serial.available() > 0) {
      // get the new byte:
      char inChar = (char)Serial.read();
      // add it to the inputString:
      input += inChar;
      // if the incoming character is a newline, set a flag so the main loop can
      // do something about it:
      if (inChar == '\n') {
        stringComplete = true;
      }
    }
  }
  humanMove[0] = (int)input.charAt(0) - 48;
  humanMove[1] = (int)input.charAt(1) - 48;
  humanMove[2] = (int)input.charAt(2) - 48;
  humanMove[3] = (int)input.charAt(3) - 48;
}

//void changeNewBoard(){
//  newBoard[humanMove[1]][humanMove[0]]=0;
//  newBoard[humanMove[3]][humanMove[2]]=1;
//}


//void changeA(){
//  int decimal;
//  for(int j=0;j<8;j++){
//     A[j+1]=convertToDecimal(newBoard[j]);
//  }
//}

int convertToDecimal(int arr[8]) {
  int i = 0;
  int wei = 1;
  int dec = 0;
  while (i < 8)
  {
    dec = dec + arr[7 - i] * wei;
    wei = wei * 2;
    i++;
  }
  return dec;
}

//void convertToBinary(byte decimal){
//  for(int i=0;i<8;i++){
//    rowAnalysis[7-i] = decimal%2;
//    decimal /= 2;
//  }
//}

String readMove() {
  for (int j = 0; j < 9; j++) {

    //OUTPUT
    digitalWrite(sonky595, LOW);
    shiftOut(data595, sagat595, LSBFIRST, A[j]);
    digitalWrite(sonky595, HIGH);

    rowAnalysis[7] = digitalRead(a8);
    rowAnalysis[6] = digitalRead(a7);
    rowAnalysis[5] = digitalRead(a6);
    rowAnalysis[4] = digitalRead(a5);
    rowAnalysis[3] = digitalRead(a4);
    rowAnalysis[2] = digitalRead(a3);
    rowAnalysis[1] = digitalRead(a2);
    rowAnalysis[0] = digitalRead(a1);
    delay(20);
    //           rowAnalysis[i] = digitalRead(newBoard[i]);


    for (int i = 0; i < 8; i++) {
      Serial.print(rowAnalysis[i]);
    }
    Serial.println();
    //        if(j==1)
    //          for(int i=0;i<8;i++){
    //            Serial.print("oldBoard");
    //            Serial.print(oldBoard[1][i]);
    //            }
    //rakirowka uchin
    if (j == 1 && rowAnalysis[4] != oldBoard[0][4] && rowAnalysis[4] == 0 ) {
      Serial.print("rakirowka");
      if (rowAnalysis[0] != oldBoard[0][0] || rowAnalysis[7] != oldBoard[0][7]) {
        //          for(int i=0;i<8;i++){
        //            oldBoard[0][i] = rowAnalysis[i];
        //            }
        if (rowAnalysis[0] == 0) {
          return "e1c1";
        }
        if (rowAnalysis[7] == 0) {
          return "e1g1";
        }
      }
    }

    //gochumleri analiz etmek uchin
    if (j > 0) {
      int some = j;
      j -= 1;
      for (int i = 0; i < 8; i++) {
        if (rowAnalysis[i] != oldBoard[j][i]) {
          if (rowAnalysis[i] == 0) {
            rowOff = j;
            colOff = i;
            oldBoard[j][i] = 0;
          } else if (rowAnalysis[i] == 1) {
            rowOn = j;
            colOn = i;
            oldBoard[j][i] = 1;
          }
        }
      }
      j = some;
    }
  }


  if (rowOff >= 0 && rowOn >= 0) {
    return convertToRowCol(rowOff, colOff) + convertToRowCol(rowOn, colOn);
  } else {
    return "nono";
  }
}

int movePiece() {
  int m = 0;

  int lastCol;
  int lastRow;

  String rowInChar = "12345678";
  String colInChar = "abcdefgh";
  Serial.println(lastM);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 8; j++) {
      if (lastM[i] == colInChar.charAt(j) || lastM[i] == rowInChar.charAt(j)) {
        //              Serial.println(lastM[i]);
        m = m * 10 + j;
        if (i == 2) {
          lastCol = j;
        }
        if (i == 3) {
          lastRow = j;
        }
      }
    }
  }

  if (oldBoard[lastRow][lastCol] == 1) {
    Serial.println(oldBoard[lastRow][lastCol]);
    m = -m;
  }
  Serial.println(oldBoard[lastRow][lastCol]);

  //WEPA
  san = m;
  if (san > 0) {
    nolsuz();

    if (san == 4767) {
      san = 7757;
      nolsuz();
    }

    if (san == 4727) {
      san = 737;
      nolsuz();
    }
  }

  if (san < 0) {
    san = san * -1;
    almak();
    nolsuz();
  }


}

void refreshOldBoard() {
  for (int i = 0; i < 8; i++) {
    Serial.println();
    for (int j = 0; j < 8; j++) {
      int c = b[16 * i + j] & 15;
      if (c >= 9  && c <= 15) {
        Serial.print(c);
        oldBoard[7 - i][j] = 1;
      } else {
        Serial.print(0);
        oldBoard[7 - i][j] = 0;
      }
    }
  }
  //  oldBoard[2][4] = 1;
}
//
//char b[]={
//  22, 19, 21, 23, 20, 21, 19, 22, 28, 21, 16, 13, 12, 13, 16, 21,
//  18, 18, 18, 18, 18, 18, 18, 18, 22, 15, 10,  7,  6,  7, 10, 15,
//   0,  0,  0,  0,  0,  0,  0,  0, 18, 11,  6,  3,  2,  3,  6, 11,
//   0,  0,  0,  0,  0,  0,  0,  0, 16,  9,  4,  1,  0,  1,  4,  9,
//   0,  0,  0,  0,  0,  0,  0,  0, 16,  9,  4,  1,  0,  1,  4,  9,
//   0,  0,  0,  0,  0,  0,  0,  0, 18, 11,  6,  3,  2,  3,  6, 11,
//   9,  9,  9,  9,  9,  9,  9,  9, 22, 15, 10,  7,  6,  7, 10, 15,
//  14, 11, 13, 15, 12, 13, 11, 14, 28, 21, 16, 13, 12, 13, 16, 21, 0
//};

//char sym[17] = {".?pnkbrq?P?NKBRQ"};

//void refresh() {
//  for (int i = 0; i < 8; i++) {
//    digitalWrite(sonky595, LOW);
//    shiftOut(data595, sagat595, MSBFIRST, A[i]);
//    digitalWrite(sonky595, HIGH);
//    newBoard[i][0] = digitalRead(a);
//    newBoard[i][1] = digitalRead(b);
//    newBoard[i][2] = digitalRead(c);
//    newBoard[i][3] = digitalRead(d);
//    newBoard[i][4] = digitalRead(e);
//    newBoard[i][5] = digitalRead(f);
//    newBoard[i][6] = digitalRead(g);
//    newBoard[i][7] = digitalRead(h);
//    delay(20);
//  }
//}


String convertToRowCol(int row, int col) {
  String rowInChar = "12345678";
  String colInChar = "abcdefgh";
  String response = "";

  response += colInChar[col];
  response += rowInChar[row];
  return response;
}

void resetRowCol() {
  rowOff = -1;
  colOff = -1;
  rowOn = -1;
  colOn = -1;
}

void printOldBoard() {
  Serial.println("  ");
  Serial.println("  |----Old Board----|");
  Serial.println("   _________________");

  for (int j = 0; j < 8; j++) {
    Serial.print(' ');
    Serial.print(7 - j);
    Serial.print("| ");

    for (int i = 0; i < 8; i++) {
      Serial.print(oldBoard[7 - j][i]);
      Serial.print(' ');
    }
    Serial.println('|');
  }
  Serial.println("   _________________");
  Serial.println("  | 0 1 2 3 4 5 6 7 |");

  Serial.println("  ");
  //    Serial.println("  |----new Board----|");
  //    Serial.println("   _________________");
  //
  //    for(int j=0;j<8;j++){
  //      Serial.print(' ');
  //      Serial.print(7-j);
  //      Serial.print("| ");
  //
  //      for(int i=0;i<8;i++){
  //        Serial.print(newBoard[7-j][i]);
  //        Serial.print(' ');
  //      }
  //       Serial.println('|');
  //    }
  //    Serial.println("   _________________");
  //    Serial.println("  | 0 1 2 3 4 5 6 7 |");
}

//void imitateChessBoard(){
//    for(int i=0; i<8; i++){
//        for(int j=0; j<8; j++){
//          char c = b[16*i+j]&15;
//          int num = b[16*i+j]&15;
//          if(num>8){
//            oldBoard[7-i][j] = 1;
//            newBoard[7-i][j] = 1;
//          }else{
//            oldBoard[7-i][j] = 0;
//            newBoard[7-i][j] = 0;
//          }
//        }
//  }
//}

//----------------------------------------end of my functions-----------------------------------------//
unsigned short myrand(void) {
  unsigned short r = (unsigned short)(seed % MYRAND_MAX);
  return r = ((r << 11) + (r << 7) + r) >> 1;
}
/* recursive minimax search */
/* (q,l)=window, e=current eval. score, */
/* E=e.p. sqr.z=prev.dest, n=depth; return score */
short D(short q, short l, short e, unsigned char E, unsigned char z, unsigned char n) {
  short m, v, i, P, V, s;
  unsigned char t, p, u, x, y, X, Y, H, B, j, d, h, F, G, C;
  signed char r;
  if (++Z > 30) {                                   /* stack underrun check */
    --Z; return e;
  }
  q--;                                          /* adj. window: delay bonus */
  k ^= 24;                                      /* change sides             */
  d = Y = 0;                                    /* start iter. from scratch */
  X = myrand() & ~M;                            /* start at random field    */
  W(d++ < n || d < 3 ||                         /* iterative deepening loop */
    z & K == I && (N < T & d < 98 ||            /* root: deepen upto time   */
                   (K = X, L = Y & ~M, d = 3)))                /* time's up: go do best    */
  { x = B = X;                                   /* start scan at prev. best */
    h = Y & S;                                   /* request try noncastl. 1st*/
    P = d < 3 ? I : D(-l, 1 - l, -e, S, 0, d - 3); /* Search null move         */
    m = -P < l | R > 35 ? d > 2 ? -I : e : -P;   /* Prune or stand-pat       */
    ++N;                                         /* node count (for timing)  */
    do {
      u = b[x];                                   /* scan board looking for   */
      if (u & k) {                                /*  own piece (inefficient!)*/
        r = p = u & 7;                             /* p = piece type (set r>0) */
        j = o[p + 16];                             /* first step vector f.piece*/
        W(r = p > 2 & r < 0 ? -r : -o[++j])        /* loop over directions o[] */
        { A:                                        /* resume normal after best */
          y = x; F = G = S;                         /* (x,y)=move, (F,G)=castl.R*/
          do {                                      /* y traverses ray, or:     */
            H = y = h ? Y ^ h : y + r;               /* sneak in prev. best move */
            if (y & M)break;                         /* board edge hit           */
            m = E - S & b[E] && y - E < 2 & E - y < 2 ? I : m; /* bad castling             */
            if (p < 3 & y == E)H ^= 16;              /* shift capt.sqr. H if e.p.*/
            t = b[H]; if (t & k | p < 3 & !(y - x & 7) - !t)break; /* capt. own, bad pawn mode */
            i = 37 * w[t & 7] + (t & 192);           /* value of capt. piece t   */
            m = i < 0 ? I : m;                       /* K capture                */
            if (m >= l & d > 1)goto C;               /* abort on fail high       */
            v = d - 1 ? e : i - p;                   /* MVV/LVA scoring          */
            if (d - !t > 1)                          /* remaining depth          */
            { v = p < 6 ? b[x + 8] - b[y + 8] : 0;    /* center positional pts.   */
              b[G] = b[H] = b[x] = 0; b[y] = u | 32;  /* do move, set non-virgin  */
              if (!(G & M))b[F] = k + 6, v += 50;     /* castling: put R & score  */
              v -= p - 4 | R > 29 ? 0 : 20;           /* penalize mid-game K move */
              if (p < 3)                              /* pawns:                   */
              { v -= 9 * ((x - 2 & M || b[x - 2] - u) + /* structure, undefended    */
                          (x + 2 & M || b[x + 2] - u) - 1  /*        squares plus bias */
                          + (b[x ^ 16] == k + 36))          /* kling to non-virgin King */
                     - (R >> 2);                       /* end-game Pawn-push bonus */
                V = y + r + 1 & S ? 647 - p : 2 * (u & y + 16 & 32); /* promotion or 6/7th bonus */
                b[y] += V; i += V;                     /* change piece, add score  */
              }
              v += e + i; V = m > q ? m : q;          /* new eval and alpha       */
              C = d - 1 - (d > 5 & p > 2 & !t & !h);
              C = R > 29 | d < 3 | P - I ? C : d;     /* extend 1 ply if in check */
              do
                s = C > 2 | v > V ? -D(-l, -V, -v,     /* recursive eval. of reply */
                                       F, 0, C) : v;    /* or fail low if futile    */
              W(s > q&++C < d); v = s;
              if (z && K - I && v + I && x == K & y == L) /* move pending & in root:  */
              { Q = -e - i; O = F;                     /*   exit if legal & found  */
                R += i >> 7; --Z; return l;            /* captured non-P material  */
              }
              b[G] = k + 6; b[F] = b[y] = 0; b[x] = u; b[H] = t; /* undo move,G can be dummy */
            }
            if (v > m)                               /* new best, update max,best*/
              m = v, X = x, Y = y | S & F;            /* mark double move with S  */
            if (h) {
              h = 0;  /* redo after doing old best*/
              goto A;
            }
            if (x + r - y | u & 32 |                 /* not 1st step,moved before*/
                p > 2 & (p - 4 | j - 7 ||             /* no P & no lateral K move,*/
                         b[G = x + 3 ^ r >> 1 & 7] - k - 6     /* no virgin R in corner G, */
                         || b[G ^ 1] | b[G ^ 2])               /* no 2 empty sq. next to R */
               )t += p < 5;                           /* fake capt. for nonsliding*/
            else F = y;                              /* enable e.p.              */
          } W(!t);                                  /* if not capt. continue ray*/
        }
      }
    } W((x = x + 9 & ~M) - B);                 /* next sqr. of board, wrap */
C: if (m > I - M | m < M - I)d = 98;           /* mate holds to any depth  */
    m = m + I | P == I ? m : 0;                  /* best loses K: (stale)mate*/
    if (z && d > 2)
    { *c = 'a' + (X & 7); c[1] = '8' - (X >> 4); c[2] = 'a' + (Y & 7); c[3] = '8' - (Y >> 4 & 7); c[4] = 0;
      char buff[150];
    }
  }                                             /*    encoded in X S,8 bits */
  k ^= 24;                                      /* change sides back        */
  --Z; return m += m < e;                       /* delayed-loss bonus       */
}
void gameOver() {
  for (;;);
}
void bkp() {
  for (int i = 0; i < 16 * 8 + 1; i++) {
    bk[i] = b[i];
  }
}
void serialBoard() {
  Serial.println("  +-----------------+");
  for (int i = 0; i < 8; i++) {
    Serial.print(' ');
    Serial.print(8 - i);
    Serial.print("| ");
    for (int j = 0; j < 8; j++) {
      char c = sym[b[16 * i + j] & 15];
      Serial.print(c);
      Serial.print(' ');
    }
    Serial.println('|');
  }
  Serial.println("  +-----------------+");
  Serial.println("  | a b c d e f g h |");
}

//WEPA

void nolsuz() {
  p1 = san / 100;
  nokat = p1;
  parameter_hasaplama();
  hasaplama();

  //*****belli bir pozisiya baryp mal alyp yokary galyanca
  esasy_ashakdaky();
  esasy_yenil();
  esasy_agyr();
  ashak_dushmek();
  gysya();
  yokary_galmak();

  //*****indiki pozisiya ucin ashagy sazlamak
  esasy_ashakdaky_tersi();
  p2 = san % 100;
  nokat = p2;
  parameter_hasaplama();
  esasy_ashakdaky();

  //*****IKISININ TAPAWUDYNY KESGITLEJEK MATEMATIKA
  pulse2 = num_pulse2;
  pulse1 = num_pulse1;
  hasaplama();
  t2 = num_pulse2 - pulse2;
  t1 = num_pulse1 - pulse1;


  //*****OWRULME SHERTLERI we 2nji pozisiya barmak
  if (t2 > 0) {
    num_pulse2 = t2;
    esasy_yenil();
  }
  else {
    num_pulse2 = -1 * t2;
    esasy_yenil_tersi();
  }

  if (t1 > 0) {
    num_pulse1 = t1;
    esasy_agyr();
  }
  else {
    num_pulse1 = -1 * t1;
    esasy_agyr_tersi();
  }

  //*****2nji pozisiyada ashak yokary
  parameter_hasaplama();
  hasaplama();
  ashak_dushmek();
  acya();
  yokary_galmak();

  //*****NOL YAGDAYA DOLANMAK
  esasy_agyr_tersi();
  esasy_yenil_tersi();
  esasy_ashakdaky_tersi();


}


//mal alyancy
void almak() {
  p2 = san % 100;
  nokat = p2;
  parameter_hasaplama();
  hasaplama();
  esasy_ashakdaky();
  esasy_yenil();
  esasy_agyr();
  ashak_dushmek();
  gysya();
  yokary_galmak();
  esasy_agyr_tersi();
  esasy_yenil_tersi();
  esasy_ashakdaky_tersi();
  acya();
}


//x we num_pulse3 parametri kesgitlap beryan funksiya
void parameter_hasaplama() {
  m = nokat / 10;
  n = nokat % 10;
  x = x_lar[m][n];
  num_pulse3 = num_pulse3_ler[m][n];
  asak = asak_lar[m][n];
}

//num_pulse1 we num_pulse2ni berlen xa gora kesgitleyan funksiya
void hasaplama() {
  teta2 = acos(1 - (h * h + (a + x) * (a + x)) / 1800) * 180 / PI - alfa;
  teta2 = teta2 / 1.9;
  num_pulse2 = int(teta2 * 1600 / 90);
  teta1 = (alfa + teta2) / 2 - atan(h / (a + x)) * 180 / PI;
  teta1 = teta1 * 1.9;
  num_pulse1 = int(teta1 * 1600 / 90);
}


//ashakdakyny aylayan funksiya
void esasy_ashakdaky() {
  yagday;
  if (m < 5) {
    yagday = HIGH;
  }
  else {
    yagday = LOW;
  }
  for (int i = 0; i < num_pulse3; i++) {
    digitalWrite(dir3, yagday);
    digitalWrite(pul3, HIGH);
    delayMicroseconds(tizlik3);
    digitalWrite(pul3, LOW);
    delayMicroseconds(tizlik3);
  }
  delay(500);
}


//ashakdakyny tersine aylayan funkisya
void esasy_ashakdaky_tersi() {
  yagday = !yagday;
  for (int i = 0; i < num_pulse3; i++) {
    digitalWrite(dir3, yagday);
    digitalWrite(pul3, HIGH);
    delayMicroseconds(tizlik3);
    digitalWrite(pul3, LOW);
    delayMicroseconds(tizlik3);
  }
  delay(500);
}

//yenili hereketlendiryan funksiya
void esasy_yenil() {
  for (int i = 0; i < num_pulse2; i++) {
    digitalWrite(dir2, LOW);
    digitalWrite(pul2, HIGH);
    delayMicroseconds(tizlik2);
    digitalWrite(pul2, LOW);
    delayMicroseconds(tizlik2);
  }
  delay(500);
}

//yenili tersine hereketlendiryan funksiya
void esasy_yenil_tersi() {
  for (int i = 0; i < num_pulse2; i++) {
    digitalWrite(dir2, HIGH);
    digitalWrite(pul2, HIGH);
    delayMicroseconds(tizlik2);
    digitalWrite(pul2, LOW);
    delayMicroseconds(tizlik2);
  }
  delay(500);
}

//agyry hereketlendiryan funksiya
void esasy_agyr() {
  for (int i = 0; i < num_pulse1; i++) {
    digitalWrite(dir1, LOW);
    digitalWrite(pul1, HIGH);
    delayMicroseconds(tizlik1);
    digitalWrite(pul1, LOW);
    delayMicroseconds(tizlik1);
  }
  delay(700);
}


//agyry tersine hereketlendiryan funksiya
void esasy_agyr_tersi() {
  for (int i = 0; i < num_pulse1; i++) {
    digitalWrite(dir1, HIGH);
    digitalWrite(pul1, HIGH);
    delayMicroseconds(tizlik1);
    digitalWrite(pul1, LOW);
    delayMicroseconds(tizlik1);
  }
  delay(700);
}

//baran pozisiyanda ashak dushuryan funksiya
void ashak_dushmek() {
  for (int i = 0; i < asak; i++) {
    digitalWrite(dir2, HIGH);
    digitalWrite(dir1, LOW);
    digitalWrite(pul2, HIGH);
    digitalWrite(pul1, HIGH);
    delayMicroseconds(950);  //800
    digitalWrite(pul2, LOW);
    digitalWrite(pul1, LOW);
    delayMicroseconds(950);  //800
  }
  delay(600);
}


//ashak dusheni yokary galdyryan funksiya
void yokary_galmak() {
  for (int i = 0; i < asak; i++) {
    digitalWrite(dir2, LOW);
    digitalWrite(dir1, HIGH);
    digitalWrite(pul2, HIGH);
    digitalWrite(pul1, HIGH);
    delayMicroseconds(950);  //800
    digitalWrite(pul2, LOW);
    digitalWrite(pul1, LOW);
    delayMicroseconds(950);   //800
  }
  delay(700);
}

//gysyan funksiya
void gysya() {
  for (int i = 0; i < 30; i++) {
    digitalWrite(ser, HIGH);
    delayMicroseconds(1200);
    digitalWrite(ser, LOW);
    delayMicroseconds(18000 - 1200);
  }
  delay(500);
}


//goyberyan funksiya
void acya() {
  for (int i = 0; i < 20; i++) {
    digitalWrite(ser, HIGH);
    delayMicroseconds(1730);
    digitalWrite(ser, LOW);
    delayMicroseconds(18000 - 1730);
  }
  delay(500);
}
