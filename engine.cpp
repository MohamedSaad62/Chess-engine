#include <bits/stdc++.h>

using namespace std;

#include "move_generator.cpp"


using namespace std;

U64 files []= {
  72340172838076673ULL,
  144680345676153346ULL,
  289360691352306692ULL,
  578721382704613384ULL,
  1157442765409226768ULL,
  2314885530818453536ULL,
  4629771061636907072ULL,
  9259542123273814144ULL
  };
int checkmate = 0, best_checkmate = 0;  
bool endg = 0;
int values [10];
int killer_move[10];
int qkiller_move[10];
U64 safety_king_table[64];

int knight_development_table[64] = {
        -50,-40,-30,-30,-30,-30,-40,-50,
        -40,-20,  0,  0,  0,  0,-20,-40,
        -30,  0, 10, 15, 15, 10,  0,-30,
        -30,  5, 15, 20, 20, 15,  5,-30,
        -30,  0, 15, 20, 20, 15,  0,-30,
        -30,  5, 10, 15, 15, 10,  5,-30,
        -40,-20,  0,  5,  5,  0,-20,-40,
        -50,-40,-30,-30,-30,-30,-40,-50
};

int white_bishop_devolpment_table[64] = {
        -20,-10,-10,-10,-10,-10,-10,-20,
        -10,  0,  0,  0,  0,  0,  0,-10,
        -10,  0,  5, 10, 10,  5,  0,-10,
        -10,  5,  5, 10, 10,  5,  5,-10,
        -10,  0, 10, 10, 10, 10,  0,-10,
        -10, 10, 10, 10, 10, 10, 10,-10,
        -10, 100,  0,  0,  0,  0, 100,-10,
        -20,-10,-10,-10,-10,-10,-10,-20
};

int balck_bishop_devolpment_table[64] = {
         10,-10,-10,-10,-10,-10,-10, 10,
        -10,  100,  0,  0,  0, 0, 100,-10,
        -10, 10, 10, 10, 10, 10, 10,-10,
        -10,  0,  10, 10, 10, 10, 0,-10,
        -10,  5,  5, 10, 10,  5,  5,-10,
        -10,  0,  5, 10, 10,  5,  0,-10,
        -10,  0,  0,  0,  0,  0,  0,-10,
        -20,-10,-10,-10,-10,-10,-10,-20
};

int white_pawn_devolpment_table[64] = {
        0,  0,  0,  0,  0,  0,  0,  0,
        50, 50, 50, 50, 50, 50, 50, 50,
        10, 10, 20, 30, 30, 20, 10, 10,
        5,  5, 10, 25, 25, 10,  5,  5,
        0,  0,  0, 20, 20,  0,  0,  0,
        5, 10,-20,  0,  0, 10, 10,  5,
        5, 10, 10,-20,-20, 10, 10,  5,
        0,  0,  0,  0,  0,  0,  0,  0
};
int black_pawn_devolpment_table[64] = {
        0,  0,  0,   0,   0,   0,  0, 0,
        5, 10, 10, -20, -20,  10, 10, 5,
        5, 10, 10,   0,   0, -20, 10, 5,
        5,  5, 10, 20, 20, 10,  5,  5,
        0,  0,  0, 25, 25,  0,  0,  0,
        10, 10, 20, 30, 30, 20, 10,  10,
        50, 50, 50, 50, 50, 50, 50, 50,
        0,  0,  0,  0,  0,  0,  0,  0
};


int white_rook_devolpment_table [] = {
        0,  0,  0,  0,  0,  0,  0,  0,
        5, 10, 10, 10, 10, 10, 10,  5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        0,  0,  0,  5,  5,  0,  0,  0
};

int black_rook_devolpment_table[64] = {
         0,  0,  0,  5,  5,  0,  0,  0,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
        -5,  0,  0,  0,  0,  0,  0, -5,
         5, 10, 10, 10, 10, 10, 10,  5,
         0,  0,  0,  0,  0,  0,  0,  0
};

int white_king_devolpment_table[]{
        -30,-40,   -40,   -50,   -50,-40,-40,-30,
        -30,-40,   -40,   -50,   -50,-40,-40,-30,
        -30,-40,   -40,   -50,   -50,-40,-40,-30,
        -30,-40,   -40,   -50,   -50,-40,-40,-30,
        -20,-30,   -30,   -40,   -40,-30,-30,-20,
        -10,-20,   -20,   -20,   -20,-20,-20,-10,
         20, 20,  -500,  -500,  -500,  0, 20, 20,
          0, 30,     0,     0,     0, 20,  0,  0
};
int end_king_devolpment_table[]{
        -50,-40,-30,-20,-20,-30,-40,-50,
        -30,-20,-10,  0,  0,-10,-20,-30,
        -30,-10, 20, 30, 30, 20,-10,-30,
        -30,-10, 30, 40, 40, 30,-10,-30,
        -30,-10, 30, 40, 40, 30,-10,-30,
        -30,-10, 20, 30, 30, 20,-10,-30,
        -30,-30,  0,  0,  0,  0,-30,-30,
        -50,-30,-30,-30,-30,-30,-30,-50
};

int black_king_devolpment_table[]{
           0,   0,  20,   0,   0,   0,  30,   0,
           0,   0,   0,-500,-500,-500,   0,   0,
         -10, -10, -10, -10, -10, -10, -10, -10,
         -10, -40, -40, -50, -50, -40, -40, -30,
         -20, -30, -30, -40, -40, -30, -30, -20,
         -10, -20, -20, -20, -20, -20, -20, -10,
         -10, -10, -10, -10, -10, -10, -10, -20,
         -10, -10, -10, -10, -10, -10, -10, -10
};

int queen_devolpment_table[]{
        -20,-10,-10, -5, -5,-10,-10,-20,
        -10,  0,  0,  0,  0,  0,  0,-10,
        -10,  0,  5,  5,  5,  5,  0,-10,
        -5,  0,  5,  5,  5,  5,  0, -5,
         0,  0,  5,  5,  5,  5,  0, -5,
        -10,  5,  5,  5,  5,  5,  0,-10,
        -10,  0,  5,  0,  0,  0,  0,-10,
        -20,-10,-10, -5, -5,-10,-10,-20
};


int mvv[6][6];

void fill_pawn_table(){

       
        for(int i = 0 ; i < 10; ++i){
                if(i == P || i == p){
                        values[i] = 1;
                }
                else if(i == N || i == n || i == B || i == b){
                        values[i] = 3;
                }
                else if(i == R || i == r){
                        values[i] = 5;
                }
                else{
                        values[i] = 9;
                }
        }

        mvv[0][0] = 10;mvv[0][1] = 40;mvv[0][2] = 41;mvv[0][3] = 43;mvv[0][0] = 44;mvv[0][0] = 45;
        mvv[1][0] = 6;mvv[1][1] = 10;mvv[1][2] = 10;mvv[0][3] = 35;mvv[1][4] = 36;mvv[1][5] = 37;
        mvv[2][0] = 6;mvv[2][1] = 10;mvv[2][2] = 10;mvv[2][3] = 30;mvv[2][4] = 31;mvv[2][5] = 32;
        mvv[3][0] = 5;mvv[3][1] = 9;mvv[3][2] = 9;mvv[3][3] = 10;mvv[3][4] = 25;mvv[3][5] = 26;
        mvv[4][0] = 4;mvv[4][1] = 7;mvv[4][2] = 7;mvv[4][3] = 8;mvv[4][4] = 10;mvv[4][5] = 20;
        mvv[5][0] = 3;mvv[5][1] = 1;mvv[5][2] = 1;mvv[5][3] = 1;mvv[5][4] = 1;mvv[5][5] = 1; 

      

        for(int index = 0; index < 64; ++index){
                safety_king_table[index] = 0;
                if(index - 1 >= 0){
                        setBit(safety_king_table[index], index - 1);
                }
                if(index + 1 <= 63){
                        setBit(safety_king_table[index], index + 1);

                }

                if(index - 8 >= 0){
                        setBit(safety_king_table[index], index - 8);
                }
                if(index + 8 <= 63){
                        setBit(safety_king_table[index], index + 8);
                }
                if(index - 7 >= 0){
                        setBit(safety_king_table[index], index - 7);
                }
                if(index + 7 <= 63){
                        setBit(safety_king_table[index], index + 7);
                }

                if(index - 9 >= 0){
                        setBit(safety_king_table[index], index - 9);
                }
                if(index + 9 <= 63){
                        setBit(safety_king_table[index], index + 9);
                }

                if(index - 14 >= 0){
                        setBit(safety_king_table[index], index - 14);
                }
                if(index + 14 <= 63){
                        setBit(safety_king_table[index], index + 14);
                }

                if(index - 15 >= 0){
                        setBit(safety_king_table[index], index - 15);
                }
                if(index + 15 <= 63){
                        setBit(safety_king_table[index], index + 15);
                }

                if(index - 16 >= 0){
                        setBit(safety_king_table[index], index - 16);
                }
                if(index + 16 <= 63){
                        setBit(safety_king_table[index], index + 16);
                }

                if(index - 17 >= 0){
                        setBit(safety_king_table[index], index - 17);
                }
                if(index + 17 <= 63){
                        setBit(safety_king_table[index], index + 17);
                }

                if(index - 18 >= 0){
                        setBit(safety_king_table[index], index - 18);
                }
                if(index + 18 <= 63){
                        setBit(safety_king_table[index], index + 18);
                }

                if(index - 6 >= 0){
                        setBit(safety_king_table[index], index - 6);
                }
                if(index + 6 <= 63){
                        setBit(safety_king_table[index], index + 6);
                }

                if(index - 10 >= 0){
                        setBit(safety_king_table[index], index - 10);
                }
                if(index + 10 <= 63){
                        setBit(safety_king_table[index], index + 10);
                }

                if(index - 2 >= 0){
                        setBit(safety_king_table[index], index - 2);
                }
                if(index + 2 <= 63){
                        setBit(safety_king_table[index], index + 2);
                }
        }

}

bool endGame(){
        
        int sum_of_pieces = 0;
        sum_of_pieces += count_bits(bitboards[Q]);
        sum_of_pieces += count_bits(bitboards[q]);
        sum_of_pieces += count_bits(bitboards[R]);
        sum_of_pieces += count_bits(bitboards[r]);
        sum_of_pieces += count_bits(bitboards[N]);
        sum_of_pieces += count_bits(bitboards[n]);
        sum_of_pieces += count_bits(bitboards[B]);
        sum_of_pieces += count_bits(bitboards[b]);

        if(sum_of_pieces == 0){
                return true;
        }
        return false;
}

int eval_pieces(){
        int ev = 0;
        ev += ( (count_bits(bitboards[P]) * 1000) - (count_bits(bitboards[p]) * 1000) );
        ev += ( (count_bits(bitboards[B]) * 3000) - (count_bits(bitboards[b]) * 3000) );
        ev += ( (count_bits(bitboards[N]) * 3000) - (count_bits(bitboards[n]) * 3000) );
        ev += ( (count_bits(bitboards[R]) * 5000) - (count_bits(bitboards[r]) * 5000) );
        ev += ( (count_bits(bitboards[Q]) * 9000) - (count_bits(bitboards[q]) * 9000) );
        return ev;
}
int pawn_advance(){
        int ev = 0;
        U64 pawnBit, tempbit;
        pawnBit = bitboards[P];
        int index;
        while(pawnBit){
                index = get_ls1b_index(pawnBit);
                ev += ((index / 8) + 1);
                popBit(pawnBit, index);
        }
        pawnBit = bitboards[p];
        while(pawnBit){
                index = get_ls1b_index(pawnBit);
                ev -= (8 - ((index / 8) + 1));
                popBit(pawnBit, index);
        }

        tempbit = bitboards[K];

        while(tempbit){
                int index = get_ls1b_index(tempbit);
                ev += end_king_devolpment_table[index];
                popBit(tempbit, index);
        }

        tempbit = bitboards[k];
        while(tempbit){
                int index = get_ls1b_index(tempbit);
                ev -= end_king_devolpment_table[index];
                popBit(tempbit, index);
        }
        

        return ev;
}
int eval_development(){
        int ev = 0;

        if(endg){
                return pawn_advance();
        }
        U64 tempbit = bitboards[N];

        while(tempbit){
                int index = get_ls1b_index(tempbit);
                ev += knight_development_table[index];
                popBit(tempbit, index);
        }

        tempbit = bitboards[n];
        while(tempbit){
                int index = get_ls1b_index(tempbit);
                ev -= knight_development_table[index];
                popBit(tempbit, index);
        }


         tempbit = bitboards[B];

        while(tempbit){
                int index = get_ls1b_index(tempbit);
                ev += white_bishop_devolpment_table[index];
                popBit(tempbit, index);
        }

        tempbit = bitboards[b];
        while(tempbit){
                int index = get_ls1b_index(tempbit);
                ev -= balck_bishop_devolpment_table[index];
                popBit(tempbit, index);
        }

        tempbit = bitboards[P];

        while(tempbit){
                int index = get_ls1b_index(tempbit);
                ev += white_pawn_devolpment_table[index];
                popBit(tempbit, index);
        }

        tempbit = bitboards[p];
        while(tempbit){
                int index = get_ls1b_index(tempbit);
                ev -= black_pawn_devolpment_table[index];
                popBit(tempbit, index);
        }


        
        tempbit = bitboards[R];

        while(tempbit){
                int index = get_ls1b_index(tempbit);
                ev += white_rook_devolpment_table[index];
                popBit(tempbit, index);
        }

        tempbit = bitboards[r];
        while(tempbit){
                int index = get_ls1b_index(tempbit);
                ev -= black_rook_devolpment_table[index];
                popBit(tempbit, index);
        }

        
        
        tempbit = bitboards[K];

        while(tempbit){
                int index = get_ls1b_index(tempbit);
                ev += (endg? end_king_devolpment_table[index] : white_king_devolpment_table[index]);
                popBit(tempbit, index);
        }

        tempbit = bitboards[k];
        while(tempbit){
                int index = get_ls1b_index(tempbit);
                ev -= (endg? ( end_king_devolpment_table[index]) : black_king_devolpment_table[index]);
                popBit(tempbit, index);
        }
        
        tempbit = bitboards[Q];

        while(tempbit){
                int index = get_ls1b_index(tempbit);
                ev += queen_devolpment_table[index];
                popBit(tempbit, index);
        }

        tempbit = bitboards[q];
        while(tempbit){
                int index = get_ls1b_index(tempbit);
                ev -= queen_devolpment_table[index];
                popBit(tempbit, index);
        }
        return ev;
}

int pawn_strcture(){
        int ev = 0;
        
        for(int file = 0; file <= 7; ++file){
                U64 tempbite = bitboards[P];
                tempbite &= files[file];
                
                if(tempbite){
                        ev -= ((count_bits(tempbite) - 1) * 20);
                }
                tempbite = bitboards[p];
                tempbite &= files[file];
                
                if(tempbite){
                        ev += ((count_bits(tempbite) - 1) * 20);
                }
        }

        int index = get_ls1b_index(bitboards[P] & files[0]);
        if(  !getBit(bitboards[P] & files[1], index + 9)){
                ev -= 20;
        }
        index = get_ls1b_index(bitboards[P] & files[1]);
        if(!getBit(bitboards[P] & files[0], index + 7) && !getBit(bitboards[P] & files[2], index + 9)){
                ev -= 20;
        }
        index = get_ls1b_index(bitboards[P] & files[2]);
        if( !getBit(bitboards[P] & files[1], index + 7) && !getBit(bitboards[P] & files[3], index + 9)){
                ev -= 20;
        }
        index = get_ls1b_index(bitboards[P] & files[3]);
        if(!getBit(bitboards[P] & files[2], index + 7) && !getBit(bitboards[P] & files[4], index + 9)){
                ev -= 20;
        }
        index = get_ls1b_index(bitboards[P] & files[4]);
        if(!getBit(bitboards[P] & files[3], index + 7) && !getBit(bitboards[P] & files[5], index + 9)){
                ev -= 20;
        }
        index = get_ls1b_index(bitboards[P] & files[5]);
        if(!getBit(bitboards[P] & files[4], index + 7) && !getBit(bitboards[P] & files[6], index + 9)){
                ev -= 20;
        }
        index = get_ls1b_index(bitboards[P] & files[6]);
        if(!getBit(bitboards[P] & files[5], index + 7) && !getBit(bitboards[P] & files[7], index + 9)){
                ev -= 20;
        }
        index = get_ls1b_index(bitboards[P] & files[7]);
        if( !getBit(bitboards[P] & files[6], index + 7)){
                ev -= 20;
        }

        index = get_ls1b_index(bitboards[p] & files[0]);
        if(!getBit(bitboards[p] & files[1], index - 7)){
                ev += 20;
        }
        index = get_ls1b_index(bitboards[p] & files[1]);
        if(!getBit(bitboards[p] & files[0], index- 9 ) && !getBit(bitboards[p] & files[2], index - 7)){
                ev += 20;
        }
        index = get_ls1b_index(bitboards[p] & files[2]);
        if(!getBit(bitboards[p] & files[1], index - 9) && !getBit(bitboards[p] & files[3], index - 7)){
                ev += 20;
        }
        index = get_ls1b_index(bitboards[p] & files[3]);
        if(!getBit(bitboards[p] & files[2], index - 9) && !getBit(bitboards[p] & files[4], index - 7)){
                ev += 20;
        }
        index = get_ls1b_index(bitboards[p] & files[4]);
        if(!getBit(bitboards[p] & files[3], index - 9) && !getBit(bitboards[p] & files[5], index - 7)){
                ev += 20;
        }
        index = get_ls1b_index(bitboards[p] & files[5]);
        if(!getBit(bitboards[p] & files[4], index - 9) && !getBit(bitboards[p] & files[6], index - 7)){
                ev += 20;
        }
        index = get_ls1b_index(bitboards[p] & files[6]);
        if(!getBit(bitboards[p] & files[5], index - 9) && !getBit(bitboards[p] & files[7], index - 7)){
                ev += 20;
        }
        index = get_ls1b_index(bitboards[p] & files[7]);
        if(!getBit(bitboards[p] & files[6], index - 9)){
                ev += 20;
        }


        if(!(bitboards[p] & files[0]) && get_ls1b_index(bitboards[P] & files[0]) > get_ls1b_index(bitboards[P] & files[1])){
                ev -= 20;
        }
        if(!(bitboards[p] & files[1]) && get_ls1b_index(bitboards[P] & files[1]) > get_ls1b_index(bitboards[P] & files[2]) && 
        get_ls1b_index(bitboards[P] & files[1]) - 1 > get_ls1b_index(bitboards[P] & files[0])){
                ev -= 20;
        }
        
        if(!(bitboards[p] & files[2]) && get_ls1b_index(bitboards[P] & files[2]) > get_ls1b_index(bitboards[P] & files[3]) && 
        get_ls1b_index(bitboards[P] & files[2]) - 1 > get_ls1b_index(bitboards[P] & files[1])){
                ev -= 20;
        }
        if(!(bitboards[p] & files[3]) && get_ls1b_index(bitboards[P] & files[3]) > get_ls1b_index(bitboards[P] & files[4]) && 
        get_ls1b_index(bitboards[P] & files[3]) - 1 > get_ls1b_index(bitboards[P] & files[2])){
                ev -= 20;
        }
        if(!(bitboards[p] & files[4]) && get_ls1b_index(bitboards[P] & files[4]) > get_ls1b_index(bitboards[P] & files[5]) && 
        get_ls1b_index(bitboards[P] & files[4]) - 1 > get_ls1b_index(bitboards[P] & files[3])){
                ev -= 20;
        }
        if(!(bitboards[p] & files[5]) && get_ls1b_index(bitboards[P] & files[5]) > get_ls1b_index(bitboards[P] & files[6]) && 
        get_ls1b_index(bitboards[P] & files[5]) - 1 > get_ls1b_index(bitboards[P] & files[4])){
                ev -= 20;
        }
        if(!(bitboards[p] & files[6]) && get_ls1b_index(bitboards[P] & files[6]) > get_ls1b_index(bitboards[P] & files[7]) && 
        get_ls1b_index(bitboards[P] & files[6]) - 1 > get_ls1b_index(bitboards[P] & files[5])){
                ev -= 20;
        }
        if(!(bitboards[p] & files[7]) && get_ls1b_index(bitboards[P] & files[7]) - 1 > get_ls1b_index(bitboards[P] & files[6])){
                ev -= 20;
        }

        //for black
        
        if(!(bitboards[P] & files[0]) && get_ls1b_index(bitboards[p] & files[0]) < get_ls1b_index(bitboards[p] & files[1] - 1)){
                ev += 20;
        }
        if(!(bitboards[P] & files[1]) && get_ls1b_index(bitboards[p] & files[1]) < get_ls1b_index(bitboards[p] & files[2]) - 1 && 
        get_ls1b_index(bitboards[p] & files[1])  < get_ls1b_index(bitboards[p] & files[0])){
                ev += 20;
        }
        
        if(!(bitboards[P] & files[2]) && get_ls1b_index(bitboards[p] & files[2]) < get_ls1b_index(bitboards[p] & files[3]) - 1 && 
        get_ls1b_index(bitboards[p] & files[2])  < get_ls1b_index(bitboards[p] & files[1])){
                ev += 20;
        }
        if(!(bitboards[P] & files[3]) && get_ls1b_index(bitboards[p] & files[3]) < get_ls1b_index(bitboards[p] & files[4]) - 1 && 
        get_ls1b_index(bitboards[p] & files[3])  < get_ls1b_index(bitboards[p] & files[2])){
                ev += 20;
        }
        if(!(bitboards[P] & files[4]) && get_ls1b_index(bitboards[p] & files[4]) < get_ls1b_index(bitboards[p] & files[5]) - 1 && 
        get_ls1b_index(bitboards[p] & files[4])  < get_ls1b_index(bitboards[p] & files[3])){
                ev += 20;
        }
        if(!(bitboards[P] & files[5]) && get_ls1b_index(bitboards[p] & files[5]) < get_ls1b_index(bitboards[p] & files[6]) - 1&& 
        get_ls1b_index(bitboards[p] & files[5])  < get_ls1b_index(bitboards[p] & files[4])){
                ev += 20;
        }
        if(!(bitboards[P] & files[6]) && get_ls1b_index(bitboards[p] & files[6]) < get_ls1b_index(bitboards[p] & files[7]) - 1&& 
        get_ls1b_index(bitboards[p] & files[6]) < get_ls1b_index(bitboards[p] & files[5])){
                ev += 20;
        }
        if(!(bitboards[P] & files[7]) && get_ls1b_index(bitboards[p] & files[7]) < get_ls1b_index(bitboards[p] & files[6])){
                ev += 20;
        }


        return ev;
}

int mobility(){
        int ev = 0;
        U64 attacks, tbit;
        tbit = bitboards[N];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks =  knight_attacks[source_square] & (~occupancies[white]);
                ev += (count_bits(attacks) * 3);
                popBit(tbit, source_square);
        }
        tbit = bitboards[B];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks = get_bishop_attacks(source_square, occupancies[both]) & (~occupancies[white]);
                ev += (count_bits(attacks) * 3);
                popBit(tbit, source_square);
        }
        tbit = bitboards[R];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks = get_rook_attacks(source_square, occupancies[both]) & (~occupancies[white]);
                ev += (count_bits(attacks) * 3);
                popBit(tbit, source_square);
        }
        tbit = bitboards[Q];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks = get_queen_attacks(source_square, occupancies[both]) & (~occupancies[white]); 
                ev += (count_bits(attacks) * 3);
                popBit(tbit, source_square);
        }

        tbit = bitboards[K];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks = king_attacks[source_square] & (~occupancies[white]); 
                ev += (count_bits(attacks) * 3);
                popBit(tbit, source_square);
        }



        tbit = bitboards[n];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks = knight_attacks[source_square] & (~occupancies[white]);
                ev -= (count_bits(attacks) * 3);
                popBit(tbit, source_square);
        }
        tbit = bitboards[b];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks = get_bishop_attacks(source_square, occupancies[both]) & (~occupancies[white]);
                ev -= (count_bits(attacks) * 3);
                popBit(tbit, source_square);
        }
        tbit = bitboards[r];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks = get_rook_attacks(source_square, occupancies[both]) & (~occupancies[white]);
                ev -= (count_bits(attacks) * 3);
                popBit(tbit, source_square);
        }
        tbit = bitboards[q];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks = get_queen_attacks(source_square, occupancies[both]) & (~occupancies[white]); 
                ev -= (count_bits(attacks) * 3);
                popBit(tbit, source_square);
        }


        tbit = bitboards[k];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks = king_attacks[source_square] & (~occupancies[white]); 
                ev -= (count_bits(attacks) * 3);
                popBit(tbit, source_square);
        }

        return ev;

}

int safety_king(){
        int ev = 0;
        int white_king_square = get_ls1b_index(bitboards[K]);
        int black_king_square = get_ls1b_index(bitboards[k]);

        U64 tbit, attacks ;
       
        tbit = bitboards[B];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks = bishop_masks[source_square];
                if(attacks & bitboards[K]){
                        ev -= 40;
                }
                popBit(tbit, source_square);
        }
        tbit = bitboards[R];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks = rook_masks[source_square];
                if(attacks & bitboards[K]){
                        ev -= 40;
                }
                popBit(tbit, source_square);
        }
        tbit = bitboards[Q];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks = (rook_masks[source_square] | bishop_masks[source_square]); 
                if(attacks & bitboards[Q]){
                        ev -= 40;
                }
                popBit(tbit, source_square);
        }


        tbit = bitboards[b];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks = bishop_masks[source_square];
                if(attacks & bitboards[k]){
                        ev += 40;
                }
                popBit(tbit, source_square);
        }
        tbit = bitboards[r];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks = rook_masks[source_square];
                if(attacks & bitboards[k]){
                        ev += 40;
                }
                popBit(tbit, source_square);
        }
        tbit = bitboards[q];
        while(tbit){
                int source_square = get_ls1b_index(tbit);
                attacks = (rook_masks[source_square] | bishop_masks[source_square]); 
                if(attacks & bitboards[q]){
                        ev += 40;
                }
                popBit(tbit, source_square);
        }

        tbit = safety_king_table[white_king_square];
        ev -= (count_bits(tbit & occupancies[black]) * 30);
        ev += (count_bits(tbit & occupancies[white]) * 20);

        tbit = safety_king_table[black_king_square];
        ev += (count_bits(tbit & occupancies[white]) * 30);
        ev -= (count_bits(tbit & occupancies[black]) * 20);
        
        if(endg){
                return ev / 5;
        }
        return ev;
}


int eval(){

        
        int ev = 0;
        endg = endGame();
        ev += (eval_pieces());        

      //  ev += eval_development() ;
        
        ev += (side == white ? 70 : -70);
        
        ev += pawn_strcture() ;

        ev += mobility() ;
        
        ev += (safety_king());

        endg = false;

       
        return ev;
}


int decode_move(string str){
        int move = 0;
        int source_square = square_back[str.substr(0, 2)];
        move |= (source_square << 11);
        int targeted_square = square_back[str.substr(2, 2)];
        move |= (targeted_square << 3);
        if(str.size() == 5){
                if(str[4] == 'r'){
                        move |= 1;
                }
                else if(str[4] == 'b'){
                        move |= 2;
                }
                else if(str[4] == 'q'){
                        move |= 3;
                }
                else{
                        move |= 4;
                }
        }
        return move;
}

void files_gen(){
        for(int i = 0; i < 8; ++i){
                U64 bitb = 0;
                for(int row = 0; row < 8; ++ row){
                        for(int col = 0; col < 8; ++col){
                                if(col != i){
                                        continue;
                                }
                                int square = 8 * row + col;
                                setBit(bitb, square);
                        }
                }

                cout<<bitb<<'\n';
                print_bitboard(bitb);
        }
}

string line;
void setUpPosition(string str){
        int start = 24;
        string move = "";
        line = "";
        int n = str.size();
        for(; start < n; ++start ){
               if(start == n - 1){
                       move += str[start];

                       make_move(decode_move(move));
               }
               else if(str[start] == ' '){
                        make_move(decode_move(move));
                        move = "";
                }
                else{
                        move += str[start];
                }
        line += str[start];        
        }
}

int best_move = 1, fixed_depth = 6;

void sort_(moveL& moves){
        int sz = moves.size;

        sort(moves.moves, moves.moves + sz);
        for(int j = sz - 1, i = 0; i < sz && j > sz; ++i, --j){
                swap(moves.moves[j], moves.moves[i]);
        }
}

void order_moves(moveL &moves){
        int mov, sz = moves.size;
        for(int i = 0; i < sz; i++){
                mov = moves.moves[i];
                if(mov & (1 << 19))
                        continue;

                int tar = 63 & (mov >> 3);
                int sc = 63 & (mov >> 11);
                int attacker, victim;
                for(int i = P; i <=k ; ++i){
                        if(getBit(bitboards[i], sc)){
                                attacker = i;
                        }
                        else if(getBit(bitboards[i], tar)){
                                victim = i;
                        }
                }

                int plus = mvv[attacker % 6][victim % 6];
                //cout<<"plus = "<<plus<<'\n';
                mov |= (plus << 20);        
        }

        sort_(moves);

        //for(int mov : moves){
           // string s =  ret_str_move(mov);
      //  }
}

bool check(){
        if(side == white){
                int index = get_ls1b_index(bitboards[K]);
                if(is_square_attacked(index, black)) return true;
        }
        else{
                int index = get_ls1b_index(bitboards[k]);
                if(is_square_attacked(index, white)) return true;
        }
        return false;
}



int quiesce(int dep, int alpha, int beta){  
        //cout<<"Hello\n";
        int temp = eval();
        if(dep == 0){
                return temp;
        }      
        moveL moves1, moves;
        generate_moves(moves1);
        int sz1 = moves1.size, sz = 0;
             int mov;   
        
                for(int i = 0; i < sz1; ++i){
                        mov = moves1.moves[i];
                        if(mov & (1<<19)){
                                continue;
                        }
                        moves.moves[sz++] = mov;
                }

        moves.size = sz;
        order_moves(moves);  

         
        for(int i = 0; i < sz; ++i){
                if(moves.moves[i] == qkiller_move[dep]){
                        swap(moves.moves[i], moves.moves[0]);
                        break;
                }
        }       
        
        int move;
        if (side == white) {       
                int maxEva= temp;
                            
                for (int i = 0; i < sz; ++i){
                        move = moves.moves[i];
                        copy_board()
                        make_move(move);
                        if(king_attacked){
                                        //if(mov == "g5g4")cout<<"ioasdh\n";
                                        king_attacked = 0;
                                        take_back()
                                        //cout<<mov<<" King is attacked\n";
                                        continue;
                                }  
                        int eva = quiesce(dep - 1, alpha, beta); 
                        maxEva= max(maxEva, eva);   
                        alpha = max(alpha, maxEva);
                        take_back()      
                        if (beta <= alpha){  
                                qkiller_move[dep] = move;
                                break;
                        }        
                }                         
                return maxEva;  
        }    
        else{   
                                        
                int minEva= temp;

                for (int i = 0; i < sz; ++i){
                        move = moves.moves[i];        
                        copy_board()
                        make_move(move);
                        if(king_attacked){
                                //if(mov == "g5g4")cout<<"ioasdh\n";
                                king_attacked = 0;
                                take_back()
                                //cout<<mov<<" King is attacked\n";
                                continue;
                        }  
                        int eva = quiesce(dep - 1, alpha, beta);  
                        minEva= min(minEva, eva);   
                        beta= min(beta, eva);
                        take_back()  
                        if (beta<=alpha){
                                qkiller_move[dep] = move;  
                                break;
                        }        
                                
                }

                return minEva;  
        }


}




int AlphaBeta(int depth, int alpha, int beta){  
    

        if (depth == 0 ){
                return quiesce(2, alpha, beta);
               //return eval();
        }  
  
        moveL moves;
        generate_moves(moves);
        order_moves(moves);
        int sz = moves.size;
        for(int i = 0; i < sz; ++i){
                if(moves.moves[i] == killer_move[depth]){
                        swap(moves.moves[i], moves.moves[0]);
                        break;
                }
        }
        int move;
        if (side == white) {       
                int maxEva= -2e9;           
                for (int i = 0; i < sz; ++i){
                        move = moves.moves[i];        
                        copy_board()
                        make_move(move);
                        if(king_attacked){
                                        //if(mov == "g5g4")cout<<"ioasdh\n";
                                        king_attacked = 0;
                                        take_back()
                                        //cout<<mov<<" King is attacked\n";
                                        continue;
                                }  
                        int eva =  AlphaBeta(depth-1, alpha, beta); 
                        if(fixed_depth == depth && best_move == 1){
                                best_move = move;
                        }
                        if(fixed_depth == depth){
                               if(eva > maxEva){
                                best_move = move;
                               }
                               if(checkmate > best_checkmate){
                                best_checkmate = checkmate;
                                best_move = move;
                               }
                        } 
                        maxEva= max(maxEva, eva);   
                        alpha = max(alpha, maxEva);
                        take_back()      
                        if (beta<=alpha){
                                killer_move[depth] = move;  
                                break;
                        }        
                }
                if(maxEva == -2e9){
                        if(!check()){
                                return 0;
                        }
                        checkmate = max(checkmate, depth);

                }                         
                return maxEva;  
        }    
        else{   
                                        
                int minEva= 2e9;
               
                for (int i = 0; i < sz; ++i){
                        move = moves.moves[i];
                        copy_board()
                        make_move(move);
                        if(king_attacked){
                                        //if(mov == "g5g4")cout<<"ioasdh\n";
                                        king_attacked = 0;
                                        take_back()
                                        //cout<<mov<<" King is attacked\n";
                                        continue;
                                        }
                        int eva =  AlphaBeta(depth-1, alpha, beta);
                        if(fixed_depth == depth && best_move == 1){
                                best_move = move;
                        }                  
                        
                        if(eva < minEva && fixed_depth == depth){
                                best_move = move;
                        }  
                        minEva= min(minEva, eva);   
                        beta= min(beta, eva);
                        take_back()  
                        if (beta<=alpha){  
                                killer_move[depth] = move;
                                break;
                        }        
                                
                }
                if(minEva == 2e9){
                        if(!check()){
                                return 0;
                        }
                        checkmate = max(checkmate, depth);

                }
                return minEva;  
        }


}

string ret_str_move(int int_move){

        string str_move = "";

        string targeted_square = coordinate[63 & (int_move >> 3)];

        string source_square = coordinate[63 & (int_move >> 11)];

        str_move = source_square;

        str_move += targeted_square;

        int pro = (int_move & 7);

        if(pro){
                // 1 = r b = 2 q = 3
                if(pro == 1)
                {
                        str_move += 'r';
                }
                else if(pro == 2){
                        str_move += 'b';
                }
                else if(pro == 3){
                        str_move += 'q';
                }
                else {
                        str_move += 'n';
                }
        }

        bitset<32>x(int_move);
        cout<<x<<'\n';
        cout<<int_move<<'\n';
       // cout<<"source_square = "<<source_square<<"    targeted square = "<<targeted_square<<'\n';

        return str_move;
        
}       


int set_depth(int dep){
        fixed_depth = dep;
        return dep;
}
 void debug(){
  
        //cout<<"number of nodes = "<<nodes<<'\n';
        int x;
        cin >> x;
 }
//#define tricky_position "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1 "
int main(){
        fill_pawn_table();
        init_attacks();
        init_sliders_attacks(1);
        init_sliders_attacks(0);
     
        
        //debug();

        printf("id name Chenglite\n");
	printf("id author CSE 2022\n");
	printf("uciok\n");
        string s;
        
        while(1){
                
                getline(cin, s);

                if(s[0] == 'i' && s[1] == 's'){
                        cout<<"readyok\n";
                }
                else if(s[0] == 'p'){
                    side = white;
                    parse_fen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 ");  
                    setUpPosition(s);
                    best_move = 1;
                    print_position();
                }
                else if(s[0] == 'g'){
                      
                        
                        checkmate = 0, best_checkmate = 0;
                   // debug();        
                                int dep = 4;

                                if(endGame()){
                                        dep = 7;
                                }
                        
                                int score = AlphaBeta(set_depth(dep), -2e9, 2e9);
                             
                               string bestm = ret_str_move(best_move); 
                                //befor_last_move = last_move;
                                //last_move = best_move;
                          cout<<"bestmove "<<bestm<<" ponder "<<bestm<<'\n';
                        
                }
                else if(s[0] == 's'){
                        break;
                }
        }
        return 0;
}